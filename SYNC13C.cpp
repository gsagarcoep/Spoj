/*
17617. WHAT A CO-ACCIDENT

Problem code: SYNC13C



Ramesh and Suresh get a box full of five stars on lottery each. Since both the boxes need not have the same number of chocolates, they decide to play a game. The winner gets to have both the boxes of chocolates. They play alternatively and Suresh starts the game. Given the number of chocolates in both the boxes, let them be c1 and c2, the player takes either c1 or c2 number of chocolates and divide the remaining box of chocolates to two boxes (these two boxes need not have the same number of chocolates). The player who cannot make such a move loses.Given the initial number of chocolates (c1 and c2) find the winner.
Ramesh and Suresh get a box full of five stars on lottery each. Since both the boxes need not have the same number of chocolates, they decide to play a game. The winner gets to have both the boxes of chocolates. They play alternatively and Suresh starts the game.

 

Given the number of chocolates in both the boxes, let them be c1 and c2, the player takes either c1 or c2 number of chocolates and divide the remaining box of chocolates to two boxes (these two boxes need not have the same number of chocolates). The player who cannot make such a move loses.

Given the initial number of chocolates (c1 and c2) find the winner.Assume both the players play optimally.

 

Input

First line of input contains a number T(1<=T<=1000), the number of test cases. Then follows T lines each containing two space separated integers c1 and c2

(1<=c1<=c2<=10000).

Output
For each test case print "Ramesh" or "Suresh" depending on who is the winner.

Example

Input:
2
3 1
4 5

Output:
Ramesh
Suresh



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
 	int T=0;
	getInt(T);
	
	while(T--)
	{
       		int a,b;
       		getInt(a);
       		getInt(b);
       	
       		if(a%2==1 && b%2==1)
          		printf("Ramesh\n");
       else
           printf("Suresh\n");
    	}
	   
       return 0;
}
