#include <stdio.h>
#include <stdbool.h>


bool isPrimeRecursive(int num, int divisor) {
    
    if (num <= 1)
        return false;
    if (divisor == 1)
        return true;
    
    if (num % divisor == 0)
        return false;

    return isPrimeRecursive(num, divisor - 1);
}


bool isPrime(int num) {
    return isPrimeRecursive(num, num / 2);
}

int main() {
    int num;

    printf("Enter a number to check if it's prime: ");
    scanf("%d", &num);


    if (isPrime(num))
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);

    return 0;
}
