/*

18056. Robert Langdon & Cipher

Problem code: RLCIPHER



Robert and Sienna are running, with Florence police catching up fast. They make a swift left, and found a shallow alley, with a strange looking metal gate at the end. Their only way out : open the gate.The gate has a horizontal bar, with N sections on it. Each section has an input portal, and a number written below that portal. They have to enter correct number at each portal to open the gate.The hint given below the portals :"Take out three, take out four,Below the voids, take no more.Tire your brain, let the blood flow,Plunge it deepest, let it go."Robert figured : For each section, keep subtracting 3 or 4 from the number written in that section, till the number becomes negative. Try to get the smallest number possible using these operations. Then enter the number in that portal.They entered the numbers and quickly got in. Can you guess what they answered?INPUT:First line contains T, number of test cases. Then each test case contains two lines.First line of each test case contains N, the number of sections on the horizontal bar.Second line contains N space separated numbers, containing the numbers on the N sections.OUTPUT:For each testcase, output one line of N space separated number, containing the numbers that must be entered in the portals to get the gate open.EXAMPLE INPUT:230 2 143 2 1 -1EXAMPLE OUTPUT:-4 -2 -3-4 -2 -3 -1CONSTRAINTS:1<=T<=10001<=N<=100000Sum of all N's in a test file will not exceed 10^5Each number in each section is between -10^9 to +10^9 inclusive.
Robert and Sienna are running, with Florence police catching up fast. They make a swift left, and found a shallow alley, with a strange looking metal gate at the end. Their only way out : open the gate.

The gate has a horizontal bar, with N sections on it. Each section has an input portal, and a number written below that portal. They have to enter correct number at each portal to open the gate.

The hint given below the portals :

"Take out three, take out four,

Below the voids, take no more.

Tire your brain, let the blood flow,

Plunge it deepest, let it go."

 

Robert figured : For each section, keep subtracting 3 or 4 from the number written in that section, till the number becomes negative. Try to get the smallest number possible using these operations. Then enter the number in that portal.

They entered the numbers and quickly got in. Can you guess what they answered?

 

INPUT:

First line contains T, number of test cases. Then each test case contains two lines.

First line of each test case contains N, the number of sections on the horizontal bar.

Second line contains N space separated numbers, containing the numbers on the N sections.

 

OUTPUT:

For each testcase, output one line of N space separated number, containing the numbers that must be entered in the portals to get the gate open.

 

EXAMPLE INPUT:

2

3

0 2 1

4

3 2 1 -1

 

EXAMPLE OUTPUT:

-4 -2 -3

-4 -2 -3 -1

 

CONSTRAINTS:

1<=T<=1000

1<=N<=100000

Sum of all N's in a test file will not exceed 105

Each number in each section is between -109 to +109 inclusive.

Solution:

For number greater 6;

n= 3*p + 4*q 

*/

#include<stdio.h>
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
	 getInt(t);
	 int result[7]={-4,-3,-2,-4,-4,-3,-4};
	 
	 while(t--)
	 {
	  	int n;
	  	getInt(n);

		for(int i=0;i<n;i++){
			int temp=0;
			getInt(temp);
			
			if(temp>=6)
				printf("-4 ");
			else if(temp>=0)
				printf("%d ",result[temp]);
			else
				printf("%d ",temp);
				
		}	  	
		printf("\n");
	 }
	 return 0;
}
