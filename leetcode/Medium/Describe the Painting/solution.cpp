#pragma warning(disable : 4996)
#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/describe-the-painting

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<long long, long long> mp;
        vector<vector<long long>> ans;
        for (auto &s : segments) {
            mp[s[0]] += s[2];
            mp[s[1]] -= s[2];
        }
        long long prev = 0, sum = 0;
        for (auto &m : mp) {
            if (sum) ans.push_back({prev, m.first, sum});
            sum += m.second;
            prev = m.first;
        }
        return ans;
    }
};