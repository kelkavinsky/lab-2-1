#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
///
const int file_size = 4;
const string file_name = "/Users/nikita/lab/task1.txt";


typedef struct sTask1 {
    string name;
    string route;
    string version;
    int count;
} Task1;

Task1* pData;

Task1 readLine(string line) {
    istringstream ss(line);
    Task1 rec;
    ss >> rec.name;
    ss >> rec.route;
   
    ss >> rec.count;
    return rec;
}

void showRecord(int i) {
    cout << "   Название: " << pData[i].name << endl;
    cout << "Разработчик: " << pData[i].route << endl;
    
    cout << "        Год: " << pData[i].count << endl;
    cout << endl;
}

void showData(bool num=false) {
    cout << endl << "============" << endl;
    for (int i=0; i < file_size; i++) {
        if (num) cout << i+1 << ") Номер записи." << endl;
        showRecord(i);
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

void writeData(void) {
    cout << "Записываем данные..." << endl;
    ofstream file(file_name);
    for (int i=0; i < file_size; i++) {
        file << pData[i].name << " ";
        file << pData[i].route << " ";
        
        file << pData[i].count << endl;
    }
    file.close();
}

void editRecord(int i) {
    Task1 rec=pData[i];
    
    
    cin.clear(); cin.ignore(256, '\n');
    cout << "Правим запись № " << i+1 << endl;
    //
    cout << "Название программы [" << pData[i].name << "]: "; cout.flush();
    getline(cin, rec.name);
    if (rec.name == "") rec.name=pData[i].name;
    //
    cout << "Разработчик [" << pData[i].route << "]: "; cout.flush();
    getline(cin, rec.route);
    if (rec.route == "") rec.route=pData[i].route;
    //
  
    //
    string count;
    cout << "Год [" << pData[i].count << "]: "; cout.flush();
    getline(cin, count);
    if (count == "") rec.count=pData[i].count;
    else rec.count=stoi(count);
    
    pData[i]=rec;
}

bool isNumber(const string &str) {
    return !str.empty() && str.find_first_not_of("0123456789") == string::npos;
}

void editData(void) {
    cout << "Редактируем..." << endl;
    showData(true);
    cout << "1-9) Номер записи." << endl;
    cout << "q) Выход." << endl;
    cout << "Ваш выбор: ";
    cout.flush();
    string choice;
    cin >> choice;
    if (isNumber(choice)) {
        int inum=stoi(choice)-1;
        
        if (0 <= inum && inum < file_size) editRecord(inum);
        else cout << "Нет такой записи..." << endl;
    } else {
        if (choice[0] == 'q') return;
        cout << "Не понял..." << endl;
    }
}

void calcData(void) {
    cout << "Вычисляем общее количество путевок..." << endl;
    int summa = 0;
    for (int i=0; i < 4; i++) { summa+=pData[i].count; }
    cout << "Количество: " << summa << endl;
    
        }




int main(void) {
    pData = new Task1[file_size];
    ifstream file(file_name);
    if (file.is_open()) {
        for (int i=0; i < file_size; i++) {
            string line;
            getline(file, line);
            cout << "Читаю: " << line << endl;
            pData[i] = readLine(line);
        }
    } else {
        cout << "Файл не открыть." << endl;
        return 1;
    }
    file.close();
    showData();
    bool keepMenu=true;
    while (keepMenu) {
        switch (showMenu()) {
            case 'q':
                keepMenu=false;
                writeData();
                cout << "Всего хорошего." << endl;
                break;
            case 's':
                showData();
                break;
            case 'e':
                editData();
                break;
            case 'c':
                calcData();
                break;
            default:
                cout << "Не понял..." << endl;
        }
    }
}

