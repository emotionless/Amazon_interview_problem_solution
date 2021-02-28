/*
Link: https://aonecode.com/Amazon-Online-Assessment-Minimum-Total-Container-Size


Given k days and array P as the item sizes, find out the minimum total container size required to move all the items...
*/

#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000;

vector<vector<int>> dp;

int solve(int ind, const int daysId, const vector<int> items, const int days) {
    if (ind == items.size()) {
        if (daysId == days) return 0;
        return INF;
    }
    if (daysId >= days) return INF;
    int &ret = dp[ind][daysId];
    if (ret != -1) return ret;
    ret = INF;
    int mx = items[ind];
    for(int i = ind; i < items.size(); i++) {
        mx = max(mx, items[i]);
        ret = min(ret, mx + solve(i + 1, daysId + 1, items, days));
    }
    return ret;
}

int getMinimumSize(int days, vector<int> items)
{
    int n = items.size();
    dp.clear();
    dp.resize(n, vector<int>(days + 1, -1));
    return solve(0, 0, items, days);
}



int main()
{
    vector<int> arr{25, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 76, 76, 80};

    cout << getMinimumSize(4, arr) << endl;

    vector<int> arr1{0, 0, 0, 8, 19, 89};

    cout << getMinimumSize(3, arr1) << endl;



    return 0;
}

/*
Time complexity: O(n*m) where n = number of players and m = maximum scores

*/
