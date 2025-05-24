#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class task
{
public:
    int index;
    int arrival;
    int execution;
    task(int i,int a,int e)
    {
        index = i;
        arrival = a;
        execution = e;
    }
};

bool mysort(const task&t1,const task&t2)
{
    if(t1.arrival!=t2.arrival)
    {
        return t1.arrival < t2.arrival;
    }
    else
    {
        return t1.index < t2.index;
    }
}


int gettime(vector<task>v1)
{
    int sum = 0;
    int current_time = 0;
    for (int i = 0; i < v1.size();i++)
    {
        if(current_time<=v1[i].arrival)
        {
            current_time = v1[i].arrival;
        }
        sum += current_time - v1[i].arrival;
        current_time += v1[i].execution;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<task> v1;
    for (int i = 0; i < n;i++)
    {
        int a, b;
        cin >> a >> b;
        v1.emplace_back(i,a, b);
    }
    sort(v1.begin(), v1.end(), mysort);
    int res = gettime(v1);
    cout << res << endl;
    return 0;
}