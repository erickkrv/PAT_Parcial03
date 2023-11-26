#pragma once

#include <string>
#include <unordered_map>
#include <map>
using namespace std;


using std::string;

class TimeMap
{
private:
	unordered_map<string, map<int, string>> mapa;
public:
	TimeMap();

	void set(string key, string value, int timestamp);

	string get(string key, int timestamp);
};

