#include <iostream>
using namespace std;

#define DATA_SIZE 10

int main()
{
  char s[DATA_SIZE];
  int n[DATA_SIZE];

  while (cin >> s) {
    for (int i = 0; i < DATA_SIZE; i++) {
      n[i] = s[i] - '0';
    }
    for (int j = DATA_SIZE - 1; j > 0; j--) {
      for (int k = 0; k < j; k++) {
        n[k] = (n[k] + n[k + 1]) % 10;
      }
    }
    cout << n[0] << endl;
  }

  return 0;
}

