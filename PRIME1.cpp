/*2. Prime Generator
Problem code: PRIME1

Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!
Input

The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.
Output

For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.
Example

Input:
2
1 10
3 5

Output:
2
3
5
7

3
5
*/
#include <iostream>
#include <cstdio>
#include <malloc.h>
using namespace std;

void scanint(long int &x)
{
	register long int c = getchar_unlocked();
	x = 0;
	int neg = 0;
	for(;((c<48 || c>57) && c != '-');c = getchar_unlocked());
	if(c=='-') {neg=1;c=getchar_unlocked();}
	for(;c>47 && c<58;c = getchar_unlocked()) 
	{
		x = (x << 1) + (x << 3) + c - 48;
	}
	if(neg) x=-x;
}

int main ()
{
	const int max=40001;
	int* primes=(int *)calloc(max,sizeof(int)); 
	int* p=(int *)calloc(5000,sizeof(int)); 
	int j=0;
	
	//sieve's method 
	for(long int i=2;i<max;i+=1)
	{
		//printf("%d   %d\n",j,i);
		if(primes[i]==0)
		{
			p[j++]=i;
			primes[i]=1;
		}
		else
		{
			primes[i]=1;
			continue;
		}
		
		//printf("%d   %ld\n",j,i);
		long int num = i*i;
		//printf("%lld\n",num);
		while(num<=max-1)
		{
			primes[num]=1;
			num+=i;
		}
		//printf("%d   %d\n",j,i);
	}
	
	long int t=0;
	scanint(t);
	while(t--)
	{
		long int a=0,b=0;
		scanint(a);
		scanint(b);
		if(a==0 && b==0){
			printf("\n");
			continue;
		}
		
		if(a==1)
			a++;
		
		if(a>b){
			printf("\n");;
			continue;
		}
					
		for(long int i=a;i<=b;i++){
			bool find=false;
			//printf("%ld\n",i);
			for(int k=0;k<j;k++){
				if(i==p[k] || i < p[k]*p[k])
					break;
				else if(i%p[k]==0 ){
					find=true;
					break;
				}
			}
			if(!find)
				printf("%ld\n",i);
			
		}
		printf("\n");
							
	}

	return 0;
}
