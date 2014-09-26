/*

4557. Musical Chairs

Problem code: ANARC08H



In the traditional game of Musical Chairs, N + 1 children run around N chairs (placed in a circle) as long as music is playing. The moment the music stops, children run and try to sit on an available chair. The child still standing leaves the game, a chair is removed, and the game continues with N children. The last child to sit is the winner. 

In an attempt to create a similar game on these days' game consoles, you modify the game in the following manner: N Children are seated on N chairs arranged around a circle. The chairs are numbered from 1 to N . Your program pre-selects a positive number D . The program starts going in circles counting the children starting with the first chair. Once the count reaches D , that child leaves the game, removing his/her chair. The program starts counting again, beginning with the next chair in the circle. The last child remaining in the circle is the winner.


For example, consider the game illustrated in the figure above for N = 5 and D = 3 . In the figure, the dot indicates where counting starts and × indicates the child leaving. Starting off, child #3 leaves the game, and counting restarts with child #4. Child #1 is the second child to leave and counting restart with child #2 resulting in child #5 leaving. Child #2 is the last to leave, and child #4 is the winner. Write a program to determine the winning child given both N and D .

Input

Your program will be tested on one or more test cases. Each test case specifies two positive integers N and D on a single line, separated by one or more spaces, where N, D < 1,000,000 . 

The last line of the input file contains two 0's and is not part of the test cases.

Output

For each test case, write the winner using the following format: 

N D W 

Where N and D are as above, is a space character, and W is the winner of that game.

Example

Input:
5 3
7 4
0 0

Output:
5 3 4
7 4 2

*/
#include <iostream>
#include <cstdio>
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
	while(1){
		int N=0,D=0;
		getInt(N);
		getInt(D);
	
		if(N==0 && D==0)
			break;
		
		int r=0;
		int i=1;
		
		while(i<=N){
			r = (r+D) % i;
			i++;
		}	

		printf("%d %d %d\n",N,D,r+1);
	}	
	return 0;
}
