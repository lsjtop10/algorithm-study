#include <bits/stdc++.h>
using namespace std;
constexpr int UNDEFINED = -1;
constexpr int BLUE = 1;
constexpr int WHITE = 0;

// 만약에 선택한 범위가 정사각형 모양의 색종이라면
// 색 코드 반환
// 아니면 -1 반환
int sectorColor(vector<vector<int>>& map, int startRow, int startCol,
                int length) {
  int color = map[startRow][startCol];

  for (int i = startRow; i < startRow + length; i++) {
    for (int j = startCol; j < startCol + length; j++) {
      if (color != map[i][j]) {
        return -1;
      }
    }
  }

  return color;
}

struct task {
  int row;
  int col;
  int length;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // 한 변의 길이
  int l;
  cin >> l;
  auto data = vector<vector<int>>(l, vector<int>(l, 0));

  for (int i = 0; i < l; i++) {
    for (int j = 0; j < l; j++) {
      cin >> data[i][j];
    }
  }

  stack<task> tasks;
  tasks.push(task{0, 0, l});

  int cntBlue = 0;
  int cntWhite = 0;

  while (!tasks.empty()) {
    struct task current = tasks.top();
    tasks.pop();

    int color = sectorColor(data, current.row, current.col, current.length);

    if (color == WHITE) {
      cntWhite++;
    } else if (color == BLUE) {
      cntBlue++;
    } else {
      int half = current.length / 2;

      for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
          tasks.push(
              task{current.row + (half * i), current.col + (half * j), half});
        }
      }
    }
  }

  cout << cntWhite << "\n";
  cout << cntBlue << "\n";
}