#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char *dstr;
    dstr = (char *) malloc(20 * sizeof(char));

    if(dstr == NULL)
    {
        printf("Failed!");
        return 1;
    }
    printf("Enter a string: ");
    scanf("%s", dstr);

    printf("The string you've entered is: %s", dstr);

    free(dstr);
    
    return 0;
}