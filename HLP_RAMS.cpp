/*18878. Topper Rama Rao

Problem code: HLP_RAMS



Rama Rao is the topper of his branch. One of his friends was jealous of it. So, he poses a question to test Rama Rao and is as follows:

For a given n, find the number of even and odd numbers among the set, { nC0, nC1,... nCn }.

Rama Rao was having hard time solving it. He hopes you can help him.

Input

First line contains t( 1<=t<=105), the number of test cases. Next t lines contain one integer per line, denoting n(0<=n<=1012). 

Output

For each test case, output two space separated integers specifying the number of even numbers and odd numbers respectively.

Example

Input:
2
3
4

Output:
0 4
3 2
Explaination:
 for 3, values are: 1 3 3 1. All are odd. Hence 0 4
 for 4, values are: 1 4 6 4 1. Hence 3 2
 
*****For pascal patterns, read https://docs.google.com/file/d/0B61dMEtLcfLJcWtxQVZONEp4MkE/edit 
 
 
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
		unsigned long long int num=0;
		scanf("%llu",&num);
		
		if(num==0){
			printf("0 1\n");
			continue;
		}				
		unsigned long long temp=num;
		unsigned long long odd=1;
		while(temp){
			odd=odd*((temp & 1)+1);	
			temp=temp>>1;
		}
		printf("%llu %llu\n",num+1-odd,odd);
	}
	   
       return 0;
}
