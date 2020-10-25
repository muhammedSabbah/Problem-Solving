/*
https://codeforces.com/contest/53/problem/A
*/

/*
Autocomplete is a program function that enables inputting the text (in editors, command line shells, browsers etc.) completing the text by its inputted part. Vasya is busy working on a new browser called 'BERowser'. He happens to be working on the autocomplete function in the address line at this very moment. A list consisting of n last visited by the user pages and the inputted part s are known. Your task is to complete s to make it an address of one of the pages from the list. You have to find the lexicographically smallest address having a prefix s.

Input
The first line contains the s line which is the inputted part. The second line contains an integer n (1 ≤ n ≤ 100) which is the number of visited pages. Then follow n lines which are the visited pages, one on each line. All the lines have lengths of from 1 to 100 symbols inclusively and consist of lowercase Latin letters only.

Output
If s is not the beginning of any of n addresses of the visited pages, print s. Otherwise, print the lexicographically minimal address of one of the visited pages starting from s.

The lexicographical order is the order of words in a dictionary. The lexicographical comparison of lines is realized by the '<' operator in the modern programming languages.
*/

 
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <Query.h>
#include <string>
#include <math.h>
 
using namespace std;
 
bool subset(string n1,string n2,int len)
{
	for(int i=0;i<len;i++)
	{
		if(n1[i] != n2[i])
			return false;
	}
	return true;
}
 
string small_min(string n1,string n2)
{
	if(n1.length() < n2.length())
		return n1;
	return n2;
}
int main()
{
	string s,ans;
    cin >> s;
    string ara[110];
    int n;
    cin >> n;
    int f=0;
    for( int i=0 ; i<n ; i++ )
    {
        cin >> ara[i];
        int j;
        for(  j=0 ; j < s.size() ; j++ )
        {
            if(ara[i][j]!=s[j])break;
        }
        if(j==s.size())
        {
            if(f==0)ans=ara[i];
            f=1;
            ans=min(ans,ara[i]);
        }
    }
    if(f==0)cout << s << endl;
    else cout << ans << endl;
    return 0;
}