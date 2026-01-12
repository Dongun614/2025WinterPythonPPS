#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

// 1. class 수를 받는다.
// 2. class 만큼 반복하면서 입력을 받는다.
// 3. 그 안에서 다시 수(student)를 받고 그 수만큼 반복하면서 수를 바든ㄴ다.
// 4. 그 수는 score[]라는 Int배열에 저장되고
// 5. score에서 평균을 계산한다.
// 6. score를 다시 돌면서 평균을 넘은 사람의 수를 센다(above_avg)
// 7. 그 수의 퍼센트를 계산해서 소수점 세 자리까지 출력한다.

double avg(vector<int>& score){ //vector를 참조로 받음
    int sum = 0;
    double avg;
    
    for(int i=0; i<score.size(); i++){
        sum += score[i];
    }
    
    avg = sum / (score.size()*1.0);
    
    return avg;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int class_count, student;
    double averg, above_avg_stat;
    int temp;
    
    cin >> class_count;
    
    for(int i=0; i<class_count; i++){
        vector<int> score;
        int above_avg_count = 0;
        cin >> student;
        score.reserve(student);

        for(int j=0; j<student; j++){
            cin >> temp;
            score.push_back(temp);
        }
        averg = avg(score);
        
        for(int j=0; j<score.size(); j++){
            if(score[j] > averg){
                above_avg_count++;
            }
        }

        above_avg_stat = above_avg_count / (score.size()*1.0) * 100;
        cout << fixed;
        cout.precision(3);
        cout << above_avg_stat << "%\n";
    }
    
    return 0;

}