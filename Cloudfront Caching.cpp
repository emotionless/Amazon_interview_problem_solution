/*
Problem link: https://aonecode.com/aplusplus/interviewctrl/getInterview/89188231923

AWS CloudFront wants to build an algo to measure the efficiency of its caching network. The network is represented as a number of nodes and a list of connected pairs. The efficiency of this network can be estimated by first summing the cost of each isolated set of nodes where each individual node has a cost of 1. To account for the increase in efficiency as more nodes are connected, update the cost of each isolated set to be the ceiling of the square root of the original cost and return the final sum of all costs.

Example:
n = 10 nodes
edges = [[1 2] , [1 3] , [2 4] , [3 5] , [7 8]]

There are 2 isloated sets with more than one node {1,2,3,4,5} and {7,8}. The ceilings of their square roots are:
5^1/2 = 2.236 and ceil(2.236) = 3
2^1/2 = 1.414 and ceil(1.414) = 2

The other three isolated nodes are separate and the square root of their weights is 1^1/2 = 1 respectively.
The sum is 3+2+(3*1) = 8
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

int DFS(int u) {
    int ret = 1;
    vis[u] = true;
    for (auto v : adj[u]) {
        if (!vis[v]) {
            ret += DFS(v);
        }
    }
    return ret;
}

int calculateSQCeil(int u) {
    int sq = sqrt(u);
    if (sq * sq == u) return sq;
    return sq + 1;
}

int getCloudfrontCaching(int n, const vector<pair<int, int>> &edges) {
    adj.resize(n + 1);
    vis.resize(n + 1, false);
    for (auto con : edges) {
        adj[con.first].push_back(con.second);
        adj[con.second].push_back(con.first);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int cnt = DFS(i);
            ans += calculateSQCeil(cnt);
        }
    }
    return ans;
}

int main() {
    vector<pair<int, int>> arr{{1, 2} , {1, 3} , {2, 4} , {3, 5} , {7, 8}};

    cout << getCloudfrontCaching(10, arr) << endl;

    return 0;
}
