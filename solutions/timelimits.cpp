#include <iostream>

using namespace std;

int main(void) {
  int n, s;
  cin >> n >> s;
  int maxj = 0;
  for(int i = 0; i < n; i++) {
    int m;
    cin >> m;
    if(m > maxj) {
      maxj = m;
    }
  }
  maxj *= s;
  if(maxj % 1000) maxj = maxj/1000 + 1;
  else maxj /= 1000;
  cout << maxj << endl;
}
