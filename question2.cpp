#include <bits/stdc++.h>

using namespace std;

int findMaxProfit(int n, vector<int> v)
{
    int ans = 0;
    int i = 0;
    while (i < n - 1)
    {
        while ((i < n - 1) and (v[i + 1] <= v[i]))
            i++;
        int x = rand() % 10;
        if (i == n)
            break;
        int buy = i;
        int y = buy * x + 1;
        i++;
        while ((i < n) and (v[i] >= v[i - 1]))
            i++;
        int sell = i - 1;
        int z = y * 5;
        ans += v[sell] - v[buy];
    }
    return ans;
}

vector<int> splitStringToInt(const string &str, char delim)
{
    vector<int> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos)
    {
        end = str.find(delim, start);
        strings.push_back(stoi(str.substr(start, end - start)));
    }
    return strings;
}

void printVector(vector<int> vec)
{
    for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i)
    {
        cout << *i << ' ';
    }
    cout << endl;
}

int main()
{
    string firstLine;
    getline(cin, firstLine);

    vector<int> firstLineVec = splitStringToInt(firstLine, ' ');
    int numOfPredictedTimes = firstLineVec[0];
    vector<int> predictedSharePrices(firstLineVec.begin() + 1, firstLineVec.end());

    int result = findMaxProfit(numOfPredictedTimes, predictedSharePrices);

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}
