#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define M 1000000007
typedef long long ll;
stack<ll>s;
ll visited[100005]={0};
ll disited[100005]={0};
ll dfs(vector<vector<ll>> &adj,ll i)
{
    visited[i]=1;
    for(auto j : adj[i])
    if(!visited[j])
    dfs(adj,j);
    
    s.push(i);
}
void dfs1(vector<vector<ll>> &adj1, ll i)
{
    disited[i]=1;
    for( auto j: adj1[i])
    if(!disited[j])
    dfs1(adj1,j);
}
int main() 
{ 
    ll n,m,a,b;
    cin>>n>>m;
    vector<vector<ll>>adj(n+3);
    vector<vector<ll>>adj1(n+3);
    for(ll i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a].PB(b);
        adj1[b].PB(a);
    }
    for(ll i=1;i<=n;i++)
    if(!visited[i])
    dfs(adj,i);
    ll cnt=0;
    while(!s.empty())
    {
        ll i=s.top();
        s.pop();
        
        if(!disited[i])
        {dfs1(adj1,i);
         cnt++;
        }
       
    }
    cout<<cnt<<"\n";
    
	return 0; 
} 


