#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int Randomized_Partition(int *arr, int p, int r)
{
  int i = p + rand() % (r - p + 1);
  int temp = arr[i];
  arr[i] = arr[r];
  arr[r] = temp;
  int x = arr[r];
  i = p - 1;
  for (int j = p; j < r; j++)
  {
    if (arr[j] <= x)
    {
      i++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  temp = arr[i + 1];
  arr[i + 1] = arr[r];
  arr[r] = temp;
  return i + 1;
}

int Random_Select(int *arr, int p, int r, int i)
{
  if (p == r)
  {
    return arr[p];
  }
  int q = Randomized_Partition(arr, p, r);
  int k = q - p + 1;
  if (i == k)
  {
    return arr[q];
  }
  else if (i < k)
  {
    return Random_Select(arr, p, q - 1, i);
  }
  else
  {
    return Random_Select(arr, q + 1, r, i - k);
  }
}

int main()
{
  int n, i, k;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int *arr = (int *)malloc(n * sizeof(int));
  printf("Enter the elements: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  printf("Enter the value of k: ");
  scanf("%d", &k);
  if (k > n)
  {
    printf("Invalid value of k\n");
    exit(0);
  }
  int kMax = Random_Select(arr, 0, n - 1, k);
  printf("The kth largest element is: %d\n", kMax);

  return 0;
}