//Minimum number of insertion and deletion to convert string a to b
#include <bits/stdc++.h>
using namespace std;
int t[101][101];
int LCS(string a, string b, int n, int m)
{
    t[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {

            // if (i == 0)
            // {
            //     t[i][j] = 0;
            // }                     //Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.
            // if(j==0){
            //     t[i][j]=1;
            // }

            // if (i == 0 or j == 0)
            // {
            //     t[i][j] = 0;
            // }

            if (i == 0)
                t[i][j] = j;
            else if (j == 0) //edit distance
                t[i][j] = i;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {

            if (a[i - 1] == b[j - 1])
            {
                t[i][j] = (t[i - 1][j] + t[i - 1][j - 1]);
            } //given .....
            else
                t[i][j] = t[i - 1][j];
        

        if (a[i - 1] == b[j - 1])
        {
            // t[i][j] = (1 + t[i - 1][j - 1]);

            t[i][j] = t[i - 1][j - 1];
        }
        else
        {
            // t[i][j] = max(t[i][j - 1], t[i - 1][j]);

            t[i][j] = 1 + min(t[i - 1][j - 1], min(t[i - 1][j], t[i][j - 1]));
        }
    }
}
return t[n][m];
}
int main()
{
    string x = "heap";
    string y = "pea";
    int n = x.length(), m = y.length();
    int k = LCS(x, y, x.length(), y.length());
    cout << n - k << "   " << m - k << " ";
}