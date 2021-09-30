#include <bits/stdc++.h>

using namespace std;
// 接雨滴
class Trap {
    public:
        int trap(vector<int>& heights) {
            // 以竖条累加，每个竖条最多能盛多少水 盛的是左右也是前缀 后缀（最大值）维护两个max（前缀 后缀最大值）
            int n = heights.size();
            preMax = vector<int>(n);
            sufMax = vector<int>(n);
            preMax[0] = heights[0];

            for (int i = 1; i < n; i++) {
                preMax[i] = max(preMax[i - 1], heights[i]);
            }

            sufMax[n - 1] = heights[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                sufMax[i] = max(sufMax[i + 1], heights[i]);
            }

            int ans = 0;
            for (int i = 1; i < n - 1; i++) {
                int up = min(preMax[i - 1], sufMax[i + 1]);
                int bottom = heights[i];
                if (up > bottom) {
                    ans += up - bottom;
                }
            }

            return ans;
        }

    private:
        vector<int> preMax;
        vector<int> sufMax;

};