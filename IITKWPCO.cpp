#include <iostream>
#include <cstdio>
#include <algorithm>
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
		//O(n^2)
		
	int T=0;
	getInt(T);
	while(T--){
		int C=0;
		getInt(C );	
	
			
		int* arr=new int [C];
		bool flag[101];
		int count=0;
		//int ncounter=0;
	
		for(int i=0;i<C;i++){
			getInt(arr[i]);
			flag[i]=false;
		}
		
		sort(arr,arr+C);
		for(int i=0;i<C;i++){
			printf("%d--",arr[i]);
				for(int j=i+1;j<C;j++)
				{
					long temp1=arr[j];
					long tem=arr[i];
					if(!flag[j] && 2*temp1==tem){
						flag[i]=true;
						flag[j]=true;
						count++;
						break;
					}

				}	
		}
			
		
		printf("%d\n",count);
	}
	return 0;
}
