#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
  int n, x;
  while (cin >> n >> x && (n != 0 && x != 0)) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        for (int k = 1; k <= n; k++) {
          if (i + j + k == x && i != j && j != k && k != i) cout << i << j << k << "\n";
        }
      }
    }
    cout << n << x<< cnt << endl;
  }
  return 0;
}

