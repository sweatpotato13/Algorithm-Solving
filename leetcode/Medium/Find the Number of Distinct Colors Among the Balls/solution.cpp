#pragma warning(disable : 4996)
#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> res;
        int n = queries.size();
        map<int, int> ball;
        map<int, int> color;
        for(int i = 0;i<n;i++){
            ball[i] = -1;
        }
        int ans = 0;
        
        for(int i = 0;i<n;i++){
            int a, b;
            a = queries[i][0];
            b = queries[i][1];
            if (ball[a] == -1) {
                ball[a] = b;
                color[b]++;
                if (color[b] == 1) {
                    ans++;
                }
            } else {
                color[ball[a]]--;
                if (color[ball[a]] == 0) {
                    ans--;
                }
                ball[a] = b;
                color[b]++;
                if (color[b] == 1) {
                    ans++;
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};