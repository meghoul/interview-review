#include <assert.h>

void test_memcpy(void* dst, void* src, size_t n) {
    assert(dst);
    assert(src);
    assert(n > 0);

    if (src == dst)
        return;
    if (dst < src || dst >= (char *) src + n) {
        char* d = (char*)dst;
        char* s = (char*)src;
        while(n--)
        {
            *d++ = *s++;
        }
    } else {
        char* d = (char*)dst + n - 1;
        char* s = (char*)src + n - 1;
        while(n--)
        {
            *d-- = *s--;
        }
    }
}