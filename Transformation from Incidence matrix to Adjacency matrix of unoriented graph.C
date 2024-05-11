#include <stdio.h>
int main() {
    //Input of number of vertices and number of edges
    int n_v, n_e;
    printf("Enter number of vertices : ");
    scanf("%i", &n_v);
    printf("Enter number of edges : ");
    scanf("%i", &n_e);
    int N[n_v][n_e], A[n_v][n_v];
    //Input of the Incidence matrix
    printf("Enter Incidence Matrix : \n");
    for (int v = 0; v < n_v; v++){
        for (int e = 0; e < n_e; e++){
            scanf("%i", &N[v][e]);
        }
    }
    //Initialize element of Adjacency matrix
    for (int i = 0; i < n_v; i++){
        for (int j = 0; j < n_v; j++){
            A[i][j] = 0;
        }
    }
    //Transformation
    for (int e = 0; e < n_e; e++){
        int x1 = -1, x2 = -1;
        for (int v = 0; v < n_v; v++){
            if (N[v][e] == 0){
                continue;
            }
            else if (N[v][e] == 1 && x1 == -1){
                x1 = v;
            }
            else if (N[v][e] == 1 && x1 != -1 && x2 == -1){
                x2 = v;
            }
            else if (N[v][e] == 1 && x1 != -1 && x2 != -1){
                printf("Incidence matrix error");
                return 1;
            }
            else if (N[v][e] == 2 && x1 ==-1){
                x1 = v;
                x2 = v;
            }
            else {
                printf("Incidence matrix error");
                return 1;
            }
        }
        if (x1 != -1 && x2 != -1){
            A[x1][x2] += 1;
            A[x2][x1] += 1;
        }
        if (x1 != -1 && x2 == -1){
            printf("Incidence matrix error");
            return 1;
        }
    }
    //Output of the Adjacency matrix
    printf("The Adjacency Matrix : \n");
    for (int i = 0; i < n_v; i++){
        for (int j = 0; j < n_v; j++){
            printf("%i ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}