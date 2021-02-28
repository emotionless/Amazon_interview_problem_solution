/*
Problem link: https://aonecode.com/amazon-online-assessment-rover-control

A Mars rover is directed to move within a square matrix. It accepts a sequence of commands to move in any of the four directions from each cell: [UP, DOWN, LEFT or RIGHT]. The rover starts from cell 0. and may not move diagonally or outside of the boundary.

Each cell in the matrix has a position equal to:
(row * size) + column
where row and column are zero-indexed, size = row length of the matrix.

Return the final position of the rover after all moves.

Example
n = 4
commands = [RIGHT, UP, DOWN, LEFT, DOWN, DOWN]

The rover path is shown below.

0	1	2	3
4	5 	6 	7
8 	9 	10 	11
12 	13 	14 	15

RIGHT: Rover moves to position 1
UP: Position unchanged, as the move would take the rover out of the boundary.
DOWN: Rover moves to Position 5.
LEFT: Rover moves to position 4
DOWN: Rover moves to position 8
DOWN: The rover ends up in position 12.

The function returns 12.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, pair<int, int>> dir;

int finalCells(int n, vector<string> cmds) {
    dir["RIGHT"] = {0, 1};
    dir["DOWN"] = {1, 0};
    dir["LEFT"] = {0, -1};
    dir["UP"] = {-1, 0};


    int x = 0, y = 0;
    for (auto cmd : cmds) {
        auto p = dir[cmd];
        int ax = x + p.first;
        int ay = y + p.second;
        if (ax < 0 || ax >= n || ay < 0 || ay >= n) continue;
        x = ax;
        y = ay;
    }
    return x*n + y;
}

int main() {
    vector<string> arr{ "RIGHT", "UP", "DOWN", "LEFT", "DOWN", "DOWN"};

    cout << finalCells(4, arr) << endl;

    return 0;
}
