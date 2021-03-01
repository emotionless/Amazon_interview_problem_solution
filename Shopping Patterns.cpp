/*
Problem link:  https://aonecode.com/amazon-online-assessment-shopping-patterns

Amazon is trying to understand customer shopping patterns and offer items that are regularly bought together to new customers. Each item that has been bought together can be represented as an undirected graph where edges join often bundled products. A group of n products is uniquely numbered from 1 of product_nodes. A trio is defined as a group of three related products that all connected by an edge. Trios are scored by counting the number of related products outside of the trio, this is referred as a product sum.

Given product relation data, determine the minimum product sum for all trios of related products in the group. If no such trio exists, return -1.

STDIN        Funtion
-------        ------------------------------------------------
5   6     ->  products_nodes = 5    products_edges = 6
1   2     ->  products_from[0] = 1   products_to[0] = 2
1   3     ->  products_from[1] = 1   products_to[1] = 3
2   3     ->  products_from[2] = 2   products_to[2] = 3
2   4     ->  products_from[3] = 2   products_to[3] = 4
3   4     ->  products_from[4] = 3   products_to[4] = 4
4   5     ->  products_from[5] = 4   products_to[5] = 5

Sample Output

2

Explanation

There are two possible trios: {1,2,3} and {2,3,4}

The score for {1,2,3} is 0 + 1 + 1 = 2.

The score for {2,3,4} is 1 + 1 + 1 = 3.

Return 2.
*/

#include <iostream>
#include <vector>
#include <map>
#include <sstream>

using namespace std;
const int INF = 1000000;
vector<vector<int>> adj;
vector<vector<bool>> mat;
vector<bool> visited;

int dfs(int cur, int pre1, int pre2) {
    int ret = INF;
    if (mat[cur][pre2] == 1) {
        ret = adj[cur].size() + adj[pre1].size() + adj[pre2].size() - 6;
        //cout << ret << endl;
    }
    visited[cur] = true;
    for (auto v : adj[cur]) {
        if (!visited[v])
            ret = min(ret, dfs(v, cur, pre1));
    }
    return ret;
}

int getShoppingPatterns(int n, vector<pair<int, int>> edges) {
    mat.resize(n+1, vector<bool>(n+1, false));
    adj.resize(n+1);
    for (auto edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
        mat[edge.first][edge.second] = true;
        mat[edge.second][edge.first] = true;
    }
    int ans = INF;
    visited.resize(n+1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ans = min(ans, dfs(i, 0, 0));
        }
    }
    if (ans < INF)
        return ans;
    return -1;
}

int main() {
    cout << getShoppingPatterns(5, {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {4, 5}}) << endl;
//    cout << getShoppingPatterns(6, {{1, 2}, {2, 5}, {2, 4}, {3, 5}, {4, 5}, {5, 6}}) << endl;

    return 0;
}

/*
Time: O(n*logn)
Space: O(n)
*/
