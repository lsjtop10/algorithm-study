#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// C언어 기본 자료형에는 bool이 없지만 stdbool 헤더를 include해서
// 코드 상에 명확한 의도를 표현할 수 있도록 한다.
#include <stdbool.h>

// ERR
// 에러 코드를 상수로 정의해서 호출자에서 에러를 처리할 수 있도록 한다.
//---------------------------------------------------------------------------

typedef int err;

#define OK 0
#define ERR_STACK_IS_EMPTY 1
#define ERR_STACK_IS_FULL 2

void printErr(err err) {
    switch (err) {
    case ERR_STACK_IS_EMPTY:
        printf("ERR: Stack is empty \n");
        break;

    case ERR_STACK_IS_FULL:
        printf("ERR: Stack is full \n");
        break;
    }
}

//---------------------------------------------------------------------------

// Stack구현부
//---------------------------------------------------------------------------

// configuration
#define STACK_MAX_ELEMENTS 100
#define STACK_ELEMENT_ZERO                                                     \
    0 // element의 zero value를 설정함. 빈 값을 반환할 수 없으니 안전하게

typedef char element;
// 반환할 값을 정의함

typedef struct {
    element arr[STACK_MAX_ELEMENTS];
    int top;
} StackType; // 강의 시간 컨벤션 준수: 각 ADT의 핵심 타입에는 Type으로 끝낸다.

// ADT의 연산을 담당하는 함수 이름 앞에는 ADT의 대상 데이터 타입을 접두어로
// 붙이겠다. 이러한 규칙을 통해서 여러 데이터 타입을 동시에 구현하는 경우에
// namespace 충돌을 방지한다.(isEmpty, isFull함수 등)

void stack_init(StackType *s);
element stack_pop(StackType *s, err *err);
void stack_push(StackType *s, element e, err *err);
bool stack_isFull(StackType *s);
bool stack_isEmpty(StackType *s);
element stack_peek(StackType *s, err *err);

void stack_init(StackType *s) { s->top = -1; }

bool stack_isFull(StackType *s) {
    if (s->top >= STACK_MAX_ELEMENTS - 1) {
        return true;
    }
    return false;
}

bool stack_isEmpty(StackType *s) {
    if (s->top == -1) {
        return true;
    }
    return false;
}

void stack_push(StackType *s, element e, err *err) {
    if (stack_isFull(s)) {
        *err = ERR_STACK_IS_FULL;
        return;
    }

    s->top++;
    s->arr[s->top] = e;
}

element stack_pop(StackType *s, err *err) {
    if (stack_isEmpty(s)) {
        *err = ERR_STACK_IS_EMPTY;
        return STACK_ELEMENT_ZERO;
    }

    element e = s->arr[s->top];
    s->top--;
    return e;
}

element stack_peek(StackType *s, err *err) {
    if (stack_isEmpty(s)) {
        *err = ERR_STACK_IS_EMPTY;
        return STACK_ELEMENT_ZERO;
    }

    return s->arr[s->top];
}

// 중위 표기법 변환 구현
//---------------------------------------------------------------------------
/*
연산자의 글자 수가 2자 이상일 수도 있기 때문에 강의처럼 간단하게 char형으로
구현할 수 없음.. 이를 해결하려면 방법1: op라는 새로운 구조체를 정의하고 op에
char[]를 포함하도록 해 연산자를 표현하는 방법
방법2: 아니면 OP를 파싱해서 연산자를 숫자로 매핑해 토큰 단위로 표현하는 방법\
예시:

typedef int op

#define OP_PLUS 1
#define OP_MINUS 2
#define OP_MUL 3
...
방법3:
다른 아스키 코드로 치환하는 방법-구글 검색에서 확인함
문제 조건은 대문자이므로 && -> 'a' || -> 'o'로 치환하면 char 형으로도 모든
연산자를 표현할 수 있음 마찬가지로 이항 연산자 +와 단항 연산자+는 'p', 단항
연산자 -는 'm'으로 치환하면 표현 가능

전자는 stack의 element를 구조체 형식으로 바꿔야하지만 후자는 토큰을 숫자로
매핑하므로 Stack Element를 숫자 형식으로 유지할 수 있다. 하지만 두 개의 다른
type의 stack이 필요하지 않으니까 문제는 없음.

입력을 보니까 토큰끼리 공백으로 구분되지 않음 -> 어차피 파싱은 구현해야 함.
모든 연산자를 숫자로 매핑하는 것보다는 치환을 이용해 문자로 구현하는 방식이 더
간단하다고 판단했다.

중위표현식에 단항연산자도 고려해야 할까?
식 중간에 단항연산자가 올 수 있을까?
입력 예시에는 없긴해서 일단 빼고 구현하고 나중에 추가하는 것으로 함
*/

