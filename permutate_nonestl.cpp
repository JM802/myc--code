#include<iostream>
#include<string>
#include<sstream>
using namespace std;

string permutate(string s,string st,size_t start)
{
    size_t n = s.length();
    string result = "";
    if(start==n-1)
    {
        st += s[start];
        result += st;
        result +='#';
    }
    for (size_t i = start; i < n;i++)
    {
        swap(s[start], s[i]);
        result+=permutate(s, st + s[start], start + 1);
        swap(s[start], s[i]);
    }
    return result;
}

int main()
{
    string s;
    cin >> s;
    string result = permutate(s, "", 0);
    stringstream ss(result);
    string s1;
    while(getline(ss,s1,'#'))
    {
        cout << s1 << endl;
    }
    return 0;
}
