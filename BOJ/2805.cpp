#include <bits/stdc++.h>
using namespace std;


// 이 문제에서 나올 수 있는 가장 큰 나무 길이는
// (나무의 최대 개수) * (나무의 최대 높이)
// 이 값이 int의 최댓값을 한참 넘기 때문에 long long 자료형 필수 
long long caculateLength(vector<int>& trees, int height) {
  long long ans = 0;
  for (int i = 0; i < trees.size(); i++) {
    if (trees[i] > height) {
      ans += trees[i] - height;
    }
  }

  return ans;
}

int main() {

  ios::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  int num;
  int target;
  cin >> num >> target;

  auto trees = vector<int>(num, 0);

  int low = 0;
  int high = 0;

  for (int i = 0; i < num; i++) {
    cin >> trees[i];
    if (trees[i] > high) {
      high = trees[i];
    }
  }

  int ans = 0;


  while (low <= high) {
    int mid = (low + high) / 2;

    long long product = caculateLength(trees, mid);

    if (product >= target) {
      // product가 target보다 크면 일단 정답 후보로 저장함.
      // 그럼에도 더 좋은 값이 있는지 탐색하기 위해 탐색 범위를 mid보다 1큰 범위로 좁힘
      ans = mid;
      low = mid + 1;
    } else if (product < target) {
      high = mid - 1;
    } 
  }

  cout << ans;
}