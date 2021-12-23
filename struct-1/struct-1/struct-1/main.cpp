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

void KB::showRecord() {
    cout << "  Название: " << this->name << endl;
    cout << "   Маршрут: " << this->route << endl;
    cout << "Количество: " << this->count << endl;
    cout << endl;
    //cout << this->getName() << " " << this->getPrice() << " " << this->getConnector() << endl;
}

int  SCANNER::getResolution() {
    return this -> resolution;
}

int SCANNER::setResolution (int r){
    int t = this -> resolution;
    this -> resolution = r;
    return t;
}
void SCANNER::showRecord() {
    cout << "  Название: " << this->getName() << endl;
    cout << "   Маршрут: " << this->route << endl;
    cout << "Количество: " << this->count << endl;
    cout << endl;
    //cout << this ->getName() << " " << this->getPrice() << " " << this -> getResolution() << endl;
 }


void showData(PUK *tr, bool showNumbers=false) {
    cout << endl << "============" << endl;
    for (int i=0; i<PUKS; i++) {
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

void KB::editRecord() {
    // tr -> this
    string name, route, sCount;
    int count;
    cin.clear(); cin.ignore(256, '\n');
    cout << "Правим запись" << endl;
    //
    cout << "Название [" << tr->getName() << "]: "; cout.flush();
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

void editData(PUK *tr) {
    cout << "Редактируем..." << endl;
    showData(tr, true);
    cout << "1-" << PUKS << ") Номер записи." << endl;
    cout << "q) Выход." << endl;
    cout << "Ваш выбор: ";
    cout.flush();
    string choice;
    cin >> choice;
    if (isNumber(choice)) {
        int inum=stoi(choice)-1;
        if (0 <= inum && inum < PUKS) editRecord(tr+inum);
        else cout << "Нет такой записи..." << endl;
    } else {
        if (choice[0] == 'q') return;
        cout << "Не понял..." << endl;
    }
}

void calcData(PUK *tr) {
    cout << "Вычисляем количаство путёвок..." << endl;
    int summaCount=0;
    for (int i=0; i < PUKS; i++) { summaCount+=tr[i].getPrice(); }
    cout << "Количество: " << summaCount/PUKS << endl;
}

int main(void) {
    PUK puks[PUKS]={
        KB("zopa", 64, "USB"),
        SCANNER("poppa", 100, 22)
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
