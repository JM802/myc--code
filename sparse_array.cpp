#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class triple
{
public:
    int row;
    int col;
    int val;
    triple(int r, int c, int v)
    {
        row = r;
        col = c;
        val = v;
    }
};

vector<triple> get_transepose(int i, int j, int n, vector<triple> v1)
{
    vector<int> num(j, 0);
    vector<int> pos(j, 0);
    vector<triple> transepose(n, triple(0, 0, 0));

    for (const auto &a : v1)
    {
        num[a.col]++;
    }
    for (int k = 1; k < j; k++)
    {
        pos[k] = pos[k - 1] + num[k - 1];
    }

    for (const auto &a : v1)
    {
        int start = pos[a.col];
        transepose[start] = triple(a.col, a.row, a.val);
        pos[a.col]++;
    }
    return transepose;
}

int main()
{
    vector<triple> v1, result;
    ifstream ifs("in.txt");
    int i, j, n;
    ifs >> i >> j >> n;
    ifs.ignore(100, '\n');
    string s;
    while (getline(ifs, s))
    {
        istringstream ss(s);
        int a, b, c;
        ss >> a >> b >> c;
        v1.emplace_back(triple(a, b, c));
    }
    result = get_transepose(i, j, n, v1);
    ofstream ofs("abc.out");
    ofs << j << " " << i << " " << n << endl;
    for (const auto &tri : result)
    {
        ofs << tri.row << " " << tri.col << " " << tri.val << endl;
    }
    return 0;
}