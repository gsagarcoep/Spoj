/*
Transform the Expression

Problem code: ONP

Transform the algebraic expression with brackets into RPN form (Reverse Polish Notation). Two-argument operators: +, -, *, /, ^ (priority from the lowest to the highest), brackets ( ). Operands: only letters: a,b,...,z. Assume that there is only one RPN form (no expressions like a*b*c).

Input

t [the number of expressions <= 100]
expression [length <= 400]
[other expressions]
Text grouped in [ ] does not appear in the input file.

Output

The expressions in RPN form, one per line.
Example

Input:
3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))

Output:
abc*+
ab+zx+*
at+bac++cd+^*
*/

#include <iostream>
#include <cstdio>
#define MAX 400
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

struct stack{
	char data[MAX];
	int top;
};

int priority(char c)
{
	if(c=='(' || c==')')
		return 0;
	if(c=='+')
		return 1;
	if(c=='-')
		return 2;
	if(c=='*')
		return 3;
	if(c=='/')
		return 4;
	if(c=='^')
		return 5;		
	return 0;
}

int main()
{
	int T=0;

	getInt(T);	
	stack s;
	s.top=0;
	
	while(T--)
	{
		char token;
		while((token=getchar())!='\n')
		{
			if(isalnum(token))
				printf("%c",token);
			else if(token=='(')
				s.data[s.top++]=token;	
			else if(token==')')
			{
				while(s.data[s.top-1]!='(')
					printf("%c",s.data[--(s.top)]);	
				
				if(s.data[s.top-1]=='(')
					s.top--;	
			}
			else//for operators +,-,*,/,^
			{
				while(s.top!=0 && priority(token)<=priority(s.data[s.top-1]))
					printf("%c",s.data[--(s.top)]);
				s.data[s.top++]=token;	
				//printf("%c\n",token);
			}
//			printf("\n%c\n",s.data[s.top-1]);	
		}

		while( s.top!=0 )
			printf("%c",s.data[--(s.top)]);
		printf("\n");
	}
	
	return 0;
}

