/*
3442. The last digit

Problem code: LASTDIG



Nestor was doing the work of his math class about three days but he is tired of make operations a lot and he should deliver his task tomorrow. His math’s teacher gives two numbers a and b. The problem consist in find the last digit of the potency of base a and index b. Help Nestor with his problem. You are given two integer numbers: the base a (0 <= a <= 20) and the index b (0 <= b <= 2,147,483,000), a and b both are not 0. You have to find the last digit of a^b.

Input

The first line of input contains an integer t, the number of test cases (t <= 30). t test cases follow. For each test case will appear a and b separated by space.

Output

For each test case output an integer per line representing the result.

Example

Input:
2
3 10
6 2

Output:
9
6
 */


#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main()
{
	unsigned long long int q;
	int t=0,modp=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&modp,&q);
		if(modp==0)
			printf("%d\n",modp);
		else if(q==0)
			printf("1\n");
		else
		{
		long long int p= modp%10;
		int modq= q%4;
		
		while(q--)
			p*=p;
		printf("%lld\n",p%10);
		}
	
	}
	return 0;
}
		/*
		switch(p)
		{
		case 1:
			printf("%d\n",p);
			break;
		case 2:
			if(q%4==1)
				printf("2\n");
			else if(q%4==2)
				printf("4\n");
			else if(q%4==3)
				printf("8\n");
			else if(q%4==0)
				printf("6\n");
			break;
		case 3:
			if(q%2==1)
				printf("3\n");
			else if(q%2==0)
				printf("9\n");
			break;
		case 4:
			if(q%2==1)
				printf("4\n");
			else if(q%2==0)
				printf("6\n");
			break;
		case 5:
			printf("%d\n",p);
			break;
		case 6:
			printf("6\n");
			break;
		case 7:
			if(q%4==1)
				printf("7\n");
			else if(q%4==2)
				printf("9\n");
			else if(q%4==3)
				printf("3\n");
			else if(q%4==0)
				printf("1\n");
			
			break;
		case 8:
			if(q%4==1)
				printf("8\n");
			else if(q%4==2)
				printf("4\n");
			else if(q%4==3)
				printf("2\n");
			else if(q%4==0)
				printf("6\n");
			break;
		case 9:
			if(q%2==1)
				printf("9\n");
			else if(q%2==0)
				printf("1\n");
			break;
		case 0:
			printf("%d\n",p);
			break;
		default:
			break;
		}
	
	}
	return 0;
}*/
