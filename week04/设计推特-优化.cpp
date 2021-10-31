
/**
 * [355.] 设计推特 使用 map deque set  
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
        time = 0;
        maxFeed = 10;
    }

    void postTweet(int userId, int tweetId) {
        // 存入所发的推特的数据
        tweets[userId].push_back({time++, tweetId});
        if (tweets[userId].size() > maxFeed)
        {
            tweets[userId].pop_front();
        }
    }

    vector<int> getNewsFeed(int userId) {
        // 双端队列 保证是有序的
        priority_queue<pair<int, int>> feed;
        for (const auto& tweet : tweets[userId]) {
            feed.push(tweet);
        }

        for (const auto& user : subscriptions[userId]) {
            for (const auto& tweet : tweets[user]) {
                feed.push(tweet);
            }
        }

        vector<int> result;
        while(!feed.empty()) {
            if (result.size() == maxFeed) {
                break;
            }
            result.push_back(feed.top().second);
            feed.pop();
        }
        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            subscriptions[followerId].insert(followeeId);
        }
        
    }
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            auto it = subscriptions.find(followerId);
            if (it != subscriptions.end())
            {
                subscriptions[followerId].erase(followeeId);
            }
        }
    }

private:
    int time, maxFeed;
    unordered_map<int, deque<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> subscriptions;
}