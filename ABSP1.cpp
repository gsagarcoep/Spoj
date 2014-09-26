#include <stdio.h>
#include <iostream>
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
   int t;
   getInt(t);
   while(t--)
   {
       int n,i;
       getInt(n);
       int a[n+9];
       for(i=0;i<n;i++)
           getInt(a[i]);
       long long sum=0;
       for(i=0;i<n/2;i++)
       {
            sum+=((n- 2*i -1)*(a[n-i-1] - a[i]));
       }
       printf("%lld\n",sum);
    }
    return 0;
}

