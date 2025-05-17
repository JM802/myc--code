#include<iostream>
#include<string>
#include<vector>
using namespace std;

void getpermutation(vector<bool>&visited,vector<string>&res,string&s,const string input)
{
    if(s.size()==input.size())
    {
        res.push_back(s);
        return;
    }
    for (int i = 0; i < input.size();i++)
    {
        if(visited[i])
        {
            continue;
        }
        else
        {
            visited[i] = true;
            s += input[i];
            getpermutation(visited, res, s, input);
            visited[i] = false;
            s.pop_back();
        }
    }
}


int main()
{
    string input;
    cin >> input;
    int n = input.size();
    vector<bool> visited(n, false);
    vector<string> res;
    string s = "";
    getpermutation(visited, res, s, input);
    for(const auto&t:res)
    {
        cout << t << " ";
    }
    cout << endl;
    return 0;
}