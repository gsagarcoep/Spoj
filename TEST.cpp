#include<iostream>
#include<cstdio>
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

int main()
{
	int num;
	
	while(1){
		scanint(num);
		if(num==42 || num>99)
			break;
		printf("%d\n",num);
	}
	return 0;
}
