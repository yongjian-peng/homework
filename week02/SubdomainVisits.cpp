#include <bits/stdc++.h>

using namespace std;

class SubdomainVisits{
    public:
        vector<string> subdomainVisits(vector<string>& cpdomains) {
            // 使用 map 存储 域名 Key value 存储 数量
            for (auto& word : cpdomains) {
                // 找出第一个 空格 的位置
                int idx = word.find(' ');
                // 字符串切割 求访问数量
                int num = stoi(word.substr(0, idx));
                string dmName = word.substr(idx + 1); // 返回除了 数量的 后面的全部字符串
                while (idx > 0) {
                    cnt[dmName] += num;
                    idx = dmName.find('.');
                    // 依次向右，以 . 为单位 移动计算
                    dmName = dmName.substr(idx + 1);
                }
            }

            // 统计
            for (auto& c : cnt) {
                // 组合成 '100 domain.com' 格式 字符串 压入到 ans 数组中
                ans.push_back(to_string(c.second) + " " + c.first);
            }

            return ans;
        }

    private:
        vector<string> ans;
        unordered_map<string,int> cnt;
};