//
//  main.cpp
//  Task2
//
//  Created by Nikita Keler on 03.12.21.
//  Copyright © 2021 Nikita Keler. All rights reserved.
//

#include "task2.hpp"

Train::Train() {
    this->name = "";
    this->route = "";
    this->count = 0;
}

Train::Train(string n, string r, int c) {
    this->name = n;
    this->route = r;
    this->count = c;
}

string Train::getName() {
    return this->name;
}

string Train::setName(string n) {
    string s = this->name;
    this->name = n;
    return s;
}

string Train::getRoute() {
    return this->route;
}

string Train::setRoute(string r) {
    string s = this->route;
    this->route = r;
    return s;
}

int Train::getCount() {
    return this->count;
}

int Train::setCount(int c) {
    int s = this->count;
    this->count = c;
    return s;
}

int main(void) {
    Train *t = new Train("qaz","wsx",5);
    cout << t->getName() << endl;
    cout << t->getRoute() << endl;
    cout << t->getCount() << endl;
    //
}

