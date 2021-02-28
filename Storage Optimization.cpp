/*
Problem link:  https://aonecode.com/aplusplus/interviewctrl/getInterview/90812391

Amazon is experimenting with a flexible storage system for their warehouses. The storage unit consists of a shelving system which is one meter deep with removable vertical and horizontal separators. When all separators are installed, each storage space is one cubic meter (1' x 1' x 1'). Determine the volume of the largest space when a series of horizontal and vertical separators are removed.

Example
n = 6
m = 6
h = [4]
v = [2]
Consider the diagram below. The left image depicts the initial storage unit with n = 6 horizontal and m = 6 vertical separators, where the volume of the largest storage space is 1 x 1 x 1. The right image depicts that unit after the fourth horizontal and second vertical separators are removed. The maximum storage volume for that unit is then 2 x 2 x 1 = 4 cubic meters:
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;


int getStorage(int n, int m, vector<int> h, vector<int> v)
{
    sort(h.begin(), h.end());
    sort(v.begin(), v.end());
    int pre = 0;
    int cnt = 0;
    int mxH = 0;
    for (auto x : h)
    {
        if (x == (pre+1))
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }
        mxH = max(mxH, cnt);
        pre = x;
    }

    cnt = 0;
    pre = 0;
    int mxV = 0;
    for (auto x : v)
    {
        if (x == (pre+1))
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }
        mxV = max(mxV, cnt);
        pre = x;
    }

    return (mxH + 1) * (mxV + 1);
}

int main()
{

    cout << getStorage(3, 2, {1, 2, 3}, {1, 2}) << endl;

    return 0;
}
