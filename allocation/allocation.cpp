#include <iostream>
using namespace std;
#define MAX 100000
long long n, k, w[MAX];

void bubbleSort(long long a[], long long n) {
  int flag = 1;
  int done = 0;
  while (flag) {
    flag = 0;
    int j;
    for (j = n - 1; j > done; j--) {
      if (a[j] < a[j - 1]) {
        long long temp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = temp;
        flag = 1;
      }
    }
    done++;
  }
}

long long check(long long P) {
  long long v = 0, num_track = k, available_load = P;
  while (1) {
    if (w[v] > P || v == n) return v;
    if (w[v] > available_load) {
      if(!(--num_track)) return v;
      available_load = P;
    }
    available_load -= w[v];
    v++;
  }
  return v;
}

long long solve() {
  long long mid, left = 0, right = 100000 * 10000;
  while (right - left > 1) {
    mid = (left + right) / 2;
    if (check(mid) >= n) right = mid;
    else left = mid;
  }
  return right;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  long long p = 0;
  cout << solve() << endl;
}
