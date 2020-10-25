/*
Capitalization is writing a word with its first letter as a capital letter. Your task is to capitalize the given word.

Note, that during capitalization all the letters except the first one remains unchanged.

Input
A single line contains a non-empty word. This word consists of lowercase and uppercase English letters. The length of the word will not exceed 103.

Output
Output the given word after capitalization.
*/

/*****************
**
**
**
 
  -----------------             ------------------	         ---------
 |                 |          |                    |		|          |
 | Muhammed Sabbah |          |  Software Engineer |		|   Oddy   |
 |                            |                    |		|          |
  -----------------             ------------------		     ---------
 
**
**
**
******************/
 
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <Query.h>
#include <string>
#include <math.h>
 
using namespace std;
 
int main()
{
	char c[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	string n;
	cin>>n;
	if(toascii(n[0]) < 97)
		cout<<n<<endl;
	else
	{
		int index = toascii(n[0]) - 97;
		n[0] = c[index];
		cout<<n<<endl;
	}
    return 0;
}