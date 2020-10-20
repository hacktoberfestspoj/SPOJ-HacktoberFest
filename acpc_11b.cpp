#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[1000], i;
        for (i = 0; i < n; i++)
            cin >> a[i];
        int m;
        cin >> m;
        int b[1000];
        for (i = 0; i < m; i++)
            cin >> b[i];
        int diff = 1000000, s, j;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (a[i] > b[j])
                    s = a[i] - b[j];
                else
                    s = b[j] - a[i];
                if (s < diff)
                    diff = s;
            }
        }
        cout << diff << endl;
    }
    return 0;
}