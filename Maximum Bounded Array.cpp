#include <iostream>
#include <vector>

using namespace std;

/*
Link: https://aonecode.com/interview-question/maximum-bounded-array
*/

vector<int> getMaximumBoundedArray(int n, int lower, int upper) {
    int tot = (upper - lower) * 2 + 1;
    if (n > tot) return {};
    int mx = lower + n - 1;
    vector<int> ans;
    while(mx >= lower) {
        if (mx > upper) {
            int diff = mx - upper;
            ans.push_back(upper - diff);
        } else {
            ans.push_back(mx);
        }
        mx--;
    }
    return ans;
}

int main() {

    auto ans = getMaximumBoundedArray(4, 10, 12);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    ans = getMaximumBoundedArray(6, 1, 3);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;



    return 0;
}
