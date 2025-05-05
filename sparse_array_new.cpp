// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<fstream>
// #include<sstream>
// using namespace std;

// class triple
// {
// public:
//     int row;
//     int col;
//     int val;
//     triple(int r,int c,int v)
//     {
//         row = r;
//         col = c;
//         val = v;
//     }
// };


// bool mysort(const triple&a,const triple&b)
// {
//     if(a.row!=b.row)
//     {
//         return a.row < b.row;
//     }
//     else
//     {
//         return a.col < b.col;
//     }
// }


// vector<triple> get_transepose(int i,int j,int n,vector<triple>v1)
// {
//     vector<triple> transepose;
//     for(const auto&a:v1)
//     {
//         transepose.emplace_back(a.col, a.row, a.val);
//     }
//     sort(transepose.begin(), transepose.end(), mysort);
//     return transepose;
// }


// int main()
// {
//     vector<triple> v1;
//     ifstream ifs("in.txt");
//     int i, j, n;
//     ifs >> i >> j >> n;
//     ifs.ignore(100, '\n');
//     string s;
//     while(getline(ifs,s))
//     {
//         istringstream ss(s);
//         int row, col, val;
//         ss >> row >> col >> val;
//         v1.emplace_back(row, col, val);
//     }
//     vector<triple> result = get_transepose(i, j, n, v1);
//     ofstream ofs("abc.out");
//     ofs << j << " " << i << " " << n << endl;
//     for(const auto&t:result)
//     {
//         ofs << t.row << " " << t.col << " " << t.val << endl;
//     }
//     return 0;
// }