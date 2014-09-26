/*
13404. The Encrypted Password

Problem code: ICPC12C



Encrypting passwords is one of the most important problems nowadays, and you trust only the encryption algorithms which you invented, and you have just made a new encryption algorithm.

Given a password which consists of only lower case English letters, your algorithm encrypts this password using the following 3 steps (in this given order):

Swap two different characters of the given password (you can do this step zero or more times).
Append zero or more lower case English letters at the beginning of the output of step one.
Append zero or more lower case English letters to the end of the output of step two.
And the encrypted password is the output of step three.

You have just finished implementing the above algorithm and applied it on many passwords. Now you want to make sure that there are no bugs in your implementation, so you decided to write another program which validates the output of the encryption program. Given the encrypted password and the original password, your job is to check whether the encrypted password may be the result of applying your algorithm on the original password or not.

Input

Your program will be tested on one or more test cases. The first line of the input will be a single integer T, the number of test cases (1$ \le$T$ \le$100). Followed by the test cases, each test case is on two lines. The first line of each test case contains the encrypted password. The second line of each test case contains the original password. Both the encrypted password and the original password are at least 1 and at most 100,000 lower case English letters (from a' to z'), and the length of the original password is less than or equal the length of the encrypted password.

Output

For each test case, print on a single line one word, YES' (without the quotes) if applying the algorithm on the original password may generate the encrypted password, otherwise print NO' (without the quotes).

Example

Input:
3

abcdef

ecd

cde

ecd

abcdef

fcd

Output:
YES
YES
NO
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		char encr[100001],pwd[100001];
		scanf("%s\n%s",&encr,&pwd);
		int alpha[26]={0};
		int temp[26]={0};
		
		//for(int i=0;i<26;i++)
		//{	alpha[i]=0;}
			
		int size_pwd=strlen(pwd);
		int size_encr=strlen(encr);
		
		for(int j=0;j<size_pwd;j++)
		{
			alpha[pwd[j]-97]++;
			temp[pwd[j]-97]=alpha[pwd[j]-97];
		}
		int s_temp=size_pwd;
		int current=0;
		bool flag=false;
		
		for(int j=0;j<size_encr && current<size_pwd;j++)
		{
			int c=encr[j]-97;
			if(temp[c]==0){
				current=0;
				flag=false;
				for(int l=0;l<26;l++)
					temp[l]=alpha[l];
			}
			else{
				temp[c]--;
				current++;
				if(current==size_pwd)
					flag=true;
			
			}
			
		
		}
		if(flag)
			printf("YES\n");
		else printf("NO\n");
	//	for(int i=0;i<26;i++)
	//		printf("%d %d\n",i,alpha[i]);
		
		
	
	}
	return 0;
}
#include <string>
