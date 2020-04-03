#include <iostream>
#include <vector>

#include "Tree.h"

using namespace std;
typedef long long ll;

int main() {
    vector <ll> a;
    size_t n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        a.push_back(temp);
    }
    Tree ts(n, a);
    string s;
    int cnt = 0;
    while (cin >> s) {
        cnt++;
        if (s == "min") {
            int left, right;
            cin >> left >> right;
            cout << ts.min(left, right) << "\n";
        }
        if (s == "set") {
            int left, right;
            ll x;
            cin >> left >> right >> x;
            ts.set_on_segment(left, right, x);
        }
        if (s == "add") {
            int left, right;
            ll x;
            cin >> left >> right >> x;
            ts.add_on_segment(left, right, x);
        }
    }
    return 0;
}
