#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, n, max, secondMax;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int *arr = (int *)malloc(n * sizeof(int));
  printf("Enter the elements: ");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  max = arr[0];
  secondMax = -1;
  for (i = 1; i < n; i++)
  {
    if (arr[i] > max)
    {
      secondMax = max;
      max = arr[i];
    }
    else if (arr[i] > secondMax && arr[i] != max)
    {
      secondMax = arr[i];
    }
  }
  if (secondMax == -1)
  {
    printf("There is no second largest element\n");
  }
  else
  {
    printf("The second largest element is: %d\n", secondMax);
  }
  return 0;
}