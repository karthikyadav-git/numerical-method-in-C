#include <stdio.h>
#include <math.h>

// Define the function for which we want to find the root
float f(float x)
{
    // Example function: x^3 - x - 2
    return x * x * x - x - 2;
}

// Function to perform the Bisection method
void bisection(float a, float b, float tol, int max_iter)
{
    if (f(a) * f(b) >= 0)
    {
        printf("The function must have different signs at the endpoints a and b.\n");
        return;
    }

    float c;
    int iteration = 0;

    printf("\n\tIteration\t a\t\t b\t\t c\t\t f(a)\t\t f(b)\t\t f(c)\n");

    while ((b - a) / 2 > tol && iteration < max_iter)
    {
        c = (a + b) / 2; // Midpoint
        printf("\t%d\t\t %f\t %f\t %f\t %f\t %f\t %f\n", iteration + 1, a, b, c, f(a), f(b), f(c));

        if (f(c) == 0)
        {
            break; // Exact root found
        }
        else if (f(a) * f(c) < 0)
        {
            b = c; // Root lies between a and c
        }
        else
        {
            a = c; // Root lies between c and b
        }

        iteration++;
    }

    if (iteration >= max_iter)
    {
        printf("\nMaximum number of iterations reached.\n");
    }

    printf("\nRoot is approximately %f\n", c);
}

int main()
{
    float a, b, tol;
    int max_iter;

    // Input initial guesses, tolerance, and maximum number of iterations
    printf("Enter the initial guesses (a and b): ");
    scanf("%f %f", &a, &b);

    printf("Enter the tolerance: ");
    scanf("%f", &tol);

    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iter);

    // Call the bisection function
    bisection(a, b, tol, max_iter);

    return 0;
}
