#include<bits/stdc++.h>
using namespace std;
int knapsack(int n,int we[],int val[],int W)
{
    if(we[n-1]<=W)
    {
        int op1=knapsack(n-1,we,val,W-we[n-1])+val[n-1];
        int op2=knapsack(n-1,we,val,W);
        return max(op1,op2);
    }
    else
    {
        int op2=knapsack(n-1,we,val,W);
        return op2;
    }
}
int main()
{
    int n;
    cin>>n;
    int we[n],val[n];
    for(int i=0;i<n;i++)
    {
        cin>>we[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    int W;
    cin>>W;
    cout<<knapsack(n,we,val,W);


    return 0;
}