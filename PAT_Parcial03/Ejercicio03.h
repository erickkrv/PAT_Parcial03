#pragma once

#include <string>
#include <unordered_map>
#include <map>

using namespace std;


using std::string;
class TimeMap
{
private:
	struct valor {
		int timestamp;
		string value;
	};
	unordered_map<string, vector<valor>> map;
public:
	TimeMap();

	void set(string key, string value, int timestamp);

	string get(string key, int timestamp);

};

