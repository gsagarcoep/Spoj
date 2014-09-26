/*
17112. Training Land of Fury

Problem code: NFURY



S.H.I.E.L.D. is recruiting soldiers for the battle with Loki's army. Nick Fury has come to Manhattan to find a large area of land to be used for training purposes. He meets a popular landlord there who is a little foolish by nature. 
He gives square pieces of land with integral sides and charges on the basis of number of pieces of land bought irrespective of how large a piece of land is. Fury has to buy exactly A square units of land. Help Fury by determining the minimum number of pieces that should be bought in order to minimize the expenditure.

Input

The first line of the input contains an integer T denoting the number of test cases. The first line of each test case contains a single integer A denoting the area that nick fury want to buy.

10 ≤ T ≤ 100000
1 ≤ A ≤ 1000
Output

For each test case print the minimum number of pieces that should be bought.

Example

Input:
4
1
2
3
10

Output:
1
2
3
2
Explanation

For the last test case 10 the answer will be 2. 10 can be expressed as sum of minimum two squares that is 10 = 32+12.



*/

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int result[1001]={0};
	result[0]=0;
	result[1]=1;
	
	int sqr[33];
	for(int j=0;j<=32;j++)
	{
		sqr[j]=j*j;	
	}

	for(int i=2;i<1001;i++)
	{
		int k=1;
		while(sqr[k]<=i)
		{
			//printf("1");
			if(result[i]==0)
				result[i]=result[i-1]+1;
			else if(result[i-sqr[k]]+1 < result[i])
				result[i]=result[i-sqr[k]]+1;
			k++;	
		}
	}
	
	int T=0;
	scanf("%d",&T);
	while(T--)
	{
		int n=0;
		scanf("%d",&n);
		printf("%d\n",result[n]);
	}


}
