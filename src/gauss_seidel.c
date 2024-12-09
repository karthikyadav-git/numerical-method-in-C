#include <stdio.h>
#include <math.h>

#define N 3 // Size of the matrix (number of equations)

// Function prototypes
void printMatrix(double matrix[N][N], double b[N]);
void gaussSeidel(double matrix[N][N], double b[N], double x[N], int maxIter, double tolerance);

int main()
{
    // Example system of equations:
    // 4x + y - z = 7
    // x + 5y + 2z = -3
    // 2x + 3y + 6z = 15
    double matrix[N][N] = {
        {4, 1, -1},
        {1, 5, 2},
        {2, 3, 6}};
    double b[N] = {7, -3, 15};
    double x[N] = {0};       // Initial guess for solution
    int maxIter = 25;        // Maximum number of iterations
    double tolerance = 1e-6; // Tolerance for convergence

    printf("Initial matrix and b vector:\n");
    printMatrix(matrix, b);

    gaussSeidel(matrix, b, x, maxIter, tolerance);

    printf("\nSolution:\n");
    for (int i = 0; i < N; i++)
    {
        printf("x[%d] = %f\n", i, x[i]);
    }

    return 0;
}

void printMatrix(double matrix[N][N], double b[N])
{
    printf("Matrix A:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%6.2f ", matrix[i][j]);
        }
        printf(" | %6.2f\n", b[i]);
    }
}

void gaussSeidel(double matrix[N][N], double b[N], double x[N], int maxIter, double tolerance)
{
    double xOld[N];
    int iter;

    for (iter = 0; iter < maxIter; iter++)
    {
        // Store old values of x
        for (int i = 0; i < N; i++)
        {
            xOld[i] = x[i];
        }

        // Update each variable
        for (int i = 0; i < N; i++)
        {
            double sum = b[i];
            for (int j = 0; j < N; j++)
            {
                if (i != j)
                {
                    sum -= matrix[i][j] * x[j];
                }
            }
            x[i] = sum / matrix[i][i];
        }

        // Check for convergence
        double maxDiff = 0;
        for (int i = 0; i < N; i++)
        {
            double diff = fabs(x[i] - xOld[i]);
            if (diff > maxDiff)
            {
                maxDiff = diff;
            }
        }

        if (maxDiff < tolerance)
        {
            printf("Converged after %d iterations.\n", iter + 1);
            return;
        }
    }

    printf("Did not converge after %d iterations.\n", maxIter);
}
