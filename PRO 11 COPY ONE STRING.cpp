#include <stdio.h>


void stringCopy(char *source, char *destination) {

    if (*source == '\0') {
        *destination = '\0';
        return;
    }
    
    
    *destination = *source;
    
    stringCopy(source + 1, destination + 1);
}

int main() {
    char source[100], destination[100];
    
    printf("Enter a string: ");
    fgets(source, sizeof(source), stdin);
    

    stringCopy(source, destination);
    
    printf("Copied string: %s", destination);
    
    return 0;
}
