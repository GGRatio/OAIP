#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

void writeToFile(const std::string& input) {
    std::ofstream outFile("output.txt");
    if (outFile.is_open()) {
        outFile << input;
        outFile.close();
    }
}

std::string readFromFile() {
    std::ifstream inFile("output.txt");
    std::string content((std::istreambuf_iterator<char>(inFile)), (std::istreambuf_iterator<char>()));
    return content;
}

int main() {
    std::string input;
    std::cout << "Введите строку символов: ";
    std::getline(std::cin, input);

    writeToFile(input);

    std::string fileContent = readFromFile();

    size_t minIndex = 0;
    size_t minLength = SIZE_MAX;
    size_t currentLength = 0;
    size_t currentIndex = 0;
    bool inWord = false;

    for (size_t i = 0; i <= fileContent.size(); ++i) {
        if (i < fileContent.size() && fileContent[i] != ' ' && fileContent[i] != '\n') {
            if (!inWord) {
                inWord = true;
                currentIndex = i;
            }
            ++currentLength;
        }
        else {
            if (inWord) {
                inWord = false;
                if (currentLength < minLength) {
                    minLength = currentLength;
                    minIndex = currentIndex;
                }
                currentLength = 0;
            }
        }
    }

    std::cout << "Порядковый номер слова минимальной длины: " << minIndex + 1 << std::endl;
    std::cout << "Количество символов в этом слове: " << minLength << std::endl;

    return 0;
}
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
