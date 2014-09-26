/*
10401. Aliens at the train

Problem code: ALIEN



The aliens have arrived to Earth and everything is in harmony, the two races can live together. However, one specific Female Alien does not want to see humans on her way to the university, the alien must use the train as every human does. But she can choose any train station such she doesn’t see more than B humans, however, the Alien wants to go as far as possible with the train. Please, help her in this task

                        INPUT:
You will receive one integer T denoting the number of test cases, then, the next line will contain two integers At Bt where At and Bt is the number of stations in the train (1<=At<=100,000) and the number of people that the alien wants to see as maximum (1<=Bt<=10,000,000), after that, one line containing At integers separated by a single space will denote the number of people the Alien can find in the At-i-th station. (For each station there will be as much 100 people)
                        OUTPUT:
Your output should consist on T pair of numbers denoting the number of people the alien will see and the number of stations she will pass respectively.

SAMPLE:


INPUT:
1
5 100
20 15 30 80 100


OUTPUT
65 3

 

Output note:
The alien takes the train at station 1 (with 20 people) and goes to station 2, then the 3rd station, at this point, she have seen 65 people, if she decides to go to station 4 she will see 145 people… Then she exits the station.

The alien, however, can start at station 2 with 15 people, then continue up to the 4th station, then, she would have seen 125 people, but, as she wants to see the minimum people possible and this number of people exceeds what she wants to see, she decides to choose the way from the 1st to the 3rd station.

Clarification: The alien will be moving always forward (remember, she can choose any station as a start), NEVER backwards, and you should choose the best path that satisfies the output specification.
*/


#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int T;
	
	scanf("%d",&T);
	
	if(T==0)
		return 0;
		
	for(int l=0;l<T;l++)
	{
		int C=0,max=0;
		
		scanf("%d%d",&C,&max);	
	
		if(C==0)
			continue;
			
		int* arr=new int [C];
		long long int* sum_arr=new long long int [C];
		int ncounter=-1,head=0,tail=0;
		long long sumTemp=0,sum_final=0;
		
		for(int i=0;i<C;i++)
		{
			scanf("%d",&arr[i]);
			
			if(i==0)
				sum_arr[i]=arr[i];
			else
				sum_arr[i]=sum_arr[i-1]+arr[i];
		}	
		
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
			
			if(sumTemp<=max)
			{
				if(sumTemp <= max && (ncounter<=(tail-head+1)))
				{
					if(ncounter==(tail-head+1) ){
						if(sum_final>sumTemp)
							sum_final=sumTemp;}
					else 
						sum_final=sumTemp;	
					
					ncounter=tail-head+1;
				}			

				tail++;
			}
			else
			{
				sumTemp=sumTemp-arr[head];
				head++;
				if(head>tail)
					tail++;
			}		
		}
		
		printf("%lld %d\n",sum_final,ncounter);
	}
	return 0;
}
