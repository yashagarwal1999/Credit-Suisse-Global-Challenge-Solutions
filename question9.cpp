#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
string organizingContainers(vector<vector<ll>> arr)
{
    ll n = arr.size();
    int px = 0;
    int alpha = 10;
    for (ll i = 0; i < n; i++) //col
    {
        for (ll j = 0; j < n; j++)
        {
            if (j != i)
            {
                px++;

                ll x = arr[j][i];
                arr[j][i] = 0;

                ll end = 0, m = 1e12;
                for (ll k = 0; k < n; k++)
                {
                    if (k != i && arr[i][k] >= x && arr[i][k] <= m)
                    {
                        m = arr[i][k];
                        end = k;
                        px += 2;
                    }
                }
                alpha = 10;

                if (m != 1e12 && m >= x)
                {
                    arr[i][end] -= x;
                    arr[i][i] += x;
                    arr[j][end] += x;
                }
                else
                    return "Impossible";
            }
        }
        px = 0;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         cout << arr[i][j] << " ";
    //     cout << endl;
    // }
    return "Possible";
}

int main()
{
    ll q;
    cin >> q;
    string answer = "";
    for (ll a0 = 0; a0 < q; a0++)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> M(n, vector<ll>(n));
        for (ll M_i = 0; M_i < n; M_i++)
        {
            for (ll M_j = 0; M_j < n; M_j++)
            {
                cin >> M[M_i][M_j];
            }
        }

        string result = organizingContainers(M);
        if (answer == "")
            answer = result;
        else
            answer = answer + "," + result;
    }

    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line

    return 0;
}
