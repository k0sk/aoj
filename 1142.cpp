#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int m;
    string dataset;
    while (cin >> m && m) {
        for (int i=0; i<m; i++) {
            cin >> dataset;
            int len = dataset.size();

            string rev_dataset = dataset;
            for (int j=0; j<len; j++) rev_dataset[j]=dataset[len-j-1];

            set<string> sub_trains;
            for (int j=1, k=len-1; j<len; j++, k--) {
                string sub1 = dataset.substr(0, j),
                       sub2 = dataset.substr(j, k),
                       sub3 = rev_dataset.substr(k, j), // sub1の反転
                       sub4 = rev_dataset.substr(0, k); // sub2の反転

                sub_trains.insert(sub1+sub2);
                sub_trains.insert(sub2+sub1);
                sub_trains.insert(sub3+sub2);
                sub_trains.insert(sub2+sub3);
                sub_trains.insert(sub1+sub4);
                sub_trains.insert(sub4+sub1);
                sub_trains.insert(sub3+sub4);
                sub_trains.insert(sub4+sub3);
            }

            cout << sub_trains.size() << endl;
        }
    }

    return 0;
}

