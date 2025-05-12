#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

class btnode
{
public:
    int data;
    btnode *lchild;
    btnode *rchild;
    btnode *parent;
    btnode(int d)
    {
        data = d;
        lchild = nullptr;
        rchild = nullptr;
        parent = nullptr;
    }
};

btnode *createmytree(const string &s)
{
    btnode *root=nullptr;
    vector<btnode *> v1;
    istringstream ss(s.substr(1, s.length() - 2));
    string input;
    while (getline(ss, input, ','))
    {
        if (input != "#")
        {
            btnode *b1 = new btnode(stoi(input));
            v1.push_back(b1);
            if (!root)
            {
                root = b1;
            }
        }
        else
        {
            v1.push_back(nullptr);
        }
    }
    for (size_t i = 0; i < v1.size(); i++)
    {
        if (v1[i])
        {
            if (2 * i + 1 < v1.size() && v1[2 * i+1])
            {
                v1[i]->lchild = v1[2 * i + 1];
                v1[2 * i + 1]->parent = v1[i];
            }
            if (2 * i + 2 < v1.size() && v1[2 * i + 2])
            {
                v1[i]->rchild = v1[2 * i + 2];
                v1[2 * i + 2]->parent = v1[i];
            }
        }
    }
    return root;
}

btnode *findk(btnode *root, int target)
{
    if (!root)
    {
        return nullptr;
    }
    else if (root->data == target)
    {
        return root;
    }
    btnode *left = findk(root->lchild, target);
    if (left)
    {
        return left;
    }
    return findk(root->rchild, target);
}

vector<int> finddisk(int deep, btnode *tar, int target, int k,btnode*from)
{
    if(tar)
    {
        vector<int> v1;
        if (k == deep)
        {
            v1.push_back(tar->data);
            return v1;
        }
        else if(deep<k)
        {
            if(tar->lchild!=from)
            {   
                vector<int> l = finddisk(deep + 1, tar->lchild, target, k,tar);
                v1.insert(v1.end(), l.begin(), l.end());
            }
            if(tar->rchild!=from)
            {
                vector<int> r = finddisk(deep + 1, tar->rchild, target, k,tar);
                v1.insert(v1.end(), r.begin(), r.end());
            }
            if(tar->parent!=from)
            {
                vector<int> p = finddisk(deep + 1, tar->parent, target, k,tar);
                v1.insert(v1.end(), p.begin(), p.end());
            }
        }
        else
        {
            return {};
        }
        return v1;
    }
    else
    {
        return {};
    }
}

int main()
{
    string s;
    int target;
    int k;
    cin >> s >> target >> k;
    btnode *root;
    btnode *tar;
    root = createmytree(s);
    tar = findk(root, target);
    vector<int> result = finddisk(0, tar, target, k,nullptr);
    for_each(result.begin(), result.end(), [](int a)
             { cout << a << ","; });
    cout << endl;
    return 0;
}
