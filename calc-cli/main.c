#include <stdio.h>
#include <stdlib.h>

void instructions()
{
    printf("Usage: ./main <num1> <operator> <num2>\n");
    printf("Operators: + - * / %%\n\n");
}

int main(int argc, char const *argv[])
{
    long long n1, n2, ret;
    char op;
    char *endptr1, *endptr2;

    if (argc != 4)
    {
        printf("\nError: expected 3 args\n");
        instructions();
        return 1;
    }

    n1 = strtol(argv[1], &endptr1, 10);
    n2 = strtol(argv[3], &endptr2, 10);
    if (*endptr1 != '\0' || *endptr2 != '\0') 
    {
        printf("\nError: Inputs must be integers\n\n");
        return 1;
    }

    op = argv[2][0];
    if (argv[2][1] != '\0' || (op != '+' && op != '-' && op != '*' && op != '/' && op != '%')) 
    {
        printf("\nInvalid operator\n");
        instructions();
        return 1;
    }
    
    if ((op == '/' || op == '%') && n2 == 0)
    {
        printf("\nError: division by 0\n");
        return 1;
    }

    switch (op)
    {
        case '+': ret = n1 + n2; break;
        case '-': ret = n1 - n2; break;
        case '*': ret = n1 * n2; break;
        case '/': ret = n1 / n2; break;
        case '%': ret = n1 % n2; break;
        default: return 1;
    }

    printf("%ld\n\n", ret);
    return 0;
}
