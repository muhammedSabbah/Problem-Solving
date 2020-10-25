/*
https://codeforces.com/contest/6/problem/B
*/

/*
President of Berland has a very vast office-room, where, apart from him, work his subordinates. Each subordinate, as well as President himself, has his own desk of a unique colour. Each desk is rectangular, and its sides are parallel to the office walls. One day President decided to establish an assembly, of which all his deputies will be members. Unfortunately, he does not remember the exact amount of his deputies, but he remembers that the desk of each his deputy is adjacent to his own desk, that is to say, the two desks (President's and each deputy's) have a common side of a positive length.

The office-room plan can be viewed as a matrix with n rows and m columns. Each cell of this matrix is either empty, or contains a part of a desk. An uppercase Latin letter stands for each desk colour. The «period» character («.») stands for an empty cell.

Input
The first line contains two separated by a space integer numbers n, m (1 ≤ n, m ≤ 100) — the length and the width of the office-room, and c character — the President's desk colour. The following n lines contain m characters each — the office-room description. It is guaranteed that the colour of each desk is unique, and each desk represents a continuous subrectangle of the given matrix. All colours are marked by uppercase Latin letters.

Output
Print the only number — the amount of President's deputies.
*/

// Muhammed Sabbah
#include <iostream>
#include <string>
 
using namespace std;
 
 
int main()
{
	int n,m,ch[26] = {0};
	char A[100][100],c;
	cin>>n>>m>>c;
	for(int i=0;i<n;i++)
	{
		for(int t=0;t<m;t++)
			cin>>A[i][t];
	}
 
	for(int i=0;i<n;i++)
	{
		for(int t=0;t<m;t++)
		{
			char x = A[i][t];
			if(x == c && x != '.')
			{
				int index = toascii(A[i-1][t]) - 65;
				if(i-1 < n && i-1 >= 0 && ch[index] == 0 && A[i][t] != A[i-1][t])
				{
					ch[index]++;
				}
				index = toascii(A[i+1][t]) - 65;
				if(i+1 < n && ch[index] == 0 && A[i][t] != A[i+1][t])
				{
					ch[index]++;
				}
				index = toascii(A[i][t-1]) - 65;
				if(t-1 < m && t-1 >= 0 && ch[index] == 0 && A[i][t] != A[i][t-1])
					ch[index]++;
				index = toascii(A[i][t+1]) - 65;
				if(t+1 < m && ch[index] == 0 && A[i][t] != A[i][t+1])
					ch[index]++;
			}
		}
	}
	int l = 0;
	for(int i=0;i<26;i++)
		if(ch[i] == 1)
			l++;
 
	cout<<l<<endl;
	return 0;
}