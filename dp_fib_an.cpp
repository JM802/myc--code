#include<iostream>
#include<vector>
using namespace std;

int fib(int n,vector<int>&v1)
{
    if(n==1||n==2)
    {
        return 1;
    }
    if(v1[n]!=0)
    {
        return v1[n];
    }
    else
    {
        v1[n] = fib(n - 1,v1) + fib(n - 2,v1);
        return v1[n];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v1(n + 1, 0);
    int res = fib(n,v1);
    cout << res << endl;
    return 0;
}