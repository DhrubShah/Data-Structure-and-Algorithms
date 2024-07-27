#include<stdio.h>
void toh(int n, char a, char b, char c){
if(n==1){
    printf("\n Move disk1 from %c to %c \n",a,c);
    return;
}
 toh(n-1,a,b,c);
 printf("\n move disk %d from %c to %c",n,a,c);
 toh(n-1,b,c,a);
}
int main(){
int n;
printf("enter number of disk \n");
scanf("%d",&n);
toh(n,'a','b','c');
return 0;
}
