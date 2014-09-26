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
	 
	 while(t--)
	 {
	  	int temp;
	  	getInt(temp);

		while(temp % 2==0) 
		   temp=temp/2;
		
		if(temp % 3==0)
		   temp=temp/3;
		if(temp % 5==0)
		   temp=temp/5;
		if(temp % 17==0)
		   temp=temp/17;
		if(temp % 257==0)
		   temp=temp/257;
		if(temp % 65537==0)
		   temp=temp/65537;
		if(temp==1)
		   printf("Yes\n");
		else
		   printf("No\n");
	 }
	 return 0;
}
