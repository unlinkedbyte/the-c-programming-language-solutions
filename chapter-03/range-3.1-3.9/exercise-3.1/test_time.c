// testing the time of cpu

#include <stdio.h>
#include <time.h>

int binsearch_original(int x, int v[], int n){
  int low, mid, high;

  low = 0;
  high = n - 1;

  while (low <= high) {
    mid = (low+high) / 2;
    if (x < v[mid]) {
      high = mid - 1;
    } else if (x > v[mid]) {
      low  = mid + 1;
    } else {
      return mid;
    }
  }

  return -1;
}

int binsearch_exercise(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;

  while (low < high) {
    mid = (low+high) / 2;
    if (x <= v[mid]) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  
  if (v[low] == x) {
    return low;
  } else {
    return -1;
  }

}


int main() {
  int size = 50000;
  int v[50000];
  for (int i = 0; i < size; ++i) {
    v[i] = i;
  }

  int iterations = 1000000;
  clock_t beg, end;
  double time_original, time_exercise;

  beg = clock();
  for (int i = 0; i < iterations; ++i) {
    binsearch_original(25000, v, size);
  }
  end = clock();
  time_original = (double)(end - beg) / CLOCKS_PER_SEC; // type casting. clock_t suele ser long int

  beg = clock();
  for (int i = 0; i < iterations; ++i) {
    binsearch_exercise(25000, v, size); 
  }
  end = clock();
  time_exercise = (double)(end - beg) / CLOCKS_PER_SEC;

  printf("Original version: %f seconds\n", time_original);
  printf("Our version: %f seconds\n", time_exercise);

  return 0;



}
