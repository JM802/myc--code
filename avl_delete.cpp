#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class btnode
{
public:
    char data;
    int height;
    btnode *lchild;
    btnode *rchild;
    btnode(char c)
    {
        data = c;
        height = 1;
        lchild = nullptr;
        rchild = nullptr;
    }
};

int getdepth(btnode *root)
{
    if (!root)
    {
        return 0;
    }
    else
    {
        return root->height;
    }
}

btnode *findrightmin(btnode *root)
{
    if (!root)
    {
        return nullptr;
    }
    btnode *cur = root;
    while (cur->lchild)
    {
        cur = cur->lchild;
    }
    return cur;
}

btnode *rotateleft(btnode *root)
{
    btnode *m = root->rchild;
    root->rchild = m->lchild;
    m->lchild = root;
    root->height = 1 + max(getdepth(root->lchild), getdepth(root->rchild));
    m->height = 1 + max(getdepth(m->lchild), getdepth(m->rchild));
    return m;
}

btnode *rotateright(btnode *root)
{
    btnode *m = root->lchild;
    root->lchild = m->rchild;
    m->rchild = root;
    root->height = 1 + max(getdepth(root->lchild), getdepth(root->rchild));
    m->height = 1 + max(getdepth(m->lchild), getdepth(m->rchild));
    return m;
}

int getbalance(btnode *root)
{
    if (!root)
    {
        return 0;
    }

    else
    {
        return getdepth(root->lchild) - getdepth(root->rchild);
    }
}

btnode *insert(char key, btnode *root)
{
    if (!root)
    {
        root = new btnode(key);
        return root;
    }
    else
    {
        if (key < root->data)
        {
            root->lchild = insert(key, root->lchild);
        }
        else if (key > root->data)
        {
            root->rchild = insert(key, root->rchild);
        }
        else
        {
            return root;
        }
    }

    root->height = 1 + max(getdepth(root->lchild), getdepth(root->rchild));
    int balance = getbalance(root);
    if (balance > 1 && key < root->lchild->data)
    {
        return rotateright(root);
    }
    else if (balance > 1 && key > root->lchild->data)
    {
        btnode *m = root->lchild;
        root->lchild = rotateleft(m);
        return rotateright(root);
    }
    else if (balance < -1 && key > root->rchild->data)
    {
        return rotateleft(root);
    }
    else if (balance < -1 && key < root->rchild->data)
    {
        btnode *m = root->rchild;
        root->rchild = rotateright(m);
        return rotateleft(root);
    }
    return root;
}

btnode *remove(btnode *root, char tar)
{
    if (!root)
    {
        return nullptr;
    }

    if (tar < root->data)
    {
        root->lchild = remove(root->lchild, tar);
    }
    else if (tar > root->data)
    {
        root->rchild = remove(root->rchild, tar);
    }
    else
    {
        if (root->lchild == nullptr || root->rchild == nullptr)
        {
            btnode *temp = root->lchild ? root->lchild : root->rchild;
            if (!temp)
            {
                delete root;
                root = nullptr;
            }
            else
            {
                btnode *old = root;
                root = temp;
                delete old;
                old = nullptr;
            }
        }
        else
        {
            btnode *temp = findrightmin(root->rchild);
            root->data = temp->data;
            root->rchild = remove(root->rchild, temp->data);
        }
    }
    if (!root)
    {
        return nullptr;
    }
    root->height = 1 + max(getdepth(root->lchild), getdepth(root->rchild));
    int balance = getbalance(root);
    if (balance > 1 && getbalance(root->lchild) >= 0)
        return rotateright(root);
    if (balance > 1 && getbalance(root->lchild) < 0)
    {
        root->lchild = rotateleft(root->lchild);
        return rotateright(root);
    }

    if (balance < -1 && getbalance(root->rchild) <= 0)
        return rotateleft(root);

    if (balance < -1 && getbalance(root->rchild) > 0)
    {
        root->rchild = rotateright(root->rchild);
        return rotateleft(root);
    }
    return root;
}

void postorder(btnode *root)
{
    if (!root)
    {
        return;
    }
    else
    {
        postorder(root->lchild);
        postorder(root->rchild);
        cout << root->data;
    }
}

int main()
{
    int n1;
    cin >> n1;
    btnode *root = nullptr;
    for (int i = 0; i < n1; i++)
    {
        char c;
        cin >> c;
        root = insert(c, root);
    }
    int n2;
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        char c;
        cin >> c;
        root = remove(root, c);
    }
    postorder(root);
    cout << endl;
    return 0;
}