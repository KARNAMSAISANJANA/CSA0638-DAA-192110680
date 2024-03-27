#include <stdio.h>

void print_factors(int n, int i) {
    if (i > n / 2) {
        printf("%d ", n); // Print n itself as a factor
        return;
    }
    
    if (n % i == 0) {
        printf("%d ", i);
        print_factors(n / i, i); // Recursively find factors of n/i
    } else {
        print_factors(n, i + 1); // Increment i and continue
    }
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    
    printf("Factors of %d are: ", n);
    print_factors(n, 2); // Start with i=2 since 1 is always a factor
    
    printf("\n");
    
    return 0;
}
