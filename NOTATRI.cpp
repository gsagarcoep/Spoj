/*
2905. Not a Triangle
Problem code: NOTATRI

You have N (3 ≤ N ≤ 2,000) wooden sticks, which are labeled from 1 to N. The i-th stick has a length of Li (1 ≤ Li ≤ 1,000,000). Your friend has challenged you to a simple game: you will pick three sticks at random, and if your friend can form a triangle with them (degenerate triangles included), he wins; otherwise, you win. You are not sure if your friend is trying to trick you, so you would like to determine your chances of winning by computing the number of ways you could choose three sticks (regardless of order) such that it is impossible to form a triangle with them.
Input

The input file consists of multiple test cases. Each test case starts with the single integer N, followed by a line with the integers L1, ..., LN. The input is terminated with N = 0, which should not be processed.
Output

For each test case, output a single line containing the number of triples.
Example

Input:
3
4 2 10
3
1 2 3
4
5 2 9 6
0

Output:
1
0
2

For the first test case, 4 + 2 < 10, so you will win with the one available triple. For the second case, 1 + 2 is equal to 3; since degenerate triangles are allowed, the answer is 0.


*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int binary_search(int *arr,int size,int sum)
{
	int low=0,high=size-1;
	int mid=(low+high)/2;

	while(1)
	{
		if(mid>=size)
			return 0;
		if(arr[mid]==sum){
			if(mid>2)
				return size-mid-1;
			else return 0;		
		}
		if(arr[mid]>sum){
			if(arr[mid-1]<sum)
				return size-mid+1;
			high =mid-1;
			mid=(low+high)/2;
		}
		else{
			if(arr[mid+1]>sum)
				return size-mid-1;
			low=mid+1;
			mid=(low+high)/2;

		}
	}
	return 0;
}

int binSearch(int *arr, int size, int value) {
	int low = 0, high = size - 1, mid;

	while(low < high) {
		mid = (low + high) / 2;
		if(arr[mid] <= value)
			low = mid + 1;
		else
			high = mid;
	}

	return 	size-low;
}

int main()
{
	
	while(1)
	{
		int n=0;
		scanf("%d",&n);
		if(n==0)	break;
		
		int* arr=new int[n];
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		sort(arr,arr+n);
		int count=0;
		
		for(int i=0;i<n-2;i++)
			for(int j=i+1;j<n-1;j++)
			{
				int temp=0;
				int sum=arr[i]+arr[j];
				//int k=n-1;
			//	cout<<arr[i]<<":::"<<arr[j]<<":::"<<endl;
				if(arr[n-1]>sum)
					temp=binSearch(arr,n,sum);
			//	cout<<"?? "<<temp<<" ?? "<<endl;
				count+=temp;
				//while(arr[k--]>sum) count++;
			}	
		
		printf("%d\n",count);
	}	
	
	
	return 0;
}