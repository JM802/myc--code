#include<iostream>
using namespace std;
struct listnode
{
    int val;
    listnode *next;
    listnode(int x) : val(x), next(nullptr) {}
};

int getmax(listnode*head)
{
    if(!head)
    {
        return 0;
    }
    else
    {
        return max(head->val, getmax(head->next));
    }
}

void getmax1(int&res,listnode*head)
{   
    if(!head)
    {
        return;
    }
    else
    {
        res = max(res, head->val);
        getmax1(res, head->next);
    }

}
