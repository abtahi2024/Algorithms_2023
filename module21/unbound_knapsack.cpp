#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int unbounded_knapsack(int n,int s,int val[],int wet[])
{
    if(n==0||s==0)
    {
        return 0;
    }
    if(dp[n][s]!= -1)
    {
        return dp[n][s];
    }
    if(wet[n-1]<=s)
    {
        int c1=val[n-1]+unbounded_knapsack(n,s-wet[n-1],val,wet);
        int c2=unbounded_knapsack(n-1,s,val,wet);
        return dp[n][s]=max(c1,c2);
    }
    else
    {
        return dp[n][s]=unbounded_knapsack(n-1,s,val,wet);
    }
}
int main()
{
    int n,w;
    cin>>n>>w;
    int val[n],wet[n];
      for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            dp[i][j]= -1;
        }
    }
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    } 
    for(int j=0;j<n;j++)
    {
        cin>>wet[j];
    }
  
    cout<<unbounded_knapsack(n,w,val,wet);


    return 0;
}