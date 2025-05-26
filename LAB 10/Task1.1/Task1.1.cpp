#include <iostream>
#include <windows.h>

using namespace std;

int C(int m, int n) {
    if (m == 0 || m == n) {
        return 1;
    }
    return C(m, n - 1) + C(m - 1, n - 1);
}

int main() {
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int m, n;
    cout << "Введите целые числа m и n (0 < m < n): ";
    cin >> m >> n;

    if (m <= 0 || m >= n) {
        cout << "Ошибка: должно выполняться условие 0 < m < n" << endl;
        return 1;
    }

    int result = C(m, n);
    cout << "Биномиальный коэффициент C(" << m << ", " << n << ") = " << result << endl;

    return 0;
}