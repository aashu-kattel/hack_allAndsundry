#include<bits/stdc++.h>
using namespace std;

int knapsackType(vector<vector<int>>& arr2, int K) {
    int size = arr2.size();
    map<tuple<int, long long, int>, int> dp;
    
    function<int(int, int, int)> dfs = [&](int i, long long mask, int cap) -> int {
        if (i >= size) return 0;
        if (dp.count({i, mask, cap})) return dp[{i, mask, cap}];
        auto& P = arr2[i];
        int t = P[0], w = P[1], c = P[2];
        int excl = dp.count({i + 1, mask, cap}) ? dp[{i + 1, mask, cap}] : dfs(i + 1, mask, cap);
        if ((1LL << t) & mask or cap + w > K) return excl;
        int incl = dp.count({i + 1, mask | (1LL << t), cap + w}) ? dp[{i + 1, mask | (1LL << t), cap + w}] : c + dfs(i + 1, mask | (1LL << t), cap + w);
        return dp[{i, mask, cap}] = max(incl, excl);
    };
    
    return dfs(0, 0LL, 0);
}

int main() {
    int numProducts;
   
    cin >> numProducts;

    vector<vector<int>> products;
    for (int i = 0; i < numProducts; ++i) {
        int type, weight, cost;
        cin >> type >> weight >> cost;
        products.push_back({type, weight, cost});
    }

    int K;
   
    cin >> K;

    int maxCost = knapsackType(products, K);

    cout  << maxCost << endl;

    return 0;
}
