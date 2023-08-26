#include <bits/stdc++.h>
using namespace std;
    int dp[10][10];


int main(){
    int a [] = {1, 2, 3, 4};
    int count =0 ;
    int size = 4;
    // vector<vector<int>>dp(10);
    // for (int i =0 ;i<10;i++)


    for (int i =0 ;i<10;i++)
        for (int j =  0;j<10;j++)
            dp[i][j] =0;


    for (int i = 0;i<size-1;i++)
    {
        dp[i][i]=0;
    }

    for (int l = 1;l<size;l++)
    {
        for (int i =0;i<=size-3;i++)
        {
            int j = i+l;
            int minval = INT_MAX;
            for(int k  =0;k<=j-1;k++)
            {
                
                int temp = dp[i][k]+dp[k+1][j]+a[i]*a[k+1]*a[j+1];
                minval = min(minval, temp);
            }
            dp[i][j]=minval;
        }
    }
        // for (int i =0 ;i<10;i++)
        // for (int j =  0;j<10;j++)
        //     cout<<dp[0][3]<<" ";

    cout<<dp[0][5];

}