/*
Problem code: EGYPIZZA



 

Abotrika is having a party because his team won the african cup so he is inviting his friends to eat some pizza.

Unfortunately,Abotrika's friends can't eat an entire pizza but all of them know exactly how much pizza 

they can eat and insist on getting the exact amount of pizza but Abotrika eats one complete pizza 
and all of them wants his amount of pizza in one slice.


Their requests break down to three different pizza slices-either one quarter or a half or three quarters of pizza.

write a program that will help Abotrika to find out what is the minimal number of pizzas he has to order so that 

everyone gets exact amount of pizza they want.

Input

First line contains an integer N, 0<=N<=10,000 , number of friends.

In each of next N lines there is amount of pizza that each of Abotrika's friends wants to eat,that 

is the fraction 1/4 , 1/2 or 3/4.

Output

In the first and only line you should write the minimal number of pizzas Abotrika has order don't forget to order 

one complete pizza for Abotrika

Example

Input:
3

1/2

3/4

3/4

Output:
4

Input:

5

1/2

3/4

1/2

1/4

1/4

Output:

4
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
	int N=0;
	getInt(N);
	int cnt1=0,cnt2=0,cnt3=0;
	
	for(int i=0;i<N;i++){
		char op;
		int numer,denom;
		scanf("%d%c%d",&numer,&op,&denom);
		
		if(numer==3) cnt1++;
		else if(denom==2) cnt2++;
		else if(denom==4) cnt3++;
//		printf("%d %d %d\n",cnt1,cnt2,cnt3);		
	}
	
	if(cnt1 >= cnt3) cnt3=0;
	else cnt3=cnt3-cnt1;
	
	int rem=cnt2%2;
	
	
	if(rem == 1){
	 	if(cnt3<2) cnt3=0;
	 	else cnt3-=2;
	 	cnt2=cnt2/2 + 1;
	}
	else
		cnt2=cnt2/2;
	
	if(cnt3%4==0)
		cnt3=cnt3/4;
	else if(cnt3>0)
		cnt3=cnt3/4 +1;
	
//	printf("%d %d %d\n",cnt1,cnt2,cnt3);
	printf("%d\n",cnt1+cnt2+cnt3+1);
	return 0;
	
}

