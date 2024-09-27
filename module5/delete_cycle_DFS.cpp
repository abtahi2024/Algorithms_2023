#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool vis[N];
vector <int>adj[N];
int parentArray[N];
bool ans;
void dfs(int pr)
{
    vis[pr]=true;
    for(int c:adj[pr])
    {
        if(vis[c]&&c!=parentArray[pr])
        {
            ans=true;
        }
        if(!vis[c])
        {
            parentArray[c]=pr;
            dfs(c);
        }
    }
}
int main()
{
  int n,e;
  cin>>n>>e;
  while(e--)
  {
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  memset(vis,false,sizeof(vis));
  memset(parentArray,-1,sizeof(parentArray));
  ans=false;
  for(int i=0;i<n;i++)
  {
    if(!vis[i])
    {
        dfs(i);
    }
  }
  if(ans)
  {
    cout<<"Yes";
  }
  else
  {
    cout<<"no";
  }


    return 0;
}