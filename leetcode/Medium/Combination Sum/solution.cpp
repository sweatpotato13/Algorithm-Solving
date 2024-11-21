#pragma warning(disable : 4996)
#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> result;
            vector<int> combination;
            function<void(int, int)> dfs = [&](int idx, int target) {
            if (target == 0) {
                result.push_back(combination);
                return;
            }
            if (target < 0) return;
            for (int i = idx; i < candidates.size(); i++) {
                combination.push_back(candidates[i]);
                dfs(i, target - candidates[i]);
                combination.pop_back();
            }
        };

        dfs(0, target);
        return result;
    }
}; 