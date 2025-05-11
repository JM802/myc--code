#include<iostream>
#include<string>
#include<vector>
using namespace std;

void getpermutation(const vector<char>v1,vector<string>res)
{
    vector<bool> used(v1.size(), false);
    string s = "";
    if(s.size()==v1.size())
    {
        res.push_back(s);
        return;
    }

}