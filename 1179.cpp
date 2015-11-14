#include <bits/stdc++.h>
using namespace std;

const int days_per_odd_month  = 20,
          days_per_even_month = 19,
          days_per_month_sp   = 20,
          days_per_year       = 19 * 5 + 20 * 5,
          days_per_year_sp    = 20 * 10;

int main() {
    int n;
    int Y, M, D;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> Y >> M >> D;

            int days = 0;
            if (Y % 3 == 0) days += days_per_month_sp - D + 1;
            else {
                if (M % 2 == 0) days += days_per_even_month - D + 1;
                else days += days_per_odd_month - D + 1;
            }

            for (int mm = M + 1; mm <= 10; mm++) {
                if (Y % 3 == 0) days += days_per_month_sp;
                else {
                    if (mm % 2 == 0) days += days_per_even_month;
                    else days += days_per_odd_month;
                }
            }

            for (int yy = Y + 1; yy < 1000; yy++) {
                if (yy % 3 == 0) days += days_per_year_sp;
                else days += days_per_year;
            }

            cout << days << endl;
        }
    }

    return 0;
}

