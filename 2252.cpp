#include <bits/stdc++.h>
using namespace std;

const int RIGHT = 0, LEFT = 1;
const string left_side  = "yuiophjklnm";

int main() {
    string line;
    while (cin >> line) {
        if (line == "#") break;

        int hand, cnt = 0;
        if (left_side.find(line[0], 0) == string::npos) hand = RIGHT;
        else hand = LEFT;

        for (int i = 1; i < line.size(); i++) {
            if (hand == LEFT && left_side.find(line[i], 0) == string::npos) {
                cnt++;
                hand = RIGHT;
                continue;
            }

            if (hand == RIGHT && left_side.find(line[i], 0) != string::npos) {
                cnt++;
                hand = LEFT;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}

