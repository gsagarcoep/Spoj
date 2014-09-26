/*
54. Julka

Problem code: JULKA



Julka surprised her teacher at preschool by solving the following riddle:

Klaudia and Natalia have 10 apples together, but Klaudia has two apples more than Natalia. How many apples does each of he girls have?

Julka said without thinking: Klaudia has 6 apples and Natalia 4 apples. The teacher tried to check if Julka's answer wasn't accidental and repeated the riddle every time increasing the numbers. Every time Julka answered correctly. The surprised teacher wanted to continue questioning Julka, but with big numbers she could't solve the riddle fast enough herself. Help the teacher and write a program which will give her the right answers.

Task

Write a program which

reads from standard input the number of apples the girls have together and how many more apples Klaudia has,
counts the number of apples belonging to Klaudia and the number of apples belonging to Natalia,
writes the outcome to standard output
Input

Ten test cases (given one under another, you have to process all!). Every test case consists of two lines. The first line says how many apples both girls have together. The second line says how many more apples Klaudia has. Both numbers are positive integers. It is known that both girls have no more than 10100 (1 and 100 zeros) apples together. As you can see apples can be very small.

Output

For every test case your program should output two lines. The first line should contain the number of apples belonging to Klaudia. The second line should contain the number of apples belonging to Natalia.

Example

Input:
10
2
[and 9 test cases more]

Output:
6
4
[and 9 test cases more]
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 120
using namespace std;

int main()
{
	int T=10;
	
	while(T--){
		char total[MAX],diff[MAX],temp[MAX],klaudia[MAX],natalia[MAX];
		scanf("%s",&total);	
		scanf("%s",&diff);	
		
		int len1=strlen(total);
		int len2=strlen(diff);
		
    int a, b, c, i, j, k, f;

		
		  for(i=len1-1, j=len2-1, k=c=0; i>=0 || j>=0 || c; i--, j--, k++)
    {
        a = i>=0? total[i]-'0' : 0;
        b = j>=0? diff[j]-'0' : 0;
        temp[k] = (a+b+c)%10 + '0';
        c = (a+b+c)/10;
    }
    temp[k] = 0;

    strcpy(klaudia,"0");
    for(i=k-1, j=a=f=0; i>=0; i--)
    {
        b = (a*10 + temp[i]-'0') / 2;
        a = (a*10 + temp[i]-'0') % 2;
        if(b) f = 1;
        if(f) klaudia[j++] = b+'0';
    }
    if(!j) j++;
    klaudia[j] = 0;

    for(i=len1-1, j=len2-1, k=c=0; i>=0; i--, j--, k++)
    {
        a = total[i]-'0';
        b = j>=0? diff[j]-'0' : 0;
        if(a < b+c)
        {
            temp[k] = (10+a-b-c) + '0';
            c = 1;
        }
        else
        {
            temp[k] = a-b-c + '0';
            c = 0;
        }
    }
    temp[k] = 0;

        strcpy(natalia,"0");
        for(i=k-1, j=a=f=0; i>=0; i--)
        {
                b = (a*10 + temp[i]-'0') / 2;
                a = (a*10 + temp[i]-'0') % 2;
                if(b) f = 1;
                if(f) natalia[j++] = b+'0';
        }
        if(!j) j++;
        natalia[j] = 0;


		printf("%s\n%s\n",klaudia,natalia);	
	}
	
	return 0;
}

