#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int V; 
int i;

void printSolution(int path[]) {
    printf("Hamiltonian Circuit: ");
    for (i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]); 
}

int isSafe(int v, int graph[MAX_VERTICES][MAX_VERTICES], int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0) {
        return 0; 
    }
    
    for (i = 0; i < pos; i++) {
        if (path[i] == v) {
            return 0;
        }
    }
    
    return 1;
}

int hamiltonianUtil(int graph[MAX_VERTICES][MAX_VERTICES], int path[], int pos) {
	int i,v;
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            return 1; 
        } else {
            return 0;
        }
    }

    for (v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (hamiltonianUtil(graph, path, pos + 1) == 1) {
                return 1; 
            }
            path[pos] = -1; 
        }
    }

    return 0; 
}

int hamiltonianCycle(int graph[MAX_VERTICES][MAX_VERTICES]) {
	int i;
    int path[MAX_VERTICES];
    for (i = 0; i < V; i++) {
        path[i] = -1;
    }
    path[0] = 0; 
    
    if (hamiltonianUtil(graph, path, 1) == 0) {
        printf("No Hamiltonian Circuit exists.\n");
        return 0;
    }
    
    printSolution(path);
    return 1;
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int i,j;
    
    printf("Enter the number of vertices (maximum %d): ", MAX_VERTICES);
    scanf("%d", &V);
    
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    hamiltonianCycle(graph);

    return 0;
}

