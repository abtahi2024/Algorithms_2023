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
    int n;
    cin>>n;
    int val[n],wet[n];
    for(int i=0;i<=n;i++)
    {
        for (int j = 0; j <=n; j++)
        {
            dp[i][j]= -1;
        }
    }
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
        wet[i]=i+1;
    }
    cout<<unbounded_knapsack(n,n,val,wet);
    return 0;
}