// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// class light
// {
//  public:
//     int num;
//     bool bright;
//     light(int n,bool flag)
//     {
//         num = n;
//         bright = flag;
//     }
// };


// int main()
// {
//     vector<light> v1(1000,light(0,false));
//     for (int i = 1; i <= 100;i++)
//     {
//         v1[i] = light(i, false);
//     }
//     for (int i = 1; i <= 100;i++)
//     {
//         for (int j = i; j <= 100;j++)
//         {
//             if(j%i==0)
//             {
//                 v1[j].bright = !v1[j].bright;
//             }
//         }
//     }
//     for(light l1:v1)
//     {
//         if(l1.bright)
//         {
//             cout << l1.num << " ";
//         } 
//     }
//     cout << endl;
//     return 0;
// }