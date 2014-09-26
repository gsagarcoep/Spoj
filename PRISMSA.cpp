/*
8371. TRIANGULAR PRISM

Problem code: PRISMSA



In a far away nation, all the liquid substance are stored in a can of shape of a triangular prism. According to belief, this will bring security to their children. As they are very resource conservative people, unlike the earth natives, they want to use as less as possible amount of the raw material to be used for producing the can, which directly depends on the surface area of the can. Mr. Buzz Light Year, of Star Command, is provided with the responsiblity to find the minimal suface area required to prodce a can of a given volume.

Notes

- Consider the material the can is made of to be infinitely thin.

- The base of the prism is equilateral triangle.

- Some formuls:

  a: triangle side's length.

  h: height of the prism.

  Volume, V =  (a2 * sin(60°) * h)/2

  Surface Area, S = a2*sin(60°) + 3*a*h

 - If not provided by a library, use the alue of 2*acos(0) for PI(π).

 - Reminder

    If your result is within 10-2 of the expected result, your solution will be evaluated as correct.

    If your result is between (1-10-2)*expected and (1+10-2)*expected, it will be evaluated as correct.

 

Prism

 

Constriants:

 - Volume will be between 1 and 100000, inclusive.

 - Volume will always be a integer.

Input

Input begins with a integer t, number of test cases. Then follows t lines, each one containing an integer, V, given volume.

Output

For each volume, print the minimum surface area required to produce the can in separate line.

Example

Input:
5
10
5
100
245
5421

Output:
30.3872837089
19.1427891970
141.0452767471
256.3318686611
2020.2796324002

Explanation for test case 1: Volume = 10
 a = 3.41995
 h = 1.97451
 Minimum Surface Area = 30.3872837089

*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
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
	double sqr=sqrt(3);
	while(T--)
	{
       		int v;
       		getInt(v);
       		
       		long double s=0.0;
       		long double a=cbrt(4*v);
       		//printf("%.10Lf\n",a);
       		long double h=4*v/(sqr*a*a);
        	//printf("%.10Lf\n",h);
        	s=(a*a*sqr/2)+(3*a*h);
       		printf("%.10Lf\n",s);	
       	}
	   
       return 0;
}
