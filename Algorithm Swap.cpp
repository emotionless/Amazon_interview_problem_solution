/*
Link: https://aonecode.com/aplusplus/interviewctrl/getInterview/892221223

You're a new Amazon Software Development Engineer (SDE). You're reading through your team's code and find an old sorting algorithm. The following algorithm is used to sort an array of distinct n integers:

For the input array arr of size n do:
Try to find the smallest pair of indices 0 <= i < j <= n-1 such that arr[i] > arr[j]. Here smallest means usual alphabetical ordering of pairs, i.e. (i1, j1) < (i2, j2) if and only if i1 < i2 or (i1 = i2 and j1 <j2).
If there is no such pair, stop.
Otherwise, swap a[i] and a[j] and repeat finding the next pair.
The algorithm seems to be correct, but the question is how efficient is it? Write a function that returns the number of swaps performed by the above algorithm.

For example, if the initial array is [5,1,4,2], then the algorithm first picks pair (5,1) and swaps it to produce array [1,5,4,2]. Next, it picks pair (5,4) and swaps it to produce array [1,4,5,2]. Next, pair (4,2) is picked and swapped to produce array [1,2,5,4], and finally, pair (5,4) is swapped to produce the final sorted array [1,2,4,5], so the number of swaps performed is 4.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(int st, int mid, int ed, vector<int> &nums, int &ans) {
    int counter = 0;
    int j = mid + 1;
    for (int i = st; i <= mid; i++) {
        while(j <= ed && nums[i] >= nums[j]) {
            j++;
        }
        counter += (j - mid - 1);
    }
    ans += counter;

    int st1 = st, st2 = mid + 1;
    int ind = 0;
    vector<int> tmp;
    tmp.resize(ed - st + 1, 0);
    while (st1 <= mid || st2 <= ed) {
        if (st1 > mid) {
            tmp[ind] = nums[st2++];
        } else if (st2 > ed) {
            tmp[ind] = nums[st1++];
        } else if (nums[st1] < nums[st2]) {
            tmp[ind] = nums[st1++];
        } else {
            tmp[ind] = nums[st2++];
        }
        ind++;
    }
    for (int i = st ; i <= ed; i++) {
        nums[i] = tmp[i - st];
    }
    return;
}

void divideAndConquer(int st, int ed, vector<int> &nums, int &ans) {
    if (st >= ed) return;
    int mid = (st + ed) >> 1;
    divideAndConquer(st, mid, nums, ans);
    divideAndConquer(mid + 1, ed, nums, ans);

    merge(st, mid, ed, nums, ans);
}

int getNumberOfSwap(vector<int> nums) {
    int n = nums.size();
    int ans = 0;
    divideAndConquer(0, n-1, nums, ans);
    return ans;
}

int main() {

    int ans = getNumberOfSwap({5,1,4,2});
    cout << ans << endl;

    return 0;
}
