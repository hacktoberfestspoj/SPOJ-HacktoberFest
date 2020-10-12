#include<bits/stdc++.h>
 
#define ll long long
#define endl "\n"
#define mod 1000000007
using namespace std;
#define mp make_pair
ll merge(ll arr[],ll l,ll mid,ll h)
{
    ll temp[100009];
    ll ans=0;
    ll x1=l;ll x2=l,x3=mid+1;
    while(x1<=(mid) && x3<=h){
    if(arr[x1]<=arr[x3])
    {
        temp[x2++]=arr[x1++];
    }
    else
    {
        ans+=(mid-x1+1)*arr[x3];
        temp[x2++]=arr[x3++];
    }
    }
    while(x1<=(mid))
    temp[x2++]=arr[x1++];
    while(x3<=h)
    temp[x2++]=arr[x3++];
    for(ll i=l;i<=h;i++)
    arr[i]=temp[i];
    return ans;
}
ll mergeSort(ll arr[],ll l,ll h)
{
     ll ans=0;
     if(l<h)
     {
         ll mid=(l+h)/2;
         ans+=mergeSort(arr,l,mid);
         ans+=mergeSort(arr,mid+1,h);
         ans+=merge(arr,l,mid,h);
     }
     return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++)
        cin>>arr[n-i-1];
        cout<<mergeSort(arr,0,n-1)<<endl;
    }
    
}  
