#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

class matgraph
{
public:
    int numvertices, numedges;
    vector<vector<int>> edge;
    vector<char> verlist;
};

int getindex(matgraph &g, char c)
{
    for (int i = 0; i < g.numvertices; i++)
    {
        if (g.verlist[i] == c)
        {
            return i;
        }
    }
    return -1;
}

int getoutcount(matgraph &g, int tar)
{
    int count = 0;
    for (int i = 0; i < g.numvertices; i++)
    {
        if (g.edge[tar][i] == 1)
        {
            count++;
        }
    }
    return count;
}

int getincount(matgraph &g, int tar)
{
    int count = 0;
    for (int i = 0; i < g.numvertices; i++)
    {
        if (g.edge[i][tar] == 1)
        {
            count++;
        }
    }
    return count;
}

int getk(matgraph &g, vector<bool> &v1)
{
    int count = 0;
    for (int i = 0; i < g.numvertices; i++)
    {
        int outcount = getoutcount(g, i);
        int incount = getincount(g, i);
        if (outcount > incount)
        {
            count++;
            v1[i] = true;
        }
    }
    return count;
}

int main()
{
    matgraph g;
    g.numvertices = 0;
    g.numedges = 0;
    string inputver;
    cin >> inputver;
    for (const auto &c : inputver)
    {
        if (isalpha(c))
        {
            g.verlist.push_back(c);
            g.numvertices++;
        }
    }
    int n = g.numvertices;
    vector<bool> v(n, false);
    g.edge = vector<vector<int>>(n, vector<int>(n, 0));
    string inputedge;
    cin >> inputedge;
    int t = 0;
    while (t < inputedge.size() - 3)
    {
        if (!isalpha(inputedge[t]))
        {
            t++;
        }
        else
        {
            int from = getindex(g, inputedge[t]);
            int to = getindex(g, inputedge[t + 2]);
            if (from != -1 && to != -1)
            {
                g.edge[from][to] = 1;
                g.numedges++;
            }
            t += 3;
        }
    }
    int count = getk(g, v);
    cout << "K vertices :";
    for (int i = 0; i < g.numvertices; i++)
    {
        if (v[i])
        {
            cout << " " << g.verlist[i];
        }
    }
    cout << endl;
    cout << "Number of K vertices:" << count << endl;
    return 0;
}
