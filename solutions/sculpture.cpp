#include <iostream>

using namespace std;

int main(void) {
  int c, r;
  cin >> r >> c;
  int heights[r][c];
  int drains[r][c];
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cin >> heights[i][j];
      drains[i][j] = 0;
    }
  }
  for(int i = 1; i < r - 1; i++) {
    for(int j = 1; j < c - 1; j++) {
      int h = heights[i][j];
      if(heights[i-1][j] > h && heights[i+1][j] > h && heights[i][j-1] > h && heights[i][j+1] > h) {
        drains[i][j] = 1;
      }
    }
  }
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cout << drains[i][j] << " ";
    }
    cout << endl;
  }
}
