/*
 * week4_1_dynamic_array.c
 * Author: [Kamer]
 * Student ID: [241ADB155]
 * Description:
 *   Demonstrates creation and usage of a dynamic array using malloc.
 *   Allocate memory for n integers, read them from the user,
 *   print their sum and average, and then free the memory.
 *
 *   Output must match the format in the Week 4 instructions exactly
 *   (it is checked by the autograder).
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int n;
  int* arr = NULL;

  printf("Enter number of elements: ");
  if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Invalid size.\n");
    return 1;
  }

  // TODO: Allocate memory for n integers using malloc
  arr = malloc(n * sizeof(int));
  // Example: arr = malloc(n * sizeof(int));

  // TODO: Check allocation success
  if (arr == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }
  // If arr is NULL: print "Memory allocation failed." and return 1

  // TODO: Print the prompt "Enter %d integers: " (with n), then read
  printf("Enter %d integers: ", n);

  for (int sayac = 0; sayac < n; sayac++) {
    if (scanf("%d", &arr[sayac]) != 1) {
      printf("Invalid input.\n");
      free(arr);
      return 1;
    }
  }

  // TODO: Compute the sum and the average (use floating point for the average)
  int toplam = 0;
  for (int sayac = 0; sayac < n; sayac++) {
    toplam += arr[sayac];
  }
  // TODO: Print the results exactly as:
  double ortalama = (double)toplam / n;

  printf("Sum %d\n", toplam);
  printf("Average = %.2f\n", ortalama);
  // TODO: Free allocated memory
  // remove this line once you use arr
  free(arr);
  return 0;
}
