#include <stdio.h>

#define MAX_CONTAINERS 10
#define MAX_TRUCK_CAPACITY 100

int containers[MAX_CONTAINERS];
int loaded[MAX_CONTAINERS];
int truck_capacity;

int num_containers;

int min_trucks = MAX_TRUCK_CAPACITY; // Initializing with maximum possible value

void load_containers(int truck, int current_capacity) {
    if (truck > min_trucks) // If we've already found a better solution, stop searching
        return;
    
    if (current_capacity >= truck_capacity) {
        if (truck < min_trucks) {
            min_trucks = truck;
            printf("Solution found: %d trucks\n", truck);
            for (int i = 0; i < num_containers; i++) {
                if (loaded[i])
                    printf("Container %d: Truck %d\n", containers[i], truck - 1);
            }
            printf("\n");
        }
        return;
    }
    
    for (int i = 0; i < num_containers; i++) {
        if (!loaded[i]) {
            loaded[i] = 1;
            load_containers(truck, current_capacity + containers[i]);
            loaded[i] = 0;
        }
    }
    
    load_containers(truck + 1, 0); // Move to the next truck
}

int main() {
    printf("Enter the number of containers: ");
    scanf("%d", &num_containers);
    
    printf("Enter the weights of containers:\n");
    for (int i = 0; i < num_containers; i++) {
        scanf("%d", &containers[i]);
        loaded[i] = 0;
    }
    
    printf("Enter the capacity of each truck: ");
    scanf("%d", &truck_capacity);
    
    load_containers(1, 0);
    
    printf("Minimum number of trucks required: %d\n", min_trucks);
    
    return 0;
}
