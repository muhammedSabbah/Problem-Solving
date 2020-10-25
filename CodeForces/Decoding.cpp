/*
https://codeforces.com/contest/746/problem/B
*/

/*
Polycarp is mad about coding, that is why he writes Sveta encoded messages. He calls the median letter in a word the letter which is in the middle of the word. If the word's length is even, the median letter is the left of the two middle letters. In the following examples, the median letter is highlighted: contest, info. If the word consists of single letter, then according to above definition this letter is the median letter.

Polycarp encodes each word in the following way: he writes down the median letter of the word, then deletes it and repeats the process until there are no letters left. For example, he encodes the word volga as logva.

You are given an encoding s of some word, your task is to decode it.

Input
The first line contains a positive integer n (1 ≤ n ≤ 2000) — the length of the encoded word.

The second line contains the string s of length n consisting of lowercase English letters — the encoding.

Output
Print the word that Polycarp encoded.
*/

#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    int n;
    string word , r = "";
    cin>>n>>word;
    r = word[0];
    for(int i=1;i<n;i++)
    {
        if(i % 2 == 0)
            r += word[i];
        else
            r = word[i] + r;
    }
    if(n % 2 == 0)
    {
        for(int i=n-1;i>=0;i--)
            cout<<r[i];
        cout<<endl;
    }
    else
        cout<<r<<endl;
    return 0;
}