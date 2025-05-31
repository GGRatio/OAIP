#include "sorts.h"
#include <iostream>
#include <Windows.h>
#include <chrono>
#include <iomanip>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::cout << std::fixed << std::setprecision(8);

    // Ввод массива A
    int num, sizeA = 0;
    int capacity = 1;
    int* A = new int[capacity];

    std::cout << "Вводите числа массива A (0 для завершения): ";
    do {
        std::cin >> num;
        if (num == 0) break;

        if (sizeA == capacity) {
            capacity *= 2;
            int* newArr = new int[capacity];
            for (int i = 0; i < sizeA; i++) {
                newArr[i] = A[i];
            }
            delete[] A;
            A = newArr;
        }

        A[sizeA++] = num;
    } while (true);

    if (sizeA == 0) {
        std::cout << "Массив пуст!" << std::endl;
        delete[] A;
        return 0;
    }

    // Поиск максимального элемента
    int maxIndex = 0;
    for (int i = 1; i < sizeA; i++) {
        if (A[i] > A[maxIndex]) {
            maxIndex = i;
        }
    }

    // Формирование массива B
    int sizeB = 0;
    int* B = new int[sizeA];

    for (int i = maxIndex + 1; i < sizeA; i++) {
        if (i % 2 != 0) {
            B[sizeB++] = A[i];
        }
    }

    // Вывод исходных данных
    std::cout << "\nМассив A: ";
    for (int i = 0; i < sizeA; i++) std::cout << A[i] << " ";

    std::cout << "\nМаксимальный элемент: " << A[maxIndex] << " (индекс " << maxIndex << ")";
    std::cout << "\nМассив B до сортировки: ";
    for (int i = 0; i < sizeB; i++) std::cout << B[i] << " ";

    // Создание копий для сортировок
    int* B_bubble = new int[sizeB];
    int* B_quick = new int[sizeB];
    int* B_counting = new int[sizeB];
    int* B_selection = new int[sizeB];
    int* B_shell = new int[sizeB];

    for (int i = 0; i < sizeB; i++) {
        B_bubble[i] = B[i];
        B_quick[i] = B[i];
        B_counting[i] = B[i];
        B_selection[i] = B[i];
        B_shell[i] = B[i];
    }

    // Сортировка и замер времени
    auto start = std::chrono::steady_clock::now();
    bubbleSort(B_bubble, sizeB);
    auto end = std::chrono::steady_clock::now();
    double bubbleTime = std::chrono::duration<double>(end - start).count();

    start = std::chrono::steady_clock::now();
    quickSort(B_quick, sizeB);
    end = std::chrono::steady_clock::now();
    double quickTime = std::chrono::duration<double>(end - start).count();

    start = std::chrono::steady_clock::now();
    countingSort(B_counting, sizeB);
    end = std::chrono::steady_clock::now();
    double countingTime = std::chrono::duration<double>(end - start).count();

    start = std::chrono::steady_clock::now();
    selectionSort(B_selection, sizeB);
    end = std::chrono::steady_clock::now();
    double selectionTime = std::chrono::duration<double>(end - start).count();

    start = std::chrono::steady_clock::now();
    shellSort(B_shell, sizeB);
    end = std::chrono::steady_clock::now();
    double shellTime = std::chrono::duration<double>(end - start).count();

    // Вывод результатов
    std::cout << "\n\nПосле сортировки пузырьком: ";
    for (int i = 0; i < sizeB; i++) std::cout << B_bubble[i] << " ";
    std::cout << "\nВремя: " << bubbleTime << " сек";

    std::cout << "\n\nПосле быстрой сортировки: ";
    for (int i = 0; i < sizeB; i++) std::cout << B_quick[i] << " ";
    std::cout << "\nВремя: " << quickTime << " сек";

    std::cout << "\n\nПосле сортировки подсчетом: ";
    for (int i = 0; i < sizeB; i++) std::cout << B_counting[i] << " ";
    std::cout << "\nВремя: " << countingTime << " сек";

    std::cout << "\n\nПосле сортировки выбором: ";
    for (int i = 0; i < sizeB; i++) std::cout << B_selection[i] << " ";
    std::cout << "\nВремя: " << selectionTime << " сек";

    std::cout << "\n\nПосле сортировки Шелла: ";
    for (int i = 0; i < sizeB; i++) std::cout << B_shell[i] << " ";
    std::cout << "\nВремя: " << shellTime << " сек";

    // Освобождение памяти
    delete[] A;
    delete[] B;
    delete[] B_bubble;
    delete[] B_quick;
    delete[] B_counting;
    delete[] B_selection;
    delete[] B_shell;

    return 0;
}