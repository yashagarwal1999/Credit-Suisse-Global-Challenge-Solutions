#include <bits/stdc++.h>
#define forr(i, p, n) for (int i = p; i < (int)n; i++)
using namespace std;

int calculateMinimumSession(int nb, int np, vector<vector<int>> bp, vector<vector<int>> pp)
{
    vector<set<int>> b2p(nb + 1);
    vector<set<int>> p2b(np + 1);
    b2p.clear();
    p2b.clear();
    forr(i, 0, bp.size())
    {
        for (int j = 0; j < (int)bp[i].size(); j++)
        {
            b2p[i + 1].insert(bp[i][j]);
            p2b[bp[i][j]].insert(i + 1);
        }
    }
    // int base1 = (int)b2p.size() * (int)p2b.size();
    forr(i, 0, pp.size())
    {
        for (int j = 0; j < (int)pp[i].size(); j++)
        {
            p2b[i + 1].insert(pp[i][j]);
            b2p[pp[i][j]].insert(i + 1);
            // base1++;
        }
        // base1 -= nb;
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= nb; i++)
        ans1 = max(ans1, (int)b2p[i].size());
    for (int i = 1; i <= np; i++)
        ans2 = max(ans2, (int)p2b[i].size());
    return max(ans1, ans2);
}

vector<string> split(const string &str, char delim)
{
    vector<string> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos)
    {
        end = str.find(delim, start);
        strings.push_back(str.substr(start, end - start));
    }
    return strings;
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

void printVector(vector<string> vec)
{
    for (vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i)
    {
        cout << *i << ' ';
    }
    cout << endl;
}

int main()
{
    int numOfBankers, numOfParticipants;
    vector<vector<int>> bankersPreferences, participantsPreferences;

    cin >> numOfBankers;

    string bankersPreferencesStr;
    cin >> bankersPreferencesStr;
    vector<string> bankersPreferencesVecByComma = split(bankersPreferencesStr, ',');

    for (vector<string>::const_iterator i = bankersPreferencesVecByComma.begin(); i != bankersPreferencesVecByComma.end(); ++i)
    {
        vector<int> bankerPreferenceVecByAnd = splitStringToInt(*i, '&');
        bankersPreferences.push_back(bankerPreferenceVecByAnd);
    }

    string participantsPreferencesStr;
    cin >> numOfParticipants;
    cin >> participantsPreferencesStr;
    vector<string> participantsPreferencesVecByComma = split(participantsPreferencesStr, ',');

    for (vector<string>::const_iterator i = participantsPreferencesVecByComma.begin(); i != participantsPreferencesVecByComma.end(); ++i)
    {
        vector<int> participantPreferenceVecByAnd = splitStringToInt(*i, '&');
        participantsPreferences.push_back(participantPreferenceVecByAnd);
    }

    int result = calculateMinimumSession(numOfBankers, numOfParticipants, bankersPreferences, participantsPreferences);

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}
