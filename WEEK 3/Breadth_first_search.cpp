#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define M 1000000007
typedef long long ll;
ll visited[100009]={0};
void bfs(vector<vector<ll>>&adj,ll u,ll v)
{
    ll level[100009]={0},k;
    visited[u]=1;
    queue<ll>q;
    q.push(u);
    while(!q.empty())
    {   
        k=q.front();
        q.pop();
        for( auto i : adj[k])
        {
            if(!visited[i])
            {
            visited[i] = 1;
            q.push(i);
            level[i] = level[k] + 1;
            
            }
        }
        
    }
     if(visited[v]==0) cout<<-1;
     else  cout<<level[v];

}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll m,n;
    cin>>n>>m;
    ll a,b,u,v;
    vector<vector<ll>>adj(n+4);
    for(ll i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    cin>>u>>v;
    bfs(adj,u,v);
    // if(bfs(adj,u,v))
    // cout<<bfs(adj,u,v);
    // else
    // cout<<-1;
    
    
    return 0;
}
