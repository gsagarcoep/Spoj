#include <stdio.h> int f(int n){return n<2?2:f(n-1)*(4*n-2)/n;} void main(){int T;scanf("%d",&T);while(T--){int n;scanf("%d",&n);printf("%d\n",f(n));}}
