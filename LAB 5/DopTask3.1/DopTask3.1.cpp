#include <iostream>
#include <windows.h>

#define ntrain 3

using namespace std;

void add();
void out();
void del();
void search();

struct Strain {
    int trainNumber;
    char destination[30];
    enum Edays {
        Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
    } days;
    struct Stime {
        unsigned hours : 5; // 5 бит для часов (0-23)
        unsigned minutes : 6; // 6 бит для минут (0-59)
    } arrivalTime, departureTime;
} trains[ntrain];

int main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int choice;
    do {
        cout << "\nВарианты использования...\n" <<
            "1 - Ввод данных\n" <<
            "2 - Вывод данных\n" <<
            "3 - Удаление элементов\n" <<
            "4 - Поиск по пункту назначения\n" <<
            "5 - Завершение работы...\n" <<
            "Выбор: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            add();
            break;
        }
        case 2: {
            out();
            break;
        }
        case 3: {
            del();
            break;
        }
        case 4: {
            search();
            break;
        }
        case 5: {
            cout << "Завершение работы...\n";
            break;
        }
        default: {
            cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
        }
    } while (choice != 5);
    return 0;
}

void add() {
    for (int i = 0; i < ntrain; i++) {
        cout << "\n-------\n";
        cout << "Поезд №" << i + 1 << endl;
        cout << "Введите номер поезда: ";
        cin >> trains[i].trainNumber;
        cout << "Введите пункт назначения: ";
        cin >> trains[i].destination;

        int dayChoice;
        do {
            cout << "\nВыберите день следования...\n" <<
                "1 - Понедельник\n" <<
                "2 - Вторник\n" <<
                "3 - Среда\n" <<
                "4 - Четверг\n" <<
                "5 - Пятница\n" <<
                "6 - Суббота\n" <<
                "7 - Воскресенье\n";
            cin >> dayChoice;
            switch (dayChoice) {
            case 1: {
                trains[i].days = Strain::Monday;
                break;
            }
            case 2: {
                trains[i].days = Strain::Tuesday;
                break;
            }
            case 3: {
                trains[i].days = Strain::Wednesday;
                break;
            }
            case 4: {
                trains[i].days = Strain::Thursday;
                break;
            }
            case 5: {
                trains[i].days = Strain::Friday;
                break;
            }
            case 6: {
                trains[i].days = Strain::Saturday;
                break;
            }
            case 7: {
                trains[i].days = Strain::Sunday;
                break;
            }
            default: {
                cout << "\nНекоректный ввод..\n";
                break;
            }
            }
        } while (dayChoice < 1 || dayChoice > 7);

        unsigned int hours, minutes;
        cout << "Введите время прибытия (часы минуты): ";
        cin >> hours >> minutes;
        trains[i].arrivalTime.hours = hours;
        trains[i].arrivalTime.minutes = minutes;

        cout << "Введите время отправления (часы минуты): ";
        cin >> hours >> minutes;
        trains[i].departureTime.hours = hours;
        trains[i].departureTime.minutes = minutes;
    }
}

void out() {
    for (int i = 0; i < ntrain; i++) {
        cout << "\n-------\n";
        cout << "Поезд №" << i + 1 << endl;
        cout << "номер поезда: " << trains[i].trainNumber << endl;
        cout << "пункт назначения: " << trains[i].destination << endl;
        switch (trains[i].days) {
        case 1: {
            cout << "день следования: Понедельник\n";
            break;
        }
        case 2: {
            cout << "день следования: Вторник\n";
            break;
        }
        case 3: {
            cout << "день следования: Среда\n";
            break;
        }
        case 4: {
            cout << "день следования: Четверг\n";
            break;
        }
        case 5: {
            cout << "день следования: Пятница\n";
            break;
        }
        case 6: {
            cout << "день следования: Суббота\n";
            break;
        }
        case 7: {
            cout << "день следования: Воскресенье\n";
            break;
        }
        default: {
            cout << "\nошибка в перечислении..\n";
            break;
        }
        }
        cout << "время прибытия: " << trains[i].arrivalTime.hours << ":" << trains[i].arrivalTime.minutes << endl;
        cout << "время отправления: " << trains[i].departureTime.hours << ":" << trains[i].departureTime.minutes << endl;
    }
}

void del() {
    cout << "\n------------\n";
    int size = ntrain;
    if (size == 0) {
        cout << "\nСписок поездов и так пуст...\n";
    }
    else {
        int n;
        cout << "\nВведите номер поезда, который желаете удалить (от 1 до " << ntrain << "): ";
        cin >> n;

        if (n < 1 || n > ntrain) {
            cout << "Неверный номер поезда.\n";
            return;
        }

        // Сдвигаем элементы массива влево
        for (int i = n - 1; i < ntrain - 1; i++) {
            trains[i] = trains[i + 1];
        }

        // Очищаем последний элемент
        trains[ntrain - 1] = Strain(); // Обнуляем последний элемент

        cout << "Поезд №" << n << " удален.\n";
    }
}

void search() {
    char searchDestination[30];
    cout << "Введите пункт назначения для поиска: ";
    cin >> searchDestination;

    bool found = false; // Флаг для проверки, найден ли хотя бы один поезд

    for (int i = 0; i < ntrain; i++) {
        if (strcmp(trains[i].destination, searchDestination) == 0) {
            cout << "\n-------\n";
            cout << "Поезд №" << i + 1 << endl;
            cout << "номер поезда: " << trains[i].trainNumber << endl;
            cout << "пункт назначения: " << trains[i].destination << endl;
            switch (trains[i].days) {
            case 1: {
                cout << "день следования: Понедельник\n";
                break;
            }
            case 2: {
                cout << "день следования: Вторник\n";
                break;
            }
            case 3: {
                cout << "день следования: Среда\n";
                break;
            }
            case 4: {
                cout << "день следования: Четверг\n";
                break;
            }
            case 5: {
                cout << "день следования: Пятница\n";
                break;
            }
            case 6: {
                cout << "день следования: Суббота\n";
                break;
            }
            case 7: {
                cout << "день следования: Воскресенье\n";
                break;
            }
            default: {
                cout << "\nошибка в перечислении..\n";
                break;
            }
            }
            cout << "время прибытия: " << trains[i].arrivalTime.hours << ":" << trains[i].arrivalTime.minutes << endl;
            cout << "время отправления: " << trains[i].departureTime.hours << ":" << trains[i].departureTime.minutes << endl;
            found = true; // Поезд найден
        }
    }

    if (!found) {
        cout << "Поезды в пункт назначения " << searchDestination << " не найдены.\n";
    }
}