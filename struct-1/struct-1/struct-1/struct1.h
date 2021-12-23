//
//  struct1.h
//  struct-1
//
//  Created by Nikita Keler on 24.12.21.
//  Copyright © 2021 Nikita Keler. All rights reserved.
//

#ifndef struct1_h
#define struct1_h

#include <iostream>
#include <string>

using namespace std;

class PUK {
private:
    int price;
    string name;
public:
    // Наследуемые методы.
    int getPrice();
    int setPrice(int p);
    string getName();
    string setName(string n);
    // Переопределяемый метод.
    virtual void showRecord(bool num=false) = 0;
};

class KB: public PUK {
private:
    string connector;
public:
    // Собственные методы.
    string getConnector();
    string setConnector(string c);
    // Переопределяемый метод.
    virtual void showRecord(bool num=false);
};

class SCANNER: public PUK {
private:
    int resolution;
public:
    // Собственные методы.
    int getResolution();
    int setResolution(int r);
    // Переопределяемый метод.
    virtual void showRecord(bool num=false);
};

#endif /* struct1_h */
