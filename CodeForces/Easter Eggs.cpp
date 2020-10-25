/*
https://codeforces.com/contest/78/problem/B
*/

/*
The Easter Rabbit laid n eggs in a circle and is about to paint them.

Each egg should be painted one color out of 7: red, orange, yellow, green, blue, indigo or violet. Also, the following conditions should be satisfied:

Each of the seven colors should be used to paint at least one egg.
Any four eggs lying sequentially should be painted different colors.
Help the Easter Rabbit paint the eggs in the required manner. We know that it is always possible.

Input
The only line contains an integer n — the amount of eggs (7 ≤ n ≤ 100).

Output
Print one line consisting of n characters. The i-th character should describe the color of the i-th egg in the order they lie in the circle. The colors should be represented as follows: "R" stands for red, "O" stands for orange, "Y" stands for yellow, "G" stands for green, "B" stands for blue, "I" stands for indigo, "V" stands for violet.

If there are several answers, print any of them.
*/

#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
	char c[] = {'R','O','Y','G','B','I','V'};
	int n;
	cin>>n;
	int index = 0;
	while(n > 0)
	{
		if(index == 7)
			index = 3;
		cout<<c[index];
		index++;
		n--;
	}
	cout<<"\n";
	return 0;
}