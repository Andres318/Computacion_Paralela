#include <stdio.h>
#include <omp.h>

int main() {
    printf("Iniciando ejecucion del Script...\n");
    int N = 90000; // Número de filas de la primera matriz
    int M = 50000; // Número de columnas de la primera matriz y número de filas de la segunda matriz
    int P = 12300; // Número de columnas de la segunda matriz

    printf("\n Tamano de matrices de entrada:\n");
    printf("Matriz 1 = %d x %d\n", N, M);
    printf("Matriz 2 = %d x %d\n", M, P);

    // Declarar punteros a matrices
    int **matriz1;
    int **matriz2;
    int **resultado;

    // Asignar memoria dinámica para las matrices
    matriz1 = (int **)malloc(N * sizeof(int *));
    matriz2 = (int **)malloc(M * sizeof(int *));
    resultado = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        matriz1[i] = (int *)malloc(M * sizeof(int));
        resultado[i] = (int *)malloc(P * sizeof(int));
    }
    for (int i = 0; i < M; i++) {
        matriz2[i] = (int *)malloc(P * sizeof(int));
    }

    // Inicializar la semilla para generar números aleatorios
    srand(time(NULL));

    // Inicializar las matrices con valores específicos
    printf("\n Inicializando matriz 1...\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matriz1[i][j] = (rand() % 100) + 1;
            //printf("%d ", matriz1[i][j]);
        }
       // printf("\n");
    }

    printf("\n Inicializando matriz 2...\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            matriz2[i][j] = (rand() % 100) + 1;
            //printf("%d ", matriz2[i][j]);
        }
        //printf("\n");
    }

    // Inicializar la matriz resultado
    printf("\n Inicializando matriz del resultado...\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            resultado[i][j] = 0;
        }
    }

    // Realizar la multiplicación de matrices en paralelo usando OpenMP
    printf("\n Realizando la multiplicacion de matrices en paralelo usando OpenMP...\n");
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        int idHilo = omp_get_thread_num();
        for (int j = 0; j < P; j++) {
            for (int k = 0; k < M; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
                //printf("Hola, soy el hilo %d, en este momento se esta(n) ejecutando %d hilo(s), el resultado de esta ejecucion es %d\n", idHilo, omp_get_num_threads(), resultado[i][j]);
            }
        }
    }
    printf("\n Tamaño de la matriz de salida:\n");
    printf("Matriz de salida = %d x %d\n", N, P);

    // Imprimir la matriz resultado
   // printf("\n Resultado de la multiplicación de matrices:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < P; j++) {
            //printf("%d ", resultado[i][j]);
        }
       //printf("\n");
    }

    // Liberar memoria
    printf("\n Liberando memoria...\n Finalizando ejecucion del script... \n");
    for (int i = 0; i < N; i++) {
        free(matriz1[i]);
        free(resultado[i]);
    }
    for (int i = 0; i < M; i++) {
        free(matriz2[i]);
    }
    free(matriz1);
    free(matriz2);
    free(resultado);

    return 0; // Salir con éxito
}
