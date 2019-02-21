#include <bits/stdc++.h>
using namespace std;
int DB = 0;

template<typename T>
string dbs(T const &v) {
	ostringstream o;
	o << v;
	return o.str();
}

template<typename T1, typename T2>
string dbs(pair<T1, T2> const &v) {
	return string("[ ") + dbs(v.first) + ", " + dbs(v.second) + " ]";
}

template<typename T1, typename T2>
string dbs(map<T1, T2> const &v) {
	string o("[");
	for(auto x : v) {
		o += " " + dbs(x.first) + ": " + dbs(x.second) + ",";
	}
	o.pop_back();
	return o + " }";
}

template<template<typename, typename...> class T1, typename... T2>
string dbs(T1<T2...> const &v) {
	string o("{");
	for(auto x : v) {
		o += " " + dbs(x) + ",";
	}
	o.pop_back();
	return o + " }";
}

template<typename T>
void db(T const &v) {
	if(!DB) return;
	cerr << dbs(v) << endl;
}

int main(int argc, char *argv[]) {
	DB = argc - 1;
	(void) argv;

	string v = "a string";
	db(v);

	vector<int> v2 = {0, 1, 7};
	db(v2); 
	
	map<string, pair<int, double>> v30, v31;
	v30["this"] = make_pair(77, 8.65);
	v30["that"] = make_pair(1, -6.3);
	v31["other"] = make_pair(-54, 3);
	v31["s"] = make_pair('s', M_PI);
	deque<map<string, pair<int, double>>> v3 = {v30, v31};
	db(v3);
}