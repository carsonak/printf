#define _TASK1_
#ifdef _TASK1_
#include "main.h"

/**
 * main - the TASK0 test file
 *
 * Return: Always 0
 */
int main(void)
{
    int ret;

    ret = printf("5*2=%d, 7896*4562=%i", 10, 36021552);
    printf("\n%d\n", ret);
    ret = _printf("5*2=%d, 7896*4562=%i", 10, 36021552);
    printf("\n%d\n\n", ret);

    ret = printf("%d is -ve and %i is +ve", -10, +10);
    printf("\n%d\n", ret);
    ret = _printf("%d is -ve and %i is +ve", -10, +10);
    printf("\n%d\n", ret);
    ret = printf("%d is +ve and %i is -ve", +10984, -109395);
    printf("\n%d\n", ret);
    ret = _printf("%d is +ve and %i is -ve", +10984, -109395);
    printf("\n%d\n\n", ret);

    printf("5+2=%d, 15095+294833=%i", 5 + 2, 15095 + 294833);
    printf("\n%d\n", ret);
    ret = _printf("5+2=%d, 15095+294833=%i", 5 + 2, 15095 + 294833);
    printf("\n%d\n\n", ret);

    ret = printf("57-32=%d, 15095-294833=%i", 57 - 32, 15095 - 294833);
    printf("\n%d\n", ret);
    ret = _printf("57-32=%d, 15095-294833=%i", 57 - 32, 15095 - 294833);
    printf("\n%d\n\n", ret);

    ret = printf("5*0=%d, 74/3=%i", 5 * 0, 74 / 3);
    printf("\n%d\n", ret);
    ret = _printf("5*0=%d, 74/3=%i", 5 * 0, 74 / 3);
    printf("\n%d\n", ret);

    ret = printf("5*3=%d, 5*2=%i", 5 * 3, 10);
    printf("\n%d\n", ret);
    ret = _printf("5*3=%d, 5*2=%i", 5 * 3, 10);
    printf("\n%d\n\n", ret);

    ret = printf("5*5=%d, 10000*10000=%i", 25, 10000 * 10000);
    printf("\n%d\n", ret);
    ret = _printf("5*5=%d, 10000*10000=%i", 25, 10000 * 10000);
    printf("\n%d\n\n", ret);

    ret = printf("NULL=%d, NULL=%i", NULL, NULL);
    printf("\n%d\n", ret);
    ret = _printf("NULL=%d, NULL=%i", NULL, NULL);
    printf("\n%d\n\n", ret);

    ret = printf("INT_MAX=%d, INT_MAX=%i", INT_MAX, INT_MAX);
    printf("\n%d\n", ret);
    ret = _printf("INT_MAX=%d, INT_MAX=%i", INT_MAX, INT_MAX);
    printf("\n%d\n\n", ret);

    ret = printf("INT_MIN=%d, INT_MIN=%i", INT_MIN, INT_MIN);
    printf("\n%d\n", ret);
    ret = _printf("INT_MIN=%d, INT_MIN=%i", INT_MIN, INT_MIN);
    printf("\n%d\n\n", ret);

    return (0);
}

#endif /*_TASK1_*/
