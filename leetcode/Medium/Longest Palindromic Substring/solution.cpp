// https://leetcode.com/problems/longest-palindromic-substring
class Solution {
public:
    string longestPalindrome(string s) {
    string ans = s.substr(0,1);
    if(s.size() == 2) {
        if(s[0] == s[1]) ans = s;
    }
    int n = s.size();
    int dp[1010][1010] = {0};
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for(int i = 0; i < n - 1; i++) {
        dp[i][i+1] = (s[i] == s[i+1]);
        if(dp[i][i+1]) ans = s.substr(i, 2);
    }
    for(int l = 2;l<n;l++){
        int start = 0, end = l;
        while(end < n){
            dp[start][end] = dp[start+1][end-1] && (s[start] == s[end]);
            if(dp[start][end]){
                ans = s.substr(start, end-start+1);
            }
            start++;
            end++;
        }
    }
    return ans;

    }
};