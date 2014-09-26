/*

10286. DOTA HEROES

Problem code: DOTAA





DOTA HEROES

 

Problem Description:

                Defence Of The Ancients(DOTA) is one of the most addictive online multiplayer games. There are n heroes in our team and our motto is to conquer the opponent’s empire. To safeguard their empire, the opponents had constructed m towers on the path. If one or more heroes get into the sight of a tower, then the tower does D amount of damage to one of those heroes at that instant (i.e. one of the heroes’ health decreases by D). Any hero will die if his health H <=0.  Once a tower attacks one of the heroes at that instant, all of those at that instant get out of its sight. Find whether all of the heroes in our team can reach the opponent’s empire alive.

 

Input Specification:

The first line consists of one integer t representing the number of test cases. For each test case, the first line consists of three integers n, m and D, the number of heroes, number of towers and the amount of Damage respectively. The next n lines consist of an integer representing the health of respective hero.

Output Specification:

Just a word “YES” if we can reach the opponent’s empire alive, else “NO”.

Input Constraints:

1<=t<=500

1<=n<=500

1<=m<=n

1<=D,H<=20000


Sample Input:

3

6 3 400

500

500

500

500

500

500

 

6 5 400

800

800

801

200

200

200

 

6 3 400

401

401

400

200

400

200



Sample Output:

YES

NO 

NO

 

Explanation of test case 1:

One of the possible solutions is 
First, three of the heroes can goes together. One of them receives 400 damage from the first tower and all of them cross it. Then while crossing the next tower, one of the heroes who is at 500 health gets 400 damage and all of them cross it. Then the third hero receives the damage when crossing the last tower. Similarly the other 3 heroes can reach the opponent’s base together without dying.
 
*/

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
	  	int n,m,d,cnt=0;
	  	getInt(n);
	  	getInt(m);
	  	getInt(d);

		//printf("%d %d %d\n",n,m,d);
		for(int i=0;i<n;i++){
			int temp=0;
			getInt(temp);
			
			if(cnt>=m)
				continue;
				
			while((temp-=d)>0)
				cnt++;
				
		}
		
		if(cnt>=m)	  	
			printf("YES\n");
		else
			printf("NO\n");
	 }
	 return 0;
}
