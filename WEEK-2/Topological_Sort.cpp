#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define M 1000000007
typedef long long ll;
ll visited[100007]={0};
vector<ll>x;

ll dfs(vector<vector<ll>>&adj,ll start)
{   visited[start]=1;
    for( ll i: adj[start])
    {
        if(visited[i]==0 )
         dfs(adj,i);
    }
    
    x.push_back(start);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    ll a,b,u,v;
    vector<vector<ll>>adj(n+3);
    
    for(ll i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a].PB(b);
    }
    ll k=0;
    ll arr[n+1]={0};
    for(ll i=1;i<=n;i++)
    {   
        if(visited[i]==0){
          dfs(adj,i);
        }
    }
    for(ll i=x.size()-1;i>=0;i--) cout<<x[i]<<" ";
    return 0;
}
