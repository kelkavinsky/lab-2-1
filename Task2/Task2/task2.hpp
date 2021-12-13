//
//  task2.hpp
//  Task1
//  10 вариант
//  Количество строк: 4. Столбцы: Название турфирмы, Маршрут, Количество оставшихся путевок. Вычислить общее количество оставшихся путевок.
//  Created by Nikita Keler on 02.12.21.
//  Copyright © 2021 Nikita Keler. All rights reserved.
//

#ifndef task2_hpp
#define task2_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Train {
private:
    string name;
    string route;
    int count;
public:
    string getName();
    string setName(string n);
    string getRoute();
    string setRoute(string r);
    int getCount();
    int setCount(int c);
};

#endif /* task2_hpp */

