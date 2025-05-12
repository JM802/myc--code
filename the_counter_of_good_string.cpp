#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool decstr(const string &s)
{
    int n = s.length();
    for (int i = 0; i < n - 1; i++)
    {
        if (!(s[i] == s[i + 1] || s[i] == s[i + 1] - 1))
        {
            return false;
        }
    }
    return true;
}

vector<string> get_good_string(const string &s)
{
    vector<string> result;
    int n = s.length();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            string sub = s.substr(j, i);
            if (i == 1)
            {
                result.push_back(sub);
            }
            else if (i == 2)
            {
                result.push_back(sub);
            }
            else
            {
                for (int k = 1; k < i; k++)
                {
                    if ((decstr(s.substr(j, k))) && decstr(s.substr(j + k, i - k)))
                    {
                        result.push_back(sub);
                        break;
                    }
                }
            }
        }
    }
    return result;
}

int main()
{
    string s;
    cin >> s;
    vector<string> result = get_good_string(s);
    cout << result.size() << endl;
    return 0;
}