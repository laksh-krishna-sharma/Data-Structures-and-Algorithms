#include <bits/stdc++.h>
using namespace std;

bool dp[6][13];

bool subsetSum(vector<int> &a, int sum, int n) {
    for (int i = 0; i < (n + 1); i++) {
        for (int j = 0; j < (sum + 1); j++) {
            if (i == 0) {
                dp[i][j] = false;
            } else if (j == 0) {
                dp[i][j] = true;
            } else if (a[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int main() {
    memset(dp, 0, sizeof(dp));
    vector<int> arr = {1, 5, 3, 7, 4};
    int sum = 12;
    int n = (int)arr.size();

    cout << "Is Subset Sum: " << (subsetSum(arr, sum, n) ? "True" : "False")
         << "\n";
    return 0;
}
