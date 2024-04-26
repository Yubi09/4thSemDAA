#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int main()
{
  int n;
  printf("Enter the number of matrices: ");
  scanf("%d", &n);
  int *p = (int *)malloc((n + 1) * sizeof(int));
  printf("Enter the dimensions of the matrices: ");
  for (int i = 0; i <= n; i++)
  {
    scanf("%d", &p[i]);
  }
  int **m = (int **)malloc((n) * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    m[i] = (int *)malloc((n) * sizeof(int));
  }
  int **s = (int **)malloc((n) * sizeof(int *));
  for (int i = 0; i < n; i++)
  {
    s[i] = (int *)malloc((n) * sizeof(int));
  }
  int i, d, j, k, q;
  for (i = 0; i < n; i++)
  {
    m[i][i] = 0;
  }

    return 0;
}