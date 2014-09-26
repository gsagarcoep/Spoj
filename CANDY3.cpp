/*
Problem code: CANDY3
 
A class went to a school trip. And, as usually, all N kids have got their backpacks stuffed with candy. But soon quarrels started all over the place, as some of the kids had more candies than others. Soon, the teacher realized that he has to step in: "Everybody, listen! Put all the candies you have on this table here!"

Soon, there was quite a large heap of candies on the teacher's table. "Now, I will divide the candies into N equal heaps and everyone will get one of them." announced the teacher.

"Wait, is this really possible?" wondered some of the smarter kids.

Problem specification

You are given the number of candies each child brought. Find out whether the teacher can divide the candies into N exactly equal heaps. (For the purpose of this task, all candies are of the same type.)

Input specification

The first line of the input file contains an integer T specifying the number of test cases. Each test case is preceded by a blank line.

Each test case looks as follows: The first line contains N : the number of children. Each of the next N lines contains the number of candies one child brought.

Output specification

For each of the test cases output a single line with a single word "YES" if the candies can be distributed equally, or "NO" otherwise.

Example

Input:
2

5
5
2
7
3
8

6
7
11
2
7
3
4

Output:
YES
NO
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
	int T=0;
	getInt(T);	
	
	while(T--)
	{
		int n=0;
		getInt(n);
		
		//printf("**%d\n",n);
		long long int sum=0;
		
		for(int i=0;i<n;i++){
			long long int temp;
			scanf("%lld",&temp);
			sum+=temp;
			sum=sum%n;
		//	printf("++%d\n",temp);
		}
		if( sum%n==0)
			printf("YES\n");
		else
			printf("NO\n");
	}		 		
	
	return 0;
}

