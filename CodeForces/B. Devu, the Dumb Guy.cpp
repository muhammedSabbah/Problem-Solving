/*
https://codeforces.com/contest/439/problem/B
*/

/*
Devu is a dumb guy, his learning curve is very slow. You are supposed to teach him n subjects, the ith subject has ci chapters. When you teach him, you are supposed to teach all the chapters of a subject continuously.

Let us say that his initial per chapter learning power of a subject is x hours. In other words he can learn a chapter of a particular subject in x hours.

Well Devu is not complete dumb, there is a good thing about him too. If you teach him a subject, then time required to teach any chapter of the next subject will require exactly 1 hour less than previously required (see the examples to understand it more clearly). Note that his per chapter learning power can not be less than 1 hour.

You can teach him the n subjects in any possible order. Find out minimum amount of time (in hours) Devu will take to understand all the subjects and you will be free to do some enjoying task rather than teaching a dumb guy.

Please be careful that answer might not fit in 32 bit data type.

Input
The first line will contain two space separated integers n, x (1 ≤ n, x ≤ 105). The next line will contain n space separated integers: c1, c2, ..., cn (1 ≤ ci ≤ 105).

Output
Output a single integer representing the answer to the problem.
*/

#include <iostream>
using namespace std;
 
void swap(int &A,int &B)
{
	int T = A;
	A = B;
	B = T;
}
 
void sort(int A[],int n)
{
	for(int i=1;i<=n;i++)
	{
		int index = i;
		for(int t=i+1;t<=n;t++)
		{
			if(A[t] < A[index])
			{
				index = t;
			}
		}
		swap(A[i],A[index]);
	}
}
 
int main()
{
	int n,A[100001]={0},x,num;
	long long R = 0;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>num;
		A[num]++;
	}
	for(int i=1;i<=100000;i++)
	{
		if(A[i] == 0)
			continue;
		for(int t=0;t<A[i];t++)
		{
			R += (long long)x*i;
			if(x > 1)
				x--;
		}
	}
	cout<<R<<endl;
	return 0;
}