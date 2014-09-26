/*
18245. Maggu and Triangles

Problem code: IITWPC4B



Maggu has a wire of length n. He has to make triangles out of it such that the side lengths of each triangle are integers. He now wants to know the number of distinct (not congruent) triangles that he can create using the wire of length n. Note that he has to use all of the wire in making the triangle.

Input

First line contains T: number of test cases. (1 <= T <= 10^5)
For each test case, there is a single line containging an integer n (n >= 1 && n <= 10^9)

Output

Each test case output a single integer representing the number of triangles he can create.

Example

Input:
3
5
7
9

Output:
1
2
3

Solution:
Alcuin's sequence

http://mathworld.wolfram.com/AlcuinsSequence.html

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
    unsigned long long n;

    getInt(t);

    while(t--)
    {
        scanf("%llu",&n);

        if(n%2==0){
        	unsigned long long k=n*n;
        	k=(k%48 <= 24 ) ? k/48: k/48+1;
        	printf("%llu\n", k);
        }
        else{
        	unsigned long long k=(n+3)*(n+3);
        	k=(k%48 <= 24 ) ? k/48: k/48+1;
        	printf("%llu\n", k);
        }

    }
    return 0;
}
