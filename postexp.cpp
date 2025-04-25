// #include <iostream>
// #include <string>
// #include <stack>
// using namespace std;

// void getpostexp(const string &s, string &postexp)
// {
//     size_t i = 0;
//     stack<char> mystack;
//     while (i < s.length())
//     {
//         char ch = s[i];
//         if (ch == '(')
//         {
//             mystack.push(ch);
//             i++;
//         }
//         else if (ch == ')')
//         {
//             while (!mystack.empty() && mystack.top() != '(')
//             {
//                 char ch1 = mystack.top();
//                 mystack.pop();
//                 postexp += ch1;
//             }
//             mystack.pop();
//             i++;
//         }
//         else if (ch == '+' || ch == '-')
//         {
//             while (!mystack.empty() && mystack.top() != '(')
//             {
//                 char ch1 = mystack.top();
//                 mystack.pop();
//                 postexp += ch1;
//             }
//             mystack.push(ch);
//             i++;
//         }
//         else if (ch == '*' || ch == '/')
//         {
//             while ((!mystack.empty() && mystack.top() != '(') && (mystack.top() == '*' || mystack.top() == '/'))
//             {
//                 char ch1 = mystack.top();
//                 mystack.pop();
//                 postexp += ch1;
//             }
//             mystack.push(ch);
//             i++;
//         }
//         else
//         {
//             string d = "";
//             while (i<s.length()&&ch >= '0' && ch <= '9')
//             {
//                 d += ch;
//                 i++;
//                 if (i < s.length())
//                 {
//                     ch = s[i];
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//             postexp += d;
//             postexp += '#';
//         }
//     }
//     while (!mystack.empty())
//     {
//         char m = mystack.top();
//         postexp += m;
//         mystack.pop();
//     }
// }

// int calculatemypostexp(const string &t)
// {
//     size_t i = 0;
//     stack<int> st;
//     while (i < t.length())
//     {
//         switch (t[i])
//         {
//         case '+':
//         {
//             int a = st.top();
//             st.pop();
//             int b = st.top();
//             st.pop();
//             st.push(b + a);
//             i++;
//             break;
//         }
//         case '-':
//         {
//             int a = st.top();
//             st.pop();
//             int b = st.top();
//             st.pop();
//             st.push(b - a);
//             i++;
//             break;
//         }
//         case '*':
//         {
//             int a = st.top();
//             st.pop();
//             int b = st.top();
//             st.pop();
//             st.push(b * a);
//             i++;
//             break;
//         }
//         case '/':
//         {
//             int a = st.top();
//             st.pop();
//             int b = st.top();
//             st.pop();
//             st.push(b / a);
//             i++;
//             break;
//         }
//         default:
//         {
//             int d = 0;
//             while (i<t.length()&&t[i] >= '0' && t[i] <= '9')
//             {
//                 d = 10 * d + (t[i] - '0');
//                 i++;
//             }
//             st.push(d);
//             i++;
//             break;
//         }
//         }
//     }
//     return st.top();
// }

// int main()
// {
//     string s;
//     cin >> s;
//     string postexp = "";
//     getpostexp(s, postexp);
//     int result = calculatemypostexp(postexp);
//     cout << result << endl;
//     return 0;
// }