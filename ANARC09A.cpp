/*

Bracket Stabling

No fancy story for this one.
You would be given a string of curly braces i.e either an opening brace '{' or a closing bracket '}'.
 Which may or may not be stable. The definition of a stable string is:
	
	a. A NULL string is stable.
	b. If a string str is stable so would be {str}
	c. If two strings are stable than their concatenation would also be stable
i.e. if str1 and str2 is stable then str1str2 is also stable.
	
Some examples of Stable strings: {{}}, {}{} and {}
Some examples of Un-Stable strings: {{ , }{ and {{}{

You have to tell minimum number of actions needed to make a string stable.
An action is to either replace an opening brace with a closing or vice-versa.

Input Specification:

There would be multiple test cases. Each line would be containing one input string.
Each line/string would be a non-empty string
and would be composed of only opening and closing braces '{' and '}' only.
Any string can contain atmost 2000 braces and would be even in length.
Last line would be containg one or more minus sign(-)
your program should not process beyond that.

Output Specification:

For every input line you have to print the following line :

n.(space)A

where 'n' is the test case no (starting from 1) followed by a dot(.) then a single space 
and the number of actions needed to make input string stable.
Print a new-line character (\n) after each line.


Sample Input:

 

{{}{
{{
{}
----

Sample Output:

 

1. 1
2. 1
3. 0

Timelimit: 1s


*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int t=0,count=0,flag=0;
	char inp[2000];
	do
	{
		t++;
		count=0;
		flag=0;
		gets(inp);
		int len=strlen(inp);
		if(inp[0]=='-')
			break;

		for(int i=0;i<len;i++)
		{
			if(inp[i]=='{')
			{
				count++;
			
			}
			if(inp[i]=='}')
			{
				/*if(flag==1)
				{
					if(count<=0)
					{
						count++;
						flag=0;	
					}
					else 
					{
						count--;
					//	flag=0;
					}
						
				
				}
				else*/
				{
					if(count > 0)
						count--;
					else
					{
						//count++;
						flag++;
					}
					
				}
			}
		}		
		int temp=0;
		
		if(count%2==0 && flag%2==0)
			temp=(count+flag)/2;
			
		else if (count%2==1 && flag%2==1)
			temp=(count+flag)/2 +1;

		cout<<t<<". "<<temp<<endl;
	}while(1);

	return 0;
}
