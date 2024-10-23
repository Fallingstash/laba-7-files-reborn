// СОЛДАТОВ А. М.
// ПИ-241
// Задание : Работа с файлами; Вариант 10
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <format>

using namespace std;

class car {
    public: 
    string mark;
    string year;
    string surname;
    string CarId;
    
    car(const string& mar, const string& yea, const string& sur, const string& Id):
    mark(mar), year(yea), surname(sur), CarId(Id) {}
};
void Read(const string& FileName, vector<car>& cars) {
    ifstream path(FileName);
    if (!path.is_open()) 
        cerr << "Не удалось открыть файл" << endl;
    string mar, yea, sur, Id;
    while (path >> mar >> yea >> sur >> Id) {
        cars.emplace_back(mar, yea, sur, Id);
    }
    path.close();
}

void printCar(const string& mark, const vector<car>& cars) {
    float AverageAge = 0;
    int count = 0;
    for (const auto& CAR : cars) {
        if (CAR.mark == mark) {
            AverageAge = AverageAge + (2024 - stoi(CAR.year));
            cout << CAR.year << " " << CAR.surname << " " << CAR.CarId << endl;
            count ++;
        
        }
    }
    AverageAge = AverageAge / count;
    cout << "Средний возраст машин " << AverageAge << endl;
    
} 

int main() {
    vector<car> cars;
    string FileName = "cars.txt";
    Read(FileName, cars);
    string mark = "";
    cout << "Введите марку машины (Ferrari, Jeep, BMW, Lamborghini)" << endl;
    cin >> mark;
    printCar(mark, cars);
}
