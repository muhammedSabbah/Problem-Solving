/*
https://codeforces.com/contest/463/problem/B
*/

/*
Caisa solved the problem with the sugar and now he is on the way back to home.

Caisa is playing a mobile game during his path. There are (n + 1) pylons numbered from 0 to n in this game. The pylon with number 0 has zero height, the pylon with number i (i > 0) has height hi. The goal of the game is to reach n-th pylon, and the only move the player can do is to jump from the current pylon (let's denote its number as k) to the next one (its number will be k + 1). When the player have made such a move, its energy increases by hk - hk + 1 (if this value is negative the player loses energy). The player must have non-negative amount of energy at any moment of the time.

Initially Caisa stand at 0 pylon and has 0 energy. The game provides a special opportunity: one can pay a single dollar and increase the height of anyone pylon by one. Caisa may use that opportunity several times, but he doesn't want to spend too much money. What is the minimal amount of money he must paid to reach the goal of the game?

Input
The first line contains integer n (1 ≤ n ≤ 105). The next line contains n integers h1, h2, ..., hn (1  ≤  hi  ≤  105) representing the heights of the pylons.

Output
Print a single number representing the minimum number of dollars paid by Caisa.
*/

// Muhammed Sabbah
#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
	int n,number;
	long long E = 0,D = 0;
	int pre = 0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>number;
		if(pre - number + E < 0)
		{
			D += number - pre - E;
			E = 0;
		}
		else
		{
			E += pre - number;
		}
		pre = number;
	}
	cout<<D<<endl;
	return 0;
}