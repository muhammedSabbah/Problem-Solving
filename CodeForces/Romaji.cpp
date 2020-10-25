/*
https://codeforces.com/contest/1008/problem/A
*/

/*
Vitya has just started learning Berlanese language. It is known that Berlanese uses the Latin alphabet. Vowel letters are "a", "o", "u", "i", and "e". Other letters are consonant.

In Berlanese, there has to be a vowel after every consonant, but there can be any letter after any vowel. The only exception is a consonant "n"; after this letter, there can be any letter (not only a vowel) or there can be no letter at all. For example, the words "harakiri", "yupie", "man", and "nbo" are Berlanese while the words "horse", "king", "my", and "nz" are not.

Help Vitya find out if a word s is Berlanese.

Input
The first line of the input contains the string s consisting of |s| (1≤|s|≤100) lowercase Latin letters.

Output
Print "YES" (without quotes) if there is a vowel after every consonant except "n", otherwise print "NO".

You can print each letter in any case (upper or lower).
*/

#include <iostream>
#include <string>
 
using namespace std;
 
 
int main()
{
	string n;
	cin>>n;
	int len = n.length();
	for(int i=0;i<len;i++)
	{
		if(n[i] != 'a' && n[i] != 'o' && n[i] != 'u' && n[i] != 'i' && n[i] != 'e' && n[i] != 'n')
		{
			if(i+1 < len)
			{
				if(n[i+1] == 'a' || n[i+1] == 'o' || n[i+1] == 'u' || n[i+1] == 'i' || n[i+1] == 'e')
					continue;
				else
				{
					cout<<"NO"<<endl;
					return 0;
				}
			}
		}
		if(i == len-1)
		{
			if(n[i] != 'a' && n[i] != 'o' && n[i] != 'u' && n[i] != 'i' && n[i] != 'e' && n[i] != 'n')
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
}