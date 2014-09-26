/*
3638. Word Counting

Problem code: WORDCNT



English	Vietnamese
Nguyen is writing a small software for counting words in a string. He becomes bored after finishing the software very fast. He now wants to find the number of words P in the longest consecutive sequence of words of the same length.

Given a string containing only characters a...z and spaces (ASCII code is 32), a word is defined to be the longest sequence of non-space characters. Your task is to write a program to help Nguyen find the number P.

Input

The input file consists of several data sets. The first line of the input file contains the number of data sets which is a positive integer and is not bigger than 20. The following lines describe the data sets.

For each data test, there is one single line containing the string to count words. There are less than 1000 words in the string. The length of each word does not exceed 20 characters.

Output

For each data test, write in one line the number P Nguyen wants to find.

Example

Sample Input
2
a aa bb cc def ghi
a a a a a bb bb bb bb c c	

Sample Output
3
5
*/

#include <iostream>
#include <cstdio>
#include <string>
#include<sstream>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	string str;
	getline(std::cin,str);	
	while(T--)
	{
		getline(std::cin,str);
		istringstream iss(str, istringstream::in);
		
		int result=0,curr=0,curr_len=0,prev_len=0;
		string word;
		while(iss>>word)
		{
			curr_len=word.length();
			
			if(curr_len==prev_len)
				curr++;
			else
				curr=1;
			if(curr > result)
				result=curr;	
			prev_len=curr_len;
			curr_len=0;	
			
		}
		
		printf("%d\n",result);
	}
	
	return 0;
}
