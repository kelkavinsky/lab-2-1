//
//  main.cpp
//  Task2
//
//  Created by Nikita Keler on 03.12.21.
//  Copyright © 2021 Nikita Keler. All rights reserved.
//

#include "task2.hpp"

Train::Train() {}

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

void Train::showRecord() {
    cout << "  Название: " << this->name << endl;
    cout << "   Маршрут: " << this->route << endl;
    cout << "Количество: " << this->count << endl;
    cout << endl;
}

void showData(Train tr[], bool showNumbers=false) {
    cout << endl << "============" << endl;
    for (int i=0; i<TRAINS; i++) {
        if (showNumbers) cout << i+1 << ") Номер записи." << endl;
        tr[i].showRecord();
    }
}

char showMenu(void) {
    cout << "s) Показать." << endl;
    cout << "c) Вычислить." << endl;
    cout << "e) Править." << endl;
    cout << "q) Выход." << endl;
    cout << "Выбор и ентер: ";
    cout.flush();
    char choice;
    cin >> choice;
    cin.ignore(256,'\n');
    return choice;
}

void editRecord(Train *tr) {
    string name, route, sCount;
    int count;
    cin.clear(); cin.ignore(256, '\n');
    cout << "Правим запись" << endl;
    //
    cout << "Название [" << tr->getName() << "]: "; cout.flush();
    getline(cin, name);
    if (name == "") name=tr->getName();
    //
    cout << "Маршрут [" << tr->getRoute() << "]: "; cout.flush();
    getline(cin, route);
    if (route == "") route=tr->getRoute();
    //
    cout << "Количество [" << tr->getCount() << "]: "; cout.flush();
    getline(cin, sCount);
    if (sCount == "") count=tr->getCount();
    else count=stoi(sCount); // isNumber?
    //
    *tr=Train(name, route, count);
}

bool isNumber(const string &str) {
    return !str.empty() && str.find_first_not_of("0123456789") == string::npos;
}

void editData(Train tr[]) {
    cout << "Редактируем..." << endl;
    showData(tr, true);
    cout << "1-" << TRAINS << ") Номер записи." << endl;
    cout << "q) Выход." << endl;
    cout << "Ваш выбор: ";
    cout.flush();
    string choice;
    cin >> choice;
    if (isNumber(choice)) {
        int inum=stoi(choice)-1;
        if (0 <= inum && inum < TRAINS) editRecord(tr+inum);
        else cout << "Нет такой записи..." << endl;
    } else {
        if (choice[0] == 'q') return;
        cout << "Не понял..." << endl;
    }
}

void calcData(Train tr[]) {
    cout << "Вычисляем количаство путёвок..." << endl;
    int summaCount=0;
    for (int i=0; i < TRAINS; i++) { summaCount+=tr[i].getCount(); }
    cout << "Количество: " << summaCount << endl;
}

int main(void) {
    Train trains[TRAINS]={
        Train("zopa", "xxxxx", 64),
        Train("zzzzzopa", "xyyyxxxx", 22)
    };
    trains[0].setName("qaz");
    showData(trains);
    bool keepMenu=true;
    while (keepMenu) {
        switch (showMenu()) {
            case 'q':
                keepMenu=false;
                cout << "Всего хорошего." << endl;
                break;
            case 's':
                showData(trains);
                break;
            case 'e':
                editData(trains);
                break;
            case 'c':
                calcData(trains);
                break;
            default:
                cout << "Не понял..." << endl;
        }
    }
}

