#include<stdio.h>

static const int N = 1000;

void trace(int A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

void insertionSort(int A[], const int n){
  int i;
  for (i = 0; i < n; i++) {
      int v = A[i];
      int j = i - 1;
      while ((j >= 0) && (A[j] > v)) {
          A[j + 1] = A[j];
          j -= 1;
      }
      A[j + 1] = v;
      trace(A, n);
  }
}

int main(){
  int n, i, j;
  int A[N+1];
  scanf("%d", &n);

  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
  
  insertionSort(A, n);

  return 0;
}
