#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// C언어 기본 자료형에는 bool이 없지만 stdbool 헤더를 include해서
// 코드 상에 명확한 의도를 표현할 수 있도록 한다.
#include <math.h>
#include <stdbool.h>

// ERR
// 에러 코드를 상수로 정의해서 호출자에서 에러를 처리할 수 있도록 한다.
//---------------------------------------------------------------------------

typedef int err;

#define OK 0
#define ERR_STACK_IS_EMPTY 1
#define ERR_STACK_IS_FULL 2
#define ERR_EXPR_IS_FULL 3
#define ERR_DIVEDE_BY_0 4

void printErr(err err) {
    switch (err) {
    case ERR_STACK_IS_EMPTY:
        printf("ERR: Stack is empty \n");
        break;

    case ERR_STACK_IS_FULL:
        printf("ERR: Stack is full \n");
        break;
    case ERR_DIVEDE_BY_0:
        printf("ERR: The number is devided by 0 \n");
    }
}

// TermType 구현부
//---------------------------------------------------------------------------
#define EXPR_MAX_TERMS 50

#define TERM_TYPE_NUM 'n'
#define TERM_TYPE_OPERATOR 'o'

#define UNDNOWN 0
#define OPERATOR_PLUS 1
#define OPERATOR_MINUS 2
#define OPERATOR_MUL 3
#define OPERATOR_DIV 4
#define OPERATOR_L_PARNTHES 5
#define OPERATOR_R_PARNTHES 6

typedef struct _TermType {
    char type;
    int value;
} TermType;

int charToOpcode(char c) {
    switch (c) {
    case '+':
        return OPERATOR_PLUS;
    case '-':
        return OPERATOR_MINUS;
    case '*':
        return OPERATOR_MUL;
    case '/':
        return OPERATOR_DIV;
    case '(':
        return OPERATOR_L_PARNTHES;
    case ')':
        return OPERATOR_R_PARNTHES;
    default:
        return UNDNOWN;
    }
}

char opCodeToChar(int op) {
    switch (op) {
    case OPERATOR_PLUS:
        return '+';
    case OPERATOR_MINUS:
        return '-';
    case OPERATOR_MUL:
        return '*';
    case OPERATOR_DIV:
        return '/';
    case OPERATOR_L_PARNTHES:
        return '(';
    case OPERATOR_R_PARNTHES:
        return ')';
    default:
        return ' ';
    }
}
// 연산자 우선순위 구하는 코드
int term_prec(TermType *term) {

    switch (term->value) {
    case OPERATOR_MUL:
    case OPERATOR_DIV:
        return 3;
    case OPERATOR_PLUS:
    case OPERATOR_MINUS:
        return 2;
    default:
        return 1;
        break;
    }
}

int term_print(TermType *term) {
    if (term->type == TERM_TYPE_NUM) {
        printf("%d ", term->value);
    } else {
        printf("%c ", opCodeToChar(term->value));

    }
}

//---------------------------------------------------------------------------
// ExprType 구현부

//---------------------------------------------------------------------------
typedef struct ExprType {
    TermType arr[EXPR_MAX_TERMS];
    int size;
} ExprType;

void expr_init(ExprType *e) { e->size = 0; }

void expr_addTerm(ExprType *e, TermType t, err *err) {
    if (e->size >= EXPR_MAX_TERMS) {
        *err = ERR_EXPR_IS_FULL;
        return;
    }

    e->arr[e->size] = t;
    e->size++;
}

void expr_print(ExprType *e) {
    for (int i = 0; i < e->size; i++) {
        term_print(&e->arr[i]);
    }

    printf("\n");
}

//---------------------------------------------------------------------------

// Stack구현부
//---------------------------------------------------------------------------

// configuration
#define STACK_MAX_ELEMENTS 100
#define STACK_ELEMENT_ZERO (TermType){0, 0}
// element의 zero value를 설정함. 빈 값을 반환할 수 없으니 안전하게

typedef TermType element;
// 반환할 값을 정의함

