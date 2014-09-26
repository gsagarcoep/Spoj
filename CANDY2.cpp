/*
Problem code: CANDY2

Little Michael loves candies. Most of all, he likes chocolate, strawberry and banana flavored ones. No wonder that he has candy bags everywhere - there are at least four bags on his table, one or two in the pockets of his jeans, and one under his bed (just in case). Each bag contains some candies of all three flavors. Whenever he wants to eat a candy, he finds the nearest bag (which is usually is not very far because he has really A LOT of them) and eats the candy he wants.

Yesterday, he wanted a strawberry one, so he opened one of his bags and... It is almost impossible to describe how great his disappointment was when he found out that there were no strawberry candies left in that bag. To make the matters worse, there were also none in the second bag he found. He was sure that he had lots of strawberry candies left, but he didn't know in which bags they were. Therefore, he decided to reorganize his candies, and keep the candies of the three different flavors in three distinct bags. He brought all his bags into the center of his room and realized, that there are really an awful lot of them.

Michael has N bags full of candies. He knows the number of candies of each flavor in each bag. He wants to put all chocolate ones into one bag, all strawberry ones into another bag and all banana ones into yet another bag. He has to move the candies one-by-one, because he always has to look at it to determine its flavor. Moving one candy from one bag into another takes 1 second. Your task is to select the bag for each flavor, so that the total time required for Michael to move all the candies into their bags would be minimal.

Input file specification

The first line of the input file contains a single integer N - the number of bags (N<=5000). Each of the following N lines consists of three numbers ci, si, bi - the numbers of chocolate, strawberry and banana candies in the i-th bag. The bags are numbered from 0 to N-1 in the order in which they appear in the input.

Output file specification

Output file should contain three lines with the following text:

C[Bag for chocolate candies]
S[Bag for strawberry candies]
B[Bag for banana candies]
The numbers C, S, B have to be such that the total number of the required moves is minimal. If there are more solutions, you may choose any of them.

Example

Input file:
5
10 10 10
40 39 40
10 20 30
30 20 10
1 2 27

Output file:
3
1
2
Note: In this case Michael has to move 200 candies. If the bags for the different flavors were chosen in any other way, he would have to move more than 200 candies.
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
	int n=0;
	getInt(n);	
	int max1[3]={0,0,0};
	int max2[3]={0,0,0};
	int max3[3]={0,0,0};
	int bag1[3],bag2[3],bag3[3];
	//int sum1=0,sum2=0,sum3=0;
	
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		scanf("%d",&a);
		scanf("%d",&b);
		scanf("%d",&c);
		/*getInt(a);
		getInt(b);
		getInt(c);
		sum1+=a;
		sum2+=b;
		sum3+=c;
	*/	
		if(max1[2]<a){
			if(max1[1]<a){
				if(max1[0]<a){
					max1[2]=max1[1];
					max1[1]=max1[0];
					max1[0]=a;bag1[0]=i;
				}
				else{
					max1[2]=max1[1];
					max1[1]=a;bag1[1]=i;
				}
			}
			else{
				max1[2]=a; bag1[2]=i;}
		}
		if(max2[2]<b){
			if(max2[1]<b){
				if(max2[0]<b){
					max2[2]=max2[1];
					max2[1]=max2[0];
					max2[0]=b;bag2[0]=i;
				}
				else{
					max2[2]=max2[1];
					max2[1]=b;bag2[1]=i;
				}
			}
			else{
				max2[2]=b;bag2[2]=i;}
		}
		if(max3[2]<c){
			if(max3[1]<c){
				if(max3[0]<c){
					max3[2]=max3[1];
					max3[1]=max3[0];
					max3[0]=c;bag3[0]=i;
				}
				else{
					max3[2]=max3[1];
					max3[1]=c;bag3[1]=i;
				}
			}
			else{
				max3[2]=c;bag3[2]=i;}
		}
		
	}
	
			int optimal=0;
		int out[3];
//		int sum=sum1+sum2+sum3;
		
		for(int i=0;i<3;i++)	
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++)				 	
				{
					int temp=max1[i]+max2[j]+max3[k];
					if(optimal < temp){
						//printf("%d\n",temp);
						if(bag1[i]!= bag2[j] && bag1[i]!=bag3[k] && bag2[j]!= bag3[k]){
							out[0]=bag1[i];
							out[1]=bag2[j];
							out[2]=bag3[k];
							optimal=temp;
						}
					}
				}	}		 		
		printf("%d\n%d\n%d\n",out[0],out[1],out[2]);

	return 0;
}

