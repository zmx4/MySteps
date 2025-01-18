#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char *str = NULL;
    size_t len = 0;
    int a=0;
    size_t read;
    read = getline(&str, &len, stdin);
    str[strcspn(str, "\n")] = '\0';
    size_t length = strlen(str);
    for(int i=0;i<length;i++)
    {
        if(str[i]%2==0){
            a++;
        }
    }
    printf("%d",a);
    free(str);
}