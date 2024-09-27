#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vis[1005];
int lev[1005];
int p[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    lev[src]=0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        // cout << par << endl;
        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                lev[child]=lev[par]+1;
                p[child]=par;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int src,des;
    cin >> src>>des;
    memset(vis, false, sizeof(vis));
    memset(lev,-1, sizeof(lev));
    memset(p,-1, sizeof(p));
    bfs(src);
    int x=des;
    vector<int >pa;
    while(x!=-1)
    {
        pa.push_back(x);
        x=p[x];
    }
    reverse(pa.begin(),pa.end());
    for(int v:pa)
    {
        cout<<v<<" ";
    }
    return 0;
}