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
typedef pair<int, int> pii;
typedef pair<pii, string> pis;

const int MAX_N = 1000;

int n, k;
string m;
vector<pis> posts;

void display_posts(int k, int d) {
    for (int i = 0; i < n; i++) {
        if (posts[i].first.first > k) break;

        if (posts[i].first.first == k) {
            cout << (string(d, '.') + posts[i].second).c_str() << endl;
            display_posts(posts[i].first.second, d + 1);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k >> m;
        posts.push_back(pis(pii(k, i + 1), m));
    }

    sort(posts.begin(), posts.end());

    display_posts(0, 0);

    return 0;
}

