#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define M 1000000007
typedef long long  ll;
vector<pair<double,pair<ll,ll>>>vec2;
vector<pair<ll,ll>>v;
const ll MAX = 1e4 + 5;
ll id[MAX],size[MAX];
void initialize()
{
    for(ll  i = 0;i < MAX;++i)
        {id[i] = i;
        size[i]=1;}
}
ll parent(ll  v)
{
    if (v == id[v])
        return v;
    return id[v] = parent(id[v]);
}

void union1(ll  x, ll  y)
{
    ll  p = parent(x);
    ll  q = parent(y);
     if (size[p] < size[q])
     swap(p, q);
     id[q] = p;
     size[p] += size[q];
    
}
double kruksal()
{
    ll  x, y;
    double cost, minimumCost = 0;
    for(ll i = 0;i < vec2.size();++i)
    {
        
        x = vec2[i].S.F;
        y = vec2[i].S.S;
        cost = vec2[i].F;
       // cout<<x<<" "<<y<<" "<<cost<<" ";
        
        if(parent(x) != parent(y))
        {   
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;
}
int main() 
{ 
    ll n,a,b;
    cin>>n;
    initialize();
    for(ll i=0;i<n;i++)
    {
        cin>>a>>b;
        v.PB({a,b});
    }
    
    ll x1,y1,x2,y2;
    double k;
    for(ll i=0;i<v.size();i++)
    {
        for(ll j=i+1;j<v.size();j++)
        {
            x1=v[i].F;
            y1=v[i].S;
            x2=v[j].F;
            y2=v[j].S;
            k=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
            vec2.PB({k,{i,j}});
        }
    }
    sort(vec2.begin(),vec2.end());
    double min_cost;
    min_cost=kruksal();
    cout<<fixed<<setprecision(6)<<min_cost;
	return 0; 
} 


