/*
20038. Easiest Loop 1

Problem code: SNGLOOP1



Ileana D'Cruz is taking programming classes but she is having problem in understanding while loops. She is working on following set of instructions -
INTEGER I = 0, S, U = 1010;
WHILE (I < U) {
S = (3 * S) + (5 * I);
I = I + 1;
}
Let Sk be the value assigned to INTEGER S for the iteration I = (k + 1) and n, m, p be positive integers such that m > n. Ileana knows the values of n and m and she is trying to find the value of p. She also knows the following equality -
(2 * n + 3) * (p - 1) + (4 / 5) * [(p * Sn) - Sm] = 2 * (m - n)
Input

First line of input is T(total no. of test cases). Each of next T lines contains two integers n and m.

Output

Print unit digit of p for each test case in separated lines.

Example

Input:
1
2 3

Output:
3
Explanation

Let S = 2
S0 = 6
S1 = 23
S2 = 79
S3 = 252
Now solving the equation gives p = 3.
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

void getInt(long long int &x)
{
	register long long int c = getchar_unlocked();
	x=0;
	long long int neg=0;
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
	scanf("%d",&T);

	while(T--)
	{
		int n=0,m=0;
		long long i=0;
		unsigned long long s=2;
		unsigned long long sn=0,sm=0;
		//long long U=10000000000;
		scanf("%llu",&n);
		scanf("%llu",&m);

/*		while(i<m+2){
			s=(3*s)+5*i;
			//printf("%llu %lld\n",s,i);
			if(i==m+1)
				sm=s*0.8;
			if(i==n+1)
				sn=s*0.8;
			i++;
		}
	*/	unsigned long long powm=3,pown=3;
		for( int j=1;j<=m;j++){
			powm*=3;
			if(j==n)
				pown=powm;
		}


		sn=(39*pown/4)-15/4-(5*(n+1)/2)*0.8; 
		sm=(39*powm/4)-15/4-(5*(m+1)/2)*0.8; 

		unsigned long long p=(2*(m-n)+(2*n+3+sm))/(2*n+3+sn);
//		printf("%llu %llu++\n",pown,powm);
		printf("%llu\n",p);
	}

	return 0;

}