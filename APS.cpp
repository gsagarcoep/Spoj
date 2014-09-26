/*
13753. Amazing Prime Sequence
Problem code: APS

Bablu is very fond of Series and Sequences...

After studying Fibonacci Series in Class IX, he was impressed and he designed his own sequence as follows...

a[0] = a[1] = 0 

For n > 1, a[n] = a[n - 1] + f(n), where f(n) is smallest prime factor of n.

He is also very fond of programming and thus made a small program to find a[n], but since he is in Class IX, he is not very good at programming. So, he asks you for help. Your task is to find a[n] for the above sequence....
Input

Your code will be checked for multiple Test Cases.

First Line of Input contains T (<= 100), the number of Test Cases.

Next T lines contain a single number N. (1 < N < 10^7).
Output

Single line containing a[n] i.e. nth number of the sequence for each test case.
Example

Input:
3

2

3

4

Output:
2

5

7
*/

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int T;
	long long int* arr=new long long int[10000001];
	arr[2]=0;
	for(long long int i=2;i<10000001;i++)
	{
		//printf("%d\n",i);
		if(arr[i]==0)
		{	
			for(int j=i+i;j<10000001;j+=i){
		//		printf("%d\n",j);
				if(arr[j]==0 && j%i==0)
					arr[j]=i;
		
			}
			arr[i]=i+arr[i-1];
		}
		else
			arr[i]=arr[i]+arr[i-1];	
	}
	
	/*for(int i=2;i<100;i++)
	{
		cout<<i<<"  "<<arr[i]<<endl;
	}
	*/
	scanf("%d",&T);
	
	while(T--)
	{
		int n=0;
		scanf("%d",&n);
		
		//for(int i=1;i<=n;i++){
			
		//	arr[i]+=arr[i-1];
		//	printf("--%d--%d--\n",arr[i],arr[i-1]);
		//}
		printf("%lld\n",arr[n]);
	
	}

	return 0;
}
