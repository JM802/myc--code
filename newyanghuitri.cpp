#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> yh(int n)
{
    vector<vector<int>> v1;
    if(n==1)
    {
        v1.push_back({1});
        return v1;
    }
    else
    {
        vector<vector<int>> v2 = yh(n - 1);
        vector<int> v3 = v2.back();
        vector<int> cur(n,1);
        for (int i = 1; i < n - 1;i++)
        {
            cur[i] = v3[i - 1] + v3[i];
        }
        v1 = v2;
        v1.push_back(cur);
    }
    return v1;
}
int main()
    {
        int n;
        cin >> n;
        vector<vector<int>> v1 = yh(n);
        for (int i = 0; i < n;i++)
        {
            for (int j = 0; j < n - 1 - i;j++)
            {
                cout << " ";
            }
            for (int k = 0; k <= i;k++)
            {
                cout << v1[i][k] << " ";
            }
            cout << endl;
        }

        return 0;
    }