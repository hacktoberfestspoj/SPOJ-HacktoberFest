#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define mk make_pair
#define endl "\n"
using namespace std;
ll recur(ll n,ll k,vector<vector<ll> > &ans)
{
    if(n==0)
        return 0;
    if(k==0)
        return 1;
    if(ans[n][k]!=0)
        return ans[n][k];
    ll s=0;
    for(ll i=0;i<=k;i++)
    {
        if(i<=n-1)
            s+=recur(n-1,k-i,ans);
    }
    ans[n][k]=s;
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<vector<ll> > ans;
        for(ll i=0;i<=200;i++)
        {
            vector<ll> x;
            for(ll j=0;j<=200;j++)
            {
                x.pb(0);
            }
            ans.pb(x);
        }

        cout<<recur(n,k,ans)<<endl;
    }
    return 0;
}
