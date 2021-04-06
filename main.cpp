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
    list.extend(list_2);
    list.showQueue();
    (list.next()).showQueue();
    cout << list.display();
}
