#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


bool isPalindrome(char *str, int start, int end) {
    
    if (start >= end) {
        return true;
    }


    while (!isalnum(str[start]) && start < end) {
        start++;
    }

    
    while (!isalnum(str[end]) && end > start) {
        end--;
    }
    if (tolower(str[start]) != tolower(str[end])) {
        return false;
    }

    
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str, 0, strlen(str) - 1)) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}
