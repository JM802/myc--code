#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

class btnode
{
public:
    int data;
    btnode *lchild;
    btnode *rchild;
    btnode(int c)
    {
        data = c;
        lchild = nullptr;
        rchild = nullptr;
    }
};

btnode *createmytree(vector<int> s, int &index)
{
    if (s[index] == -1)
    {
        if(index<s.size()-1)
        {
            index++;
        }
        return nullptr;
    }
    btnode *root = new btnode(s[index]);
    index++;
    root->lchild = createmytree(s, index);
    root->rchild = createmytree(s, index);
    return root;
}

int getwidth(btnode *root)
{
    int res = 0;
    queue<btnode *> q;
    if (root)
    {
        q.push(root);
    }
    else
    {
        return 0;
    }
    while (!q.empty())
    {
        int sz = q.size();
        res = max(res, sz);
        for (int i = 0; i < sz; i++)
        {
            btnode *cur = q.front();
            q.pop();
            if (cur->lchild)
            {
                q.push(cur->lchild);
            }
            if (cur->rchild)
            {
                q.push(cur->rchild);
            }
        }
    }
    return res;
}

int main()
{
    vector<int> s;
    string input;
    getline(cin, input);
    istringstream iss(input);
    int num;
    while (iss >> num)
    {
        s.push_back(num);
    }
    int index = 0;
    btnode *root = createmytree(s, index);
    int res = getwidth(root);
    cout << res << endl;
    return 0;
}