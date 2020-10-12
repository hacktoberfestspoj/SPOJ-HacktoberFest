#include<bits/stdc++.h>
 
#define ll long long
#define endl "\n"
#define mod 1000000007
using namespace std;
#define mp make_pair
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true)
    {
        ll n,m;
        cin>>n>>m;
        if(n==0)
        break;
        ll a[n][m];
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            cin>>a[i][j];
        }
        ll dp1[n];
        ll dp2[m];
        for(ll i=0;i<n;i++)
        {
            if(m==1)
            {
                dp1[i]=a[i][0];
            }
            if(m==2)
            {
                dp1[i]=max(a[i][0],a[i][1]);
            }
            else
            {
                dp2[0]=a[i][0];
                dp2[1]=max(a[i][1],a[i][0]);
                for(ll j=2;j<m;j++)
                {
                    dp2[j]=max(dp2[j-1],a[i][j]+dp2[j-2]);
                }
                dp1[i]=dp2[m-1];
            }
            
        }
        ll dp3[n];
        ll ans=0;
        if(n==1)
        ans=dp1[0];
        else if(n==2)
        ans=max(dp1[0],dp1[1]);
        else
        {
            dp3[0]=dp1[0];
            dp3[1]=max(dp1[0],dp1[1]);
            for(ll i=2;i<n;i++)
            dp3[i]=max(dp3[i-1],dp3[i-2]+dp1[i]);
            ans=dp3[n-1];
        }
        cout<<ans<<endl;
        
    }
 
    
    return 0;
}  
