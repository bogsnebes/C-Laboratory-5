#pragma once
#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>

using namespace std;

class Client {
    public:
    Client() {
    }
    void setFio(char *value) {
        this -> fio = value;
    }
    void setAdress(char *value) {
        this -> adress = value;
    }
    void setDiscount(int value) {
        if (value <= 100 and value >= 0)
            this -> discount = value;
    }
    char* getFio() {
        return this->fio;
    }
    char* getAdress() {
        return this->adress;
    }
    int getDiscount() {
        return this->discount;
    }
    Client(char *name, char *adress, int discount) {
        setFio(name);
        setAdress(adress);
        setDiscount(discount);
    }
    void showClient() {
        setlocale(0, "");
        cout << "Name client:" << getFio() << endl;
        cout << "Adress client:" << getAdress() << endl;
        cout << "Discount client:" << getDiscount() << endl;
        cout << endl;
    }
    ~Client() {}
    bool operator==(Client &value) {
        if (string(fio) == string(value.getFio()) and string(adress) == string(value.getAdress()) and discount == value.getDiscount())
            return true;
        return false;
    }

    void operator=(Client &value) {
        this->fio = value.getFio();
        this->adress = value.getAdress();
        this->discount = value.getDiscount();
    }
    private:
    char *fio;
    char *adress;
    int discount;
};
#endif