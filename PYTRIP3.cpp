/*
19913. Counting Pythagorean Triples

Problem code: PYTRIP3



We define a Pythagorean triple as a set of three positive integers a, b and c which satisfy a2+b2=c2.

Let P(N) denote the number of Pythagorean triples whose hypotenuses (=c) are less than or equal to N (i.e. c≤N).

Your task is to find P(N).

Input

The first line of input contains a positive integer N
Output

Print on a single line the value of P(N).

Constraints

1≤N≤1234567891011
Example

Input1:

5

Output1:

1

 

Input2:

15

Output2:

4

 

Input3:

10000

Output3:

12471

 

Input4:

1000000000000

Output4:

4179478903392

 

Explanation for Input2

There are four Pythagorean triples: {3,4,5}, {5,12,13}, {6,8,10}, {9,12,15}
Information

There are 15 test cases.

The sum of the time limits is 93 sec. (My solution runs in 14.03 sec.)

Solution:-
http://vixra.org/pdf/1310.0211v1.pdf

*/
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() 
{
  	long int counter = 0,n1,nv;
  	long N=0;
	scanf("%ld",&N);	
	double s2 = sqrt(2);
	long double sqr= sqrt (N/(1+(1+s2)*(1+s2)) ) ;
	
	long l1=floor(s2*sqr);
	for(long int i=0;i<=l1;i++ )
	{
		if(i%2==1)
		{
			n1=floor(i/s2)+1;
			nv=floor(( sqrt(2*N-i*i)-i)/2);
			
			for(long j=n1;j<=nv;j++){
				if(i==j) counter++;
			}
		}
	}
	
	l1=floor(sqr);
	for(long int i=0;i<= l1;i++)
	{
		n1=floor(i*s2)+1;
		nv=floor(( sqrt(N-i*i)-i));
			
		for(long j=n1;j<=nv;j++){
			if(j%2==1 && i==j) counter++;
		}
		
	}
	
	printf("%ld\n",counter);
	
	return 0;
}
