#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int pt[N];
int g_s[N];
void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        pt[i] = -1;
        g_s[i] = 1;
    }
}
int dsu_find(int nd)
{
    if(pt[nd]== -1)
    {
        return nd;
    }
    int l=dsu_find(pt[nd]);
    pt[nd]=l;
    return l;
}
void dsu_union_by_size(int n1,int n2)
{
    int l_A=dsu_find(n1);
    int l_B=dsu_find(n2);
    if(g_s[l_A]>g_s[l_B])
    {
        pt[l_B]=l_A;
        g_s[l_A]+=g_s[l_B];
    }
    else
    {
        pt[l_A]=l_B;
        g_s[l_B]+=g_s[l_A];
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    dsu_initialize(n);
    bool cycle=false;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        int l_A=dsu_find(a);
        int l_B=dsu_find(b);
        if(l_A==l_B)
        {
            cycle=true;
        }
        else
        {
            dsu_union_by_size(a,b);
        }
    }
    if(cycle)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
  


    return 0;
}