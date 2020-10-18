#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define pb push_back

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
	int p = 1;
    while (t--)
        {
            int n , k ;
            cin>>n>>k;
            
            vector<int> v[n+1];
            int x , y;
            for(int i=0;i<k;i++)
            	{
            		cin>>x>>y;
            		v[x].push_back(y);
            		v[y].push_back(x);
				}
				
			vector<int> vis(n+1 , -1);
			int c = 1;
			stack<int> s;
			for(int i=1 ; i<=n ; i++)
				{
					while(s.size()>0)
						{
							vector<int> arr;
							while(s.size()>0)
								{
									arr.pb(s.top());
									s.pop();
								}
							if(c==1)
								c=2;
							else
								c=1;							
							for(int x = 0 ; x<arr.size() ; x++)						
									for(int j=0;j<v[arr[x]].size();j++)
										{										
											if(vis[v[arr[x]][j]] == -1)
												{
													vis[v[arr[x]][j]] = c;
													s.push(v[arr[x]][j]);
												}
										}
						}
						
					if(vis[i] == -1)
						{
							vis[i] = c;
							
							
							int check = 0;	
							for(int j=0;j<v[i].size();j++)
								{
									if(vis[v[i][j]] == -1 && check == 0)
										{
											if(c==1)
												c=2;
											else
												c=1;
												
											check = 1;
										}
										
									if(vis[v[i][j]] == -1)
										{
											vis[v[i][j]] = c;
											s.push(v[i][j]);
										}
								}
						}
				}
			int mark = 0;	
			for(int i=1;i<=n;i++)
				{
					for(int j=0;j<v[i].size();j++)
						{
							if(vis[i] == vis[v[i][j]])
								{
									mark = 1;
									break;
								}
						}
				}
				
			if(mark == 0)
				{
					cout<<"Scenario #"<<p<<":"<<endl;
					cout<<"No suspicious bugs found!"<<endl;
				}
			else
				{
					cout<<"Scenario #"<<p<<":"<<endl;
					cout<<"Suspicious bugs found!"<<endl;
				}
			p++;
            
        }
    
    
return 0;
}
