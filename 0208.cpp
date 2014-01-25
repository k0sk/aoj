#include <iostream>
using namespace std;

int main()
{
  string nums = "01235789";
  int n;
  while (cin >> n && n != 0) {
    string ans = "";
    int tmp;
    while (n) {
      tmp = (int)(n % 8);
      ans = nums[tmp] + ans;
      n /= 8;
    }
    cout << ans << endl;
  }
  return 0;
}
