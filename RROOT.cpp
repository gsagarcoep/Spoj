/*
18174. REAL ROOTS

Problem code: RROOT



 

Anurag is not so good at probability,infact he tends to avoid any probability questions.Bhavik being his friend knows this and also knows that Anurag is excellent with quadratic equations.In order to help he gives Anurag a quadratic equation of the form x^2+2*b*x+c=0 and asks him to find the probability that the given equation has real roots.To make this question non-trivial he gives Anurag,side of the square centered at origin assuming values of b and c will not go outside that square given.Help Anurag to find the probability?
Anurag is not so good at probability,infact he tends to avoid any probability questions.Bhavik being his friend knows this and also knows that Anurag is excellent with quadratic equations.

In order to help he gives Anurag a quadratic equation of the form x^2+2*b*x+c=0 and asks him to find the probability that the given equation has real roots.

To make this question non-trivial he gives Anurag,side of the square centered at origin assuming values of b and c will not go outside that square given.

Help Anurag to find the probability?

 

Input

First line contains a number of test cases T(<25).Next T lines contain the side of the square S(<=1000000).

Output

Output the required probability in new line for each case upto 6 decimal places.

Example

Input:
1
8

Output:
0.833333

Solution:-

x^2 + 2*b*x + c = 0 , for the real roots of this quadratic equation, delta should be >= 0, which is 4*(b^2 - c) here ,
 or  b*b - c >= 0  which mean if c <= 0 , no need to bother about b since delta will always be positive.
but when c > 0, then we need to check where delta is non - negative.
follow the steps:
b^2 - c  < 0   ( this part we gotta exclude ). 
b^2 < c 
here by, we can conclude that all we have to do is to exclude the area  inclosed by parabola with the upper side of square.

After all the evaluation, we'll get 1 - 1/(3 * sqrt(n/2)) as an answer.

*/
#include<stdio.h>
#include<math.h>

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
    int t;  
    double d;

    getInt(t);

    while(t--)
    {
        scanf("%lf",&d);

        printf("%0.6lf\n", 1 - 1/(3*sqrt(d/2)));

    }
    return 0;
}
