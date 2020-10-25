/*
Grigoriy, like the hero of one famous comedy film, found a job as a night security guard at the museum. At first night he received embosser and was to take stock of the whole exposition.

Embosser is a special devise that allows to "print" the text of a plastic tape. Text is printed sequentially, character by character. The device consists of a wheel with a lowercase English letters written in a circle, static pointer to the current letter and a button that print the chosen letter. At one move it's allowed to rotate the alphabetic wheel one step clockwise or counterclockwise. Initially, static pointer points to letter 'a'. Other letters are located as shown on the picture:


After Grigoriy add new item to the base he has to print its name on the plastic tape and attach it to the corresponding exhibit. It's not required to return the wheel to its initial position with pointer on the letter 'a'.

Our hero is afraid that some exhibits may become alive and start to attack him, so he wants to print the names as fast as possible. Help him, for the given string find the minimum number of rotations of the wheel required to print it.

Input
The only line of input contains the name of some exhibit — the non-empty string consisting of no more than 100 characters. It's guaranteed that the string consists of only lowercase English letters.

Output
Print one integer — the minimum number of rotations of the wheel, required to print the name given in the input.
*/


#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <Query.h>
#include <string>
#include <math.h>
#include<cstdio>
using namespace std;
 
void swap(int &a,int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
 
bool stringMatchProblem(string txt,string pattern)
{
	int LP = pattern.length();
	int LT = txt.length();
	bool found = false;
	for(int i=0; i < LT; i++)
	{
		int tmp = 0, length = i + LP, j = i;
		for(; j < length; j++)
		{
			if(pattern[tmp] != txt[j])
				break;
			tmp++;
		}
		if(j == length)
		{
			found = true;
			break;
		}
	}
	return found;
}
 
void SelectionSort(int A[],int N)
{
	for(int i=0;i<N;i++)
	{
		int s = A[i], tmp = i;
		for(int j = i+1; j<N; j++)
		{
			if(A[j] < s)
			{
				s = A[j];
				tmp  = j;
			}
		}
		swap(A[i],A[tmp]);
	}
}
 
void BubbleSort(int A[],int N)
{
	int i = 0;
	while (i < N)
	{
		for(int j=0; j<N-1; j++)
		{
			if(A[j] > A[j+1])
				swap(A[j],A[j+1]);
		}
		N--;
	}
}
 
void InsertionSort(int A[],int N)
{
	for(int i=0;i<N;i++)
	{
		int j = i;
		while(j > 0)
		{
			if(A[j] < A[j-1])
			{
				swap(A[j],A[j-1]); j--;
			}
			else
				break;
		}
	}
}
 
int BinarySearch(int A[],int item,int start,int end)
{
	int mid = (start + end) / 2;
	if(A[mid] == item)
		return mid;
	if(start == end)
		return -1;
	if(item > A[mid])
		BinarySearch(A,item,mid+1,end);
	else
		BinarySearch(A,item,start,mid-1);
}
 
void merge(int A[],int start,int mid,int end)
{
	int s = start, j = mid + 1, k = start, B[1000];
	while(start <= mid && j <= end)
	{
		if(A[start] < A[j])
		{
			B[k] = A[start];
			k++; start++;
		}
		else
		{
			B[k] = A[j];
			k++; j++;
		}
	}
	while(start <= mid)
	{
		B[k] = A[start];
		k++; start++;
	}
	while(j <= end)
	{
		B[k] = A[j];
		k++; j++;
	}
	for(int i=s;i<=end;i++)
	{
		A[i] = B[i];
	}
}
void MergeSort(int A[],int start,int end)
{
	if(start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(A,start,mid);
		MergeSort(A,mid+1,end);
		merge(A,start,mid,end);
	}
}
 
int partition(int A[],int start,int End)
{
	int pivot = A[start];
	int i = start + 1;
	while(i < End)
	{
		while(A[i] <= pivot)
			i++;
		while(A[End] > pivot)
			End--;
		if(i < End)
			swap(A[i],A[End]);
	}
	swap(A[start],A[End]);
	return End;
}
void QuickSort(int A[],int start,int end)
{
	if(start <= end)
	{
		int P = partition(A,start,end);
		QuickSort(A,start,P-1);
		QuickSort(A,P+1,end);
	}
}
 
bool isSafe(int A[][10],int x,int y,int h,int w)
{
	if(x < h && y < w && A[x][y] == 1)
		return true;
	return false;
}
bool maze(int A[][10],int sol[][10],int x,int y,int h,int w)
{
	if(x == h-1 && y == w-1)
	{
		sol[x][y] = 1;
		return true;
	}
	if(isSafe(A,x,y,h,w))
	{
		A[x][y] = 2;
		sol[x][y] = 1;
		if(maze(A,sol,x+1,y,h,w))
			return true;
		if(maze(A,sol,x-1,y,h,w))
			return true;
		if(maze(A,sol,x,y+1,h,w))
			return true;
		if(maze(A,sol,x,y-1,h,w))
			return true;
		sol[x][y] = 0;
		return false;
	}
	else
		return false;
}
 
int pow(int x,int p)
{
	if(p == 0)
		return 1;
	int R = pow(x,p/2);
	if(p % 2 == 0)
		return R * R;
	else
		return R * R * x;
}
 
//DP
//memozation
long long A[1000] = {0};
long long fibb(long long N)
{
	if(N == 0)
	{
		A[0] = 0;
		return 0;
	}
	if(N == 1)
	{
		A[1] = 1;
		return 1;
	}
	if(A[N] != 0)
		return A[N];
	A[N] = fibb(N-1) + fibb(N-2);
	return A[N];
}
 
int RodCute(int Len[],int price[],int max,int N)
{
	if(max == 0 || N == -1)
		return 0;
	if(A[N] != 0)
		return A[N];
	if(max - Len[N] >= 0)
	{
		int R1 = RodCute(Len,price,max-Len[N],N) + price[N];
		int R2 = RodCute(Len,price,max,N-1);
		return A[N] = max(R1,R2);
	}
	RodCute(Len,price,max,N-1);
}
 
int sol[100][4];
int minCost(int R[],int G[],int B[],int Last,int i,int N)
{
	if(i == N)
		return 0;
	int &ret  = sol[i][Last];
	if(ret != -1)
		return ret;
	ret = 1000000;
	if(Last != 0)
		ret = min(ret, minCost(R,G,B,0,i+1,N) + R[i]);
	if(Last != 1)
		ret = min(ret, minCost(R,G,B,1,i+1,N) + G[i]);
	if(Last != 2)
		ret = min(ret, minCost(R,G,B,2,i+1,N) + B[i]);
	return ret;
}
 
long long maxPro(int s,int k)
{
	if(k == 0)
	{
		if(s == 0)
			return 1;
		return 0;
	}
	long long ret = 0;
	for(int i=1;i<=s;i++)
	{
		long long sol = maxPro(s-i, k-1) * i;
		ret = max(ret,sol);
	}
	return ret;
}
int V[100] = {0};
int maxprofit(int A[],int n,int k)
{
	if(V[n] != -1)
		return V[n];
	if(n == -1)
		return 0;
	if(k == 0)
		return A[n];
	int path1 = maxprofit(A,n-1,k-1) + (A[n]*-1);
	int path2 = maxprofit(A,n-1,k) + A[n];
	return V[n] = max(path1,path2);
}
 
string LCS(string str1,string str2,int i1,int i2,int N1,int N2)
{
	if(i1 > N1 || i2 > N2)
		return "";
	if(str1[i1] == str2[i2])
		return str1[i1] + LCS(str1,str2,i1+1,i2+1,N1,N2);
	else
	{
		string s1 = LCS(str1,str2,i1,i2+1,N1,N2);
		string s2 = LCS(str1,str2,i1+1,i2,N1,N2);
		if(s1.length() > s2.length())
			return s1;
		else
			return s2;
	}
}
int LCSLOOP(string str1,string str2,int i1,int i2,int N1,int N2)
{
	int A[10][10];
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			A[i][j] = 0;
	for(int row = 1; row <= N2+1; row++)
	{
		i1 = 0;
		for(int col = 1; col <= N1+1; col++)
		{
			if(str1[i1] == str2[i2])
				A[row][col] = 1 + A[row-1][col-1];
			else
				A[row][col] = max(A[row-1][col], A[row][col-1]);
			i1++;
 
		}
		i2++;
	}
	return A[N2+1][N1+1];
}
 
int knapsack(int weight[],int price[],int maxBag,int N)
{
	if(N == -1 || maxBag == 0)
		return 0;
	if(maxBag - weight[N] >= 0)
	{
		int R1 = knapsack(weight, price, maxBag - weight[N], N-1) + price[N];
		int R2 = knapsack(weight, price, maxBag, N-1);
		return max(R1,R2);
	}
	knapsack(weight, price, maxBag, N-1);
}
int knapsackLoop(int weight[],int price[],int maxBag,int N)
{
	int A[10][10];
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			A[i][j] = 0;
 
	for(int col = 1; col <= N; col++)
	{
		for(int row = 1; row <= maxBag; row++)
		{
			if(row >= weight[col])
			{
				if(price[col] + A[row-weight[col]][col-1] > A[row][col-1])
					A[row][col] = price[col] + A[row-weight[col]][col-1];
				else
					A[row][col] = A[row][col-1];
			}
			else
					A[row][col] = A[row][col-1];
		}
	}
	return A[maxBag][N];
}
 
int CD(int A[],int maxsize,int N)
{
	if(N == -1 || maxsize == 0)
		return 0;
	if(maxsize - A[N] >= 0)
	{
		int R1 = CD(A, maxsize - A[N], N-1) + A[N];
		int R2 = CD(A, maxsize, N-1);
		return max(R1,R2);
	}
	CD(A, maxsize, N-1);
}
int CDLOOP(int w[],int maxsize,int N)
{
	int A[100][100];
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			A[i][j] = 0;
	for(int col = 1; col <= N; col++)
	{
		for(int row = 1; row <= maxsize; row++)
		{
			if(row >= w[col])
			{
				if(w[col] + A[row-w[col]][col-1] > A[row][col-1])
					A[row][col] = w[col] + A[row-w[col]][col-1];
				else
					A[row][col] = A[row][col-1];
			}
			else
				A[row][col] = A[row][col-1];
		}
	}
	return A[maxsize][N];
}
 
int EditDis(string str1,string str2,int N1,int N2)
{
	//N1 = str1.length()   and    N2 = str2.length()
	if(N1 == 0)
		return N2;
	if(N2 == 0)
		return N1;
	if(str1[N1-1] == str2[N2-1])
		return EditDis(str1,str2,N1-1,N2-1);
	else
	{
		int insert = EditDis(str1,str1,N1,N2-1);
		int remove = EditDis(str1,str2,N1-1,N2);
		int replace = EditDis(str1,str2,N1-1,N2-1);
		return 1 + min(insert, min(remove,replace));
	}
}
int EditDisLoop(string str1,string str2,int N1,int N2)
{
	int A[100][100];
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			A[i][j] = 0;
	for(int row = 1; row <= N2; row++)
	{
		for(int col = 1; col <= N1; col++)
		{
			if(str1[col-1] == str2[row-1])
				A[row][col] = A[row-1][col-1];
			else
			{
				int insert = A[row][col-1];
				int remove = A[row-1][col];
				int rep = A[row-1][col-1];
				A[row][col] = 1 + min(insert, min(remove,rep));
			}
		}
	}
	return A[N2][N1];
}
 
int coinChange(int A[],int maxcapa,int N)
{
	if(N == -1)
		return 0;
	if(maxcapa == 0)
		return 1;
	if(maxcapa - A[N] >= 0)
	{
		int R1 = coinChange(A, maxcapa - A[N], N);
		int R2 = coinChange(A, maxcapa, N-1);
		return R1 + R2;
	}
	coinChange(A, maxcapa, N-1);
}
int coinChangeLoop(int A[],int maxcapa,int N)
{
	int sol[100][100];
	for(int i=1; i<= N; i++)
		sol[0][i] = 1;
 
	for(int row = 1; row <= maxcapa; row++)
	{
		for(int col = 1; col <= N; col++)
		{
			int R1 = 0,R2 = 0;
			if(row - A[col] >= 0)
				R1 = sol[row - A[col]][col];
			if(col > 1)
				R2 = sol[row][col-1];
			sol[row][col] = R1 + R2;
		}
	}
	return sol[maxcapa][N-1];
}
 
// Greedy
int tmp[100];
int ASM(int S[],int F[],int N)
{
	tmp[0] = 0;
	int k = 1;
	for(int i=1;i<N;i++)
	{
		if(S[i] >= F[tmp[k-1]])
		{
			tmp[k] = i;
			k++;
		}
	}
	return k;
}
int main()
{
	string n;
	int count = 0;
	cin>>n;
	n = 'a' + n;
	int len = n.length();
	for(int i=0;i<len-1;i++)
	{
		int A1 = toascii(n[i]);
		int A2 = toascii(n[i+1]);
		int mi = min(A1,A2);
		int ma = max(A1,A2);
		int S1 = ma - mi;
		int S2 = (mi + 26) - ma;
		count += min(S1,S2);
	}
	cout<<count<<endl;
    return 0;
}