#include<iostream>
#include<cstdio>
using namespace std;

void scanlongint(long long int &x)
{
	register long long int c = getchar_unlocked();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = getchar_unlocked());
	if(c=='-') {neg=1;c=getchar_unlocked();}
	for(;c>47 && c<58;c = getchar_unlocked()) 
	{
		x = (x << 1) + (x << 3) + c - 48;
	}
	if(neg) x=-x;
}

int main()
{
	long long int t=0;
	scanlongint(t);
	
	while(t--){

	long long int a,b,sum;
	scanlongint(a);
	scanlongint(b);
	scanlongint(sum);
	
	long long int n= (sum*2)/(a+b);

	long long int d= (b-a)/(n-2-3);

	printf("%lld\n",n);

	a=a-2*d;
	//long long int final=a+(n-1)*d;
	
	for(long long int j=0;j<n;a+=d,j++)
		printf("%lld ",a);
	printf("\n");
	}
	return 0;
}
