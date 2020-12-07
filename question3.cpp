#include <bits/stdc++.h>
using namespace std;
int n, d;
string find_min_days(int profit[], int price[])
{
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
        m[price[i]].push_back(i);
    }
    string ans;

    for (int i = 0; i < d; i++)
    {
        int l = 0, r = 100000000;
        for (int j = 0; j < n; j++)
        {
            int val = price[j] + profit[i];
            auto v = m[val];
            int it = -1;
            for (auto Tx : v)
            {
                if (Tx > j)
                {
                    it = Tx;
                    break;
                }
            }
            if (it != -1)
            {
                if (r > it)
                {
                    l = j;
                    r = it;
                }
                if (r == it)
                {
                    if (r - l > it - j)
                    {
                        l = j;
                        r = it;
                    }
                }
            }
        }
        if (r == 100000000)
        {
            if (ans.length() != 0)
                ans += ',';
            ans += "-1";
        }
        else
        {
            if (ans.length() != 0)
                ans += ',';
            ans += to_string(l + 1) + " " + to_string(r + 1);
        }
    }
    return ans;
}

int main()
{
    int i;
    string answer = "";
    cin >> n >> d;
    int price[n];
    int profit[d];
    for (i = 0; i < n; i++)
        cin >> price[i];
    for (i = 0; i < d; i++)
        cin >> profit[i];
    answer = find_min_days(profit, price);

    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line

    return 0;
}
