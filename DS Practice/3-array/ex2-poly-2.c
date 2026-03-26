#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct Trem{
    float coef;
    int expon;
}Term;

typedef struct polynomial{
    int num;
    Term terms[N];
} Poly;

Poly make_poly(){
    Poly p;
    printf("Enter the number of coefficents of the polynomianl");
    scanf("%d", &p.num);

    printf("Enter the cofficent and the exponent of the polynomial ");
    for(int i = 0; i <= p.num; i++){
        printf("%d 번 입력", i + 1);
        scanf("%f %d", &p.terms[i].coef, &p.terms[i].expon);
    }
    return p;
}

void print(Poly p, const char* str){
    printf("%s", str);
    for(int i = 0; i < p.num; i++){
        printf("%.1f x^%d+ ", p.terms[i].coef, p.terms[i].expon);
        // \b는 backspace를 나타내는 이스케이브 시퀀스이다. 마지막 항이 상수항이라는 보장이 없기 때문에
        // +기호를 지운 다음 줄바꿈한다.
        printf("\b\b   \n");
    }
}

Poly add(Poly a, Poly b){
    Poly c;
    c.num = 0;

    // 왜 <일까?
    for(int i = 0, j = 0; i < a.num || j < b.num;){

        // a 다항식 
        if( i == a.num || a.terms[i].expon < b.terms[j].expon){
            c.terms[c.num] = b.terms[j];
            
            j++;
            c.num++;
        }else if(j == b.terms || a.terms[i].expon > b.terms[i].expon){
            c.terms[c.num] = a.terms[i];

            i++;
            c.num++;
        }else{
            float coef = a.terms[i].coef + b.terms[j].coef;
            if(coef != 0.0){
                c.terms[c.num].coef = coef;
                c.terms[c.num].expon = a.terms[i].expon;
                c.num++;
            }
            i++;
            j++;
        }
    }
    
    return c;
}

int main(){
    // Poly a = make_poly();
    // Poly b = make_poly();

    // print(a, "A = ");
    // print(b, "A = ");

    // Poly c = add(a,b);
    // printf("--------------------------------------------\n");
    // print(c, "C = ");

    printf("%s", (0.684132165846321354684531 - 0.684132165846321354684531 == 0.0)? "true":"false");
}