#include <bits/stdc++.h>

using namespace std;

string encrypt(string words)
{
    string px = "";

    int n = words.length();
    for (int i = 0; i < n; i++)
    {
        if (words[i] != ' ')
            px += words[i];
    }
    words = px;
    n = words.length();
    int x = ceil(sqrt(n));
    if (x * x > n)
    {
        int temp = x * x - n;
        string a = "";
        while (temp > 0)
        {
            a += '@';
            temp--;
        }
        words = words + a;
    }
    char arr[x][x];
    int k = 0;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {

            arr[i][j] = words[k++];
        }
    }
    string ans;
    for (int i = 0; i < x; i++)
    {
        string t = "";
        for (int j = 0; j < x; j++)
        {
            if (arr[j][i] != '@')
                t += arr[j][i];
        }
        ans += t + " ";
    }
    return ans;
}

int main()
{
    string words;
    getline(cin, words);

    string result = encrypt(words);

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}
