#include <bits/stdc++.h>
using namespace std;

void getInt(int &x)
{
	register int c = getchar_unlocked();
	x=0;
	int neg=0;
	for( ;((c<48 || c>57) && c != '-'); c = getchar_unlocked());
	
	if(c == '-')
	{
		neg = 1;
		c = getchar_unlocked();
	}

	for(;c>47 && c<58; c = getchar_unlocked())
	{
		x= (x << 1) + (x << 3) + c - 48;
	}

	if(neg) 
		x=-x;

}

int main()
{
	int T=0;
	getInt(T);
		
	while(T--)
	{
		int n=0,m=0;
		getInt(n);
		getInt(m);
		
		int x=0,y=0;
		getInt(x);
		getInt(y);
		
		int r1=abs(n-x)+abs(1-y);
		int r2=abs(1-x)+abs(m-y);
		int r3=abs(1-x)+abs(1-y);
		int r4=abs(n-x)+abs(m-y);
		
		printf ("%d\n",max(r1,max(r2,max(r3,r4))));

		
	}
	return 0;
	
}

