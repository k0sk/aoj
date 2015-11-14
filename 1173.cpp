// The Balance of the World
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1173
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, N) for (int i = 0; i < (int)N; i++)

int main() {
    string str;
    while (getline(cin, str)) {
        if (str == ".") break;

        bool balanced = true;
        stack<char> st;
        for (int i = 0; str[i] != '.'; i++) {
            if (str[i] == '(' || str[i] == '[') {
                st.push(str[i]);
            } else if (str[i] == ')' || str[i] == ']') {
                if (st.empty()) {
                    balanced = false;
                    break;
                }

                if ((str[i] == ')' && st.top() == '(') ||
                        (str[i] == ']' && st.top() =='[')) {
                    st.pop();
                } else {
                    balanced = false;
                    break;
                }
            }
    }

        cout << (balanced ? "yes" : "no") << endl;
    }

    return 0;
}

