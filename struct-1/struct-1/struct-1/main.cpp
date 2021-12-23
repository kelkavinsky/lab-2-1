//
//  main.cpp
//  struct-1
//
//  Created by Nikita Keler on 13.12.21.
//  Copyright © 2021 Nikita Keler. All rights reserved.
//

#include "struct1.h"

string PUK::getName() {
    return this->name;
}

string PUK::setName(string n) {
    string s = this->name;
    this->name = n;
    return s;
}

int PUK::getPrice() {
    return this->price;
}

int PUK::setPrice(int p) {
    int s = this->price;
    this->price = p;
    return s;
}

string KB::getConnector() {
    return this->connector;
}

string KB::setConnector(string c) {
    string s = this->connector;
    this->connector = c;
    return s;
}

void KB::showRecord(bool num) {
    cout << this->getName() << " " << this->getPrice() << " " << this->getConnector() << endl;
}



int main(int argc, const char * argv[]) {
    KB k;
//    PUK p;
//    p.setName("zzzz");
//    p.setPrice(456);
    k.setName("blah");
    k.setPrice(123);
    k.setConnector("USB");
//    p.showRecord();
    k.showRecord();
    return 0;
}
