#pragma warning(disable : 4996)
#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        map<int, int> mp;
        int ans = 0;
        int head = 0, tail = 0;
        while (head < n && tail <= head){
            mp[nums[head]]++;
            if(mp[nums[head]] <= k){
                ans = max(ans, head - tail + 1);
                head++;
            } else {
                while(mp[nums[head]] > k){
                    mp[nums[tail]]--;
                    tail++;
                }
                ans = max(ans, head - tail + 1);
                head++;
            }
        } 
        return ans;
    }   
};