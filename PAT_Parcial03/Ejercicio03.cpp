#include "Ejercicio03.h"
#include <unordered_map>
#include <string>
#include <map>
using namespace std;

TimeMap::TimeMap()
{
}

void TimeMap::set(string key, string value, int timestamp)
{
    if (mapa.find(key) == mapa.end()) {
        mapa[key] = map<int, string>();

    }
    mapa[key][timestamp] = value;
}

string TimeMap::get(string key, int timestamp)
{
    if (mapa.find(key) == mapa.end()) {
        return "";
    }

    auto& map2 = mapa[key];
    auto it = map2.upper_bound(timestamp);

    if (it == map2.begin()) {
        return "";
    }

    --it;
    return it->second;
}