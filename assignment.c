#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *argv[]) 
{
    srand(time(NULL));
    int minrand = 1;
    int maxrand = 100;

    printf("Random number between %d and %d: %d\n", minrand, maxrand, (rand() % (maxrand - minrand + 1)) + minrand);
    
    if (argc != 3) 
    {
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n", argc - 1);
        return 1;
    }
    
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    if (rows <= 0 || cols <= 0) 
    {
        printf("Incorrect usage. The parameters you provided are not positive integers\n");
        return 1;
    }

    int **matrix = malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) 
    {
        matrix[i] = malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            matrix[i][j] = (rand() % (maxrand - minrand + 1)) + minrand;
        }
    }

    FILE *file = fopen("matrix.txt", "w");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) 
        {
            fprintf(file, "%d", matrix[i][j]);
            if (j < cols - 1) 
            {
                fprintf(file, " ");
            }
        }
        fprintf(file, "\n");
    }
    fclose(file);

    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}