#include <bits/stdc++.h>
using namespace std;

typedef long long int LLD;

LLD a[10001];

int main()
{
    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i= 0; i < n; i++)
        cin >> a[i];
        LLD sum=0;
        for(int i= 0; i < n; i++)
        {
            sum += i*a[i]-a[i]*(n-i-1);
        }
        cout << sum << endl;
    }
    return 0;
}