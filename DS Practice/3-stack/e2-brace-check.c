#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef char element;

//___type은 우리가 만들 최종 자료구조를 정의한 것임
typedef struct {
  element arr[N];
  int top;
} StackType;

void stack_init(StackType* s) {
  // 일반적으로는 -1로 놓고 시작한다.
  s->top = -1;
}

int isEmpty(StackType* s) { return s->top == -1; }

int isFull(StackType* s) { return s->top >= N - 1; }

void printStack(StackType* s) {
  for (int i = s->top; i >= 0; i--) {
    printf("|  %c  |\n", s->arr[i]);
    printf("-----\n");
  }
}

// 이미 주소를 받았으니까 그냥 받은 주소를 넘기면 됨
void push(StackType* s, element e) {
  if (isFull(s)) {
    printf("Overflow!");
    return;
  }

  s->top++;
  s->arr[s->top] = e;
}

element peek(StackType* s) {
  if (isEmpty(s)) {
    printf("empty\n");
  }

  return s->arr[s->top];
}

element pop(StackType* s) {
  if (isEmpty(s)) {
    printf("Empty\n");
    return -1;
  }

  element e = s->arr[s->top];
  s->top--;
  return e;
}

int check(char* str) {
  StackType s;
  stack_init(&s);

  char ch_str;
  char ch_stack;

  int n = strlen(str);
  for (int i = 0; i < n; i++) {
    ch_str = str[i];

    // 왼쪽이면 push
    if (ch_str == '(' || ch_str == '{' || ch_str == '[') {
      push(&s, ch_str);

    } else if (ch_str == ')' || ch_str == '}' || ch_str == ']') {
      // Stack이 비어있으면 -> 왼쪽 괄호가 나오기 전 오른쪽 괄호가 나옴
      if (isEmpty(&s)) {
        return 2;
      }

      ch_stack = pop(&s);
      // 연산자 우선순위가 AND가 더 높았나?
      // Pop한 괄호의 짝이 맞지 않으면 -> 포함관계 위반
      if ((ch_stack == '(' && ch_str != ')') ||
          (ch_stack == '{' && ch_str != '}') ||
          (ch_stack == '[' && ch_str != ']')) {
        return 3;
      }
    }
  }

  // Stack에
  if (!isEmpty(&s)) {
    return 1;
  }

  return 0;
}

int main() {
  char str[N];
  printf("Input Exper...");
  fgets(str, N, stdin);

  int res = check(str);
  if (res == 0) {
    printf("Check Passed.\n");
  } else {
    printf("Check Failed. Condition %d", res);
  }

  StackType s;
}
