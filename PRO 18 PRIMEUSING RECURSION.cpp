#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num, int i) {
    if (i == 1) {
        return 1; // Base case: 1 is always prime
    } else {
        if (num % i == 0) {
            return 0; // If num is divisible by i, then it's not prime
        } else {
            return isPrime(num, i - 1); // Recursively check for divisibility by decreasing i
        }
    }
}

// Function to print prime numbers up to n
void printPrimes(int n, int i) {
    if (i <= n) {
        if (isPrime(i, i / 2)) {
            printf("%d ", i); // If i is prime, print it
        }
        printPrimes(n, i + 1); // Recursively check the next number
    }
}

int main() {
    int n;
    printf("Enter the limit: ");
    scanf("%d", &n);

    printf("Prime numbers up to %d are: ", n);
    printPrimes(n, 2); // Start from 2 as 1 is not a prime number
    printf("\n");

    return 0;
}
