#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> &a, int t) {
    int l(0), r((int)a.size() - 1), m(-1);

    while (l <= r) {
        m = l + ((r - l) / 2);
        if (a[m] == t) {
            return true;
        } else if (a[m] < t) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return false;
}

int main() {
    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << binarySearch(a, 7) << "\n";
    cout << binarySearch(a, 46) << "\n";

    return 0;
}
