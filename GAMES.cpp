/*
12448. HOW MANY GAMES

Problem code: GAMES



Problem Statement:

A player has played unknown number of games. We know the average score of the player (sum of scores in all the games / no. of games). Find the minimum number of games the player should have played to achieve that average.

The player can score any non-negative integer score in a game.

Input:

The first line consists of an integer t, the number of test cases. Each test case consists of a single Rational Number which represents the average score of the player.


Output:

For each test case, find the minimum number of matches the player should have played to achieve that average.

Input Constraints:

1<=t<=1000
1<=avg<=1000000 (maximum 4 digits after the decimal place)

Example:

Sample Input:

3

5

5.5

30.25

 

Sample Output:

1

2

4
*/
#include <stdio.h>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;
long gcd(long a,long b)
{
 return b==0?a:gcd(b,a%b);
}
int main()
{
 int t,count,i,flage;
 scanf("%d",&t);
 while(t--)
 {
  string s;
  cin>>s;
  long number=1,frac;
  count=0;
  flage=0;
  for(i=s.size()-1;i>=0;i--)
  {
   if(s[i]=='.')
   {
    flage=1;
    break;
   }
   else
    count++;
  }
  for(i=0;i<s.size();i++)
  {
   if(s[i]!='.')
   {
    number=number*10 + (s[i]-48);
   }
  }
  frac=1;
  if(flage)
   frac=pow(10,count);
  printf("%ld\n",frac/gcd(number,frac));
 }
 return 0;
}


