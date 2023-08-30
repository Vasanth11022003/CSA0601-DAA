#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int optimalBSTCost(int freq[], int n) {
    int cost[n][n];
    int i,L,j;
    int r,c;

    for (i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }

    for (L = 2; L <= n; L++) {
        for (i = 0; i <= n - L + 1; i++) {
            j = i + L - 1;
            cost[i][j] = INT_MAX;

            for (r = i; r <= j; r++) {
                c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        freq[r];

                cost[i][j] = min(cost[i][j], c);
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    int n,i;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n], freq[n];
    printf("Enter the keys and their corresponding frequencies:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &keys[i], &freq[i]);
    }

    int minCost = optimalBSTCost(freq, n);
    printf("Minimum total cost of all searches: %d\n", minCost);

    return 0;
}

