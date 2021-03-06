//   Convert this program to C++
//   to C++ io
//   change to one line comments
//   change defines of constants to const
//   change array to vector<>
//   inline any short function


#include <iostream>
#include <vector>

using namespace std;

const int N = 40;

inline void sum(int*p, int n, vector<int> d)
{
  *p = 0;
  for(int i = 0; i < n; ++i)
    *p = *p + d[i];
}

int main()
{
  vector<int> data(N);
  for(int i = 0; i < N; ++i)
    data[i] = i;
  int accum = 0;
  sum(&accum, N, data);
  cout << "sum is " << accum << endl; 
  return 0;
}
