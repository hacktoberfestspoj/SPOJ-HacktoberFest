#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int check(ll mid , vector<ll> v , int c)
	{
		c--;
		ll prev = v[0];
		for(int i=1;i<v.size();i++)
			{
				if(v[i]-prev >= mid)
					{
						c--;
						prev = v[i];
					}
				if(c==0)
					break;
			}
		
		if(c==0)
			return 1;
		else
			return 0;
			
		return 0;	
		
	}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
		{
			int n , c;
			cin>>n>>c;
			
			vector<ll> v(n);
			
			for(int i=0;i<n;i++)
				{
					cin>>v[i];
				}
				
			if(c>n)
				{
					cout<<0<<endl;
					continue;
				}
				
			sort(v.begin(),v.end());
			ll l , r , mid;
			
			l = 0;
			r = v[v.size()-1];
			mid = l + (r-l)/2;
			ll ans = 0;
			int x;
			while(l<=r)
				{
					x = check(mid , v , c);
					
					if(x==0)
						{
							r = mid-1;
							mid = l + (r-l)/2 ;
						}
					else
						{
							ans = mid;
							l = mid+1;
							mid = l + (r-l)/2 ;
						}
				}
			cout<<ans<<endl;
			
		}	
		
	return 0;
}
