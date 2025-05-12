#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

vector<string> permutation(string s, string st, size_t start)
{
    vector<string> v1;
    size_t n = s.length();
    if (start == n - 1)
    {
        v1.push_back(st + s[start]);
        return v1;
    }
    for (size_t i = start; i < n; i++)
    {
        swap(s[start], s[i]);
        vector<string> sub = permutation(s, st + s[start], start + 1);
        swap(s[start], s[i]);
        for (auto &s1 : sub)
        {
            v1.push_back(s1);
        }
    }
    return v1;
}

int main()
{
    string s;
    cin >> s;
    vector<string> result = permutation(s, "", 0);
    for_each(result.begin(), result.end(), [](string st)
             { cout << st << endl; });
    return 0;
}