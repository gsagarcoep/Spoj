/*
10232. Distinct Primes
Problem code: AMR11E

 
Arithmancy is Draco Malfoy's favorite subject, but what spoils it for him is that Hermione Granger is in his class, and she is better than him at it.  Prime numbers are of mystical importance in Arithmancy, and Lucky Numbers even more so. Lucky Numbers are those positive integers that have at least three distinct prime factors; 30 and 42 are the first two. Malfoy's teacher has given them a positive integer n, and has asked them to find the nth lucky number. Malfoy would like to beat Hermione at this exercise, so although he is an evil git, please help him, just this once.  After all, the know-it-all Hermione does need a lesson.
Input (STDIN):
The first line contains the number of test cases T. Each of the next T lines contains one integer n.
Output (STDOUT):
Output T lines, containing the corresponding lucky number for that test case.
Constraints:
1 <= T <= 20
1 <= n <= 1000
Time Limit: 2 s
Memory Limit: 32 MB
Sample Input:
2
1
2
Sample Output:
30
42

 

Arithmancy is Draco Malfoy's favorite subject, but what spoils it for him is that Hermione Granger is in his class, and she is better than him at it.  Prime numbers are of mystical importance in Arithmancy, and Lucky Numbers even more so. Lucky Numbers are those positive integers that have at least three distinct prime factors; 30 and 42 are the first two. Malfoy's teacher has given them a positive integer n, and has asked them to find the nth lucky number. Malfoy would like to beat Hermione at this exercise, so although he is an evil git, please help him, just this once.  After all, the know-it-all Hermione does need a lesson.

 

Input (STDIN):

The first line contains the number of test cases T. Each of the next T lines contains one integer n.

 

Output (STDOUT):

Output T lines, containing the corresponding lucky number for that test case.

 

Constraints:

1 <= T <= 20

1 <= n <= 1000

 

Sample Input:

2

1

2

 

Sample Output:

30

42
*/

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int T;
	int arr[10000]={0};
	
	for(int i=2;i<10000;i++)
	{
		if(arr[i]==0)
		{	for(int j=i+i;j<=10000;j++){
				if(j%i==0)
					arr[j]++;
		
			}
		arr[i]++;}	
	}
	
	/*for(int i=2;i<100;i++)
	{
		cout<<i<<"  "<<arr[i]<<endl;
	}
	*/
	scanf("%d",&T);
	
	while(T--)
	{
		int n=0;
		scanf("%d",&n);
		
		for(int i=30;i<=10000;i++){
			if(arr[i]>=3)n--;
			if(n==0){
				printf("%d\n",i);
				break;
			}
		}
	
	}

	return 0;
}
