#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// int partition(int *arr, int l, int r)
// {
//   int pivot = arr[r];
//   int i = l - 1;
//   int j;
//   for (j = l; j < r; j++)
//   {
//     if (arr[j] < pivot)
//     {
//       i++;
//       int temp = arr[i];
//       arr[i] = arr[j];
//       arr[j] = temp;
//     }
//   }
//   int temp = arr[i + 1];
//   arr[i + 1] = arr[r];
//   arr[r] = temp;
//   return i + 1;
// }

// int select(int *arr, int n, int i)
// {
//   if (arr[0] == arr[n - 1])
//   {
//     return arr[0];
//   }
//   int r = partition(arr, 0, n - 1);
//   int k = r - 0 + 1;
//   if (i == k)
//   {
//     return arr[r];
//   }
//   else if (i < k)
//   {
//     return select(arr, r, i);
//   }
//   else
//   {
//     return select(arr + r + 1, n - r - 1, i - k);
//   }
// }

int rand_select(int *arr, int n, int k)
{
  if (n == 1)
  {
    return arr[0];
  }
  int pivot = arr[rand() % n];
  int *left = (int *)malloc(n * sizeof(int));
  int *right = (int *)malloc(n * sizeof(int));
  int i, j, l = 0, r = 0;
  for (i = 0; i < n; i++)
  {
    if (arr[i] < pivot)
    {
      left[l++] = arr[i];
    }
    else if (arr[i] > pivot)
    {
      right[r++] = arr[i];
    }
  }
  if (k <= l)
  {
    return rand_select(left, l, k);
  }
  else if (k == l + 1)
  {
    return pivot;
  }
  else
  {
    return rand_select(right, r, k - l - 1);
  }
}


int main()
{
  int n, i, k;
  printf("Enter the number of elements: ");
  scanf("%d", &n);
  int *arr = (int *)malloc(n * sizeof(int));
  printf("Enter the elements: ");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  printf("Enter the value of k: ");
  scanf("%d", &k);
  if (k > n)
  {
    printf("Invalid input\n");
    return 0;
  }
  printf("The kth smallest element is: %d\n", rand_select(arr, n, k));

  return 0;
}