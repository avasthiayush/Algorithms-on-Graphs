#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define M 1000000007
typedef long long ll;
stack<ll>s;
ll arr[100005]={0};
ll visited[100005]={0};
ll bfs(vector<vector<ll>>&adj,ll n)
{
    ll source=1;
    visited[source]=1;
    queue<ll>q;
    q.push(source);
    arr[source]=1;
    while(!q.empty())
    {
        ll k=q.front();
        q.pop();
        for(auto i : adj[k])
        {
            if(!visited[i])
            {
                arr[i]=1^arr[k];
                q.push(i);
                visited[i]=1;
            }
            else if(visited[i] && arr[i]==arr[k])
            return 0;
        }
        
    }
    return 1;
}
int main() 
{ 
    ll n,m,a,b;
    cin>>n>>m;
    vector<vector<ll>>adj(n+3);
    for(ll i=0;i<m;i++) 
    {
        cin>>a>>b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    
    cout<<bfs(adj,n);
    
	return 0; 
} 


