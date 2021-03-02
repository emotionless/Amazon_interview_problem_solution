/*
Link: https://aonecode.com/amazon-online-assessment-lru

A virtual memory management system in an operating system at Amazon can use LeastRecently-Used (LRU) cache. When a requested memory page is not in the cache and the cache is full, the page that was least-recently-used should be removed from the cache to make room for the requested page. If the cache is not full, the requested page can simply be added to the cache and considered the most-recently-used page in the cache. A given page should occur at most once in the cache.

Given the maximum size of the cache and a list of page requests, write an algorithm to calculate the number of cache misses. A cache miss occurs when a page is requested and isn't found in the cache.

Input

The input to the function/method consists of three arguments:

num, an integer representing the number of pages;

pages, a list of integers representing the pages requested;

maxCacheSize, an integer representing the size of the cache.

Output

Return an integer representing the number of cache misses.
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getLRUCacheMisses(int num, int size, vector<int> pages) {
    int cnt = 0;
    vector<int> container;
    for (auto page : pages) {
        auto it = find(container.begin(), container.end(), page);
        if (it != container.end()) {
            container.erase(it);
        } else {
            cnt++;
            if (container.size() > size) {
                container.pop_back();
            }
        }
        container.push_back(page);
    }
    return cnt;
}

int main() {
    cout << getLRUCacheMisses(6, 2, {1,2,1,3,1,1}) << endl;
    return 0;
}
