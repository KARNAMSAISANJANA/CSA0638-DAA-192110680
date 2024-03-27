#include <stdio.h>
#include <stdbool.h>

#define N 4 // Number of agents and tasks (assuming equal)

int costMatrix[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

bool assigned[N];
int minCost = 0;

void branchAndBound(int currentWorker, int currentCost) {
    if (currentWorker == N) {
        if (currentCost < minCost) {
            minCost = currentCost;
        }
        return;
    }
    
    for (int task = 0; task < N; task++) {
        if (!assigned[task]) {
            assigned[task] = true;
            branchAndBound(currentWorker + 1, currentCost + costMatrix[currentWorker][task]);
            assigned[task] = false;
        }
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        assigned[i] = false;
    }
    
    branchAndBound(0, 0);
    
    printf("Minimum cost for assignment: %d\n", minCost);
    
    return 0;
}
