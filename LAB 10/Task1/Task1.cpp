#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

float func(int n) {
    static int k = 0;
    if (k == n) {
        return sqrt(1 + (n + 1)); 
    }
    k++;
    return sqrt(1 + (n + k) * func(n));  
}

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введите целое число n: ";
    cin >> n;

    float result = func(n);  
    cout << "Результат: " << result << endl;

    return 0;
}