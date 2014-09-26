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
	double X=3+2*sqrt(2);
	while(T--)
	{
		int n=0;
		getInt(n);
		
		if(n==0)
			printf ("4\n");
		else {
			double k;
			double temp= ceil(n/X);
			k=floor(temp*X);
			if(k==n)
			   printf("4\n");
			else
			   printf("5\n");
		}
		
	}
	return 0;
	
}

