
#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define mk make_pair
#define endl "\n"
using namespace std;
ll dp[20][180][180][2];
bool isprime[1000];
void primee()
{
    memset(isprime,true,sizeof(isprime));
    isprime[0]=false;
    isprime[1]=false;
    for(ll p=2;p<=1000;p++)
    {
        if(isprime[p]==true)
        {
             for(ll i=p*p;i<=1000;i+=p)
        {
            isprime[i]=false;
        }
        }
        //cout<<isprime[p]<<" ";

    }
  //  cout<<endl;
}
void getdigits(ll x,vector<ll> &digit)
{
    while(x)
    {
        digit.pb(x%10);
        x/=10;
    }

}
ll digitsum(ll idx,ll evensum,ll oddsum,ll tight,vector<ll> &digit)
{
    if(idx==-1)
    {
    //	cout<<evensum<<" . "<<oddsum<<endl;
       ll r=evensum-oddsum;
       if(r>=0&&isprime[r]==true)
       return 1;
       else
       return 0;
    }

    if(dp[idx][evensum][oddsum][tight]!=-1&&tight!=-1)
        return dp[idx][evensum][oddsum][tight];
    ll ret=0;
    ll k=(tight)?digit[idx]:9;
    for(ll i=0;i<=k;i++)
    {

        ll neww=(digit[idx]==i)?tight:0;
        if(idx%2!=0)
            ret+=digitsum(idx-1,evensum+i,oddsum,neww,digit);
        else
            ret+=digitsum(idx-1,evensum,oddsum+i,neww,digit);


    }

    if(!tight)
        dp[idx][evensum][oddsum][tight]=ret;
    return ret;
}
ll range(ll a,ll b)
{
    memset(dp,-1,sizeof(dp));
    vector<ll> digita;
    getdigits(a-1,digita);
   // ll es=0,os=0;
    ll ans1=digitsum(digita.size()-1,0,0,1,digita);
    vector<ll> digitb;
    getdigits(b,digitb);
    // es=0;
    // os=0;
    ll ans2=digitsum(digitb.size()-1,0,0,1,digitb);
    return ans2-ans1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    primee();

    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<range(a,b)<<endl;
    }
    return 0;
}
