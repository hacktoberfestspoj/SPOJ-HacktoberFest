/******************************************
* AUTHOR : AAYUSH GARG*
* NICK : aayushgarg_03 *
* INSTITUTION : BIT MESRA *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define mod 1000000007
#define dd double
#define ld long double
#define f(i,a,b) for(ll i=a; i<b; i++)
#define vec vector<ll>
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define VP vector< pii >
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define ascii(c) (int)char (c)
#define all(v) (v).begin(),(v).end()
#define Sort(v) sort(v.begin(), v.end(), sortbysec)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define addmod(a,b,mod) (a%mod + b%mod)%mod
#define submod(a,b,mod) (a%mod - b%mod + mod)%mod
#define N 1000000
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define max4(a,b,c,d) max(a,max3(b,c,d))
#define min4(a,b,c,d) min(a,min3(b,c,d))

ll prime[N];

ll mulmod(ll a, ll b, ll m) 
{ 
    ll res = 0;  
    a = a % m; 
    while (b > 0) 
    { 
        if (b % 2 == 1) 
            res = (res + a) % m; 

        a = (a * 2) % m; 
        b /= 2; 
    } 
  
    return res % m; 
} 

ll power(ll x, ll y, ll p) 
{ 
    ll res = 1;     
  
    x = x % p;  
  
    while (y > 0) 
    {    
      if (y & 1) 
            res = (res*x) % p; 
    
        y = y>>1; 
        x = (x*x) % p;   
    } 
    return res; 
}

void sieve() {
    for(ll i = 0;i < N;i++)
        prime[i] = 1;
    prime[0] = 0;
    prime[1] = 0;
    for(ll i = 2;i*i < N;i++) {
        if(prime[i] == 0)
            continue;
        for(ll j = i*i;j < N;j+=i) {
            prime[j] = 0;
        }
    }
    for(ll i = 1;i < N;i++)
        prime[i] += prime[i-1];
}



bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b) 
{ 
    return (a.second < b.second); 
} 

/*vec v;
void divisors(ll n)
{
    
for(ll i=1;i<=sqrt(n);i++)
{
    if(n%i==0)
    {
        if(i==n/i)
        v.pb(i);
        else
        {
            v.pb(i);
            v.pb(n/i);
        }
        
    }
}

sort(all(v));
}*/
ll a[1001];
ll dp[1001][1001];

int ans(int start,int end)
{
    if(start > end)
    return 0;

    if (dp[start][end] != -1)
        return dp[start][end];

    ll val1,val2;
      
      if(a[start+1] >= a[end] )
      val1 = a[start] + ans(start+2,end);
      else
      val1 = a[start] + ans(start+1,end-1);

      if(a[start] >= a[end-1])
      val2 = a[end] + ans(start+1,end-1);
      else
      val2 = a[end] + ans(start,end-2);

      dp[start][end] = max(val1,val2);
      return dp[start][end];
      
}

int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll c=1;
while(1)
{
    
    ll n;
    cin>>n;
    if(!n)
    break;

    
    ll sum =0;
    f(i,0,n)
    {
        cin>>a[i];
        sum += a[i];
    }
    
    f(i,0,n){
        f(j,0,n)
        dp[i][j]=-1;
    }
      ll s = ans(0,n-1);
      s*=2;
      s-=sum;
      //cout<<sum<<endl;
      
    cout<<"In game "<< c <<", the greedy strategy might lose by as many as "<<s<<" points."<<endl;
    c++;
}




return 0;
}