typedef struct {
    element arr[STACK_MAX_ELEMENTS];
    int top;
} StackType; // 강의 시간 컨벤션 준수: 각 ADT의 핵심 타입에는 Type으로 끝낸다.

// ADT의 연산을 담당하는 함수 이름 앞에는 ADT의 대상 데이터 타입을 접두어로
// 붙이겠다. 이러한 규칙을 통해서 여러 데이터 타입을 동시에 구현하는 경우에
// namespace 충돌을 방지한다.(isEmpty, isFull함수 등)

bool stack_isFull(StackType *s) {
    if (s->top >= STACK_MAX_ELEMENTS - 1) {
        return true;
    }
    return false;
}

bool stack_isEmpty(StackType *s) {
    if (s->top <= -1) {
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

void stack_init(StackType* s){
    s->top = -1;
}
//---------------------------------------------------------------------------

// 전위표기법 - 후위표기법 변환 및 evaludaten 구현
//---------------------------------------------------------------------------

/*
수식을 어떻게 나타낼까?
- 어차피 피연산자의 범위의 제한이 없으므로 단순 숫자로 피연산자와 연산자를 모두
표현하는 것은 불가능
- Term 타입의 배열로 표현하는 방안을 고려
- 식 -> 토크나이징(term으로 표현) -> 변환 ->
*/


int min(int a, int b) {
    if (a > b) {
        return b;
    }

    return a;
}

char findNextCharPassingWhitespaces(char *str, int idx, int length) {

    int i = min(idx + 1, length - 1);
    while (i < length - 1 && isspace(str[i])) {
        i++;
    }
    return str[i];
}

int parseSignedNum(char *str, int start, int end) {
    bool isNeg = false;
    int val = 0;

    if (str[start] == '-') {
        isNeg = true;
        start++;
    }

    for (int i = start; i <= end; i++) {
        val = val * 10 + (str[i] - '0');
    }
    val = isNeg ? -val : val;

    return val;
}

// 앞선 문제에서는 Char형으로 모든 수식을 표현할 수 있었으나 지금은 불가능하므로
// 항들의 배열로 변경하기로 한다.
void parseExpr(char *str, ExprType *expr, err *err) {
    int n = strlen(str);
    int tokenStartPos = 0, tokenEndPos = 0;

    //-기호는 연산자이거나 부호 기호일 수 있다.
    // 식의 연산자는 곱하기, 나누기, 더하기, 빼기로 구성된다고 했기 때문에 -는
    // 숫자의 부호 아니면 빼기연산자이다.

    while (true) {
        if (tokenStartPos >= n) {
            break;
        }

        if (isspace(str[tokenStartPos])) {
            tokenStartPos++;
            tokenEndPos = tokenStartPos;
            continue;
        }

        // 숫자인 경우 숫자를 파싱한다.
        //  1. -기호 뒤에 바로 뒤 기호가 숫자인 경우
        //  2. 숫자로 시작하는 경우
        if ((str[tokenStartPos] == '-' &&
             isdigit(findNextCharPassingWhitespaces(str, tokenStartPos, n))) ||
            isdigit(str[tokenStartPos])) {

            // 아래 루프를 실행하면 endpos는 처음으로 만나는 숫자가 아닌 문자의
            // 위치를 가리킨다. 숫자가 아닌 문자는 널문자도 포함이기 때문에 범위
            // 설정에 유의.
            tokenEndPos++;
            while (tokenEndPos <= n && isdigit(str[tokenEndPos])) {
                tokenEndPos++;
            }

            // 이런 과정을 거치면 startpos는 부호기호 -를 가리키고
            // endpos는 숫자의 맨 뒷자리를 가리킨다.
            int val = parseSignedNum(str, tokenStartPos, tokenEndPos - 1);

            expr_addTerm(expr, (TermType){TERM_TYPE_NUM, val}, err);
            if (*err != OK) {
                return;
            }

            tokenStartPos = tokenEndPos;
        } else if (strchr("+-*/()", str[tokenStartPos])) {
            // 연산자인 경우
            expr_addTerm(expr,
                         (TermType){TERM_TYPE_OPERATOR,
                                    charToOpcode(str[tokenStartPos])},
                         err);
            if (*err != OK) {
                return;
            }

            tokenStartPos++;
            tokenEndPos = tokenStartPos;
        }
    }
}

void infixToPostFix(ExprType *infixExpr, ExprType *postfixExpr, err *err) {
    StackType s;
    stack_init(&s);
    TermType cur;
    int n = infixExpr->size;

    for (int i = 0; i < n; i++) {

        cur = infixExpr->arr[i];

        if (cur.type == TERM_TYPE_NUM) {
            expr_addTerm(postfixExpr, cur, err);
            if (*err != OK) {
                return;
            }
        } else if (cur.type == TERM_TYPE_OPERATOR) {
            TermType stackTerm;

            if (cur.value == OPERATOR_L_PARNTHES) {
                stack_push(&s, cur, err);
                if (*err != OK) {
                    return;
                }
            } else if (cur.value == OPERATOR_R_PARNTHES) {
                stackTerm = stack_pop(&s, err);
                if (*err != OK) {
                    return;
                }

                while (stackTerm.value != OPERATOR_L_PARNTHES) {
                    expr_addTerm(postfixExpr, stackTerm, err);
                    stackTerm = stack_pop(&s, err);
                    if (*err != OK) {
                        return;
                    }
                }
            } else {
                // 자신보다 우선순위 높은 항 있으면 Pop
                while (!stack_isEmpty(&s)) {
                    stackTerm = stack_peek(&s, err);
                    if (*err != OK) {
                        return;
                    }

                    if (term_prec(&cur) <= term_prec(&stackTerm)) {
                        expr_addTerm(postfixExpr, stackTerm, err);
                        stack_pop(&s, err);
                        if (*err != OK) {
                            return;
                        }
                    } else {
                        break;
                    }
                }

                stack_push(&s, cur, err);
                if (*err != OK) {
                    return;
                }
            }
        }
    }

    while (!stack_isEmpty(&s)) {
        expr_addTerm(postfixExpr, stack_pop(&s, err), err);
        if (*err != OK) {
            return;
        }
    }
}

int evaluate(ExprType *postfixExpr, err *err) {

    StackType s;
    stack_init(&s);

    TermType op1;
    TermType op2;
    int num;
    TermType cur;
    int n = postfixExpr->size;

    for (int i = 0; i < n; i++) {
        cur = postfixExpr->arr[i];
        if (cur.type == TERM_TYPE_NUM) {
            stack_push(&s, cur, err);
        } else if (cur.type == TERM_TYPE_OPERATOR) {
            op2 = stack_pop(&s, err);
            op1 = stack_pop(&s, err);
            if (*err != OK) {
                return 0;
            }

            switch (cur.value) {
            case OPERATOR_PLUS:
                num = op1.value + op2.value;
                break;
            case OPERATOR_MINUS:
                num = op1.value - op2.value;
                break;
            case OPERATOR_MUL:
                num = op1.value * op2.value;
                break;
            case OPERATOR_DIV:
                if(op2.value == 0){*err = ERR_DIVEDE_BY_0;}
                num = op1.value / op2.value;
                break;
            }

            stack_push(&s, (TermType){TERM_TYPE_NUM, num}, err);

            if (*err != OK) {
                return 0;
            }
        }
    }

    cur = stack_pop(&s, err);
    if (*err != OK) {
        return 0;
    }

    return cur.value;
}

//---------------------------------------------------------------------------

int main() {
    ExprType expr;
    expr_init(&expr);
    ExprType expr2;
    expr_init(&expr2);
    err err = OK;
    expr_init(&expr);

    char input[101];
    fgets(input, 101, stdin);

    parseExpr(input, &expr, &err);
    if (err != OK) {
        printErr(err);
    }

    infixToPostFix(&expr, &expr2, &err);
    if (err != OK) {
        printErr(err);
    }

    int val = evaluate(&expr2, &err);
    if (err != OK) {
        printErr(err);
    }

    printf("%d", val);
}