#include<bits/stdc++.h>
using namespace std;
const int maxN = 1000;
const int maxW = 1000;
int dp[maxN][maxW];
int knapsack(int n,int weight[],int vale[],int W)
{
    if(n==0||W==0)
    {
        return 0; 
    }
    if(dp[n][W]!=-1)
    {
        return dp[n][W];
    }
    if(weight[n-1]<=W)
    {
        int op1=knapsack(n-1,weight,vale,W-weight[n-1])+vale[n-1];
        int op2=knapsack(n-1,weight,vale,W);
        return dp[n][W]=max(op1,op2);
    }
    else
    {// ekta option  na niyei dekhte hobe
        int op=knapsack(n-1,weight,vale,W);
        return dp[n][W]=op;
    }
    
}
int main()
{
    int n;cin>>n;
    int we[n],val[n];
    for(int i=0;i<n;i++)
    {
        cin>>we[i];      
    }
    for(int j=0;j<n;j++)
    {
        cin>>val[j];
    }
    int W;cin>>W;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j]= -1;
        }
    }
    cout<<knapsack(n,we,val,W)<<endl;


    return 0;
}