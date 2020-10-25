/*
https://codeforces.com/contest/16/problem/B
*/

/*
A burglar got into a matches warehouse and wants to steal as many matches as possible. In the warehouse there are m containers, in the i-th container there are ai matchboxes, and each matchbox contains bi matches. All the matchboxes are of the same size. The burglar's rucksack can hold n matchboxes exactly. Your task is to find out the maximum amount of matches that a burglar can carry away. He has no time to rearrange matches in the matchboxes, that's why he just chooses not more than n matchboxes so that the total amount of matches in them is maximal.

Input
The first line of the input contains integer n (1 ≤ n ≤ 2·108) and integer m (1 ≤ m ≤ 20). The i + 1-th line contains a pair of numbers ai and bi (1 ≤ ai ≤ 108, 1 ≤ bi ≤ 10). All the input numbers are integer.

Output
Output the only number — answer to the problem.
*/

#include <iostream>
#include <string>
 
using namespace std;
 
void swap(int &a,int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
 
void sort(int A[],int B[],int n)
{
	for(int i=0;i<n;i++)
	{
		int index = i;
		for(int t=i+1;t<n;t++)
		{
			if(B[t] > B[index])
			{
				index = t;
			}
		}
		swap(B[i],B[index]);
 
		swap(A[i],A[index]);
	}
}
	
int main()
{
	long long n;
	int m,A[20],B[20];
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>A[i]>>B[i];
	}
	sort(A,B,m);
 
	long long sum = 0;
	for(int i=0;i<m;i++)
	{
		if(A[i] > n)
		{
			sum += n*B[i];
			break;
		}
		n-=A[i];
		sum += A[i] * B[i];
	}
	cout<<sum<<endl;
	return 0;
}