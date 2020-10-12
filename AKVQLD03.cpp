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
    if(pow(2,c)==f)
    return pow(2,c)-1;
    else
    return pow(2,c+1)-1;
}
void createSegTree(ll arr[],ll segtree[],ll l,ll h,ll pos)
{
    if(l==h)
    {
        segtree[pos]=arr[l];
        return;
    }
    ll mid=(l)+(h-l)/2;
    createSegTree(arr,segtree,l,mid,2*pos+1);
    createSegTree(arr,segtree,mid+1,h,2*pos+2);
    segtree[pos]=segtree[pos*2+1]+segtree[pos*2+2];
}
void update(ll arr[],ll segtree[],ll l,ll h,ll i,ll diff,ll pos)
{
   if(i<l || i>h)
   return;
   segtree[pos]+=diff;
   ll mid=l+(h-l)/2;
   if(l!=h)
   {
       update(arr,segtree,l,mid,i,diff,2*pos+1);
       update(arr,segtree,mid+1,h,i,diff,2*pos+2);
   }
}
ll rangequery(ll segtree[],ll ql,ll qh,ll l,ll h,ll pos)
{
    if(h<ql || l>qh)
    return 0;
    else if(l>=ql && h<=qh)
    return segtree[pos];
    else{
        ll mid=l+(h-l)/2;
        return rangequery(segtree,ql,qh,l,mid,pos*2+1)+rangequery(segtree,ql,qh,mid+1,h,pos*2+2);
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;
    cin>>n>>q;
    ll size=findlen(n);
    ll arr[n];
    memset(arr,0,sizeof(arr));
    ll segtree[size];
    memset(segtree,0,sizeof(segtree));
    //createSegTree(arr,segtree,0,n-1,0);
    //for(ll i=0;i<size;i++)
    //cout<<segtree[i]<<" ";
    //cout<<endl;
    while(q--)
    {
        string str;
        ll a,b;
        cin>>str>>a>>b;
        if(str=="find")
        {
            //ll aa=8;
            cout<<rangequery(segtree,a-1,b-1,0,n-1,0)<<endl;
        }
        else
        {
            ll diff=b;
            arr[a-1]+=b;
            update(arr,segtree,0,n-1,a-1,diff,0);
           
        }
    }
    
    return 0;
}  
