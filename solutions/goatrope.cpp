#include <iostream>
#include <math.h>

using namespace std;

double distance(int x1, int y1, int x2, int y2) {
  int a2 = pow(x1 - x2, 2);
  int b2 = pow(y1 - y2, 2);
  double c2 = a2 + b2;
  return sqrt(c2);
}

int main(void) {
  int x, y, x1, y1, x2, y2;
  cin >> x >> y >> x1 >> y1 >> x2 >> y2;
  double min = 1000000;
  if(distance(x, y, x1, y1) < min) min = distance(x, y, x1, y1);
  if(distance(x, y, x1, y2) < min) min = distance(x, y, x1, y2);
  if(distance(x, y, x2, y1) < min) min = distance(x, y, x2, y1);
  if(distance(x, y, x2, y2) < min) min = distance(x, y, x2, y2);
  if(y2 < y1) {
    int temp = y2;
    y2 = y1;
    y1 = temp;
  }
  if(x2 < x1) {
    int temp = x2;
    x2 = x1;
    x1 = temp;
  }
  if(x1 < x && x < x2) {
    if(distance(x, y, x, y1) < min) min = distance(x, y, x, y1);
    if(distance(x, y, x, y2) < min) min = distance(x, y, x, y2);
  }
  if(y1 < y && y < y2) {
    if(distance(x, y, x1, y) < min) min = distance(x, y, x1, y);
    if(distance(x, y, x2, y) < min) min = distance(x, y, x2, y);
  }
  printf("%.3f\n", min);
}
