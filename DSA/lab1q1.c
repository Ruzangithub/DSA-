#include<stdio.h>
#include<stdlib.h>

int main()
{
    int* dInt = (int*)malloc(sizeof(int));

    if (dInt == NULL)
    {
        printf("Memory allocaton failed!");
        return 1;
    }

    *dInt = 42;

    printf("The value is :%d\n", *dInt);

    free(dInt);

    return 0;
}