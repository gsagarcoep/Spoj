/*
DP**
Be Awesome As Barney Stinson

Problem code: BEHAPPY


Barney Stinson ;) is way too flirty. He has many girlfriends and he wants to keep all of them happy. He has M girlfriends. He bought N gifts for them. Now he knows that some girlfriends need more gifts and some need less. So he decided that he will give atleast Ai gifts and at most Bi gifts to his ith girlfriend. He has to give away all the N gifts. Tell us in how many different ways he can do this.

INPUT:

For each test case, first line contains two integers M and N, then follows M lines each having two integers Ai and Bi (1<=i<=M). Input ends with M and N both equal to 0 and that case should not be processed.

OUTPUT:

For each test case, output the number of different ways in which he can distribute those gifts in a single line.

Example:

Input:

3 5

0 1

1 3

1 4

0 0

 

Output:

6

 

Explanation: He can distribute 5 gifts in his 3 girlfriends in 6 different ways as follows (0 1 4), (0 2 3), (0 3 2), (1 1 3), (1 2 2), (1 3 1).


Constraints: 1<=M<=20, 1<=N<=100, 0<=Ai,Bi,<=100
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
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
	while(1)
	{
		int M=0,N=0;
		getInt(M);
		getInt(N);
		int T=M;
		
		if(M==0 && N==0)
			break;
			
		while(T--)
		{
			int a=0;
			getInt(a);
		
			if(a%2==0)
				printf("Thankyou Shaktiman\n");
			else
				printf("Sorry Shaktiman\n");
		}
	}
	return 0;
	
}

