#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

int main() {
    int N, M;
    string ui, ti;
    vector<string> ids;

    while (cin >> N) {
        for (int i = 0; i < N; i++) {
            cin >> ui;
            ids.push_back(ui);
        }

        cin >> M;
        int status = 0;
        for (int i = 0; i < M; i++) {
            cin >> ti;

            if (!count(ids.begin(), ids.end(), ti)) {
                printf("Unknown %s\n", ti.c_str());
                continue;
            }

            if (status == 0) {
                printf("Opened by %s\n", ti.c_str());
                status = 1;
            }
            else {
                printf("Closed by %s\n", ti.c_str());
                status = 0;
            }
        }
    }

    return 0;
}

