#include <string>
#include <vector>

using namespace std;
int dist[12][12] ={0,};
void pre(){
    dist[2][1] = dist[2][3] = dist[5][4] = dist[5][6] = dist[8][7] = dist[8][9] = dist[0][10] = dist[0][11] = 1;
    dist[2][4] = dist[2][6] = dist[5][1] = dist[5][3] = dist[5][7] =
        dist[5][9] = dist[8][4] = dist[8][6] = dist[8][10] = dist[8][11] = dist[0][7] = dist[0][9] = 2;
    dist[2][7] = dist[2][9] = dist[5][10] = dist[5][11] = dist[8][1] = dist[8][3] = dist[0][4] = dist[0][6] = 3;
    dist[2][10] = dist[2][11] = dist[0][1] = dist[0][3] = 4;
    dist[2][5] = dist[5][8] = dist[8][0] = dist[0][8] = dist[8][5] = dist[5][2] = 1;
    dist[2][8] = dist[5][0] = dist[0][5] = dist[8][2] = 2;
    dist[2][0] = dist[0][2] = 3;
    
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    pre();
    int left_last = 10;
    int right_last = 11;
    for(int i = 0;i<numbers.size();i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
            left_last = numbers[i];
            answer += 'L';
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
            right_last = numbers[i];
            answer += 'R';
        }
        else{
            int left_dis = dist[numbers[i]][left_last];
            int right_dis = dist[numbers[i]][right_last];
            if(left_dis < right_dis){
                left_last = numbers[i];
                answer += 'L';
            }
            else if(right_dis < left_dis){
                right_last = numbers[i];
                answer += 'R';
            }
            else{
                if(hand == "right"){
                    right_last = numbers[i];
                    answer += 'R';
                }
                else{
                    left_last = numbers[i];
                    answer += 'L';
                }
            }
        }
    }
    return answer;
}
