#include <stdio.h>
#include <stdlib.h>

struct Object {
    int value;
    int weight;
    double ratio;
};

int compare(const void* a, const void* b) {
    struct Object* objectA = (struct Object*)a;
    struct Object* objectB = (struct Object*)b;
    return (objectB->ratio - objectA->ratio);
}

void knapsackGreedy(struct Object objects[], int n, int knapsackWeight) {
    qsort(objects, n, sizeof(objects[0]), compare);

    int currentWeight = 0;
    double totalValue = 0.0;
    int i;

    for (i = 0; i < n; i++) {
        if (currentWeight + objects[i].weight <= knapsackWeight) {
            currentWeight += objects[i].weight;
            totalValue += objects[i].value;
        } else {
            int remainingWeight = knapsackWeight - currentWeight;
            totalValue += (double)(remainingWeight) * objects[i].ratio;
            break;
        }
    }

    printf("Maximum value in the knapsack: %.2lf\n", totalValue);
}

int main() {
    int n;
    int i;
    printf("Enter the number of objects: ");
    scanf("%d", &n);

    struct Object objects[n];
    printf("Enter the knapsack weight: ");
    int knapsackWeight;
    scanf("%d", &knapsackWeight);

    for (i = 0; i < n; i++) {
        printf("Enter details of object %d (value weight): ", i + 1);
        scanf("%d %d", &objects[i].value, &objects[i].weight);
        objects[i].ratio = (double)objects[i].value / objects[i].weight;
    }

    knapsackGreedy(objects, n, knapsackWeight);

    return 0;
}

