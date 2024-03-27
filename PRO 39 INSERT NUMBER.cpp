#include <stdio.h>

#define MAX_SIZE 100

void insertNumber(int list[], int *size, int position, int number) {
    if (*size >= MAX_SIZE) {
        printf("List is full. Cannot insert.\n");
        return;
    }

    if (position < 0 || position > *size) {
        printf("Invalid position.\n");
        return;
    }

    // Shift elements to the right starting from the end
    for (int i = *size; i > position; i--) {
        list[i] = list[i - 1];
    }

    // Insert the number at the specified position
    list[position] = number;
    (*size)++;
}

void displayList(int list[], int size) {
    printf("List: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    int list[MAX_SIZE];
    int size = 0;

    // Example list
    list[size++] = 1;
    list[size++] = 2;
    list[size++] = 4;

    int number_to_insert = 3;
    int position_to_insert = 2; // Inserting at index 2 (0-based index)

    printf("Original ");
    displayList(list, size);

    insertNumber(list, &size, position_to_insert, number_to_insert);

    printf("After insertion ");
    displayList(list, size);

    return 0;
}
