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

void scan_longint(long long int &x)
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
	
	int t;
	scanint(t);

	while(t--){
		long long int k;
		scan_longint(k);	
		printf("%lld\n",192+(k-1)*250);

		/*long long int num=15;
		int i=0;
		while(i<k){
			while(num++){
				long long int m=num*num*num;
				if(m%1000==888){
					i++;
					printf("%lld----%lld\n",num,m);
					break;
				}
		}

		}*/


	}
	

	return 0;
}
