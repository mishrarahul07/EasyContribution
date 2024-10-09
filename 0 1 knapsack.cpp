//https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/0
#include <iostream>
#include<bits/stdc++.h>

using namespace std;


int knapsack(vector<int> wt, vector<int> v, int n, int w, vector<vector<int>> &dp)
{
   for(int i=0; i<=n; i++)
   {
       dp[i][0]=0;
   }
    for(int i=0; i<=w; i++)
   {
       dp[0][i]=0;
   }
   
   
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=w; j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j] =max(v[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
}


int main() {
	//code
	int T;
	cin>>T;
	
	while(T--)
	{
	    int n, w, x;
	    vector<int> wt, v;
	    cin>>n>>w;
	    vector<vector<int>> dp(n+1, vector<int>(w+1));
	    for(int i=0; i<n; i++)
	    {
	        cin>>x;
	        v.push_back(x);
	    }
	    
	    for(int i=0; i<n; i++)
	    {
	        cin>>x;
	        wt.push_back(x);
	    }
	    knapsack(wt, v, n, w, dp);
	    cout<<dp[n][w]<<endl;
	    dp.clear();
	    v.clear();
	    wt.clear();
	}
	return 0;
}
