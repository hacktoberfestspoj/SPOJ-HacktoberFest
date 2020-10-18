#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool sortbysec(const pair<ll,ll> &a, 
              const pair<ll,ll> &b) 
{ 
    return (a.second < b.second); 
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while (t--)
        {
            ll n;
            cin>>n;

            vector<pair<ll,ll>> v;
            pair<ll,ll> p;

            for(int i=0;i<n;i++)
                {
                    cin>>p.first>>p.second;
                    v.push_back(p);
                }
            
            sort(v.begin(),v.end(), sortbysec );

            int count = 1;
            int j=0;    
            for(int i=1;i<n;i++)
                {
                    if(v[i].first>=v[j].second)
                        {
                            count++;
                            j = i ;
                        }
                }

            cout<<count<<endl;
        }
    
    
return 0;
}