#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r;
    while (cin >> n >> r && n && r) {
        stack<int> deck, tmp_p, tmp_c;
        for (int i=1; i<=n; i++) deck.push(i);

        int p, c;
        for (int i=0; i<r; i++) {
            cin >> p >> c;
            for (int j=0; j<p-1; j++) {
                tmp_p.push(deck.top());
                deck.pop();
            }
            for (int k=0; k<c; k++) {
                tmp_c.push(deck.top());
                deck.pop();
            }
            for (int l=0; l<p-1; l++) {
                deck.push(tmp_p.top());
                tmp_p.pop();
            }
            for (int m=0; m<c; m++) {
                deck.push(tmp_c.top());
                tmp_c.pop();
            }
        }

        cout << deck.top() << endl;
    }

    return 0;
}

