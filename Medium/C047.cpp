#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int frame = 0, ans = 0, check = 0;
  string str;
  cin >> str;
  // 문자열에서 i번째 문자를 탐색 하며 10 프레임까지만 탐색
  for (int i = 0; frame < 10; i++) {
    if (str[i] >= 49 && str[i] <= 57) { // 숫자인 경우
      ans += str[i] - '0'; // 점수 추가
      if (check) { // 두 번째 투구인 경우
        check = 0; // 체크 0으로 초기화
        frame++; // 프레임 증가
      } else { // 첫 번째 투구인 경우
        check = 1; // 체크 1로 할당
      }
    } else if (str[i] == 'S') { // 스트라이크인 경우
      ans += 10; // 10점 추가
      frame++; // 프레임 증가
      for (int j = 1; j < 3; j++) { // 다음 두 번의 투구에 대한 탐색
        if (str[i + j] >= 49 && str[i + j] <= 57) { // 숫자인 경우
          ans += str[i + j] - '0'; // 점수 추가
        } else if (str[i + j] == 'S') { // 스트라이크인 경우
          ans += 10; // 10점 추가
        } else if (str[i + j] == 'P') { // 스페어인 경우
          if (str[i + j - 1] >= 49 && str[i + j - 1] <= 57) { // 이전 투구가 숫자면
            ans += 10 - (str[i + j - 1] - '0'); // 10 - 이전 투구 점수 추가
          } else { // 이전 투구가 '-' 즉, 거터라면
            ans += 10; // 10점 추가
          }
        }
      }
    } else if (str[i] == 'P') { // 스페어인 경우
      check = 0; // 체크 0으로 초기화
      frame++; // 프레임 증가
      if (str[i - 1] >= 49 && str[i - 1] <= 57) { // 이전 투구가 숫자면
        ans += 10 - (str[i - 1] - '0'); // 10 - 이전 투구 점수 추가
      } else { // 이전 투구가 '-' 즉, 거터라면
        ans += 10; // 10점 추가
      }
      if (str[i + 1] >= 49 && str[i + 1] <= 57) { // 다음 투구가 숫자라면
        ans += str[i + 1] - '0'; // 점수 추가
      } else if (str[i + 1] == 'S') { // 다음 투구가 스트라이크라면
        ans += 10; // 10점 추가
      }
    } else { // 거터라면
      if (check) { // 두 번째 투구인 경우
        check = 0; // 체크 0으로 초기화
        frame++; // 프레임 증가
      } else { // 첫 번째 투구인 경우
        check = 1; // 체크 1로 할당
      }
    }
  }
  // 점수 출력
  cout << ans << '\n';
  return 0;
}