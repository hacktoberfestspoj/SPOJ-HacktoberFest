#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    while (1)
        {
            int n;
            cin>>n;

            if(n==0)
                break;

            cout<<(int)log2(n)<<endl;
        }
    
    
return 0;
}