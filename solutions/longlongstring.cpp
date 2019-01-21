#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class delta {
  public:
  long long int left, right;
  int offset;
  bool contains(long long int position) {
    return (left + offset <= position && (right == -1 || position <= right + offset));
  }
};

class insertion {
public:
  long long int position;
  char value;
  bool operator<(const insertion_struct &rhs) const { return position < rhs.position; }
};

struct results {
  vector<delta> deltas;
  vector<insertion> insertions;
};

struct operation {
  bool type; //0 for delete, 1 for insert
  char value;
  long long int position;
};

results evaluate(vector<operation> program) {
  results r;
  r.deltas = {}; r.insertions = {};
  delta initial_d; initial_d.left = 0; initial_d.right = -1; initial_d.offset = 0;
  r.deltas.push_back(initial_d);
  for(operation o : program) {
    int containing_delta = -1;
    for(int i = 0; i < r.deltas.size(); i++) {
      if(r.deltas.at(i).contains(o.position)) {
        containing_delta = i;
        break;
      }
    }
    if(o.type) {
      // Insert
      if(containing_delta != -1) {
        delta new1, new2;
        delta old = r.deltas.at(containing_delta);
        new1.left = old.left;
        new1.right = o.position - old.offset - 1;
        new1.offset = old.offset;
        new2.left = o.position - old.offset;
        new2.right = old.right;
        new2.offset = old.offset + 1;
        r.deltas.erase(r.deltas.begin() + containing_delta);
        r.deltas.insert(r.deltas.begin() + containing_delta, new2);
        r.deltas.insert(r.deltas.begin() + containing_delta, new1);
        for(int i = containing_delta + 2; i < r.deltas.size(); i++) {
          r.deltas.at(i).offset++;
        }
      }
      else {
        for(int i = 0; i < r.deltas.size(); i++) {
          if(r.deltas.at(i).left + r.deltas.at(i).offset > o.position) r.deltas.at(i).offset++;
        }
      }
      for(int i = 0; i < r.insertions.size(); i++) {
        if(r.insertions.at(i).position >= o.position) {
          r.insertions.at(i).position++;
        }
      }
      insertion ins;
      ins.position = o.position;
      ins.value = o.value;
      r.insertions.push_back(ins);
    }
    else {
      // Delete
      if(containing_delta != -1) {
        delta new1, new2;
        delta old = r.deltas.at(containing_delta);
        new1.left = old.left;
        new1.right = o.position - old.offset - 1;
        new1.offset = old.offset;
        new2.left = o.position - old.offset + 1;
        new2.right = old.right;
        new2.offset = old.offset - 1;
        r.deltas.erase(r.deltas.begin() + containing_delta);
        r.deltas.insert(r.deltas.begin() + containing_delta, new2);
        r.deltas.insert(r.deltas.begin() + containing_delta, new1);
        for(int i = containing_delta + 2; i < r.deltas.size(); i++) {
          r.deltas.at(i).offset--;
        }
      }
      else {
        for(int i = 0; i < r.deltas.size(); i++) {
          if(r.deltas.at(i).left + r.deltas.at(i).offset > o.position) r.deltas.at(i).offset--;
        }
      }
      for(int i = 0; i < r.insertions.size(); i++) {
        if(r.insertions.at(i).position > o.position) {
          r.insertions.at(i).position--;
        }
        else if(r.insertions.at(i).position == o.position) {
          r.insertions.erase(r.insertions.begin() + (i--));
        }
      }
    }
  }
  for(int i = 0; i < r.deltas.size() - 1; i++) {
    if(r.deltas.at(i).left > r.deltas.at(i).right) {
      r.deltas.erase(r.deltas.begin() + (i--));
      continue;
    }
    if(r.deltas.at(i).offset == r.deltas.at(i+1).offset) {
      delta newd;
      delta old1 = r.deltas.at(i);
      delta old2 = r.deltas.at(i+1);
      newd.left = old1.left;
      newd.right = old2.right;
      newd.offset = old1.offset;
      r.deltas.erase(r.deltas.begin() + i);
      r.deltas.erase(r.deltas.begin() + i);
      r.deltas.insert(r.deltas.begin() + (i--), newd);
    }
  }
  return r;
}

int compare_results(results result1, results result2) {
  if(result1.deltas.size() != result2.deltas.size() || result1.insertions.size() != result2.insertions.size()) return 1;
  sort(result1.insertions.begin(), result1.insertions.end());
  sort(result2.insertions.begin(), result2.insertions.end());
  for(int i = 0; i < result1.deltas.size(); i++) {
    delta d1 = result1.deltas.at(i);
    delta d2 = result2.deltas.at(i);
    if(d1.left != d2.left || d1.right != d2.right || d1.offset != d2.offset) return 1;
  }
  for(int i = 0; i < result1.insertions.size(); i++) {
    insertion d1 = result1.insertions.at(i);
    insertion d2 = result2.insertions.at(i);
    if(d1.position != d2.position || d1.value != d2.value) return 1;
  }
  return 0;
}

int main(void) {
  vector<vector<operation>> programs;
  vector<operation> program;
  for(;;) {
    string token;
    cin >> token;
    if(token == "END") break;
    else if(token == "E") {
      programs.push_back(program);
      if(programs.size() == 2) {
        cout << compare_results(evaluate(programs.at(0)), evaluate(programs.at(1))) << endl;
        programs.clear();
      }
      program.clear();
      continue;
    }
    operation o;
    if(token == "I") {
      o.type = 1;
      cin >> o.position >> o.value;
    }
    else if(token == "D") {
      o.type = 0;
      cin >> o.position;
    }
    program.push_back(o);
  }
  return 0;
}
