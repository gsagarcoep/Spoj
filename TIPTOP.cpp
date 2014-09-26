/*
16033. Tip Top Game

Problem code: TIPTOP




Problem Statement:

Alim and sufian are two good friends. They loves to playing game with number recently they discover a new game name “Tip Top”. The rule of the game is they took a number (N) randomly after that they find the all divisors of N. Then they starting to play the game first alim took a divisor, then sufian so on. The person who took the last divisor will win the game.

Every time the game started with alim . Now alim wants to know when he will win.

As you a good programmer your task is to find will alim win or not.    

Input:

Input starts with an integer T ( T ≤ 105 ), denoting the number of test cases. Each case starts with a line containing an integer N ( 1 ≤ N ≤ 1018 ) the number.

Output:

For each case you have to print “Yes” if alim will win otherwise “No” with case number. See the sample input/output for exact formatting.

Sample Input/Output:

Sample Input

Sample Output

 2

 4

 5

 Case 1: Yes

 Case 2: No


*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
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
	int count=0;
	while(T--)
	{
       		count++;
       		unsigned long long int v;
       		scanf("%llu",&v);
       		//printf("%llu",48543*48543);
       		unsigned long long int s=sqrt(v);
       		
       		//printf("--%llu\n",sqr);
       		if(s*s==v || (s-1)*(s-1)==v || (s+1)*(s+1)==v)
       			printf("Case %d: Yes\n",count);	
       		else 
       			printf("Case %d: No\n",count);		
       	}
	   
       return 0;
}
