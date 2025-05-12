#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

class btnode
{
public:
    char data;
    btnode *lchild;
    btnode *rchild;
    btnode(char ch)
    {
        data = ch;
        lchild = nullptr;
        rchild = nullptr;
    }
};

btnode *create_bttree(vector<string> v1)
{
    btnode *root = nullptr;
    map<char, btnode *> nodemaps;
    for (size_t i = 0; i < v1.size(); i++)
    {
        if (nodemaps.find(v1[i][0]) == nodemaps.end())
        {
            btnode *r = new btnode(v1[i][0]);
            nodemaps.insert(make_pair(v1[i][0], r));
            if (i == 0)
            {
                root = r;
            }
        }
        if (v1[i][1] != '#')
        {
            if (nodemaps.find(v1[i][1]) == nodemaps.end())
            {
                nodemaps[v1[i][1]] = new btnode(v1[i][1]);
            }
            nodemaps[v1[i][0]]->lchild = nodemaps[v1[i][1]];
        }
        if (v1[i][2] != '#')
        {
            if (nodemaps.find(v1[i][2]) == nodemaps.end())
            {
                nodemaps[v1[i][2]] = new btnode(v1[i][1]);
            }
            nodemaps[v1[i][0]]->rchild = nodemaps[v1[i][2]];
        }
    }
    return root;
}

bool is_whole_bttree(btnode *root)
{
    bool isend = false;
    queue<btnode *> q;
    q.push(root);
    while (!q.empty())
    {
        btnode *cur = q.front();
        q.pop();
        if (!cur)
        {
            isend = true;
        }
        else
        {
            if (isend)
            {
                return false;
            }
            q.push(cur->lchild);
            q.push(cur->rchild);
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<string> v1;
    for (int i = 0; i < n; i++)
    {
        string node, lchild, rchild;
        cin >> node >> lchild >> rchild;
        v1.emplace_back(node + lchild + rchild);
    }
    btnode *root = create_bttree(v1);
    bool result = is_whole_bttree(root);
    cout << (result ? 1 : 0) << endl;
    return 0;
}