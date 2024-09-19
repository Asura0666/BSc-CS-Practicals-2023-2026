/*
1.1 Accept M and N 
1.2 Accept the elements of two MxN matrices 
1.3 Print Addition of the Matrices
*/
#include <stdio.h>

int main() {
    int M, N;
    printf("Enter the number of rows (M) and columns (N): ");
    scanf("%d %d", &M, &N);

    int A[M][N], B[M][N], C[M][N];

    printf("Enter elements of matrix A:\n");
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    printf("Resulting matrix after addition:\n");
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
2.1 Accept M and N 
2.2 Accept the elements of MxN matrix
2.3 Print Transpose of the Matrix
*/
#include <stdio.h>

int main() {
    int M, N;
    printf("Enter the number of rows (M) and columns (N): ");
    scanf("%d %d", &M, &N);

    int A[M][N], T[N][M];

    printf("Enter elements of matrix A:\n");
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Transpose of the matrix:\n");
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            T[j][i] = A[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }

    return 0;
}

/*
3.1 Accept N 
3.2 Accept the elements of NxN matrix 
3.3 Print Sum of Diagonal Elements
*/
#include <stdio.h>

int main() {
    int N, sum = 0;
    printf("Enter the size of the NxN matrix: ");
    scanf("%d", &N);

    int A[N][N];
    printf("Enter elements of the matrix:\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for(int i = 0; i < N; i++) {
        sum += A[i][i];  // Sum of diagonal elements
    }

    printf("Sum of diagonal elements: %d\n", sum);
    return 0;
}
