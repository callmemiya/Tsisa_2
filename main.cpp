//Кафедра "Информационная безопасность"
//ИУ8-32
//Забродина М.П.
//Лабораторная работа №1(Теория систем и системный анализ)
#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>
using namespace std;
     
const double a = 1.5, b = 4.;

double func(double x) {
    return cos(x)*tanh(x);
}

void delimeter(int f,int l){
    cout <<"+";
    cout <<setfill('-') <<setw(f) <<"+";
    for (int i = 0; i < 10; i++){
        cout <<setw(l) <<"+";
    }
    cout <<endl;
}

void printfirsttable(double q, double P){
    delimeter(8,7);
    cout <<"|  q\\P  |";
    cout <<setfill(' ');
    for (int i = 0; i < 10; i++){
        cout <<setw(6) <<P + i * 0.01 <<"|";
    }
    cout <<endl;
    delimeter(8,7);
    cout <<setfill(' ');
    for ( q = 0.005 ; q < 0.105;){
        cout <<"|" <<setw(7) <<q <<"|";
        for ( P = 0.9 ; P < 1;){
            double N = log(1 - P) / log(1 - q);
            cout <<setw(6) <<ceil(N) <<"|";
            P += 0.01;
        }
        cout <<endl;
        q += 0.005;
    }
    delimeter(8,7);
}

long double min(double q, double P){
    srand(static_cast<unsigned int>(time(nullptr)));
    int N = ceil(log(1 - P) / log(1 - q));
    vector<long double> values;
    for (int i = 0; i < N; ++i){
        double x = a + (b - a) * rand() / RAND_MAX;
        values.push_back(func(x));
    }
    return *min_element(values.begin(), values.end());
}

void get_min(double q, double P){
    delimeter(8,9);
    cout <<"|  q\\P  |";
    cout <<setfill(' ');
    for (int i = 0; i < 10; i++){
        cout <<setw(8) <<P + i * 0.01 <<"|";
    }
    cout <<endl;
    delimeter(8,9);
    cout <<setfill(' ');
    for ( q = 0.005 ; q < 0.105;){
        cout <<"|" <<setw(7) <<q <<"|";
        for ( P = 0.9 ; P < 1;){
            cout <<setw(8) <<setprecision(4) <<min(q, P) <<"|";
            P += 0.01;
        }
        cout <<endl;
        q += 0.005;
    }
    delimeter(8,9);
}

long double min(double q, double P, int n){
    srand(static_cast<unsigned int>(time(nullptr)));
    int N = ceil(log(1 - P) / log(1 - q));
    vector<long double> values;
    for (int i = 0; i < N; ++i){
        double x = a + (b - a) * rand() / RAND_MAX;
        values.push_back(func(x) * sin(5*x));
    }
    return *min_element(values.begin(), values.end());
}

void get_min(double q, double P, int f){
    delimeter(8,9);
    cout <<"|  q\\P  |";
    cout <<setfill(' ');
    for (int i = 0; i < 10; i++){
        cout <<setw(8) <<P + i * 0.01 <<"|";
    }
    cout <<endl;
    delimeter(8,9);
    cout <<setfill(' ');
    for ( q = 0.005 ; q < 0.105;){
        cout <<"|" <<setw(7) <<q <<"|";
        for ( P = 0.9 ; P < 1;){
            cout <<setw(8) <<setprecision(4) <<min(q, P, 2) <<"|";
            P += 0.01;
        }
        cout <<endl;
        q += 0.005;
    }
    delimeter(8,9);
}

int main() {
    double q = 0.005, P = 0.9;
    printfirsttable(q, P);
    cout <<endl;
    get_min(q, P);
    get_min(q, P, 2);
    return 0;
}
