/*
9861. Hotels Along the Croatian Coast

Problem code: HOTELS



There are N hotels along the beautiful Adriatic coast. Each hotel has its value in Euros.

Sroljo has won M Euros on the lottery. Now he wants to buy a sequence of consecutive hotels, such that the sum of the values of these consecutive hotels is as great as possible - but not greater than M.

You are to calculate this greatest possible total value.

Input

In the first line of the input there are integers N and M (1 ≤ N ≤ 300 000, 1 ≤ M < 231).

In the next line there are N natural numbers less than 106, representing the hotel values in the order they lie along the coast.

Output

Print the required number (it will be greater than 0 in all of the test data).

Example

input
5 12
2 1 3 4 5
output
12
	input
4 9
7 3 5 6
output
8 

*/

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
		
		int C=0,max=0;
		
		scanf("%d%d",&C,&max);	
	
			
		int* arr=new int [C];
		int* sum_arr=new int [C];
		int head=0,tail=0;
		int sumTemp=0,sum_final=0;
	
	
		for(int i=0;i<C;i++)
		{
			scanf("%d",&arr[i]);
			
			if(i==0)
				sum_arr[i]=arr[i];
			else
				sum_arr[i]=sum_arr[i-1]+arr[i];
				
		//	printf(" --%d-- ",sum_arr[i]);
		}	
		
		//bool flag=false;
		
		while(tail<C)
		{
			if(head>0)
			{
				if(head==tail)
					sumTemp=arr[head];
				else
					sumTemp=sum_arr[tail]-sum_arr[head-1];
			}
			else
			{
				sumTemp=sumTemp+arr[tail];
			}	
			//printf("++%d\n",sumTemp);
			if(sumTemp<=max)
			{
				if(sumTemp <= max && sum_final < sumTemp )
					sum_final=sumTemp;
				tail++;
			}
			else
			{
				sumTemp=sumTemp-arr[head];
				//printf("++%d\n",sumTemp);
				head++;
				
				if(head>tail)
					tail++;
			}		
		}
		//printf(" %d*%d \n",head,tail);
		printf("%d\n",sum_final);
	
	return 0;
}
