#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.second == b.second) {
    return a.first < b.first;
  } else {
    return a.second < b.second;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int num;
  cin >> num;

  auto data = vector<pair<int, int>>(num);

  for (int i = 0; i < num; i++) {
    cin >> data[i].first >> data[i].second;
  }

  sort(data.begin(), data.end(), compare);

  // 다음 시작 시각 < 현재 종료 시각
  // 이 조건을 만족하면서 다음 종료 시각이 가장 작은 것을 고르기

  int endLast = 0;
  int cnt = 0;

  for(int i = 0; i < num; i++){

    if(data[i].first >= endLast){
        endLast = data[i].second;
        cnt++;
    }
  }

  cout << cnt;
}