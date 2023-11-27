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
    map[key].emplace_back(valor{ timestamp, value });
}

string TimeMap::get(string key, int timestamp)
{
    if (map.find(key) == map.end())
        return "";

    vector<valor>& valores = map[key];

    int inicio = 0, medio = 0, fin = valores.size();

    if (valores[inicio].timestamp > timestamp)
        return "";

    if (valores[fin - 1].timestamp <= timestamp)
        return valores[fin - 1].value;

    while (inicio < fin) {
        medio = (fin + inicio) >> 1;

        if (valores[medio].timestamp == timestamp)
            return valores[medio].value;

        if (valores[medio].timestamp < timestamp)
            inicio = medio + 1;
        else
            fin = medio;
    }

    return valores[medio].value;
}
