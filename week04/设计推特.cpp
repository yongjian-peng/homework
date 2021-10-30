
/**
 * [355.] 设计推特 使用 hash + 栈 
 * 链接：https://leetcode-cn.com/problems/design-twitter
 */
#include <bits/stdc++.h>

using namespace std;

/**
输入
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
输出
[null, null, [5], null, null, [6, 5], null, [5]]
    */
class Twitter
{
public:
    Twitter() {

    }

    void postTweet(int userId, int tweetId) {
        tws.push({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        stack<pair<int, int> > tmp = tws;
        while (ans.size() < 10 && !tmp.empty()) {
            pair<int, int> tw = tmp.top();
            // 看看是不是自己发送的 或者 是不是自己关注的人发送的
            if (tw.first == userId || (folls[userId].count(tw.first))) {
                ans.push_back(tw.second);
            }
            tmp.pop();
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        folls[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        auto it = folls.find(followerId);
        if (it != folls.end()) {
            folls[followerId].erase(followeeId);
        }
    }

private:
    // 账号 -> 关注的账号；使用set 可以避免重复关注的时候重复插入
    unordered_map<int, unordered_set<int> > folls;
    // 发送的推特 用户id 推特id
    stack<pair<int, int> > tws;
}