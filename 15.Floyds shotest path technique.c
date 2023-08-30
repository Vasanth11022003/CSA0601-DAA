#include <stdio.h>
#define INF 9999
#define V 4

void floydWarshall(int graph[V][V]) {
    int dist[V][V],i,j,k;
    for ( i = 0; i < V; i++) {
        for ( j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for ( k = 0; k < V; k++) {
        for ( i = 0; i < V; i++) {
            for ( j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("Shortest distance between every pair of vertices:\n");
    for ( i = 0; i < V; i++) {
        for ( j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 8, 7, 8},
        {9, 0, 11, 12},
        {10, 9, 0, 11},
        {8, 10, 11, 0}
    };

    floydWarshall(graph);

    return 0;
}
