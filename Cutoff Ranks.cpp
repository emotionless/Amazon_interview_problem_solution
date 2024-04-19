/*
Link: https://aonecode.com/amazon-online-assessment-cutoff-ranks


A group of work friends at Amazon is playing a competitive video game together. During the game, each player receives a certain amount of 
points based on their performance. At the end of a round, players who achieve at least a cutoff rank get to "level up" their character, 
gaining increased abilities for them. Given the scores of the players at the end of the round, how many players will be able to level up 
their character?

Note that players with equal scores will have equal ranks, but the player with the next lowest score will be ranked based on the position
within the list of all players' scores. For example, if there are four players, and three players tie for first place, their ranks would 
be 1,1,1, and 4. Also, no player with a score of O can level up, no matter what their rank.

Write an algorithm that returns the count of players able to level up their character.

Input

The input to the function/method consists of three arguments:

cutOffRank, an integer representing the cutoff rank for levelin up the player's character;

num, an integer representing the total number of scores;

scores, a list of integers representing the scores of the players.

Output

Return an integer representing the number of players who will be able to level up their characters at the end of the round.

Constraints

1 <= num <= 10^5

0 <= scores[i] <= 100

0 <= i < num

cutOffRank <= num

Examples

Example 1:

Input:

cutOffRank = 3

num= 4

scores=[100, 50, 50, 25 ]

Output:

3

Explanation:

There are num= 4 players, where the cutOffRank is 3 and scores = [100, 50,50, 25]. These players' ranks are [1, 2, 2, 4]. Because the 
players need to have a rank of at least 3 to level up their characters, only the first three players will be able to do so.

So, the output is 3.

Example 2:

Input:

cutOffRank = 4

num=5

scores=[2,2,3,4,5]

Output:

5

Explanation:

In order, the players achieve the ranks [4,4,3,2,1]. Since the cutOffRank is 4, all 5 players will be able to level up their characters.

So, the output is 5.
*/

#include <iostream>
#include <vector>

using namespace std;

int getCutOffRanks(int cutOffRanks, vector<int> scores)
{
    int n = scores.size();
    if (cutOffRanks >= n)
        return n;
    int ans = 0;
    int m = 0;
    for (int i = 0; i < n; i++) {
        m = max(m, scores[i]);
    }
    for (int i = m; i > 0; i--)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (scores[j] >= i)
            {
                cnt++;
            }
        }
        ans = cnt;
        if (ans >= cutOffRanks)
        {
            break;
        }
    }
    return ans;
}



int main()
{
    vector<int> arr{25, 23, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 76, 76, 80};

    cout << getCutOffRanks(2, arr) << endl;

    vector<int> arr1{0, 0, 0, 8, 19, 89};

    cout << getCutOffRanks(5, arr1) << endl;



    return 0;
}

/*
Time complexity: O(n*m) where n = number of players and m = maximum scores

*/
