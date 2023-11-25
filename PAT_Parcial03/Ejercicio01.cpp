#include "Ejercicio01.h"
#include <queue>
using namespace std;
bool Ejercicio01::comparacion(const Node<int>* a, const Node<int>* b) {
    return a->value < b->value;  // Cambia el operador según el orden que necesites
}
Node<int>* Ejercicio01::mergeLists(Node<Node<int>*>* lists)
{
    if (!lists) return nullptr;

    // Definir una cola de prioridad basada en una lista enlazada
    priority_queue<Node<int>*, vector<Node<int>*>, decltype(&comparacion)> comp(&comparacion);

    // Insertar todas las listas en la cola de prioridad
    while (lists) {
        if (lists->value) {
            comp.push(lists->value);
        }
        lists = lists->next;
    }

    Node<int>* dummy = new Node<int>{ 0 };
    Node<int>* tail = dummy;

    // Extraer y fusionar elementos de la cola de prioridad
    while (!comp.empty()) {
        tail->next = comp.top();
        comp.pop();
        tail = tail->next;

        if (tail->next)
            comp.push(tail->next);
    }

    return dummy->next;
}
