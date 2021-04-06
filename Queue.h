#include "Client.h"
#include <string.h>

class Queue {
    public:
    // Constructors
    Queue(int value) {
        list = new Client[value];
        free = new bool[value];
        this->count = value;
        for (int i = 0; i < value; i++) {
            free[i] = false;
            Client NewClient = Client(_strdup("0"), _strdup("0"), -1);
            list[i] = NewClient;
        }
    }
    ~Queue() {}

    Queue copyQueue() {
        Queue queueTwo = Queue(count);
        for(int i = 0; i < count; i++) {
            if (free[i] == true) {
                queueTwo.enqueue(list[i]);
            }
        }
        return queueTwo;
    }

    // Enqueue

    void enqueue(Client &value) {
            for(int i = 0; i < count; i++) {
            if (free[i] == false) {
                if ((i + 1) != count) {
                    if (free[i+1] == true) {
                list[i] = list[i+1];
                free[i+1] = false;
                free[i] = true;
                }
                }
                else {
                    list[i] = value;
                    free[i] = true;
                }
            }
        }

    }

    void enqueue(char *name, char *adress, int discount) {
            for(int i = 0; i < count; i++) {
            if (free[i] == false) {
                if ((i + 1) != count) {
                    if (free[i+1] == true) {
                list[i] = list[i+1];
                free[i+1] = false;
                free[i] = true;
                }
                }
                else {
                    Client NewClient = Client(name, adress, discount);
                    list[i] = NewClient;
                    free[i] = true;
                }
            }
        }
    }

    // /enqueue

    Client dequeue() {
            for(int i = 0; i < count; i++) {
            if (free[i] == false) {
                if ((i + 1) != count) {
                    if (free[i+1] == true) {
                list[i] = list[i+1];
                free[i+1] = false;
                free[i] = true;
                }
                }
            }
            }
            if (free[0] != false) {
                Client buffer = list[0];
                Client NewClient = Client(_strdup("0"), _strdup("0"), -1);
                list[0] = NewClient;
                free[0] = false;
                return buffer;
            }
            else {
                Client NewClient = Client(_strdup("0"), _strdup("0"), -1);
                return NewClient;
            }
    }

    void extend(Queue &value) {
        Queue buffer = this->copyQueue();
        delete[] list;
        delete[] free;
        int outcomeCount = (value.getCount() + buffer.getCount());
        this->list = new Client[outcomeCount];
        this->free = new bool[outcomeCount];
        this->count = outcomeCount;
        for (int i = 0; i < outcomeCount; i++) {
            free[i] = false;
            Client NewClient = Client(_strdup("0"), _strdup("0"), -1);
            list[i] = NewClient;
        }
        for (int i = 0; i < buffer.getCount(); i++) {
            free[i] = (buffer.getFree())[i];
            list[i] = (buffer.getList())[i];
        }
        for (int i = 0; i < value.getCount(); i++) {
            free[buffer.getCount() + i] = (value.getFree())[i];
            list[buffer.getCount() + i] = (value.getList())[i];
        }
    }

    void showQueue() {
        for (int i = 0; i < count; i++) {
            if (free[i] == true) {
                list[i].showClient();
                cout << "------------------------" << endl;
                cout << endl;
            }
        }
    }

    int getCount() {
        return this->count;
    }

    Client* getList() {
        return this->list;
    }

    bool* getFree() {
        return this->free;
    }

    Client operator[](int value) {
        if (free[value] == false) {
            Client NewClient = Client(_strdup("0"), _strdup("0"), 0);
            return NewClient;
        }
        return list[value];
    }

    Queue next() {
        for (int i = 0; i < count; i++) {
            if (free[i] == false) {
                if ((i + 1) != count) {
                    if (free[i + 1] == true) {
                        list[i] = list[i + 1];
                        free[i + 1] = false;
                        free[i] = true;
                    }
                }
            }
        }
        if (free[0] != false) {
            Client bufferClient = list[0];
            Client NewClient = Client(_strdup("0"), _strdup("0"), -1);
            list[0] = NewClient;
            free[0] = false;
            Queue bufferQueue = this->copyQueue();
            list[0] = bufferClient;
            free[0] = true;
            return this->copyQueue();
        }
        else {
            return this->copyQueue();
        }
    }

    string display() {
        for (int i = 0; i < count; i++) {
            if (free[i] == false) {
                if ((i + 1) != count) {
                    if (free[i + 1] == true) {
                        list[i] = list[i + 1];
                        free[i + 1] = false;
                        free[i] = true;
                    }
                }
            }
        }
        string stringQueue = "[";
        stringQueue += string(list[0].getFio()) + ", " + string(list[0].getAdress());
        for (int i = 1; i < count; i++) {
            if (free[i] == true)
            stringQueue += " -> " + string(list[i].getFio()) + ", " + string(list[i].getAdress());
        }
        stringQueue += "]";
        return stringQueue;
    }

    int checkQueue() {
        int countFree = 0;
        for (int i = 0; i < count; i++) {
            if (free[i] == false) {
                countFree += 1;
            }
            return (count - countFree);
        }
    }

    private:
    Client *list;
    bool *free;
    int count;
};