/*
400. To and Fro

Problem code: TOANDFRO



Mo and Larry have devised a way of encrypting messages. They first decide secretly on the number of columns and write the message (letters only) down the columns, padding with extra random letters so as to make a rectangular array of letters. For example, if the message is “There’s no place like home on a snowy night” and there are five columns, Mo would write down

t o i o y
h p k n n
e l e a i
r a h s g
e c o n h
s e m o t
n l e w x
Note that Mo includes only letters and writes them all in lower case. In this example, Mo used the character ‘x’ to pad the message out to make a rectangle, although he could have used any letter. Mo then sends the message to Larry by writing the letters in each row, alternating left-to-right and right-to-left. So, the above would be encrypted as

toioynnkpheleaigshareconhtomesnlewx
Your job is to recover for Larry the original message (along with any extra padding letters) from the encrypted one.

Input

There will be multiple input sets. Input for each set will consist of two lines. The first line will contain an integer in the range 2...20 indicating the number of columns used. The next line is a string of up to 200 lower case letters. The last input set is followed by a line containing a single 0, indicating end of input.

Output

Each input set should generate one line of output, giving the original plaintext message, with no spaces.

Example

Input:

5
toioynnkpheleaigshareconhtomesnlewx
3
ttyohhieneesiaabss
0

Output:

theresnoplacelikehomeonasnowynightx
thisistheeasyoneab

*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;
int main()
{
	while(1)
	{
		int T;
		scanf("%d",&T);
		if(T==0)
			break;
			
		string str;
		getline(std::cin,str);	
		getline(std::cin,str);
		int length=str.length();
		int row = length / T;
		
		char** temp=(char**)malloc(row*sizeof(char*));
		
		for(int i=0;i<row;i++)
			temp[i]=(char*)malloc(T*sizeof(char));
		int even=0;
		string result;
		
		for(even=0;even<row;even++)
		{
			if(even%2==0){
				for(int j=0;j<T;j++){
					temp[even][j]=str[even*T+j];
				//	printf("even %c\n",temp[even][j]);
				}
			}
			else{
				int k=0;
				for(int j=T-1;j>=0;j--){
					temp[even][j]=str[even*T+k];
					k++;
				//	printf("%c odd %c\n",str[even*T+k],temp[even][j]);
				}
			}
		}
		for(int i=0;i<T;i++)
		{
			for(int j=0;j<row;j++)
				printf("%c",temp[j][i]);
		}	
		printf("\n");	
	}
	
	return 0;
}
