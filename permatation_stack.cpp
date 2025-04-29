// #include<iostream>
// #include<stack>
// #include<vector>
// #include<string>
// #include<algorithm>
// using namespace std;

// class state
// {
// public:
//     string s;
//     string st;
//     size_t start;
//     size_t i;
//     state(string s,string st,size_t start,size_t i)
//     {
//         this->s = s;
//         this->st = st;
//         this->start = start;
//         this->i = i;
//     }
// };


// vector<string> permutation_stack(string s,string st,size_t start,size_t i)
// {
//     vector<string> result;
//     stack<state> ss;
//     ss.emplace(s, "", 0, 0);
//     while(!ss.empty())
//     {
//         state cur = ss.top();
//         ss.pop();
//         if(cur.start==s.length()-1)
//         {
//             cur.st += cur.s[cur.start];
//             result.emplace_back(cur.st);
//         }
//         else
//         {
//             if(cur.i<s.length())
//             {
//                 string news = cur.s;
//                 swap(news[cur.start], news[cur.i]);
//                 ss.emplace(cur.s, cur.st, cur.start, cur.i + 1);
//                 ss.emplace(news, cur.st + news[cur.start], cur.start + 1, cur.start + 1);
//             }
//         }
//     }
//     return result;
// }

// int main()
// {
//     string s;
//     cin >> s;
//     vector<string> result = permutation_stack(s, "", 0, 0);
//     for_each(result.begin(), result.end(), [](auto &m) -> void
//              { cout << m << endl; });
//     return 0;
// }