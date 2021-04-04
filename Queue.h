#include "Client.h"
#include <string.h>

class Queue {
    public:
    // Constructor
    Queue(int value) {
        list = new Client[value];
        free = new bool[value];
        this->count = value;
    }
    ~Queue() {}

    private:
    Client *list;
    bool *free;
    int count;
};