int prec(char op);
bool isOperand(char c);
bool isOperator(char c);
void printOperator(char c);

// 연산자 우선순위 구하는 코드
int prec(char op) {
    // 단항연산자
    if (strchr("!pm", op)) {
        return 6;
    } else if (strchr("*/", op)) {
        return 5;
    } else if (strchr("+-", op)) {
        return 4;
    } else if (strchr("<>", op)) {
        return 3;
    } else if (op == 'a') { //&&
        return 2;
    } else if (op == 'o') { // ||
        return 1;
    }else{
        return 0;
    }
}

bool isOperand(char c) {
    if ('A' <= c && c <= 'Z') {
        return true;
    }
    return false;
}

bool isOperator(char c) {
    if (c < 'A' || c > 'Z') {
        return true;
    }
    return false;
}

void printOperator(char encodedOP) {

    switch (encodedOP) {
    case 'a':
        printf("%s", "&&");
        break;
    case 'o':
        printf("%s", "||");
        break;
    case 'p':
        printf("%c", '+');
        break;
    case 'm':
        printf("%c", '-');
        break;
    case '(':
        break;
    default:
        printf("%c", encodedOP);
    }
}

void printInfixToPostPrefix(char str[], err *err) {
    StackType s;
    stack_init(&s);
    int len = strlen(str);

    char prev_char;
    char current_char = str[0];
    char prev = '\0';

    // 맨 처음에 나오는 연산자는 단항 연산자밖에 없음
    if (isOperator(current_char)) {
        if (current_char == '+') {
            stack_push(&s, 'p', err);
        } else if (current_char == '-') {
            stack_push(&s, 'm', err);
        } else {
            stack_push(&s, current_char, err);
        }
        if (*err != OK) {
            return;
        }
    } else {
        printf("%c", current_char);
    }

    for (int i = 1; i < len; i++) {
        char encoded_op = '\0';

        prev_char = current_char;
        current_char = str[i];

        if (isOperand(current_char)) {
            // 피연산자는 그대로 출력
            printf("%c", current_char);
            continue;
        }

        // 현재 연산자를 한 글짜 문자로 인코딩
        if (strchr("&|", current_char) && strchr("&|", str[i + 1])) {
            // 연속으로 &또는 |이 나오는 경우는 &&또는 ||이라고 할 수 있다.
            // 물론 &|이거나 |&인 경우도 있을 수 있지만 문제 조건 상 그런 상황은
            // 있을 수 없다.
            switch (current_char) {
            case '&':

                /* code */
                encoded_op = 'a';
                break;

            case '|':
                encoded_op = 'o';
                break;
            }

            // 다음에 나올 & 또는 |가 중복처리되지 않도록 i 1증가시킨다.
            i++;
        } else if (isOperator(prev_char) && prev_char != ')' &&
                   strchr("+-", current_char)) {
            // 앞선 글짜가 닫는 괄호를 제외한 임의의 연산자이고 뒤 글짜가
            // +.-일 때 뒤의 +, -는 단항 연산자이다. 입력 예시에는 해당 케이스가
            // 없지만 문제 조건에서 단항 연산자가 있을 수 있으므로 풀이에서
            // 고려하도록 한다.
            //  생각해보니까 A++B와 같은 수식은 의미가 없다.
            // 왜냐하면 후의표기법으로 변환했을 때 AB++이 되는데 첫 번째
            // 연산자가 단항 연산자이고 두 번째 연산자는 이항 연산자이다. 그런데
            // 변환된 결과만 보고서는 이 +연산자가 단항연산자인지 이항연산자인지
            // 알 방법이 없다. A+-B와 같은 수식도 마찬가지이다. 때문에 단항
            // 연산자가 올 수 있는 자리는 한정돼 있다. 사실상 맨 앞에만 올 수
            // 있다고 봐야 하고 그렇지 않다면 단항연산자 +-와 이항연산자 +-가
            // 출력 상으로 구분돼야 한는데 문제 조건에 해당 부분은 명시돼있지
            // 않다.

            switch (current_char) {
            case '+':
                encoded_op = 'p';
                break;
            case '-':
                encoded_op = 'm';
                break;
            }
        } else {
            // !은 반드시 단항 연산자이다.
            // ) 뒤 + - 는 이항 연산자이다.
            //
            encoded_op = current_char;
        }

        // 연산자에 따른 처리

        // 여는 괄호는: 무조건 PUSH
        // 닫는 괄호는: 여는 괄호가 나올 때까지 POP
        // 여기에서 보면 여는 괄호와 닫는 괄호를 제외하고 모든 연산자에서
        // 공통적인 동작이 발생한다.
        // 1. Stack이 비어있으면 Push
        // 2. Stack이 비어있지 않으면
        // 2.1 자기보다 우선순위가 작거나 같은 연산자를 모두 POP해서 출력
        // Why? 연산자가 먼저 계산돼야 하니까.
        // 그 자리에 Push
        // 아 그런데 이렇게 하면 !!(A+B) + C와 같은 입력값에서 문제가 생긴다.
        if (encoded_op == '(') {
            stack_push(&s, encoded_op, err);
            if (*err != OK) {
                return;
            }
        } else if (encoded_op == ')') {
            char stack_op;
            while ((stack_op = stack_peek(&s, err)) != '(') {
                if (*err != OK) {
                    return;
                }

                printOperator(stack_op);

                stack_pop(&s, err);
                if (*err != OK) {
                    return;
                }
            }
            stack_pop(&s, err);
            if (*err != OK) {
                return;
            }
        } else {
            while (!stack_isEmpty(&s)) {
                char stack_op = stack_peek(&s, err);
                if (*err != OK) {
                    return;
                }

                // 현재 연산자가 우선순위가 더 높으면
                // 동치: stack의 연산자가 현재 연산자보다 나중에 계산돼야 하면
                // pop하지 말고 현재 연산자를 PUSH해야 함.
                // 일단 '!'인 경우에도 탈출하도록 조건 수정해서 회피. 다만
                // 근본적 해결책은 아닌 것 같다.
                if ((stack_op == '!' && encoded_op == '!') ||
                    prec(encoded_op) > prec(stack_op)) {
                    break;
                }

                stack_pop(&s, err);
                printOperator(stack_op);
                if (*err != OK) {
                    return;
                }
            }

            stack_push(&s, encoded_op, err);
            if (*err != OK) {
                return;
            }
        }
    }

    while (!stack_isEmpty(&s)) {
        printOperator(stack_pop(&s, err));
        if (*err != OK) {
            return;
        }
    }
}

//---------------------------------------------------------------------------

int main() {
    err err = OK;
    int num;
    printf("수식을 입력하세요.");
    scanf("%d", &num);
    // null문자까지 고려해서 101개 할당. 마지막에는 null문자 들어가야 함.
    char exprInput[101];

    for (int i = 0; i < num; i++) {
        scanf("%s", exprInput);

        printInfixToPostPrefix(exprInput, &err);
        printf("\n");
        if (err != OK) {
            printErr(err);
            return -1;
        }

        // 다음 입력을 받기 전 모두 초기화
        memset(exprInput, 0, sizeof(exprInput));
    }
}