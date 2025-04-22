#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class box
{
public:
    int i;
    int j;
    int di;
    box(int i1, int j1, int di1)
    {
        i = i1;
        j = j1;
        di = di1;
    }
    box()
    {
    }
};

int movedx[] = {-1, 1, 0, 0};
int movedy[] = {0, 0, -1, 1};

bool findpath(vector<vector<int>> mg, int xi, int yi, int xe, int ye, stack<box> &path)
{
    size_t ni, nj;
    int di1;
    box b, b1;
    bool find;
    b = box(xi, yi, -1);
    path.push(b);
    mg[xi][yi] = -1;
    while (!path.empty())
    {
        b = path.top();
        if (b.i == xe && b.j == ye)
        {
            return true;
        }
        else
        {
            find = false;
            di1 = b.di;
            while (find == false && di1 < 3)
            {
                di1++;
                ni = b.i + movedx[di1];
                nj = b.j + movedy[di1];

                if (ni >= 0 && nj >= 0 && ni < mg.size() && nj < mg[0].size() && mg[ni][nj] == 0)
                {
                    find = true;
                }
            }
            if (find)
            {
                path.top().di = di1;
                b1 = box(ni, nj, -1);
                path.push(b1);
                mg[ni][nj] = -1;
            }
            else
            {
                mg[b.i][b.j] = 0;
                path.pop();
            }
        }
    }
    return false;
}

void displaypath(stack<box> path)
{
    vector<box> mypath;
    while (!path.empty())
    {
        box b = path.top();
        path.pop();
        mypath.push_back(b);
    }
    for_each(mypath.rbegin(), mypath.rend(), [](box t)
             { cout << "[" << t.i << "," << t.j << "]" << "->"; });
    cout <<"final"<< endl;
}

int main()
{
    vector<vector<int>> mazepath;
    cout << "please input the length of maze" << endl;
    int m;
    cin >> m;
    mazepath.resize(m);
    cout << "please input the width of maze" << endl;
    int n;
    cin >> n;
    cout << "please input your maze array" << endl;
    for (int i = 0; i < m; i++)
    {   
        mazepath[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            cin >> mazepath[i][j];
        }
    }
    stack<box> p;
    if (findpath(mazepath, 0, 0, m - 1, n - 1, p))
    {
        displaypath(p);
    }
    else
    {
        cout << "no path" << endl;
    }
    return 0;
}