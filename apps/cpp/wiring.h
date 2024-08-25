#ifndef wiring_wasm_api_h
#define wiring_wasm_api_h

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
#define WASM_EXTERN_C  extern "C"
#else
#define WASM_EXTERN_C
#endif

#define WASM_EXPORT                   WASM_EXTERN_C __attribute__((used)) __attribute__((visibility ("default")))
#define WASM_EXPORT_AS(NAME)          WASM_EXPORT __attribute__((export_name(NAME)))
#define WASM_IMPORT(MODULE,NAME)      __attribute__((import_module(MODULE))) __attribute__((import_name(NAME)))
#define WASM_CONSTRUCTOR              __attribute__((constructor))

#define LOW               0x0
#define HIGH              0x1

#define INPUT             0x0
#define OUTPUT            0x1
#define INPUT_PULLUP      0x2

#ifdef __cplusplus
extern "C" {
#endif

WASM_IMPORT("wiring","millis")        uint32_t millis     (void);
WASM_IMPORT("wiring","delay")         void delay          (uint32_t ms);
WASM_IMPORT("wiring","pinMode")       void pinMode        (uint32_t pin, uint32_t mode);
WASM_IMPORT("wiring","digitalWrite")  void digitalWrite   (uint32_t pin, uint32_t value);
WASM_IMPORT("wiring","print")         void _print         (const char* s, size_t len);

WASM_EXPORT_AS("setup")               void setup(void);
WASM_EXPORT_AS("loop")                void loop(void);

#define strcpy      __builtin_strcpy
#define memcpy      __builtin_memcpy
#define memmove     __builtin_memmove

static inline
size_t strlen(const char *str) {
    const char *s;
    for (s = str; *s; ++s);
    return (s - str);
}

static inline
void strreverse(char str[], int length)
{
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
        start++;
    }
}

static inline
size_t itoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;

    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return i;
    }

    // In standard itoa(), negative numbers are handled
    // only with base 10. Otherwise numbers are
    // considered unsigned.
    if (num < 0 && base == 10) {
        isNegative = true;
        num = -num;
    }

    // Process individual digits
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    // If number is negative, append '-'
    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    strreverse(str, i);

    return i;
}

static inline void print (const char* s) {
    _print(s, strlen(s));
}

static inline void println (const char* s) {
    print(s); print("\n");
}

#ifdef __cplusplus
}
#endif

#endif // wiring_wasm_api_h
