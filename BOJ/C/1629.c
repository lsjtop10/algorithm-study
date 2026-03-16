#include <stdio.h>
#include <stdio.h>


// calculate (a mod c) ^ b
long calculate(long a, long b, long c){

    long k = a % c;

    if(b == 0){
        return 1;
    }

    if (b % 2 == 0){
        return calculate((k * k) % c, b / 2, c);
    }else{
        return (k  * calculate(k * k % c, (b - 1) / 2, c)) % c;
    }
}

int main(){
    long a, b, c;
    scanf("%ld %ld %ld", &a, &b, &c);
    printf("%ld", calculate(a, b, c));
}

