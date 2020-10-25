/*
https://codeforces.com/contest/47/problem/B
*/

/*
One day Vasya came across three Berland coins. They didn't have any numbers that's why Vasya didn't understand how their denominations differ. He supposed that if one coin is heavier than the other one, then it should be worth more. Vasya weighed all the three pairs of coins on pan balance scales and told you the results. Find out how the deminations of the coins differ or if Vasya has a mistake in the weighting results. No two coins are equal.

Input
The input data contains the results of all the weighting, one result on each line. It is guaranteed that every coin pair was weighted exactly once. Vasya labelled the coins with letters «A», «B» and «C». Each result is a line that appears as (letter)(> or < sign)(letter). For example, if coin "A" proved lighter than coin "B", the result of the weighting is A<B.

Output
It the results are contradictory, print Impossible. Otherwise, print without spaces the rearrangement of letters «A», «B» and «C» which represent the coins in the increasing order of their weights.
*/

// Muhammed Sabbah
#include <iostream>
#include <string>
#include <map>
 
using namespace std;
 
int main()
{
	string n;
	map<char,int> M;
	M.insert(pair<char,int>('A',0));
	M.insert(pair<char,int>('B',0));
	M.insert(pair<char,int>('C',0));
	for(int i=0;i<3;i++)
	{
		cin>>n;
		if(n[1] == '>')
			M[n[0]]++;
		else
			M[n[2]]++;
	}
	
	if(M['A'] == 1 && M['B'] == 1 && M['C'] == 1)
		cout<<"Impossible"<<endl;
	else
	{
		if(M['A'] == 0)
			cout<<"A";
		else if (M['B'] == 0)
			cout<<"B";
		else
			cout<<"C";
 
		if(M['A'] == 1)
			cout<<"A";
		else if (M['B'] == 1)
			cout<<"B";
		else
			cout<<"C";
 
		if(M['A'] == 2)
			cout<<"A";
		else if (M['B'] == 2)
			cout<<"B";
		else
			cout<<"C";
		cout<<"\n";
	}
	return 0;
}