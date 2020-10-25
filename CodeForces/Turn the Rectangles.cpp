/*
https://codeforces.com/contest/1008/problem/B
*/

/*
There are n rectangles in a row. You can either turn each rectangle by 90 degrees or leave it as it is. If you turn a rectangle, its width will be height, and its height will be width. Notice that you can turn any number of rectangles, you also can turn all or none of them. You can not change the order of the rectangles.

Find out if there is a way to make the rectangles go in order of non-ascending height. In other words, after all the turns, a height of every rectangle has to be not greater than the height of the previous rectangle (if it is such).

Input
The first line contains a single integer n (1≤n≤105) — the number of rectangles.

Each of the next n lines contains two integers wi and hi (1≤wi,hi≤109) — the width and the height of the i-th rectangle.

Output
Print "YES" (without quotes) if there is a way to make the rectangles go in order of non-ascending height, otherwise print "NO".

You can print each letter in any case (upper or lower).
*/

#include <iostream>
#include <string>
 
using namespace std;
 
 
int main()
{
	int n,a,b;
	cin>>n;
	cin>>a>>b;
	int last = max(a,b);
	for(int i=1;i<n;i++)
	{
		cin>>a>>b;
		int m = min(a,b);
		int m2 = max(a,b);
		if(last >= m2)
			last = m2;
		else if (last >= m)
			last = m;
		else
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}