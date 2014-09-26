/*7804. Defense of a Kingdom

Problem code: DEFKIN



 

Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends theKingdom that is represented by a rectangular grid of cells. The player builds crossbow towers in somecells of the grid. The tower defends all the cells in the same row and the same column. No two towersshare a row or a column.The penalty of the position is the number of cells in the largest undefended rectangle. For example, theposition shown on the picture has penalty 12.[IMAGE]Help Theodore write a program that calculates the penalty of the given position.
 

Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a rectangular grid of cells. The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and the same column. No two towers share a row or a column.

 

The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position shown on the picture has penalty 12.

 

This position has a penalty of 12.

 

Help Theodore write a program that calculates the penalty of the given position.

Input

 

The first line of the input file contains the number of test cases.

 

Each test case consists of a line with three integer numbers: w — width of the grid, h — height of the grid and n — number of crossbow towers (1 ≤ w, h ≤ 40 000; 0 ≤ n ≤ min(w, h)).

 

Each of the following n lines contains two integer numbers xi and yi — the coordinates of the cell occupied by a tower (1 ≤ xi ≤ w; 1 ≤ yi ≤ h).

Output

For each test case, output a single integer number — the number of cells in the largest rectangle that is not defended by the towers.


Example

Input:
1
15 8 3
3 8
11 2
8 6

Output:
12 */

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int w,h,n;
		scanf("%d%d%d",&w,&h,&n);
		int* warr=new int[n];
		int* harr=new int[n];
		
		for(int i=0;i<n;i++)
			scanf("%d%d",&warr[i],&harr[i]);
		
		sort(warr,warr+n);
		sort(harr,harr+n);
		for(int i=0;i<n-1;i++){
			printf("%d %d == ",warr[i],harr[i]);
		
		}
		long long int maxh=0,maxw=0;
		for(int i=0;i<n-1;i++){
			if(warr[i+1]-warr[i]>maxw)
				maxw=warr[i+1]-warr[i];
			if(harr[i+1]-harr[i]>maxh)
				maxh=harr[i+1]-harr[i];	
		}
		printf("%lld\n",(maxh-1)*(maxw-1));
	
	}

	return 0;
}
