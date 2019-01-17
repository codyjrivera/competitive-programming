#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mod(int a, int b) {
  while(a<0) a+=b;
  int divn = a / b;
  divn *= b;
  return a - divn;
}

struct less_abs : public binary_function<int, int, bool> {
  bool operator()(int x, int y) { return abs(x) < abs(y); }
};

int main(void) {
  int maxIndex, spotsToRotate;
  cin >> maxIndex >> spotsToRotate;
  int len1;
  cin >> len1;
  int riv1[len1];
  for(int i = 0; i < len1; i++) {
    cin >> riv1[i];
  }
  int len2;
  cin >> len2;
  int riv2[len2];
  for(int i = 0; i < len2; i++) {
    cin >> riv2[i];
  }

  vector<int> sumRiv = {};
  vector<int> productRiv = {};
  vector<int> rotatedRiv1 = {};
  vector<int> rotatedRiv2 = {};

  int j = 0;

  for(int i = 0; i < len1; i++) {
    while(j < len2 && abs(riv2[j]) < abs(riv1[i])) {
      j++;
    }
    if(abs(riv2[j]) == abs(riv1[i])) {
      int product = riv1[i] / abs(riv1[i]) * riv2[j] / abs(riv2[j]);
      if(product) {
        productRiv.push_back(abs(riv1[i]) * product);
      }
    }
  }

  j = 0;

  for(int i = 0; i < len1; i++) {
    for(; j < len2 && abs(riv2[j]) < abs(riv1[i]); j++) {
      sumRiv.push_back(riv2[j]);
    }
    if(abs(riv2[j]) == abs(riv1[i])) {
      int sum = riv1[i] / abs(riv1[i]) + riv2[j] / abs(riv2[j]);
      if(sum < -1) sum = -1;
      if(sum > 1) sum = 1;
      if(sum != 0) sumRiv.push_back(abs(riv1[i]) * sum);
      j++;
    }
    else {
      sumRiv.push_back(riv1[i]);
    }
  }
  while(j < len2) {
    sumRiv.push_back(riv2[j]);
    j++;
  }

  cout << sumRiv.size() << " ";
  for(auto x : sumRiv) {
    cout << x << " ";
  }
  cout << endl;

  cout << productRiv.size() << " ";
  for(auto x : productRiv) {
    cout << x << " ";
  }
  cout << endl;

  for(int i = 0; i < len1; i++) {
    int calcedNum = mod(abs(riv1[i]) - spotsToRotate,maxIndex) * (riv1[i] / abs(riv1[i]));
    if(!calcedNum) {
      calcedNum = maxIndex * (riv1[i] / abs(riv1[i]));
    }
    rotatedRiv1.push_back(calcedNum);
  }
  sort(rotatedRiv1.begin(), rotatedRiv1.end(), less_abs());
  cout << len1 << " ";
  for(auto x : rotatedRiv1) {
    cout << x << " ";
  }
  cout << endl;

  for(int i = 0; i < len2; i++) {
    int calcedNum = mod(abs(riv2[i]) - spotsToRotate,maxIndex) * (riv2[i] / abs(riv2[i]));
    if(!calcedNum) {
      calcedNum = maxIndex * (riv2[i] / abs(riv2[i]));
    }
    rotatedRiv2.push_back(calcedNum);
  }
  sort(rotatedRiv2.begin(), rotatedRiv2.end(), less_abs());
  cout << len2 << " ";
  for(auto x : rotatedRiv2) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
