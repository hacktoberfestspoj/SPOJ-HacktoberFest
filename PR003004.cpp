#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define mk make_pair
#define endl "\n"
using namespace std;
ll dp[20][180][2];
void getdigits(ll x,vector<ll> &digit)
{
    while(x)
    {
        digit.pb(x%10);
        x=x/10;
    }
}
ll digitsum(ll idx,ll sum,ll tight,vector<ll> &digit)
{
    if(idx==-1)
        return sum;
    if(dp[idx][sum][tight]!=-1&&tight!=-1)
        return dp[idx][sum][tight];
    ll ret=0;
    ll k=(tight)?digit[idx]:9;
    for(ll i=0;i<=k;i++)
    {
        ll neww=(digit[idx]==i)?tight:0;
        ret+=digitsum(idx-1,sum+i,neww,digit);
    }
    if(!tight)
        dp[idx][sum][tight]=ret;
    return ret;
}
ll range(ll a,ll b)
{
    memset(dp,-1,sizeof(dp));
    vector<ll> digita;
    getdigits(a-1,digita);
    ll ans1=digitsum(digita.size()-1,0,1,digita);
    vector<ll> digitb;
    getdigits(b,digitb);
    ll ans2=digitsum(digitb.size()-1,0,1,digitb);
    return ans2-ans1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<range(a,b)<<endl;
    }
    return 0;
}


