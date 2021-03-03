/*
Problem link: https://aonecode.com/interview-question/tagging-system

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class TaggingSystem {
public:
    TaggingSystem(string originalTag) {
        this->originalTag = originalTag;
    }

    string getTaggingSystem(int limit) {
        int n = originalTag.size();
        sort(originalTag.begin(), originalTag.end(), greater<char>());
        int cnt = 0;
        int j = 0;
        char pre = '\0';
        for (int i = 0; i < n; i++) {
            if (pre == originalTag[i]) {
                cnt++;
            } else {
                cnt = 1;
            }
            if (cnt > limit) {
                while (j < n && originalTag[j] == originalTag[i]) {
                    j++;
                }
                if (j == n) return "";
                cnt = 0;
                swap(originalTag[i], originalTag[j]);
            }
            pre = originalTag[i];
        }
        return originalTag;
    }


private:
    string originalTag;
};

int main() {

    TaggingSystem ts = TaggingSystem("cbdlslslslslslslslslsllsdd");
    cout << ts.getTaggingSystem(2) << endl;

    return 0;
}
