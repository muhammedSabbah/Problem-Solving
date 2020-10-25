/*
https://codeforces.com/contest/158/problem/B
*/

/*
After the lessons n groups of schoolchildren went outside and decided to visit Polycarpus to celebrate his birthday. We know that the i-th group consists of si friends (1 ≤ si ≤ 4), and they want to go to Polycarpus together. They decided to get there by taxi. Each car can carry at most four passengers. What minimum number of cars will the children need if all members of each group should ride in the same taxi (but one taxi can take more than one group)?

Input
The first line contains integer n (1 ≤ n ≤ 105) — the number of groups of schoolchildren. The second line contains a sequence of integers s1, s2, ..., sn (1 ≤ si ≤ 4). The integers are separated by a space, si is the number of children in the i-th group.

Output
Print the single number — the minimum number of taxis necessary to drive all children to Polycarpus.
*/

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
 
int main()
{
	int n,A[5] = {0} ,num,Result = 0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num;
		A[num]++;
	}
	Result += A[4];
	if(A[3] >= A[1])
	{
		Result += A[1];
		A[3] -= A[1];
		A[1] = 0;
		Result += A[3];
	}
	else
	{
		Result += A[3];
		A[1] -=A[3];
		A[3] = 0;
	}
	if(A[2] % 2 != 0)
		A[1] += (A[2] % 2)*2;
	Result += (A[2]*2) / 4;
	Result += A[1] / 4;
	if(A[1] % 4 != 0)
		Result++;
	cout<<Result<<endl;
	return 0;
}