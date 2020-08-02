#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int idx = 0;
    int min = 2100000000;
    for(int i = 0;i<arr.size();i++){
        if(arr[i] < min){
            idx = i;
            min = arr[i];
        }
    }
    for(int i = 0;i<arr.size();i++){
        if(i != idx) answer.push_back(arr[i]);
    }
    if(answer.size() == 0)
        answer.push_back(-1);
    return answer;
}
