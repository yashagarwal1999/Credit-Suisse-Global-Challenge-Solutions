#include <bits/stdc++.h>
using namespace std;
double maximumExpectedMoney(int n, int m, double p[], double x[], double y[])
{
    double v[n];
    double temp1 = 1.0;
    for (int i = 0; i < n; i++)
    {
        v[i] = p[i] * x[i] - (temp1 - p[i]) * y[i];
    }
    sort(v, v + n);
    reverse(v, v + n);
    int N = min(n, m);
    double ret = 0.0;
    for (int i = 0; i < N; i++)
    {
        ret = max(ret, ret + v[i]);
    }

    return ret;
}

int main()
{
    int n, m;

    cin >> n >> m;
    double p[n], x[n], y[n];

    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> y[i];

    double result = maximumExpectedMoney(n, m, p, x, y);

    // Do not remove below line
    cout << fixed << setprecision(2) << result << endl;
    // Do not print anything after this line

    return 0;
}