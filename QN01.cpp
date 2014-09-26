#include <iostream>
#include <cstdio>
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
		//O(n^2)
		int C=0;
		getInt(C );	
	
			
		int* arr=new int [C];
		int tail=0,temp;
		int sumTemp=-1,sum_final=-1;
		//int ncounter=0;
	
		for(int i=0;i<C;i++)
			getInt(arr[i]);
			
		
		//bool flag=false;
		int headFinal,tailFinal;
		while(tail<C)
		{
			sumTemp=arr[tail];
			temp=tail;
			//printf("++%d\n",sumTemp);
			if( sum_final < sumTemp )
			{
				sum_final=sumTemp;
				headFinal=temp;
				tailFinal=tail;
			}

			for(int j=tail+1;j<C;j++)
			{
				sumTemp=sumTemp^arr[j];
				if( sum_final < sumTemp )
				{	
					sum_final=sumTemp;
					headFinal=temp;
					tailFinal=j;
				}

			}

			tail++;
								
		}
		//printf(" %d*%d \n",head,tail);
		printf("%d\n%d %d\n",sum_final,headFinal+1,tailFinal+1);
	
	return 0;
}
