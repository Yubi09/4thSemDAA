#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *arr1, *arr2;
  int n1, n2, i;
  scanf("%d", &n1);
  arr1 = (int *)malloc(n1 * sizeof(int));
  for (i = 0; i < n1; i++)
  {
    scanf("%d", &arr1[i]);
  }
  scanf("%d", &n2);
  arr2 = (int *)malloc(n2 * sizeof(int));
  for (i = 0; i < n2; i++)
  {
    scanf("%d", &arr2[i]);
  }
  int max = 0;
  for (i = 0; i < n1; i++)
  {
    if (arr1[i] > max)
    {
      int j;
      for (j = 0; j < n2; j++)
      {
        if (arr1[i] == arr2[j])
        {
          break;
        }
      }
      if (j == n2)
      {
        max = arr1[i];
      }
    }
  }
  printf("Output: %d\n", max);

  return 0;
}