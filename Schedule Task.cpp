/*
Problem link:  https://aonecode.com/interview-question/schedule-tasks

*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int scheduleTask(int task, vector<int> powers) {
    priority_queue<int> pq;
    for (auto p : powers) {
        pq.push(p);
    }
    int steps = 0;
    while (task > 0) {
        steps++;
        int top = pq.top();
        pq.pop();
        task -= top;
        top /= 2;
        pq.push(top);
    }
    return steps;
}


int main() {
    cout << scheduleTask(19, {4,2,8,3,5}) << endl;
    return 0;
}

