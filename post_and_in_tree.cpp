#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class btnode
{
public:
    char data;
    btnode *lchild;
    btnode *rchild;
    btnode(char c)
    {
        data = c;
        lchild = nullptr;
        rchild = nullptr;
    }
};

btnode *createmytree(vector<btnode *> v1, map<char, int> nodemaps, int instart, int inend, int &postindex)
{
    if (instart > inend)
    {
        return nullptr;
    }
    btnode *root = nullptr;
    if (postindex >=0)
    {
        root = v1[postindex--];
        int inindex = nodemaps[root->data];
        root->rchild = createmytree(v1, nodemaps, inindex+1, inend, postindex);
        root->lchild = createmytree(v1, nodemaps, instart, inindex-1, postindex);
    }
    return root;
}

void leveltranvans(btnode *root)
{
    queue<btnode *> q;
    q.push(root);
    while (!q.empty())
    {
        int levelsize = q.size();
        for (int i = 0; i < levelsize; i++)
        {
            btnode *cur = q.front();
            q.pop();
            if (cur)
            {
                cout << cur->data << " ";
                q.push(cur->lchild);
                q.push(cur->rchild);
            }
            else
            {
                cout << "null" << " ";
            }
        }
    }
}
int main()
{
    string poststr, instr;
    cin >> poststr >> instr;
    int n1 = poststr.size();
    vector<btnode *> v1(n1, nullptr);
    map<char, int> nodemaps;
    for (int i = 0; i < n1; i++)
    {
        v1[i] = new btnode(poststr[i]);
    }
    for (int i = 0; i < instr.size(); i++)
    {
        nodemaps[instr[i]] = i;
    }
    int postindex=poststr.size()-1;
    btnode *root = createmytree(v1, nodemaps, 0, poststr.size() - 1, postindex);
    leveltranvans(root);
    return 0;
}