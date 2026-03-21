#include <bits/stdc++.h>
using namespace std;

int knapsackRecursive(vector<int> &val, vector<int> &wt, int w, int n) {
    if (n == 0 || w == 0) {
        return 0;
    }

    else if (wt[n - 1] <= w) {
        return max(
            val[n - 1] + knapsackRecursive(val, wt, w - wt[n - 1], n - 1),
            knapsackRecursive(val, wt, w, n - 1));
    }

    else {
        return knapsackRecursive(val, wt, w, n - 1);
    }
}

int t[6][6];

int knapsackMemoization(vector<int> &val, vector<int> &wt, int w, int n) {
    if (n == 0 || w == 0) {
        return 0;
    }

    if (t[n][w] != -1) {
        return t[n][w];
    }

    else if (wt[n - 1] <= w) {
        return t[n][w] = max(val[n - 1] + knapsackMemoization(
                                              val, wt, w - wt[n - 1], n - 1),
                             knapsackMemoization(val, wt, w, n - 1));
    }

    else {
        return t[n][w] = knapsackMemoization(val, wt, w, n - 1);
    }
}

int tDP[5][8];

int knapsackDP(vector<int> &val, vector<int> &wt, int w, int n) {
    for (int i = 0; i < (n + 1); i++) {
        for (int j = 0; j < (w + 1); j++) {
            if (i == 0 || j == 0) {
                tDP[i][j] = 0;
            } else if (wt[i - 1] <= j) {
                tDP[i][j] =
                    max(val[i - 1] + tDP[i - 1][j - wt[i - 1]], tDP[i - 1][j]);
            }

            else {
                tDP[i][j] = tDP[i - 1][j];
            }
        }
    }
    return tDP[n][w];
}

int main() {
    memset(t, -1, sizeof(t));
    memset(tDP, 0, sizeof(tDP));
    vector<int> val = {1, 4, 5, 7};
    vector<int> wt = {1, 3, 4, 5};
    int W = 7;

    int n = (int)val.size();

    cout << "Knapsack Recursive: " << knapsackRecursive(val, wt, W, n) << "\n";
    cout << "Knapsack Memoization: " << knapsackMemoization(val, wt, W, n) << "\n";
    cout << "Knapsack DP: " << knapsackDP(val, wt, W, n) << "\n";

    return 0;
}
