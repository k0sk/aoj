#include <iostream>
using namespace std;
#define NUM_SUB 5

int main()
{
  int n, tmp;
  while (cin >> n) {
    if (n == 0) break;
    int max = 0, min = 500;
    for (int i = 0; i < n; i ++) {
      int total = 0;
      for (int j = 0; j < NUM_SUB; j++) {
        cin >> tmp;
        total += tmp;
      }
      max = total > max ? total : max;
      min = total < min ? total : min;
    }
    cout << max << ' ' << min << endl;
  }
  return 0;
}

