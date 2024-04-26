#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, n, min, max;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int *arr = (int *)malloc(n * sizeof(int));
  printf("Enter the elements: ");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  if (n % 2 == 0)
  {
    min = arr[0];
    max = arr[1];
    for (i = 2; i < n; i += 2)
    {
      if (arr[i] > arr[i + 1])
      {
        if (arr[i] > max)
        {
          max = arr[i];
        }
        if (arr[i + 1] < min)
        {
          min = arr[i + 1];
        }
      }
      else
      {
        if (arr[i + 1] > max)
        {
          max = arr[i + 1];
        }
        if (arr[i] < min)
        {
          min = arr[i];
        }
      }
    }
  }
  else
  {
    min = arr[0];
    max = arr[0];
    for (i = 1; i < n; i += 2)
    {
      if (arr[i] > arr[i + 1])
      {
        if (arr[i] > max)
        {
          max = arr[i];
        }
        if (arr[i + 1] < min)
        {
          min = arr[i + 1];
        }
      }
      else
      {
        if (arr[i + 1] > max)
        {
          max = arr[i + 1];
        }
        if (arr[i] < min)
        {
          min = arr[i];
        }
      }
    }
  }
  printf("The minimum element is: %d\n", min);
  printf("The maximum element is: %d\n", max);
  return 0;
}