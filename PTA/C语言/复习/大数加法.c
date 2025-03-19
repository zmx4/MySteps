#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char First[100],Second[100];
    char *longer, *shorter;
    int length,length2,num,carry = 0;
    scanf("%s",&First);
    scanf("%s",&Second);
    if (strlen(First) < strlen(Second)) {
        shorter = First;
        longer = Second;
        length = strlen(First);
        length2 = strlen(Second);
    } else {
        shorter = Second;
        longer = First;
        length = strlen(Second);
        length2 = strlen(First);
    }
    const int L =length2+1;
    char result[L]={};
    /*
    for(int i=0;i<length;i++)
    {
        if(length2>i)
        {
            num=(int)First[i]+Second[i];
            
            if(carry=1)
            {
                result[i]=num%10+1;
                carry = 0;
            }
            else
            {
                result[i]=num%10;
            }
            carry = num / 10;
        }
    }
    */

    for (int i = 0; i < length; i++) {
        num = (shorter[length - 1 - i] - '0') + (longer[length2 - 1 - i] - '0') + carry;
        result[length2 - i] = (num % 10) + '0';
        carry = num / 10;
    }

    for (int i = length; i < length2; i++) {
        num = (longer[length2 - 1 - i] - '0') + carry;
        result[length2 - i] = (num % 10) + '0';
        carry = num / 10;
    }

    if (carry > 0) {
        result[0] = carry + '0';
    }

    for(int i=0;i<=length2;i++)
    {
        printf("%c",result[i]);
    }
}