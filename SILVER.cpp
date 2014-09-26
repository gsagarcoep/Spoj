/*
8785. Cut the Silver Bar

Problem code: SILVER



A creditor wants a daily payment during n days from a poor miner in debt. Since the miner can not pay his daily obligation, he has negotiated with the creditor an alternative way, convenient for both parties, to pay his debt: the miner will give an equivalent of a 1µ (= 0.001mm) long piece of a silver bar as a guarantee towards the debt. The silver bar owned by the poor miner is initially nµ units long.

By the end of n days the miner would not have any more silver to give and the creditor would have received an amount of silver equivalent to that of the silver bar initially owned by the miner. By then, the miner expected to have enough money to pay the debt at the next day so that he would have back all his silver.

With this negotiation in mind, the miner has realized that it was not necessary to cut exactly 1µ silver piece from the bar everyday. For instance, at the third day he could give the creditor a 3µ silver piece, taking back the equivalent of a 2µ silver piece which the creditor should already have.

Since cutting the bar was rather laborious and time consuming, the miner wanted to mini-mize the number of cuts he needed to perform on his silver bar in order to make the daily silver deposits during the n days. Could you help him?

Input

Input consists of several cases, each one deﬁned by a line containing a positive integer number n (representing the length in micras of the silver bar and the number of days of the amortization period). You may assume that 0 < n < 20000. The end of the input is recognized by a line with 0.

Output

For each given case, output one line with a single number: the minimum number of cuts in which to cut a silver bar of length nµ to guarantee the debt during n days.

Example

Input:
1
5
3
0
Output:
0
2
1 

*/
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	
	do{
		int num=0,counter=0,m=1;
		scanf("%d",&num);
	
		if(num == 0)
			return 0;
		counter=0;
		m=1;
			
		while(m < num)
		{	
			m=m*2;
			if(m<=num)
			counter++;
		}	
		
		printf("%d\n",counter);
		
	}while(1);
	
	return 0;
}
