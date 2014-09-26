/*
Problem code: ABCD



Consider a table with 2 rows and 2N columns (a total of 4N cells). Each cell of the first row is coloured by one of the colours A, B, C, D such that there are no two adjacent cells of the same colour. You have to colour the second row using colours A, B, C, D such that:

• There are exactly N cells of each colour (A, B, C and D) in the table.

• There are no two adjacent cells of the same colour. (Adjacent cells share a vertical or a horizontal side.)

It is guaranteed that the solution, not necessarily unique, will always exist.

Input

[a natural number N ≤ 50000]

[a string of 2N letters from the set {A, B, C, D}, representing the first row of the table]

Output

[a string of 2N letters from the set {A, B, C, D}, representing the second row of the table]

Example

Input

1

CB

Output

AD

 

Input

2

ABAD 

Output

BCDC
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
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
	int N=0;
	
	getInt(N);	
	int N2=2*N;
	char *ip = (char*)malloc(N2*sizeof(char));
	gets(ip);
	
	bool mymap[4];
	mymap[0]=false; 	
	mymap[1]=false; 	
	mymap[2]=false; 	
	mymap[3]=false; 	
	int new_clr ;
	

	for(int iter=0;iter<N2;iter+=2)
	{
		int int_clr1=(ip[iter]-65) % 4;
		int int_clr2=(ip[iter+1]-65) % 4;
		int a[2];
		int b;
		
		mymap[int_clr1]=true;
		mymap[int_clr2]=true;
		
		int prev_clr = int_clr1;
		
		for(int j=0;j<2;j++)
		{
			while((new_clr = (int_clr2+1) %4)==prev_clr || mymap[new_clr]==true)
			{
				int_clr2=new_clr;
				//printf("%d\n%d\n",new_clr,prev_clr);
			}
			a[j]=new_clr+65;
			mymap[new_clr]=true;
		}
		
		if( iter > 0 && b == a[0]){
			int temp=a[0];
			a[0]=a[1];
			a[1]=temp;
		}
		
		b=a[1];
		printf("%c%c",a[0],a[1]);
			
		mymap[0]=false; 	
		mymap[1]=false; 	
		mymap[2]=false; 	
		mymap[3]=false; 	
		
	}
	printf("\n");
	
	//free(ip);
	return 0;
}

