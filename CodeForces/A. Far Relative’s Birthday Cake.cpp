/*
Door's family is going celebrate Famil Doors's birthday party. They love Famil Door so they are planning to make his birthday cake weird!

The cake is a n × n square consisting of equal squares with side length 1. Each square is either empty or consists of a single chocolate. They bought the cake and randomly started to put the chocolates on the cake. The value of Famil Door's happiness will be equal to the number of pairs of cells with chocolates that are in the same row or in the same column of the cake. Famil Doors's family is wondering what is the amount of happiness of Famil going to be?

Please, note that any pair can be counted no more than once, as two different cells can't share both the same row and the same column.

Input
In the first line of the input, you are given a single integer n (1 ≤ n ≤ 100) — the length of the side of the cake.

Then follow n lines, each containing n characters. Empty cells are denoted with '.', while cells that contain chocolates are denoted by 'C'.

Output
Print the value of Famil Door's happiness, i.e. the number of pairs of chocolate pieces that share the same row or the same column.
*/

#include <iostream>
#include <string>
#include <utility>
#include <array>
using namespace std;
 
int main()
{
    int row[100] = {0}, col[100] = {0}, n;
    char val;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>val;
            if(val == 'C')
            {
                row[i]++;
                col[j]++;
            }
        }
    }
    int Result = 0;
    for(int i=0;i<n;i++)
    {
        Result += (row[i] * (row[i]-1))/2;
        Result += (col[i] * (col[i]-1))/2;
    }
    cout<<Result<<endl;
    return 0;
}