/*
1805. Largest Rectangle in a Histogram
Problem code: HISTOGRA

A histogram is a polygon composed of a sequence of rectangles aligned at a common base line. The rectangles have equal widths but may have different heights. For example, the figure on the left shows the histogram that consists of rectangles with the heights 2, 1, 4, 5, 1, 3, 3, measured in units where 1 is the width of the rectangles:

Usually, histograms are used to represent discrete distributions, e.g., the frequencies of characters in texts. Note that the order of the rectangles, i.e., their heights, is important. Calculate the area of the largest rectangle in a histogram that is aligned at the common base line, too. The figure on the right shows the largest aligned rectangle for the depicted histogram.
Input Specification

The input contains several test cases. Each test case describes a histogram and starts with an integer n, denoting the number of rectangles it is composed of. You may assume that 1<=n<=100000. Then follow n integers h1,...,hn, where 0<=hi<=1000000000. These numbers denote the heights of the rectangles of the histogram in left-to-right order. The width of each rectangle is 1. A zero follows the input for the last test case.
Output Specification

For each test case output on a single line the area of the largest rectangle in the specified histogram. Remember that this rectangle must be aligned at the common base line.
Sample Input

7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
0

Sample Output

8
4000

*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

long long int getMaxArea(long long int hist[], long int n)
{
    stack<int> s;
 
    long long int max_area = 0; // Initalize max area
    long long int tp;  // To store top of stack
    long long int area_with_top; // To store area with top bar as the smallest bar
 
    long int i = 0;
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
 
        else
        {
            tp = s.top();  // store the top index
            s.pop();  // pop the top
 
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
 
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
 
    return max_area;
}
int main()
{
	
	while(1)
	{
		long int n=0;
		scanf("%ld",&n);
		if(n==0) break;
		
		long long int* arr=new long long int[n];
		for(int i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		
		/*stack<int> st;
		long long int max_area=0;

		for(int i=0;i<=n-1;i++)
		{
			if(st.empty() || arr[st.top()]<=arr[i])
				st.push(i);
			else{
				while(!st.empty() && arr[st.top()]>arr[i]){
					int tp=st.top();
					st.pop();
				
					long long int area=(long long )arr[tp]*(i-tp);
				
					if(area > max_area)
						max_area=area;
				}
			}
		}	

		while(!st.empty()){
			int tp=st.top();
			st.pop();
			
					long long int area=(long long )arr[tp]*(n-tp);
				
					if(area > max_area)
						max_area=area;
				}
		*/
			
		cout<<getMaxArea(arr,n)<<endl;
	}	
	
	
	return 0;
}