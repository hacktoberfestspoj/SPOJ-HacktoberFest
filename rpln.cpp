#include<bits/stdc++.h>
 
#define ll long long
#define endl "\n"
#define mod 1000000007
using namespace std;
#define mp make_pair
 
ll findlen(ll n)
{
    ll c=0;
    ll f=n;
    while(n!=0)
    {
        n=n/2;
        c++;
    }
    if(pow(2,c-1)==f)
    return pow(2,c)-1;
    else
    return pow(2,c+1)-1;
}
 
ll rangeQuery(ll segtree[],ll l,ll h,ll ql,ll qh,ll pos)
{
    if(l>qh || h<ql)
    return INT_MAX;
    else if(l>=ql && h<=qh)
    {
        return segtree[pos];
    }
    else
    {
        ll mid=(l+h)/2;
        return min(rangeQuery(segtree,l,mid,ql,qh,2*pos+1),rangeQuery(segtree,mid+1,h,ql,qh,2*pos+2));
        
        //segtree[pos]=segtree[2*pos+1]+segtree[2*pos+2];
    }
}
 
void createSegTree(ll arr[],ll segtree[],ll l,ll h,ll pos)
{
    if(l==h)
    {
        segtree[pos]=arr[l];
        return;
    }
    ll mid=(l+h)/2;
    createSegTree(arr,segtree,l,mid,2*pos+1);
    createSegTree(arr,segtree,mid+1,h,2*pos+2);
    segtree[pos]=min(segtree[2*pos+1],segtree[2*pos+2]);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    ll x=1;
    cin>>t;
    while(t--){
    ll n,m;
    cin>>n>>m;
    ll arr[n];
    for(ll i=0;i<n;i++)
    cin>>arr[i];
    ll size=findlen(n);
    ll segtree[size];
    memset(segtree,0,sizeof(segtree));
    createSegTree(arr,segtree,0,n-1,0);
    cout<<"Scenario #"<<x++<<":"<<endl;
    while(m--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<rangeQuery(segtree,0,n-1,a-1,b-1,0)<<endl;
    }
    }
    return 0;
}  
