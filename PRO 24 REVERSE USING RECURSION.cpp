#include <stdio.h>

// Function to calculate the reverse of a number recursively
int reverse(int num) {
    static int reversedNum = 0;

    if (num == 0) {
        return reversedNum;
    }

    // Extract the last digit of the number
    int digit = num % 10;
    // Append the digit to the reversed number
    reversedNum = reversedNum * 10 + digit;

    // Recur for the remaining digits
    return reverse(num / 10);
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int reversedNumber = reverse(num);

    printf("Reverse of the number: %d\n", reversedNumber);

    return 0;
}
