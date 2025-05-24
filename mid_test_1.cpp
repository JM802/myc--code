#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

class queue
{
public:
    int size;
    int front;
    int rear;
    vector<int> arr;
    queue(int k)
    {
        size = k;
        front = rear = 0;
        arr.resize(k);
    }

    bool isempty()
    {
        return rear == front;
    }

    bool isfull()
    {
        return (rear + 1) % size == front;
    }
    void enqueue(int value)
    {
        if(!isfull())
        {
            rear = (rear + 1) % size;
            arr[rear] = value;
        }
        else
        {
            rear = (rear + 1) % size;
            arr[rear] = value;
            front = (front + 1) % size;
        }
    }

    int dequeue()
    {
        if(isempty())
        {
            return -1;
        }
        else
        {
            int r = arr[front];
            front = (front + 1) % size;
            return r;
        }
    }

    int get_oldest()
    {
        if(isempty())
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    int get_latest()
    {
        if(isempty())
        {
            return -1;
        }
        else
        {
            return arr[rear];
        }

    }
}; 


int main()
{
    int k, m;
    cin >> k >> m;
    cin.ignore();
    queue q(k);
    string s;
    for (int i = 0; i < m;i++)
    {
        getline(cin, s);
        istringstream iss(s);
        string st;
        iss >> st;
        if(st=="enqueue")
        {
            int num;
            iss >> num;
            q.enqueue(num);
        }
        else if(st=="dequeue")
        {
            int m=q.dequeue();
            cout << m << endl;
        }
        else if(st=="get_oldest")
        {
           int m= q.get_oldest();
           cout << m << endl;
        }
        else
        {
            int m = q.get_latest();
            cout << m << endl;
        }
    }
    return 0;
}