#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define M 1000000007
typedef long long ll;
vector<ll> path(100009,-1);
ll INF = LLONG_MAX;
ll dij(vector<vector<pair<ll,ll>>> v,ll n,ll source,ll desti)
{
  vector<ll>d(n+1,INF);
  d[source]=0;
  set<pair<ll,ll>>s;
  s.insert({0,source});
  while(!s.empty())
  {
      for( auto i : v[s.begin()->S])
         {
             if(d[i.F]==INF)
             {
                 d[i.F]=s.begin()->F+i.S;
                 s.insert({d[i.F],i.F});
             }
             else if(d[i.F]>s.begin()->F+i.S)
             {
                 s.erase({d[i.F],i.F});
                 d[i.F]=s.begin()->F+i.S;
                 s.insert({d[i.F],i.F});
             }
         }
         s.erase(s.begin());
  }
  if(d[desti]!=INF) cout<<d[desti];
  else cout<<-1;
}
int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,a,b,c,u,v;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>adj(n+3);
    for(ll i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
        cin>>u>>v;
        dij(adj,n,u,v);
        
    return 0;
}
