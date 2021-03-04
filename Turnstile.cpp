/*
Problem link: https://aonecode.com/interview-question/turnstile


A university has exactly one turnstile. It can be used either as an exit or an entrance. Unfortunately, sometimes many people want to pass through the turnstile and their directions can be different. The ith person comes to the turnstile at time[i] and wants to either exit the university if direction[i] = 1 or enter the university if direction[i] = 0. People form 2 queues, one to exit and one to enter. They are ordered by the time when they came to the turnstile and, if the times are equal, by their indices.

If some person wants to enter the university and another person wants to leave the university at the same moment, there are three cases:
If in the previous second the turnstile was not used (maybe it was used before, but not at the previous second), then the person who wants to leave goes first.
If in the previous second the turnstile was used as an exit, then the person who wants to leave goes first.
If in the previous second the turnstile was used as an entrance, then the person who wants to enter goes first.
Passing through the turnstile takes 1 second.

For each person, find the time when they will pass through the turnstile.

Input
arrTime, an array of n integers where the value at index i is the time in seconds when the ith person will come
direction, a list of integers where the value at indexi is the direction of the ith person.

Output
an array of integers where the value at index i is the time when the ith person will pass the turnstile.

Constraints
1 <= n <= 10^5
0 <= arrTime[i] <= 10^9 for 0<= i <=n-1
arrTime[i] <= arrTime[i+1] for 0 <= i <= n - 2
0 <= direction[i] <= 1 for 0 <= o <=  n - 1

Example1
Input:
n = 4
arrTime = [1, 1, 2, 6]
direction = [0, 1, 1, 0]

Output:
[3,1,2,6]

Explanation:
At time 1, person 0 and 1 want to pass through the turnstile. Person 0 wants to enter the store and person 1 wants to leave the store. The turnstile was not used in the previous second, so the priority is on the side of the person 1
At time 2, person 0 and 2 want to pass through the turnstile. Person 2 wants to leave the store and at the previous second the turnstile was used as an exit, so the person 2 passes through the turnstile.
At time 3, person 0 passes through the turnstile.
At time 6, person 3 passes through the turnstile.
*/

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Turnstile {
public:
    Turnstile() {
    }

    vector<int> getTurnstileTime(vector<int> arrTime, vector<int> directions) {
        int n = arrTime.size();
        queue<int> enters, exits;
        int cur = 0;
        int last = arrTime[n-1];
        int i = 0;
        int preD = -1;
        vector<int> ans(n, -1);
        while (cur <= last || !enters.empty() || !exits.empty()) {
            while(i < n && arrTime[i] <= cur) {
                if (directions[i] == 1) {
                    exits.push(i);
                } else {
                    enters.push(i);
                }
                i++;
            }
            bool ck = false;
            if (preD == -1) {
                if (exits.empty() && enters.empty()) {
                    if (i < n) {
                        cur = arrTime[i] - 1;
                    }
                } else if (!exits.empty()) {
                    int top = exits.front();
                    exits.pop();
                    ans[top] = cur;
                    preD = 1;
                    ck = true;
                } else {
                    int top = enters.front();
                    enters.pop();
                    ans[top] = cur;
                    preD = 0;
                    ck = true;
                }
            } else if (preD == 1) {
                if (!exits.empty()) {
                    int top = exits.front();
                    exits.pop();
                    ans[top] = cur;
                    preD = 1;
                    ck = true;
                } else {
                    preD = -1;
                }
            } else {
                if (!enters.empty()) {
                    int top = enters.front();
                    enters.pop();
                    ans[top] = cur;
                    preD = 0;
                    ck = true;
                } else {
                    preD = -1;
                }
            }
            if (ck == false) {
                if (!enters.empty()) {
                    int top = enters.front();
                    enters.pop();
                    ans[top] = cur;
                    preD = 0;
                    ck = true;
                } else if (!exits.empty()) {
                    int top = exits.front();
                    exits.pop();
                    ans[top] = cur;
                    preD = 1;
                    ck = true;
                }
            }
            cur++;
        }
        return ans;
    }

};

int main() {
    Turnstile tt = Turnstile();
    auto ans = tt.getTurnstileTime({1,2,2,4,4}, {0, 1, 0, 0, 1});
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    auto ans1 = tt.getTurnstileTime({1, 1, 2, 6}, {0, 1, 1, 0});
    for (auto x : ans1) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
