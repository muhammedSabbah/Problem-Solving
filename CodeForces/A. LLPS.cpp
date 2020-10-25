/*
https://codeforces.com/contest/202/problem/A
*/

/*
This problem's actual name, "Lexicographically Largest Palindromic Subsequence" is too long to fit into the page headline.

You are given string s consisting of lowercase English letters only. Find its lexicographically largest palindromic subsequence.

We'll call a non-empty string s[p1p2... pk] = sp1sp2... spk (1  ≤  p1 < p2 < ... < pk  ≤  |s|) a subsequence of string s = s1s2... s|s|, where |s| is the length of string s. For example, strings "abcb", "b" and "abacaba" are subsequences of string "abacaba".

String x = x1x2... x|x| is lexicographically larger than string y = y1y2... y|y| if either |x| > |y| and x1 = y1, x2 = y2, ..., x|y| = y|y|, or there exists such number r (r < |x|, r < |y|) that x1 = y1, x2 = y2, ..., xr = yr and xr  +  1 > yr  +  1. Characters in the strings are compared according to their ASCII codes. For example, string "ranger" is lexicographically larger than string "racecar" and string "poster" is lexicographically larger than string "post".

String s = s1s2... s|s| is a palindrome if it matches string rev(s) = s|s|s|s| - 1... s1. In other words, a string is a palindrome if it reads the same way from left to right and from right to left. For example, palindromic strings are "racecar", "refer" and "z".

Input
The only input line contains a non-empty string s consisting of lowercase English letters only. Its length does not exceed 10.

Output
Print the lexicographically largest palindromic subsequence of string s.
*/

/*****************
  -----------------
 | Muhammed Sabbah |
  -----------------
******************/
#include <iostream>
#include <string>
using namespace std;
 
 
int main()
{
	string n;
	char ch;
	int length = 0;
	int asc = 0;
	cin>>n;
	int len = n.length();
	for(int i=0;i<len;i++)
	{
		int a = toascii(n[i]);
		if(a > asc)
		{
			ch = n[i];
			length = 1;
			asc = a;
		}
		else if(a == asc)
			length++;
	}
	for(int i=0;i<length;i++)
		cout<<ch;
	cout<<endl;
	return 0;
}