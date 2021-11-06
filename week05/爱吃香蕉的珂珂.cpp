/**
 * [875.] 爱吃香蕉的珂珂
输入: piles = [3,6,7,11], H = 8
输出: 4
链接：https://leetcode-cn.com/problems/koko-eating-bananas/
 */
#include <bits/stdc++.h>

using namespace std;
class Solution
{
    /**
     * Your TopVotedCandidate object will be instantiated and called as such:
     * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
     * int param_1 = obj->q(t);
     */
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum = 0;
        int mx = 0;
        for (int pile : piles) {
            sum += pile;
            mx = max(mx, pile);
        }
        int left = sum / h, right = mx; // left 总香蕉数 / 小时 right 最大的堆数 有多少堆 吃多少小时
        while (left < right) {
            // 没小时吃多少香蕉 mid
            int mid = (left + right) >> 1;
            // ans 小时 吃完 香蕉
            int ans = validate(piles, mid);
            if (ans > h) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return right;
    }

private:
    int validate(vector<int>& piles, int k) {
        int h = 0; // 初始化小时
        if (k == 0)
            return INT_MAX;
        for (int pile : piles) {
            if (pile % k != 0) {
                h++;
            }
            h += (pile / k);
        }
        return h; 
    }
}