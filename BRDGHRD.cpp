#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
struct dj{
int x;
int y;
};

int  myf(struct dj m,struct dj n)
{
	if(m.x<n.x)
	{
		return 1;
	}
	else if(m.x==n.x && m.y<n.y) {
		return 1;
	}
	else return 0;
}
int main()
{
	long int n;
	int t;
	long L[100005],len;
	struct dj a[100005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i].x);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i].y);

		sort(a,a+n,myf);

		L[0]=1;
		len=1;
		for(int i=1;i<n;i++)
		{
			L[i]=1;
			for(int j=0;j<i;j++)
			{
				if((a[i].y>=a[j].y)&&(L[i]<L[j]+1))
					L[i]=L[j]+1;
			}
		if(len<L[i])
			len=L[i];
		}
		printf("%ld\n",len);
	}
	return 0;
}






