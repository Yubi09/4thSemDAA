#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap the values of two integers
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

// Function to generate permutations recursively and store them in a result arrayvoid generatePermutations(int arr[], int start, int end, int result[][10], int *index) {
int k = 0;
void generatePermutations(int arr[], int start, int end, int **result)
{
  if (start == end)
  {
    for (int i = 0; i <= end; i++)
    {
      result[k][i] = arr[i];
    }
    k++;
  }
  else
  {
    for (int i = start; i <= end; i++)
    {
      swap(&arr[start], &arr[i]);
      generatePermutations(arr, start + 1, end, result);
      swap(&arr[start], &arr[i]);
    }
  }
}

// Merge function used in merge sort
void merge(int arr[], int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  // Create temporary arrays
  int *L = (int *)malloc(n1 * sizeof(int));
  int *R = (int *)malloc(n2 * sizeof(int));

  // Copy data to temporary arrays L[] and R[]
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  // Merge the temporary arrays back into arr[l..r]
  i = 0; // Initial index of first subarray
  j = 0; // Initial index of second subarray
  k = l; // Initial index of merged subarray
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of L[], if any
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copy the remaining elements of R[], if any
  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
  free(L);
  free(R);
}

// Merge sort function
void mergeSort(int arr[], int l, int r)
{
  if (l < r)
  {
    // Find the middle point
    int m = l + (r - l) / 2;

    // Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted halves
    merge(arr, l, m, r);
  }
}

int main()
{
  // Seed random number generator
  srand(time(NULL));

  // Generate random number of elements (between 1 and 10)
  int n;

  printf("Enter number of elements: ");
  scanf("%d", &n);

  // Generate random elements in array
  int *arr = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    arr[i] = rand() % 100; // Generating random numbers between 0 and 99
  }

  // Initialize a 2D array to store permutations
  int factorial = 1;
  for (int i = 2; i <= n; i++)
  {
    factorial *= i;
  }
  int **result = (int **)malloc(factorial * sizeof(int *));
  for (int i = 0; i < factorial; i++)
  {
    result[i] = (int *)malloc(n * sizeof(int));
  }

  // Generate permutations and store them in the result array
  generatePermutations(arr, 0, n - 1, result);

  // Open a file to store results
  FILE *fp = fopen("permutations.txt", "w");
  if (fp == NULL)
  {
    printf("Error opening file.\n");
    return 1;
  }

  // Apply merge sort to each permutation and store sorted output and all permutations in the file
  for (int i = 0; i < factorial; i++)
  {
    fprintf(fp, "Permutation: ");
    for (int j = 0; j < n; j++)
    {
      fprintf(fp, "%d ", result[i][j]);
    }
    fprintf(fp, "\nSorted permutation: ");
    mergeSort(result[i], 0, n - 1); // Applying merge sort
    for (int j = 0; j < n; j++)
    {
      fprintf(fp, "%d ", result[i][j]);
    }
    fprintf(fp, "\n\n");
  }

  // Close the file
  fclose(fp);

  printf("Results stored in 'permutations.txt'.\n");

  return 0;
}