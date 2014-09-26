/*16554. Linearian Colony
Problem code: COLONY

Description
Linearians are pecurliar creatures. They are odd in several ways:

    Every Linearian is either red or blue.
    A Linearian colony is a straight line, aligned N-S with the magentic field.
    A colony starts with single red Linearian.
    Every year, each Linearian produces an offspring of the opposite color. After birth, the parent moves just south of the offspring. (Since everyone is born at once, this does make for a lot of jostling, but everyone stays in order.)

So a colony grows as follows:

N ----------- S

Year 0: R
Year 1: BR
Year 2: RBBR
Year 3: BRRBRBBR
Year 4: RBBRBRRBBRRBRBBR

Given a year and a position along the N-S axis, determine what the color of the Linearian there will be.
Input
The first line is the year Y (0 <= Y <= 51). The second line is the position P from north to south, 0-indexed (0 <= P < 2^Y).
Ouput
The color of the Linearian, either red or blue.
Input 	Input

3
6

	

51
123456789012345

Output 	Output

blue

	

red

*/

#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	int line;
	scanf("%d",&line);
	long long int p;
	//string s;
	scanf("%lld",&p);
	
	string odd("BRRBRBBRRBBRBRRB");
	string even("RBBRBRRBBRRBRBBR");
	
	if(line%2==0){
		int x=p%16;
		if(even.at(x)=='B')
			printf("blue\n");
		else printf("red\n");
	
	}
	else{int x=p%16;
		if(odd.at(x)=='B')
			printf("blue\n");
		else printf("red\n");}
}
/*

Morse sequence ;

#include <cstdio>
#include <cmath>
using namespace std;
typedef long long i64;
i64 inv;
inline void solve( i64 len, i64 post, i64 year )
{
// printf("len = %lld, post = %lld, year = %lld, inv = %lld\n",len,post,year,inv);
if( len == 2 )
{
i64 ret;
if( post == 1 )
ret = 1;
else
ret = 0;
if( inv & 1 )
{
if( ret == 1 )
ret = 0;
else
ret = 1;
}
// printf("ret = %lld\n",ret);
puts( !ret ? "red" : "blue" );
return;
}
else if( post > len/2 )
solve( len/2, post - len/2, year - 1 );
else
{
inv++;
solve( len/2 ,post ,year - 1 );
}
}
int main()
{
i64 len, post, year, t, store[52];
store[0] = 1;
for( t = 1; t <= 51; t++ )
store[t] = 2 * store[t-1];
// printf("\n") ;
for( t = 1; t--; )
{
scanf("%lld %lld",&year,&post);
if( !year && !post )
{
printf("red\n");
continue;
}
len = store[year];
post++;
inv = 0;
solve( len, post, year );
}
return 0;
}
*/
