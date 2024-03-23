#include <stdio.h>
#include <math.h>


int countDigits(int num) {
    if (num == 0)
        return 0;
    return 1 + countDigits(num / 10);
}


int isArmstrongRecursive(int num, int originalNum, int numDigits) {
    if (num == 0)
        return originalNum == 0;
    return pow(num % 10, numDigits) + isArmstrongRecursive(num / 10, originalNum, numDigits);
}

int isArmstrong(int num) {
    int numDigits = countDigits(num);
    int originalNum = num;
    return isArmstrongRecursive(num, originalNum, numDigits) == originalNum;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (isArmstrong(num))
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}
