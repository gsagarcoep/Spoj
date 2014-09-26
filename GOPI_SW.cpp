/*
18857. Gopi and Sandwich

Problem code: GOPI_SW


Gopi is fond of sandwiches. Once his friend asks him to give part of his sandwich. But, Gopi wants to give him as little sandwich as possible. So, he devices a method.

He divides the sandwich into n parts, where each part is a unit fraction( fractions of the form 1/p where p is integer) of the original sandwich. Among all these parts he chooses the smallest part and gives it to his friend. Help Gopi to find the smallest part possible.

Input

First line contains t(1<=t<=105) the number of test cases. The next t lines contain one integer per line denoting n(2<=n<=106) the number of parts the sandwich can be divided.

Output

Output one line per test case containing the denominator of the smallest part. Since, the answer can be very large, print Answer modulo 109 + 7

Example

Input:
1
3

Output:
6
Explaination:
The possible ways of dividing the sandwich into 3 parts are:
 1/3, 1/3, 1/31/3,1/3,1/3
1/6,1/2,1/3
1/4,1/4,1/2
Among these, the second way has the smallest part. Hence the output is 6

*/
#include <iostream>
#include <cstdio>
#include <cstring>
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
 	int N=0;
	getInt(N);
	
	unsigned long long a[1000009];
	a[2]=2;
 	a[3]=6;

 	for(int i=4;i<=1000000;i++)
  		a[i]=a[i-1] *(a[i-1]+1) % 1000000007;


	while(N--)
	{
		int b=0;
		getInt(b);
		
		printf("%llu\n",a[b]);
		
	}
	   
       return 0;
}
