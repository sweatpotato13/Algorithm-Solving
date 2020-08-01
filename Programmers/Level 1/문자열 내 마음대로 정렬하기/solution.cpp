#include <string>
#include <vector>

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
int global_n;
bool cmp(string a, string b){
    if(a[global_n] < b[global_n]){
        return true;
    }
    else if(a[global_n] > b[global_n]){
        return false;
    }
    else{
        if(a < b){
            return true;
        }
        else
            return false;
    }
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    global_n = n;
    sort(all(strings),cmp);
    answer = strings;
    return answer;
}
