#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <sstream>
using namespace std;
typedef long long ll;
const double eps = 1e-9;

const int M       = 256,
          MAX_N   = 256,
          MAX_SAC = 16;

int main() {
    int N, I[MAX_N];
    while (cin >> N, N) {
        for (int i = 0; i < N; i++) cin >> I[i];

        int S = 0, A = 0, C = 0;
        double H = 100000.0;
        for (int s = 0; s < MAX_SAC; s++) {
            for (int a = 0; a < MAX_SAC; a++) {
                for (int c = 0; c < MAX_SAC; c++) {
                    int oc[M] = {0};

                    int r = s;
                    for (int i = 0; i < N; i++) {
                        r = (a * r + c) % M;

                        int o = (I[i] + r) % M;
                        oc[o]++;
                    }

                    double h = 0.0;
                    for (int i = 0; i < M; i++) {
                        if (oc[i])
                            h -= ((double)oc[i] / N) * log((double)oc[i] / N);
                    }

                    if (h + eps < H) {
                        S = s;
                        A = a;
                        C = c;
                        H = h;
                    }
                }
            }
        }

        printf("%d %d %d\n", S, A, C);
    }

    return 0;
}

