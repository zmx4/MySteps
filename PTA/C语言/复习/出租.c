#include<stdio.h>
int main(){
    char a[12] = {};
    scanf("%s",a);
    int b[10]={0},c=0,i;
    for(i=0;i<11;i++){
        if((b[a[i]-'0']++)==0){
            c++;
        }
    }
    int c_1 = c;
    i=0;
    int cc[10]={0};
    while(c)
    {
        if(b[i]>0){
            c--;
            cc[c]=i;
            i++;
        }else{
            i++;
        }
    }
    for(i=0;i<11;i++){
        for(int j=c_1-1;j>=0;j--){
            if((a[i]-'0')==cc[j]){
                a[i] = j + '0';
                break;
            }
        }
    }
    printf("int[] arr = new int[]{");
    for(i=0;i<c_1-1;i++){
        printf("%d,",cc[i]);
    }
    printf("%d",cc[c_1-1]);
    printf("};\n");
    printf("int[] index = new int[]{");
    for(i=0;i<10;i++){
        printf("%c,",a[i]);
    } 
    printf("%c",a[10]);
    printf("};");
}