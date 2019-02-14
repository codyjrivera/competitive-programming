#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>

template<typename Container>
void print(const Container& v) {
	std::ostringstream ss; // include sstream
	ss << '{';
	for(auto e : v) {
		ss << e << ", ";
	}
	if(v.size()) {
		ss.seekp(-2, ss.cur); // go back over last ,
	}
	ss << "}\n";
	std::cout << ss.str(); // include iostream
}

class IntAndStrings {
public:
	long long int number;
	std::vector<std::string> strings; // include vector and string

	// overload < operator so we can sort
	bool operator<(const IntAndStrings& rhs) const {
		if(number == rhs.number) { // sort on strings if numbers are equal
			unsigned int minStringCount = std::min(strings.size(), rhs.strings.size()); // include algorithm
			for(int i = 0; i < minStringCount; i++) { // sort on strings
				int strcmp = strings.at(i).compare(rhs.strings.at(i));
				if(strcmp) {
					return strcmp < 0;
				}
			}
			// all strings were equal
			return strings.size() < rhs.strings.size(); // sort on number of strings.
		}
		// numbers are not equal so did not sort on strings
		return number < rhs.number; 
	}

	// overload << operator so we can print - this gets defined outside the class
	friend std::ostream& operator<<(std::ostream&, const IntAndStrings&);

	// Constructors
	IntAndStrings() {}
	IntAndStrings(long long int i) : number(i) {}
	IntAndStrings(long long int i, std::vector<std::string> sv) : number(i), strings(sv) {}
	IntAndStrings(long long int i, std::string s) : number(i) {
		std::vector<std::string> sv = {s};
		strings = sv;
	}

	// Methods
	void add(std::string s) {
		strings.push_back(s);
	}
	void add(std::vector<std::string> s) {
		strings.insert(strings.end(), s.begin(), s.end());
	}
};

// Definition for friend operator to IntAndStrings
std::ostream& operator<<(std::ostream& stream, const IntAndStrings& ias) {
	std::ostringstream ss;
	ss << ias.number << ": [";
	for(std::string s : ias.strings) {
		ss << '"' << s << "\",";
	}
	if(ias.strings.size()) {
		ss.seekp(-1, ss.cur);
	}
	ss << "]";
	stream << ss.str();
	return stream;
}

int main() {
	std::vector<int> v = {1, 2}; // include vector
	v.push_back(3); // {1, 2, 3}
	print(v);
	v.pop_back(); // {1, 2}
	print(v);
	v.push_back(4); // {1, 2, 4}
	print(v);
	v.at(1) = 3; // {1, 3, 4}
	print(v);
	v.erase(v.begin()); // {3, 4}
	print(v);
	std::vector<int> v2 = {7, 2, 24, 1, -6};
	v.insert(v.begin() + 1, v2.begin(), v2.end()); // {3, 7, 2, 24, 1, -6, 4}
	print(v);
	v.insert(v.begin() + 2, 0); // {3, 7, 0, 2, 24, 1, -6, 4}
	print(v);
	std::cout << v.empty() << '\n'; // 0 (false)
	if(std::find(v.begin(), v.end(), -6) != v.end()) { // include algorithm
		std::cout << "v contains -6\n";
	}
	std::cout << "max is " << *max_element(v.begin(), v.end()) << '\n'; // include algorithm
	v.erase(min_element(v.begin(), v.end())); // erase min element
	print(v);
	if(std::find(v.begin(), v.end(), -6) == v.end()) { // include algorithm
		std::cout << "v does not contain -6\n";
	}
	std::sort(v.begin(), v.end()); // include algorithm
	print(v); // {0, 1, 2, 3, 4, 7, 24}
	std::sort(v.begin(), v.end(), std::greater<int>()); // include algorithm
	print(v); // {24, 7, 4, 3, 2, 1, 0}
	std::sort(v.rbegin(), v.rend(), std::greater<int>()); // sort from "reverse begin" to "reverse end" using "greater" - equivalent to normal sort
	print(v); // {0, 1, 2, 3, 4, 7, 24}


	std::deque<IntAndStrings> q = {IntAndStrings(1, "this is string"), IntAndStrings(2)}; //include deque
	print(q); // {1: ["this is string"], 2: []}
	q.at(0).add("another string");
	print(q); // {1: ["this is string","another string"], 2: []}
	std::vector<std::string> someStrings = {"string 1", "string 2", "string 3"};
	q.push_front(IntAndStrings(2, someStrings)); // this is why one would use a deque instead of a vector
	q.at(0).add("I am now greater than the other one with int 2");
	q.at(2).add(someStrings);
	print(q); // {2: ["string 1","string 2","string 3","I am now greater than the other one with int 2"], 1: ["this is string","another string"], 2: ["string 1","string 2","string 3"]}
	std::sort(q.begin(), q.end());
	print(q); // {1: ["this is string","another string"], 2: ["string 1","string 2","string 3"], 2: ["string 1","string 2","string 3","I am now greater than the other one with int 2"]}
	q.erase(q.begin(), q.begin() + 2); // this is faster than with a vector
	print(q); // {2: ["string 1","string 2","string 3","I am now greater than the other one with int 2"]}

	return 0;
}