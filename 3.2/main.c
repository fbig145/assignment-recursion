#include <stdio.h>
int rGetHermite(int n, int x){
    if(n==0) return 1;
    if(n==1) return 2*x;
    return 2*n*rGetHermite(n-1,x)-2*(n-1)*rGetHermite(n-2,x);
}
int getHermite(int n, int x){
    int a=2*x;
    int b=1;
    int h=0;
    if(n==0) return b;
    if(n==1) return a;
    for(int i=2; i<=n; i++){
        h=2*i*a-2*(i-1)*b;
        b=a;
        a=h;
    }
    return h;
}
int main() {
    int n=0;
    int x=0;
    printf("n=");
    scanf("%d",&n);
    printf("x=");
    scanf("%d",&x);
    printf("Recursively: %d\n",rGetHermite(n,x));
    printf("Non-Recursively: %d",getHermite(n,x));
    return 0;
}