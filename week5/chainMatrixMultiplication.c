#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void matrixChain(int *p, int n, int **m, int **s)
{
  int i, l, j, k, q;
  for (i = 1; i <= n; i++)
  {
    m[i][i] = 0;
  }
  for (l = 2; l <= n; l++)
  {
    for (i = 1; i <= n - l + 1; i++)
    {
      j = i + l - 1;
      m[i][j] = INT_MAX;
      for (k = i; k <= j - 1; k++)
      {
        q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (q < m[i][j])
        {
          m[i][j] = q;
          s[i][j] = k;
        }
      }
    }
  }
}

void parenPrint(int **s, int i, int j)
{
  if (i == j)
  {
    printf("A%d", i);
  }
  else
  {
    printf("(");
    parenPrint(s, i, s[i][j]);
    parenPrint(s, s[i][j] + 1, j);
    printf(")");
  }
}

int main()
{
  int n, i;
  printf("Enter the number of matrices: ");
  scanf("%d", &n);
  int *p = (int *)malloc((n + 1) * sizeof(int));
  printf("Enter the dimensions of the matrices: ");
  for (i = 0; i <= n; i++)
  {
    scanf("%d", &p[i]);
  }
  int **m = (int **)malloc((n + 1) * sizeof(int *));
  for (i = 0; i <= n; i++)
  {
    m[i] = (int *)malloc((n + 1) * sizeof(int));
  }
  int **s = (int **)malloc((n + 1) * sizeof(int *));
  for (i = 0; i <= n; i++)
  {
    s[i] = (int *)malloc((n + 1) * sizeof(int));
  }
  matrixChain(p, n, m, s);
  printf("Minimum number of multiplications: %d\n", m[1][n]);
  printf("Optimal parenthesization: ");
  parenPrint(s, 1, n);
  printf("\n");
  return 0;
}
