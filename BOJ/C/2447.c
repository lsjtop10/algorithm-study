#include <stdio.h>
#include <stdlib.h>

char res[7000][7000];

// 가운데(2차원 배열을 가로-세로 3등분 했을 때 1행, 1열)만 제외하고 나머지를
// ch로 채우는 함수
void print(int rs, int re, int cs, int ce, char ch) {
  // printf("function is called. rs:%d, re: %d, cs:%d, ce:%d, ch:%c \n",
  // rs,re,cs,ce,ch);
  int size = re - rs + 1;
  if (size <= 1) {
    res[rs][cs] = ch;
    // printf("%d %d filled with %c\n", rs,cs,ch);
    return;
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      char fill = ch;
      if (i == 1 && j == 1) {
        fill = ' ';
      };

      int nextSize = size / 3;

      // printf("loop dumping i:%d j:%d fill: %c\n", i,j,fill);
      print(rs + (nextSize * i), rs + (nextSize * (i + 1)) - 1,
            cs + (nextSize * j), cs + (nextSize * (j + 1)) - 1, fill);
    }
  }
}

int main() {
  int size;
  scanf("%d", &size);
  print(0, size - 1, 0, size - 1, '*');
  for (int i = 0; i < size; i++) {
    puts(res[i]);
  }
}