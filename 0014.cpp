#include <iostream>
#include <cmath>
using namespace std;

/* メイン関数 */
int main()
{
  int d;
  while (cin >> d) {
    int s = 0;
  for (int i = 600 - d; i > 0; i -= d) {
    s += d * pow(i, 2);
  }
  cout << s << endl;
  }

  return 0;
}
