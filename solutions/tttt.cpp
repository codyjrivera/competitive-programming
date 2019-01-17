#include <iostream>

using namespace std;

int main(void) {
  int n;
  cin >> n;
  int appearances[n] = {0};
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    for(int j = a; j <= b; j++) {
      appearances[j]++;
    }
  }
  for(int i = n-1; i >= 0; i--) {
    if(appearances[i] == i) {
      cout << appearances[i] << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
