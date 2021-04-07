#include <iostream>
#include <string.h>
#include "Client.h"
#include "Queue.h"

using namespace std;

int main() {
    Queue list = Queue(3);
    // Test enqueue()
    Client object = Client(_strdup("Cantik"), _strdup("Boscow"), 23);
    list.enqueue(object);
    list.enqueue(_strdup("Bogdan"), _strdup("Moscow"), 40);
    // Test copyQueue()
    (list.copyQueue()).showQueue();
    (list.dequeue()).showClient();
    // Test extend()
    Queue list_2 = list.copyQueue();
    list_2.enqueue(object);
    list.extend(list_2);
    list.showQueue();
    // Test next()
    (list.next()).showQueue();
    // Test display()
    cout << list.display() << endl;
    // Test checkQueue()
    cout << list.checkQueue() << endl;
    // Test operator=
    list_2 = list;
    list_2.showQueue();
    // Test operator+=
    list += list_2;
    list.showQueue();
    // Test operator+
    Queue list_3 = list + list_2;
    list_3.showQueue();
    // Test operator==
    if (list == list_2) {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}
