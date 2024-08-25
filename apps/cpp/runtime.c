#include <stddef.h>

__attribute__((weak))
size_t strlen(const char *str) {
    const char *s;
    for (s = str; *s; ++s);
    return (s - str);
}
