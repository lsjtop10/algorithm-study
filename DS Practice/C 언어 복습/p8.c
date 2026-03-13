#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[8];

  int korean_score;
  int english_score;
  int meth_score;

  float average_score;
} Student;

int max(int size, ...) {
  va_list nums;

  va_start(nums, size);

  int max = va_arg(nums, int);

  for (int i = 0; i < size - 1; i++) {
    int val = va_arg(nums, int);

    if (val > max) {
      max = val;
    }
  }

  return max;
}

int min(int size, ...) {
  va_list nums;

  va_start(nums, size);

  int min = va_arg(nums, int);

  for (int i = 0; i < size - 1; i++) {
    int val = va_arg(nums, int);

    if (val < min) {
      min = val;
    }
  }

  return min;
}

int main() {
  int size;
  scanf("%d", &size);
  Student* arr = malloc(sizeof(Student) * size);
  if(arr == NULL){
    return 1;
  }

  for (int i = 0; i < size; i++) {
    scanf("%s %d %d %d", arr[i].name, &arr[i].korean_score,
          &arr[i].english_score, &arr[i].meth_score);
    arr[i].average_score =
        (arr[i].korean_score + arr[i].english_score + arr[i].meth_score) / 3.0f;
  }

  for (int i = 0; i < size; i++) {
    printf("%s %.1f ", arr[i].name, arr[i].average_score);

    if (max(3, arr[i].korean_score, arr[i].english_score, arr[i].meth_score) >
        90) {
      printf("GREAT ");
    }

    if (min(3, arr[i].korean_score, arr[i].english_score, arr[i].meth_score) <
        70) {
      printf("BAD\n");
    }
  }
}