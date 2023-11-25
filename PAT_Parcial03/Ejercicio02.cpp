#include "Ejercicio02.h"
#include <unordered_map>
#include <string>
using namespace std;
vector<string>* Ejercicio02::findRepeatedDnaSequences(Node<char>* head)
{
	unordered_map<string, int> map;
	vector<string>* result = new vector<string>();
	Node<char>* actual = head;
	while (actual) {
		Node<char>* tempo = actual;
		string secuencia = "";
		for (int i = 0; i < 10 && tempo; i++) {
			secuencia += tempo->value;
			tempo = tempo->next;
		}
		if (secuencia.size() == 10) {
			if (map.find(secuencia) == map.end())
			{
				map[secuencia] = 1;
			}
			else {
				map[secuencia]++;
			}
		}
		actual = actual->next;
	}
	for (const auto& st : map) {
		if (st.second > 1) {
			result->push_back(st.first);
		}
	}
	return result;
}
