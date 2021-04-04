#include "Client.h"
#include <string.h>

class Queue {
    public:
    // Constructors
    Queue(int value) {
        list = new Client[value];
        free = new bool[value];
        this->count = value;
    }
    ~Queue() {}

    void copyQueue() {
    }

    // Enqueue

    void enqueue(Client &value) {
            for(int i = 0; i < count; i++) {
            if (free[i] == false) {
                if ((i + 1) != count) {
                list[i] = list[i+1];
                free[i+1] = false;
                free[i] = true;
                }
                else {
                    list[i] = value;
                    free[i] = true;
                }
            }
        }
            throw "Ячейки в памяти закончились!";
    }

    void enqueue(char *name, char *adress, int discount) {
            for(int i = 0; i < count; i++) {
            if (free[i] == false) {
                if ((i + 1) != count) {
                list[i] = list[i+1];
                free[i+1] = false;
                free[i] = true;
                }
                else {
                    Client NewClient = Client(name, adress, discount);
                    list[i] = NewClient;
                    free[i] = true;
                }
            }
        }
            throw "Ячейки в памяти закончились!";
    }

    private:
    Client *list;
    bool *free;
    int count;
};