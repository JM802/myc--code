#include<iostream>
#include<string>
#include<cctype>
using namespace std;

const int mysize = 100;
class stack
{
public:
    int top;
    char arr[mysize];
    stack()
    {
        top = -1;
    }

    bool isempty()
    {
        return top == -1;
    }

    void push(int v)
    {
        top++;
        arr[top] = v;
    }

    int pop()
    {
        if(!isempty())
        {
            int r = arr[top];
            top--;
            return r;
        }
    }
};


int main()
{
    stack st;
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n;i++)
    {
        if(isalpha(s[i]))
        {
            st.push(s[i]);
        }
        else
        {
            st.pop();
        }
    }
    char data[mysize]={'\0'};
    int count = 0;
    while(!st.isempty())
    {
        data[count++] = st.pop();
    }
    count--;
    for (int i = count; i >= 0;i--)
    {
        cout << data[i] << " ";
    }
    cout << endl;
    return 0;
}