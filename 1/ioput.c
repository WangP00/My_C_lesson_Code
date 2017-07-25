#include <stdio.h>
int main(){
    printf("input your sid and name \n");
    int sid;
    char name[10];
    if(scanf("%d",&sid)==1) printf("get sid\n");
    if(scanf("%s",&name)==1) printf("get name\n");
    printf("Welcome	%s to the C	and	C++	world \n",name);
    return 0;
}