#include<bits/stdc++.h>
 
#define ll long long
#define endl "\n"
#define mod 1000000007
using namespace std;
#define mp make_pair
//#define ld double
map<ll,vector<ll>>graph;
map<ll,vector<ll>>rgraph;
 
stack<ll>s;
void dfsUtilR(ll visited[],ll x,ll comp[],ll value)
{
    visited[x]=1;
    comp[x]=value;
    for(auto itr=rgraph[x].begin();itr!=rgraph[x].end();itr++)
    {
        if(!visited[(*itr)])
        dfsUtilR(visited,(*itr),comp,value);
    }
}
void dfsUtil(ll visited[],ll x)
{
    visited[x]=1;
    //cout<<x<<endl;
    for(auto itr=graph[x].begin();itr!=graph[x].end();itr++)
    {
        //cout<<x<<" "<<(*itr)<<endl;
        if(!visited[(*itr)])
        dfsUtil(visited,(*itr));
    }
    s.push(x);
}
void dfs(ll n)
{
    ll visited[n];
    memset(visited,0,sizeof(visited));
    for(ll i=0;i<n;i++)
    {
        if(!visited[i])
        {
           // cout<<i<<endl;
        dfsUtil(visited,i);
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
 
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        //cout<<a<<" "<<b<<endl;
        graph[a].push_back(b);
        rgraph[b].push_back(a);
    }
    
    dfs(n);
    ll vis[n];
    memset(vis,0,sizeof(vis));
    //et<ll>ans;
    vector<ll>v;
    ll comp[n];
    ll x=1;
    ll curr=-1;
    while(!s.empty())
    {
        ll a=s.top();
        s.pop();
        v.push_back(a);
        //cout<<a<<" ";
        if(!vis[a])
        {
            //curr=a;
            //ans.insert(a);
            dfsUtilR(vis,a,comp,x);
            x++;
        }
    }
    ll ans[x];
    memset(ans,-1,sizeof(ans));
    for(ll i=0;i<n;i++)
    {
        if(ans[comp[i]]==-1){
        ans[comp[i]]=i;
        }
    }
    for(ll i=0;i<n;i++){
        cout<<ans[comp[i]]<<endl;
    }
    //cout<<endl;
    
    
    return 0;
}  
