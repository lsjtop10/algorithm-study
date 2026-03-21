#include <stdio.h>
#include <stdlib.h>
/*
희소 다항식의 경우 메모리 낭비가 심함
예: 3x^100 + 1이면
0인 값이 많이 발생
*/

int pow(int x, int e){
    if(e == 0){
        return 1;
    }

    if(e % 2 == 0){
        return pow(x * x , e / 2);
    }else{
        return x * pow(x * x, (e - 1) / 2);
    }
}

// 계수 배열의 최고차항
// 기호 상수로 배열의 최대 크기를 미리 정하는 것이 편함
#define N 100

typedef struct  polynomianl{
    //최고차항
    int degree;
    //계수배열
    int coef[N];
} Poly;

int eval(Poly p, int x){
    int res = p.coef[0];

    for(int i = 1; i <= p.degree; i++){
        res += p.coef[i] * (int)pow(x, i);
    }
}

void print(Poly p, const char* str){
    printf("%s", str);
    //상수항 빼고 출력
    for( int i = p.degree; i > 0; i--){
        //%2d는 자릿수 제한?
        printf("%2dx^d + ", p.coef[i], i);
    }

    //상수항은 문자랑 "+"기호 없이 따로 출력 
    printf("%2d \n", p.coef[0]);

}

Poly add(Poly a, Poly b){
    Poly c;
    c.degree = a.degree > b.degree ? a.degree : b.degree;
    for(int i = 0; i <= c.degree; i++){
        // 초기화가 안 됐기 때문에 그냥 더하면 안 되고 쓰래기 값을 0으로 초기화해서 더하기
        // 유효한 범위의 값이면 사용하고, 유효하지 않은 범위의 값은 0으로 치환
        // 상수항부터 표현했기 때문에 이렇게 간단하게 처리 가능.
        c.coef[i] = ((i <= a.degree ? a.coef[i] : 0)) +
                     (i <= b.degree ? b.coef[i] : 0);
    }

    return c;
}


int main(){
    Poly a, b, res;
    scanf("%d %d", &a.degree, &b.degree);
    
    for(int i = a.degree; i >= 0; i--){
        scanf("%d", &a.coef[i]);
    }

    for(int i = b.degree; i >= 0; i--){
        scanf("%d", &b.coef[i]);
    }

    print(a, "A = ");
    print(b, "B = ");
    res = add(a, b);
    printf("----------------------------------------------------\n");
    print(res,  "C = ");
}
