#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

struct rectangle {
  int x1, x2, y1, y2;
};

int main(void) {
  map<pair<int, int>, bool> pixelStates;
  vector<struct rectangle> rects;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    struct rectangle r;
    cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
    rects.push_back(r);
  }
  for(auto r : rects) {
    for(int x = r.x1; x < r.x2; x++) {
      for(int y = r.y1; y < r.y2; y++) {
        pair<int, int> coords = {x, y};
        auto it = pixelStates.find(coords);
        if(it != pixelStates.end()) {
          (*it).second = !(*it).second;
        }
        else {
          pixelStates.insert(map<pair<int, int>, bool>::value_type(coords, true));
        }
      }
    }
  }
  int count = 0;
  for(auto p : pixelStates) {
    if(p.second) count++;
  }
  cout << count << endl;
}
