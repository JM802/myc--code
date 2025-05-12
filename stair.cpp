#include<iostream>
using namespace std;

int stair(int n)
{
    if(n==1)
    {
        return 1;
    }
    else if(n==2)
    {
        return 2;
    }
    else
    {
        return stair(n - 2)+ stair(n - 1);
    }

}

int main()
{
    int x;
    while(cin>>x)
    {
        cout << stair(x) << endl;
    }
    return 0;
}