#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

struct btnode
{
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


btnode* createtree(const string&s)
{
    btnode *root=nullptr;
    bool isleft;
    stack<btnode *> st;
    btnode *r;
    for (auto &c:s)
    {
        if(isalpha(c))
        {
            r = new btnode(c);
            if(!root)
            {
                root = r;
            }
            else
            {
                if(!st.empty())
                {
                    if(isleft)
                    {
                        st.top()->lchild = r;
                    }
                    else
                    {
                        st.top()->rchild = r;
                    }
                }
            }
        }

        else if(c=='(')
        {
            st.push(r);
            isleft = true;
        }
        else if(c==',')
        {
            isleft = false;
        }
        else
        {
            st.pop();
        }
    }
    return root;
}


void preorder(btnode*root)
{
    if(root)
    {
        cout << root->data << " ";
        preorder(root->lchild);
        preorder(root->rchild);
    }
    else
    {
        return;
    }
}

void inorder(btnode*root)
{
    if(root)
    {
        inorder(root->lchild);
        cout << root->data<<" ";
       inorder(root->rchild);
    }
    else
    {
        return;
    }
}

void postorder(btnode*root)
{
    if(root)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        cout << root->data << " ";
    }
    else
    {
        return;
    }
}


int main()
{
    string s;
    cin >> s;
    btnode *root = createtree(s);
    preorder(root);
    inorder(root);
    postorder(root);
    return 0;
}