/*
10416. Van Helsings gun

Problem code: VHELSING



In Transylvania, 1753, Dracula has returned from his long sleep, now, of course, someone needs to face it or humanity will be utterly destroyed by the evil bloodthirsty Dracula.

The only one with enough courage to face Dracula is Van Helsing. The only weapon that can defeat him is the silver gun, but Van Helsing does not know the exact amount of powder required for a deadly shot.

The magazine of gunpowder has the form given by intersection of three cylinders of radius r and infinite height, mutually orthogonal, and centered on the axes $X$, $Y$ and $Z$ in $R^3$, as shown below. Your task is to help Van Helsing calculate the exact amount of gunpowder that he will need, ie, the volume of the powder magazine.



Input

The first line of input contains an integer 1 ≤ T ≤ 100 representing the number of test cases. For each of the following 
lines contain an integer 0 ≤ R ≤ 100, as shown above.

Output

For each case print one line containing the amount of gunpowder that Van Helsing needs, with 4 decimal places.

Example

Input:
2
0
1

Output:
0.0000
4.6863

*/

#include<stdio.h>
#include<math.h>
int main()
{
	int t,i=0,r;
	long double cube;
 	long double ans;
	scanf("%d",&t);
	while(i < t)
	{
		i++;
		scanf("%d",&r);
		cube = powl(r,3);
		ans = 8*(2-sqrt(2))*cube;
		printf("%.4Lf\n",ans);
	}
	return 0;
}
