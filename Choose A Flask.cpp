/*
Link: https://aonecode.com/amazon-online-assessment-choose-a-flask

A robotic chemical delivery system for an Amazon laboratory has been configured to work using only one type of glass flask per day. For each chemical ordered, it will be filled to a mark that is at least equal to the volume ordered. There are multiple flasks available, each with markings at various levels.


Given a list of order requirements and a list of flasks with their measurements, write an algorithm to determine the single type of flask that will result in minimal waste. Waste is the sum of marking - requirement for each order. Output the zero-based index of the flask type chosen. If there are multiple answers, output the minimum index. If no flask will satisfy the constraints, output -1.


Input

The input to the function/method consists of five arguments:

numOrders, an integer representing the number of orders;

requirements, a list of integers representing the requirements for the orders;

flaskTypes, an integer representing the number of flask types;

totalMarks, an integer representing the total number of markings;

markings, a list of pairs of integers where the first integer represents the index of the flask and second represents the one mark.


Output

Return an integer representing the index of the flask to choose or return -1 if none will work.


Constraints

1 <= numorders <= 10^5

1 <= flaskTypes <= 10^4

1 <= totalMarks <= 10^5

1 <= requirements[i] <= 10^9

0 <= markings[i][0] < flaskTypes

0 <= markings[i][1] <= 10^9

0 <= j < numOrders

0 <= i < totalMarks

NOTE

The markings list will be given in order of the flasks, ie, the markings for the 0-index flask will be followed by markings of the 1-index flask and so on.

For each flask, the given markings will also be sorted in ascending order.

Example

Input:

numOrders = 4

requirements = [4,6,6,7]

flaskTypes = 3

totalMarks = 9

markings =

[[0, 3],

[0,5],

[0,7],

[1,6],

[1,8],

[1,9],

[2,3],

[2,5],

[2,6]]

Output

0

Explanation:

The markings list is a list where the first element is the flask number and the second an available marking in this case, the first type has markings at 3, 5 and 7. The second type has them at 6, 8 and 9, and the third type has markings at 3, 5 and 6. Using the first flask type, the losses are: 5 - 4 = 1,7 -6 =1,7 -6 = 1, 7- 7 = 0.1 + 1 + 1 + 0 = 3 units wasted. Using the second flask type, losses are: 6 - 4 = 2.6 - 6 = 0,6-6 = 0,8 - 7 = 1.2 + 0 + 0 + 1 = 3 units wasted. The third flask type cannot be used because its maximum capacity is 6 and there is an order for 7. Two types of flasks can be used and 3 units will be lost. The lower index flask is at index 0.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Flask {
public:
    Flask() {

    }

    int chooseAFlask(vector<int> requirements, int flaskTypes, vector<pair<int, int>> markings) {
        int n = requirements.size();
        int m = markings.size();
        int k = 0;
        int pre = -1;
        int ans = INT_MAX;
        int index = -1;
        for (int i = 0; i < m; i++) {
            if (pre != markings[i].first) {
                k = 0;
                int j = i;
                int sum = 0;
                while(markings[i].first == markings[j].first) {
                    while (k < n) {
                        if (requirements[k] <= markings[j].second) {
                            sum += markings[j].second - requirements[k];
                            k++;
                        } else {
                            break;
                        }
                    }
                    j++;
                }
                if (k == n && sum < ans) {
                    ans = sum;
                    index = markings[i].first;
                }
                pre = markings[i].first;
                i = j - 1;
            }
        }
        cerr << ans << endl;
        return index;
    }
};


int main() {

    Flask flask = Flask();
    cout << flask.chooseAFlask({4,6,6,7}, 3, {{0,3}, {0,5}, {0,7}, {1, 6}, {1,8},{1,9}, {2,3}, {2,5}, {2,6}}) << endl;

    return 0;
}

/*

Time complexity: O(m*n)

*/
