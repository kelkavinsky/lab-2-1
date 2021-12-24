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
    cout << "  Название: " << this->getName() << endl;
    cout << "      Цена: " << this->getPrice() << endl;
    cout << "    Разьем: " << this->getConnector() << endl;
    cout << endl;
}

int SCANNER::getResolution() {
    return this -> resolution;
}

int SCANNER::setResolution (int r){
    int t = this -> resolution;
    this -> resolution = r;
    return t;
}

void SCANNER::showRecord() {
    cout << "  Название: " << this->getName() << endl;
    cout << "      Цена: " << this->getPrice() << endl;
    cout << "Разрешение: " << this->getResolution() << endl;
    cout << endl;
 }


void showData(PUK *tr[], bool showNumbers=false) {
    cout << endl << "============" << endl;
    for (int i=0; i<PUKS; i++) {
        if (showNumbers) cout << i+1 << ") Номер записи." << endl;
        tr[i]->showRecord();
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

void PUK::editRecord() {
    string name, sPrice;
    int price;
    cin.clear(); cin.ignore(256, '\n');
    cout << "Правим запись" << endl;
    //
    cout << "Название [" << this->getName() << "]: "; cout.flush();
    getline(cin, name);
    if (name == "") name=this->getName();
    //
    cout << "Цена [" << this->getPrice() << "]: "; cout.flush();
    getline(cin, sPrice);
    if (sPrice == "") price=this->getPrice();
    else price=stoi(sPrice); // isNumber?
    //
    this->setName(name);
    this->setPrice(price);
}

void KB::editRecord() {
    this->PUK::editRecord();
    string connector;
    //cin.clear(); cin.ignore(256, '\n');
    cout << "Разъём [" << this->getConnector() << "]: "; cout.flush();
    getline(cin, connector);
    if (connector == "") connector=this->getConnector();
    this->setConnector(connector);
}

void SCANNER::editRecord() {
    this->PUK::editRecord();
    string sResolution;
    int resolution;
    //cin.clear(); cin.ignore(256, '\n');
    cout << "Разрешение [" << this->getResolution() << "]: "; cout.flush();
    getline(cin, sResolution);
    if (sResolution == "") resolution=this->getResolution();
    else resolution=stoi(sResolution);
    this->setResolution(resolution);
}

bool isNumber(const string &str) {
    return !str.empty() && str.find_first_not_of("0123456789") == string::npos;
}

void editData(PUK *tr[]) {
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
        if (0 <= inum && inum < PUKS) tr[inum]->editRecord();
        else cout << "Нет такой записи..." << endl;
    } else {
        if (choice[0] == 'q') return;
        cout << "Не понял..." << endl;
    }
}

void calcData(PUK *tr[]) {
    cout << "Вычисляем среднюю цену..." << endl;
    int summaCount=0;
    for (int i=0; i < PUKS; i++) { summaCount+=tr[i]->getPrice(); }
    cout << "Средняя цена: " << summaCount/PUKS << endl;
}

int main(void) {
//    PUK *puks[PUKS]={
//        KB("zopa", 64, "USB"),
//        SCANNER("poppa", 100, 22)
//    };
    PUK *puks[PUKS];
    puks[0]=new KB("zopa", 64, "USB");
    puks[1]=new SCANNER("poppa", 100, 22);
    showData(puks);
    bool keepMenu=true;
    while (keepMenu) {
        switch (showMenu()) {
            case 'q':
                keepMenu=false;
                cout << "Всего хорошего." << endl;
                break;
            case 's':
                showData(puks);
                break;
            case 'e':
                editData(puks);
                break;
            case 'c':
                calcData(puks);
                break;
            default:
                cout << "Не понял..." << endl;
        }
    }
}
