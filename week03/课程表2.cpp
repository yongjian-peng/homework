/**
 * [210.] 课程表 II
 */
#include <bits/stdc++.h>

using namespace std;

/**
输入：numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
输出：[0,2,1,3]
 */
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequistites) {
        to = vector<vector<int> >(numCourses, vector<int>());
        inDeg = vector<int>(numCourses, 0);
        for (vector<int>& pre : prerequistites) {
            int ai = pre[0];
            int bi = pre[1];
            to[bi].push_back(ai);
            to[ai].push_back(bi);
            inDeg[ai]++; // 数组的度增加
        }

        queue<int> q;
        // 从拓扑排序第一步：从零度出发
        for (int i = 0; i < numCourses; i++) {
            if (inDeg[i] == 0)
                q.push(i);   
        }
        vector<int> lessons;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            lessons.push_back(x);
            // 第二步：扩展一个点，周围的点入度减一
            for (int y : to[x]) {
                inDeg[y]--;
                // 第三步：入度减为0 表示可以入队了 课程就是最早先修的 不依赖其他门课程了
                if (inDeg[y] == 0) {
                    q.push(y);
                }
            }
        }
        // 如果得到的顺序的长度 和 课程门数一样，说明不存在环，则返回课程
        if (lessons.size() == numCourses) {
            return lessons;
        } else {
            return {};
        }
    }

private:
    vector<int> inDeg; // 数组元素的度
    vector<vector<int>> to; // 出边数组
}