#include <stdio.h>
#include <stdlib.h>

void create_adjacency_matrix() {
    int choice, V;

    do {
        printf("Menu:\n");             
        printf("1. Undirected\n");
        printf("2. Directed\n");
        printf("3. Weighted Undirected\n");
        printf("4. Weighted Directed\n");
        printf("5. Quit\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting...\n");
            exit(EXIT_FAILURE);
        }

        if (choice == 5) {
            printf("Exiting...\n");
            break;
        }

        if (choice < 1 || choice > 5) {
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            continue;
        }

        printf("Enter the number of vertices: ");
        if (scanf("%d", &V) != 1 || V <= 0) {
            printf("Invalid input for the number of vertices. Please enter a positive integer.\n");
            while (getchar() != '\n'); 
            continue;
        }

        int adjacency_matrix[V][V];
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adjacency_matrix[i][j] = 0; 
            }
        }

        int v1, v2, weight;
        printf("Enter edges (format: v1 v2 for unweighted, v1 v2 weight for weighted). Enter -1 to stop:\n");
        
        while (1) {
            if (choice == 1 || choice == 2) {
                printf("Enter v1 v2: ");
                if (scanf("%d %d", &v1, &v2) != 2) {
                    break; 
                }
                if (v1 == -1 || v2 == -1) {
                    break; 
                }
                if (v1 < 1 || v1 > V || v2 < 1 || v2 > V) {
                    printf("Invalid input. Please enter two integers in the range 1 to %d.\n", V);
                    while (getchar() != '\n'); 
                    continue;
                }
                v1--; 
                v2--; 
                adjacency_matrix[v1][v2] = 1;
                if (choice == 1) {
                    adjacency_matrix[v2][v1] = 1;  
                }
            } else if (choice == 3 || choice == 4) {
                printf("Enter v1 v2 weight: ");
                if (scanf("%d %d %d", &v1, &v2, &weight) != 3) {
                    break; 
                }
                if (v1 == -1 || v2 == -1 || weight == -1) {
                    break;
                }
                if (v1 < 1 || v1 > V || v2 < 1 || v2 > V) {
                    printf("Invalid input. Please enter two integers followed by weight in the range 1 to %d.\n", V);
                    while (getchar() != '\n'); 
                    continue;
                }
                v1--; 
                v2--; 
                adjacency_matrix[v1][v2] = weight;
                if (choice == 3) {
                    adjacency_matrix[v2][v1] = weight; 
                }
            }
        }

        // Print the adjacency matrix
        printf("Adjacency Matrix:\n");
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                printf("%d ", adjacency_matrix[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    } while (1);
}

int main() {
    create_adjacency_matrix();
return 0;
}