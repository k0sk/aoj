#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
  string x;
  while (cin >> x && x != "0") {
    int nums[x.size()];
    for (int i = 0; i < x.size(); i++) nums[i] = x[i] - '0';
    int ans = 0;
    for (int j = 0; j < x.size(); j++) ans += nums[j];
    cout << ans << endl;
  }
  return 0;
}
