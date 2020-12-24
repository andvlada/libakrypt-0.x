#include <stdio.h>
#include <libakrypt.h>

int main()
{
    strt = 57204;
    printf("xorshift32: start = 57204, result = %u\n", (unsigned int)ak_xorshift32());
    printf("xorshift32: result = %u\n\n", (unsigned int)ak_xorshift32());

    start = 357338;
    printf("xorshift64: start = 357338, result = %u\n", (unsigned int)ak_xorshift64());
    printf("xorshift64: result = %u\n\n", (unsigned int)ak_xorshift64());

    start = 856352;
    printf("xorshift64star: start = 856352, result = %u\n", (unsigned int)ak_xorshift64star());
    printf("xorshift64star: result = %u\n\n", (unsigned int)ak_xorshift64star());

    start = 553023;
    start_2 = 422229;
    printf("xorshift64star: start = 553023, start_2 = 422229, result = %u\n", (unsigned int)ak_xorshift64plus());
    printf("xorshift64star: result = %u\n\n", (unsigned int)ak_xorshift64plus());

}
