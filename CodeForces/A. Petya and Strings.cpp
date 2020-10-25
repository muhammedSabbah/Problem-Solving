/*
Little Petya loves presents. His mum bought him two strings of the same size for his birthday. The strings consist of uppercase and lowercase Latin letters. Now Petya wants to compare those two strings lexicographically. The letters' case does not matter, that is an uppercase letter is considered equivalent to the corresponding lowercase letter. Help Petya perform the comparison.

Input
Each of the first two lines contains a bought string. The strings' lengths range from 1 to 100 inclusive. It is guaranteed that the strings are of the same length and also consist of uppercase and lowercase Latin letters.

Output
If the first string is less than the second one, print "-1". If the second string is less than the first one, print "1". If the strings are equal, print "0". Note that the letters' case is not taken into consideration when the strings are compared.
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
 
	string n1,n2;
	cin>>n1>>n2;
	int len = n1.length();
	int R = 0;
	for(int i=0;i<len;i++)
	{
		n1[i] = tolower(n1[i]);
		n2[i] = tolower(n2[i]);
		if(toascii(n1[i]) < toascii(n2[i]))
		{
			R = -1;
			break;
		}
		else if(toascii(n1[i]) > toascii(n2[i]))
		{
			R = 1;
			break;
		}
	}
	cout<<R<<endl;
    return 0;
}