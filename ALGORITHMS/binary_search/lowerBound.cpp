#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &a, int t) {
    int l(0), r((int)a.size() - 1), m(-1), ans(-1);

    while (l <= r) {
        m = l + ((r - l) / 2);
        if (a[m] >= t) {
            ans = a[m];
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << lowerBound(a, 7) << "\n";
    cout << lowerBound(a, 46) << "\n";

    return 0;
}
