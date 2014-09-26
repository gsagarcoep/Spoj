/*

16300. Playing with isosceles triangle

Problem code: TRIISO



Naruto was always alone as a kid. He used to get bored a lot and always tried different things for fun. Once he got facinated by isosceles triangles and developed a game. He will choose a integer value S to be length of the equal sides of the isosceles triangle. Now if it is possible that he can form any triangle which has a third side of even length as well a height of integral value with the third side as base then he becomes happy.
Given S determine if Naruto will be happy.

Input

First line contains T, the number of test cases. (T<=10000)

The next T lines each contain a integer value S<1000000.

Output

For each of T test cases output YES if Naruto will be happy and NO otherwise

Example

Input:
2
5
8
Output:
YES
NO
Explaination:
In 1st case for S=5, the third side can be 6 and height can be 4.
In 2nd case for S=8, no such combination is possible.

Solution:
Pythagorean Triplet
http://mathworld.wolfram.com/PythagoreanTriple.html
*/

#include<stdio.h>
int A[1000001]={0};

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

// i*i+j*j 
void factor()
{
	int i,j,k;
	for(i=1;i<=1000;i++)
	{
	    for(j=i+1;j<=1000;j++)
	   {
	      for(k=1;k*(i*i+j*j)<=1000000;k++)
			A[k*(i*i+j*j)]=-1;
	    }
	}
}

int main()
{
	 
	 int t;
	 getInt(t);
	 factor();
	 while(t--)
	 {
	  	int n;
	  	getInt(n);
	  	
	  	if(A[n]==-1)
	  		printf("Yes\n");
	  	else printf("No\n");
	 }
	 return 0;
}
