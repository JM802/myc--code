#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isvalid(vector<vector<int>> qu, int r, int c, int n)
{
    for (int i = 0; i < r; i++)
    {
        if (qu[i][c] == 1)
        {
            return false;
        }
    }
    for (int i = 0; i < r; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (qu[i][j] == 1)
            {
                if (abs(r - i) == abs(c - j))
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void getsolution(int n, vector<vector<int>> &qu, vector<vector<vector<int>>> &res, int row)
{
    if (row == n)
    {
        res.push_back(qu);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!isvalid(qu, row, i, n))
        {
            continue;
        }
        else
        {
            qu[row][i] = 1;
            getsolution(n, qu, res, row+1);
            qu[row][i] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> qu(n, vector<int>(n, 0));
    vector<vector<vector<int>>> res;
    getsolution(n, qu, res, 0);
    for (auto sol : res)
    {
        for (auto row : sol)
        {
            for (auto col : row)
            {
                cout << ((col == 1) ? "Q" : ".");
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}