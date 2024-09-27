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
class Edge
{
    public:
    int u,v,w;
    Edge(int u,int v,int w)
    {
        this->u=u;
        this->v=v;
        this->w=w;
    }
};
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int main()
{
    int n,e;
    cin>>n>>e;
    dsu_initialize(n);
    vector<Edge>el;
    while(e--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        el.push_back(Edge(u,v,w));
    }
    sort(el.begin(),el.end(),cmp);
    int tC=0;
    for(Edge ed:el)
    {
       int lU=dsu_find(ed.u);
       int lV=dsu_find(ed.v);
       if(lU==lV)
       {
        continue;
       }
       else
       {
        dsu_union_by_size(ed.u,ed.v);
        tC+=ed.w;
       }
    }
    cout<<tC;

    return 0;
}


