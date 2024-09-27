#include<bits/stdc++.h>
using namespace std;
int knapsack(int n,int weight[],int vale[],int W)
{
    if(n==0||W==0)
    {
        return 0; 
    }
    if(weight[n-1]<=W)
    {
        int op1=knapsack(n-1,weight,vale,W-weight[n-1])+vale[n-1];
        int op2=knapsack(n-1,weight,vale,W);
        return op1,op2;
    }
    else
    {// ekta option  na niyei dekhte hobe
        int op=knapsack(n-1,weight,vale,W);
        return op;
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
    cout<<knapsack(n,we,val,W)<<endl;


    return 0;
}