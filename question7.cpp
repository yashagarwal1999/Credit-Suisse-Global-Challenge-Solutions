#include <bits/stdc++.h>
#define forr(i, p, n) for (int i = p; i < (int)n; i++)
using namespace std;
string findSuspiciousUserId(int qs, vector<vector<int>> qA)
{
    set<int> ans;
    vector<set<int>> adj(10002);
    forr(i, 0, qA.size())
    {

        int x = qA[i][0];
        forr(j, 1, qA[i].size()) { adj[x].insert(qA[i][j]); }
    }
    forr(i, 0, adj.size())
    {
        if (adj[i].size() > 0)
        {
            int par = i;
            for (auto j = adj[i].begin(); j != adj[i].end(); j++)
            {
                auto m = adj[*j].find(par);
                if (m != adj[*j].end())
                {
                    ans.insert(par);
                    ans.insert(*j);
                }
            }
        }
    }
    int prev = ans.size(), next = ans.size();
    int cheaters[10002] = {0};
    do
    {
        forr(i, 0, qs + 1)
        {
            if (adj[i].size() > 0 && ans.find(i) == ans.end())
            {
                int count = 0;
                // cout << i << "=>";
                for (auto j : adj[i])
                {
                    if (ans.find(j) != ans.end())
                        count++;
                    // cout << j << ",";
                }
                // cout << endl;
                if (count >= 2)
                    ans.insert(i);
            }
        }
        prev = next;
        next = ans.size();
        // cout << prev << " " << next << endl;

    } while (prev != next);
    string ret;
    for (auto p : ans)
        ret += to_string(p) + ",";

    return ret.substr(0, ret.length() - 1);
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
    string firstLine;
    getline(cin, firstLine);

    int numOfQuestions = strtol(firstLine.c_str(), NULL, 10);
    ;

    string questionAndAnswerStr;
    getline(cin, questionAndAnswerStr);

    vector<vector<int>> questionAndAnswerVecOfVec;
    vector<string> questionAndAnswerVecByComma = split(questionAndAnswerStr, ',');

    for (vector<string>::const_iterator i = questionAndAnswerVecByComma.begin(); i != questionAndAnswerVecByComma.end(); ++i)
    {
        vector<int> bankerPreferenceVecByAnd = splitStringToInt(*i, ' ');
        questionAndAnswerVecOfVec.push_back(bankerPreferenceVecByAnd);
    }

    string result = findSuspiciousUserId(numOfQuestions, questionAndAnswerVecOfVec);

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}
