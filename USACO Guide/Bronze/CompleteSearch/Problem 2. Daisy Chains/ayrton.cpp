#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;

  cin >> n;

  int v[n];


  for (int i = 0; i < n; i++) {
    cin >> v[i];

  }

  int total = 0;
  int sum;
  int mean;

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      sum = 0;

      for (int k = i; k <= j; k++) {
        sum += v[k];
      }
      
      if (sum%(j - i + 1) != 0) {
        continue;
      }
      
      mean = sum / (j - i + 1);

      for (int k = i; k <= j; k++) {
        if (v[k] == mean) {
          total++;
          break;
        }
      }
    }  
  }

  cout << total;

  return 0;
}