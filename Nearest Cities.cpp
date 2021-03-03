/*
Link: https://aonecode.com/amazon-online-assessment-nearest-cities

Given a list of points, find the nearest points that shares either an x or a y coordinate with the queried point.

The distance is denoted on a Euclidean plane: the difference in x plus the difference in y.

Input

numOfPoints, an integer representing the number of points;

points, a list of strings representing the names of each point [i];

xCoordinates, a list of integers representing the X coordinates of each point[i];

yCoordinates, a list of integers representing the Y coordinates of each point[i];

numOfQueriedPoints, an integer representing the number of points queried;

queriedPoints, a list of strings representing the names of the queried points.

Output

Return a list of strings representing the name of the nearest points that shares either an x or a y coordinate with the queried point.

Example 1:

Input:

numOfPoints = 3

points = ["p1","p2","p3"]

xCoordinates = [30, 20, 10]

yCoordinates = [30, 20, 30]

numOfQueriedPoints = 3

queriedPoints = ["p3", "p2", "p1"]

Output:

["p1", NONE, "p3"]
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> getNearestCities(int n, vector<string> points, vector<int> x, vector<int> y) {
    unordered_map<int, vector<pair<int, int>>> storeX, storeY;
    for (int i = 0; i < n; i++) {
        storeX[ x[i] ].push_back({y[i], i});
        storeY[ y[i] ].push_back({x[i], i});
    }
    for (auto &x : storeX) {
        sort(x.second.begin(), x.second.end());
    }
    for (auto &y : storeY) {
        sort(y.second.begin(), y.second.end());
    }
    vector<string> res;

    for (int i = 0; i < n; i++) {
        int a = x[i];
        int b = y[i];
        pair<int, int> ans = {10000000, -1};
        auto &vec = storeX[a];
        auto ind = find(vec.begin(), vec.end(), make_pair(b, i)) - vec.begin();
        if (ind != 0) {
            if (b - vec[ind - 1].first < ans.first) {
                ans = {b - vec[ind-1].first, vec[ind-1].second};
            }
        }
        if ((ind+1) < vec.size()) {
            if ((vec[ind + 1].first - b) < ans.first) {
                ans = {vec[ind+1].first - b, vec[ind+1].second};
            }
        }

        auto &vec1 = storeY[b];
        ind = find(vec1.begin(), vec1.end(), make_pair(a, i)) - vec1.begin();
        if (ind != 0) {
            if (b - vec1[ind - 1].first < ans.first) {
                ans = {b - vec1[ind-1].first, vec1[ind-1].second};
            }
        }
        if ((ind+1) < vec1.size()) {
            if ((vec1[ind + 1].first - b) < ans.first) {
                ans = {vec1[ind+1].first - b, vec1[ind+1].second};
            }
        }
        if (ans.second == -1) {
            res.push_back("NONE");
        } else {
            res.push_back(points[ans.second]);
        }
    }
    return res;
}

int main() {
    auto res = getNearestCities(3, {"p1","p2","p3"}, {30, 20, 10}, {30, 20, 30});
    for (auto x : res) {
        cout << x << endl;
    }

    res = getNearestCities(5, {"p1", "p2","p3", "p4", "p5"}, {10, 20, 30, 40, 50}, {10, 20, 30, 40, 50});
    for (auto x : res) {
        cout << x << endl;
    }



    return 0;
}
