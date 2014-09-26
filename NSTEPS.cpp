#include <iostream>
#include <cstdio>
#include <malloc.h>
using namespace std;

void scanint(int &x)
{
	register int c = getchar_unlocked();
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

int main ()
{
	int t=0;
	scanint(t);
	while(t--)
	{
		int a=0,b=0;
		scanint(a);
		scanint(b);
		if(a==b || b==a-2){
			if(a==b){
				if(a%2==0)
					printf("%d\n",2*a);
				else
					printf("%d\n",2*a-1);
			}
			else{
				if(a%2==0)
					printf("%d\n",2*a-2);
				else
					printf("%d\n",2*a-3);
			}
		}
		else{
			printf("No Number\n");
		}
							
	}

	return 0;
}
