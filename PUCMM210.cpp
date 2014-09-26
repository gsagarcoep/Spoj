/*

11560. A Summatory

Problem code: PUCMM210



f(n) is defined as: f(n) = 13+23+33+...+n3, so it is the sum of the cubes of all natural numbers up to n.

In this problem you are about to compute,

f(1) + f(2) + f(3) + ... + f(n)

Input

The first line is an integer T(1 ≤ T ≤ 100,000), denoting the number of test cases. Then, T test cases follow.

For each test case, there is an integer n(1 ≤ n ≤ 1,000,000) written in one line.

Output

For each test case output the result of the summatory function described above.

Since this number could be very large, output the answer modulo 1,000,000,003.

Example

Input:
3
2
10
3

Output:
10
7942
46

Solution:

http://www.trans4mind.com/personal_development/mathematics/series/sumGeneralPowersNaturalNumbers.htm


*/

#include<stdio.h>
long long int A[1000010];
inline void cube()
{
	 long long int i,temp=0;
	 for(i=1;i<=1000000;i++)
	 {
		  temp=(temp + i*i*i)%1000000003;
		  A[i]= (A[i-1] + temp)%1000000003;
	 }
}

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
	 cube();
	 int t,n;
	 getInt(t);
	 while(t--)
	 {
	  	getInt(n);
	  	printf("%lld\n",A[n]);
	 }
	 return 0;
}
