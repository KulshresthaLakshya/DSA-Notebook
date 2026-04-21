// Undirected Graph Representation
#include <stdio.h>
#define V 5

int matrix[V][V] = {0};

void addEdge(int i, int j) {
    matrix[i][j] = 1;
    matrix[j][i] = 1;
}

void displayGraph() {
    printf("\n--- Current Adjacency Matrix ---\n");
    for (int i = 1; i < V; i++) {
        for (int j = 1; j < V; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int choice, u, v;

    while(1) {
        printf("\n1. Add Edge (Connect two vertices {undirected})\n2. Display Graph\n3. Exit\nSelection: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter two vertices with space to connect: ");
                if (scanf("%d %d", &u, &v) == 2) { 
                    if (u < V && v < V) {
                        addEdge(u, v);
                        printf("Connected %d and %d successfully.\n", u, v);
                    } else {
                        printf("Error: Vertices must be between 0 and %d\n", V-1);
                    }
                }
                break;

            case 2:
                displayGraph();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}