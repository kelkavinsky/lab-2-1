//
//  struct1.h
//  struct-1
//
//  Created by Nikita Keler on 24.12.21.
//  Copyright © 2021 Nikita Keler. All rights reserved.
//

#ifndef struct1_h
#define struct1_h

#define PUKS (2)

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class PUK {
private:
    int price;
    string name;
public:
    PUK() {};
    PUK(string n, int p) {
        this->setName(n);
        this->setPrice(p);
    };
    // Наследуемые методы.
    int getPrice();
    int setPrice(int p);
    string getName();
    string setName(string n);
    // Переопределяемый метод.
    virtual void showRecord(){};
    virtual void editRecord();
};

class KB: public PUK {
private:
    string connector;
public:
    KB() {};
    KB(string n, int p, string c): PUK(n, p) {
        this->setConnector(c);
    };
    // Собственные методы.
    string getConnector();
    string setConnector(string c);
    // Переопределяемый метод.
    virtual void showRecord();
    virtual void editRecord();
};

class SCANNER: public PUK {
private:
    int resolution;
public:
    SCANNER() {};
    SCANNER(string n, int p, int r): PUK(n, p) {
        this->setResolution(r);
    };
    // Собственные методы.
    int getResolution();
    int setResolution(int r);
    // Переопределяемый метод.
    virtual void showRecord();
    virtual void editRecord();
};

#endif /* struct1_h */
