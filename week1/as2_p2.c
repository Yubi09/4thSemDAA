#include <stdio.h>
#include <stdlib.h>
int main()
{
  int *arr;
  int n, i, j, c = 0;
  scanf("%d", &n);
  arr = (int *)malloc(n * sizeof(int));
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  for (i = 0; i < n; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (arr[i] == arr[j])
      {
        c++;
      }
    }
  }
  printf("Output: %d\n", n - c);
  
  return 0;
}