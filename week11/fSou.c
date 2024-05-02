#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int sum(int a, int b)
{
  if (a == INT_MAX || b == INT_MAX)
  {
    return INT_MAX;
  }
  return a + b;
}

void printsqm(int **arr, int n)
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    printf("[ ");
    for (j = 0; j < n; j++)
    {
      if (arr[i][j] == INT_MAX)
      {
        printf(" INF,");
      }
      else
      {
        printf("  %d,", arr[i][j]);
      }
    }
    printf(" ]\n");
  }
}

int main()
{
  FILE *file = fopen("graph.txt", "r");
  if (file == NULL)
  {
    printf("Error opening file");
    return 0;
  }
  int n, e, v1, v2, w;
  fscanf(file, "%d %d", &n, &e);
  int **arr = (int **)malloc(n * sizeof(int *));
  int i, j;
  for (i = 0; i < n; i++)
  {
    arr[i] = (int *)malloc(n * sizeof(int));
  }
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (i == j)
      {
        arr[i][j] = 0;
      }
      else
      {
        arr[i][j] = INT_MAX;
      }
    }
  }
  i = 0;
  while (i < e && (fscanf(file, "%d %d %d", &v1, &v2, &w) == 3))
  {
    if (w < arr[v1][v2])
    {
      arr[v1][v2] = w;
    }
    i++;
  }
  fclose(file);
  printf("Adjacency Matrix:\n");
  printsqm(arr, n);
  int k;
  printf("\nThe Matrices are: \n\n");
  for (k = 0; k < n; k++)
  {
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        if (arr[i][j] > sum(arr[i][k], arr[k][j]))
        {
          arr[i][j] = sum(arr[i][k], arr[k][j]);
        }
      }
    }
    printf("M%d :\n", k);
    printsqm(arr, n);
  }

  for (i = 0; i < n; i++)
  {
    if (arr[i][i] < 0)
    {
      printf("Negetive cycles are present!!!\n");
    }
  }
  return 0;
}