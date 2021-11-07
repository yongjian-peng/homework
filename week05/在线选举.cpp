/**
 * [911.] 在线选举
 *输入：["TopVotedCandidate","q","q","q","q","q","q"], [[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
输出：[null,0,1,1,0,0,1]
解释：
时间为 3，票数分布情况是 [0]，编号为 0 的候选人领先。
时间为 12，票数分布情况是 [0,1,1]，编号为 1 的候选人领先。
时间为 25，票数分布情况是 [0,1,1,0,0,1]，编号为 1 的候选人领先（因为最近的投票结果是平局）。
在时间 15、24 和 8 处继续执行 3 个查询。
链接：https://leetcode-cn.com/problems/online-election
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
    TopVotedCandidate(vector<int> &persons, vector<int> &times)
    {
        this->persons = persons;
        this->times = times;
        maxPersons = vector<int>(persons.size());

        vector<int> count = vector<int>(persons.size() + 1); // 统计各个候选人得票次数
        int curPerson = persons[0]; // 当前候选人编号
        int maxCount = 1; // 当前候选人得票数
        for (int i = 0; i < persons.size(); i++)
        {
            // 类似于散列表，比如 persons[i] 是 2 号候选人 候选人 ： 票数 映射关系
            // 那么 我们在 count 数组中的 2 号 下标 给他加上一票
            count[persons[i]]++;
            if (count[persons[i]] >= maxCount)
            {
                curPerson = persons[i];
                maxCount = count[persons[i]];
            }
            maxPersons[i] = curPerson;
        }
    }

    int q(int t)
    {
        int left = 0, right = times.size() - 1;
        while (left < right)
        {
            int mid = (left + right + 1) >> 1;
            if (times[mid] <= t)
            {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return maxPersons[left];
    }

private:
    vector<int> persons;
    vector<int> times;
    vector<int> maxPersons; // 获胜人员数组 取下标 即等于 下标代表获胜的候选人
}