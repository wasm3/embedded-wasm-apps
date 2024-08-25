#include <stddef.h>

class FixedBufferStream {
private:
    char* buffer_;
    size_t capacity_;
    size_t size_;

public:
    FixedBufferStream(char* buffer, size_t capacity)
        : buffer_(buffer), capacity_(capacity), size_(0) {
        // Initialize buffer to null characters
        if (buffer_ && capacity_ > 0) {
            buffer_[0] = '\0';
        }
    }

    FixedBufferStream& operator<<(int value) {
        // Convert integer to string and append to buffer
        char intStr[12]; // Enough to hold -2147483648\0
        size_t len = intToString(value, intStr);
        append(intStr, len);
        return *this;
    }

    FixedBufferStream& operator<<(const char* str) {
        // Append string to buffer
        append(str, strlen(str));
        return *this;
    }

    FixedBufferStream& operator<<(FixedBufferStream& (*manip)(FixedBufferStream&)) {
        // For handling manipulators like std::endl
        return manip(*this);
    }

    const char* get_buffer() const {
        return buffer_;
    }

    static FixedBufferStream& endl(FixedBufferStream& stream) {
        stream.append("\n", 1);
        return stream;
    }

private:
    size_t strlen(const char* str) {
        const char* s = str;
        while (*s) ++s;
        return s - str;
    }

    size_t intToString(int value, char* buffer) {
        char* p = buffer;
        if (value < 0) {
            *p++ = '-';
            value = -value;
        }
        char* start = p;
        do {
            *p++ = '0' + (value % 10);
            value /= 10;
        } while (value > 0);
        *p = '\0';
        reverse(start, p - 1);
        return p - buffer;
    }

    void reverse(char* start, char* end) {
        while (start < end) {
            char temp = *start;
            *start++ = *end;
            *end-- = temp;
        }
    }

    void append(const char* str, size_t len) {
        if (size_ + len >= capacity_) {
            len = capacity_ - size_ - 1; // Reserve space for null terminator
        }
        for (size_t i = 0; i < len; ++i) {
            buffer_[size_++] = str[i];
        }
        buffer_[size_] = '\0';
    }
};

