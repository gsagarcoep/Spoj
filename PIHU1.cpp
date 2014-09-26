/*
18180. Love Story 1

Problem code: PIHU1



 
Rancho is in love with Pihu. So on the Valentine’s Day they decided to spend time together at Assi Ghat, but Rancho, as we all know is very busy with his work, so he failed. It was now Pihu’s turn to go mad with anger. But there’s something which you can do.

Rancho tells Pihu that he is a novice programmer and is generally busy in solving problems at spoj. So Pihu decides to check his algorithmic skills. She puts forward an array of N integers. She gives him a number P and asks if he can find three (strictly three) integers Ai Aj Ak  ( i ≠ j ≠ k ) in the array, whose sum is equal to number P, i.e.

Ai + Aj + Ak  =P.

Now, sooner Rancho answers her query in YES or NO, sooner he gets a kiss.

Input

The first line of input consists of an integer T, number of test cases.

The second line of input consists of an integer N, denoting the size of array.

The third line consists of N integers A1, A2 A3 ……………. AN , separated with space .

The fourth line consists of number P.

CONSTRAINTS

1<=T<=15

3<= N <= 1000

1<= Ai <= 10^9    where 1<= i <=N

1<= P <= 3*10^9

Output

If you find three numbers Ai ,Aj ,Ak  ,  ( i ≠ j ≠ k )  in the array such that Ai + Aj + Ak  =P, print “YES” else print “NO” ( quotes for clarification only). 

Example

Input

1

3

1 2 3

6

Output

YES
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
unsigned long A[1001];
int main()
{
	 unsigned long num,sum,temp;
	 int i,t,n,flage=0,j,k;
	 scanf("%d",&t);
	 while(t--)
	 {
		flage=0;
		scanf("%d",&n);
		  
		for(i=0;i<n;i++)
		 	scanf("%lu",&A[i]);
		scanf("%lu",&num);
		sort(A,A+n);
		
		for(i=0;i<n && flage==0;i++)
			for(j=0,k=n-1;j<k;)
			{
			    sum=num-A[i];
			    temp=A[j]+A[k];
			    
			    if(sum==temp && i!=j && i!=k){
			    	flage=1;
			    	break;
			    }
			    else if(i==j)
			     	j++;
			    else if(i==k)
			    	k--;
			    else if(sum<temp)
			    	k--;
			    else if(sum>temp)
			     	j++;
		   }
		  if(flage)
		   printf("YES\n");
		  else
		   printf("NO\n");
	 }
	 return 0;
}
