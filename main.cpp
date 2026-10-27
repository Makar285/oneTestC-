// Задания с https://docs.google.com/document/d/1yzHwap5xYbqxq3509M7aAE5waWRgmNDE5ixxzlQf-Jw/edit?clckid=01128af8&tab=t.0

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <format>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <clocale>

#include <stdlib.h>
#include <ctime>

#include <windows.h> // для функций SetConsoleCP и SetConsoleOutputCP

std::size_t utf8_len(const std::string& s) {
    std::size_t count = 0;

    for (unsigned char c : s) {
        if ((c & 0xC0) != 0x80) {
            ++count;
        }
    }

    return count;
}


// Обшая функция проверяющая что число int есть в векторе
bool contains(const std::vector<int>& vec, int value) {
    return std::find(vec.begin(), vec.end(), value) != vec.end();
};

// Общая функция для получения числа, так как нету легкого преобразования из std::string в short, будуиспользуеться только int
int getNumber() {
    int number;

    // Цикл работает до тех пор, пока пользователь не введет корректное число
    while (!(std::cin >> number)) {
        std::cout << "Вы ввели не число. Попробуйте еще раз: ";

        std::cin.clear(); // Сбрасываем ошибочное состояние cin
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n'); // Очищаем буфер ввода
    };

    return number;
}


// Аналог pushNumbers но для int, а не double
std::vector<int> pushIntNumbers() {
    std::vector<int> localRes = {};

    // Инициализация переменной для вывода номера заполняемой ячейки
    short i = 0;
    while (true) {
        std::cout << "[+] Инициализация | ячейка " << i << ": ";
        std::string localLocalNString;
        int localLocalN;
        std::cin >> localLocalNString;
        std::cout << "\n";
        try {
            localLocalN = std::stoi(localLocalNString);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.\n";
            return {};
        }
        catch (const std::out_of_range& e) {
            std::cout << "Вы ввели слишком большое число.\n";
            return {};
        };

        if (localLocalN == 0) {
            break;
        }
        else {
            localRes.push_back(localLocalN);
            i++;
        };
    };

    return localRes;
};

// Функции для n = 33
// Добавление элементов в вектор и возвращение этого заполеного вектора
std::vector<double> pushNumbers() {
    std::vector<double> localRes = {};

    // Инициализация переменной для вывода номера заполняемой ячейки
    short i = 0;
    while (true) {
        std::cout << "[+] Инициализация | ячейка " << i << ": ";
        std::string localLocalNString;
        double localLocalN;
        std::cin >> localLocalNString;
        std::cout << "\n";
        try {
            localLocalN = std::stod(localLocalNString);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.\n";
            return {};
        }
        catch (const std::out_of_range& e) {
            std::cout << "Вы ввели слишком большое число.\n";
            return {};
        };

        if (localLocalN == 0) {
            break;
        }
        else {
            localRes.push_back(localLocalN);
            i++;
        };
    };

    return localRes;
};

// Вывод каждого элемента вектора разделяя его табуляцией
void printVector(std::vector<double> res) {
    std::cout << "[#] Результат: \n";

    for (short i = 0; i < res.size(); i++) {
        std::cout << res[i];

        // Проверка на то что это любая другая итерация цикла кроме последней и добавление табуляции если это так
        if (i + 1 != res.size()) {
            std::cout << "\t";
        };
    };
};

// Сортировка вектора по возростанию
void sortPlus(std::vector<double> output) {
    // Отсортированный массив
    std::vector<double> result = {};

    // Нельзя использовать output.size() в for потому что в процессе добавления элементов в вектор result и удаления элементов из вектора output длина output будет изменяться и итераций будет не длина вектора output а меньше
    int lengthVector = output.size();

    // N итерация для вектора длинной n значений, нужно только n итераций, а само значение переменной не нужно так что ее название это нижнен подчеркивание
    for (short _ = 0; _ < lengthVector; _++) {
        // Взять первое значений значением по умолчанию и дальше проверять его на то самое ли большое это значение в массиве от _ до конца массива, в случае если есть число больше перезаписывать min и индекс этого первого элемента, это нужно что бы если первое число это и есть минимальное число что бы можно было его удалить и добавить в вектор result
        double min = output[0];

        // Индекс самого маленького числа, для того что бы удалитб его из output
        int minIndex = 0;

        // Для прохода по вектору и нахождения минимального числа для текущего вектора
        short i = 0;
        while (i < output.size()) {
            // Если число с текущий индексом i вектора output меньше чем минимальное число(min), то записать в min это число
            if (output[i] < min) {
                min = output[i];
                minIndex = i;
            };

            i++;

            // Выаод в консоль для того что бы посмотреть как работает сортировка
            /* std::cout << "START\n";
            std::cout << " текущее index    " << i << "\n";
            printVector(output);
            std::cout << "\n";
            printVector(result);
            std::cout << "\n00000  " << _ << "   "  << output[i] << "   " << min << "   00000\n";
            std::cout << "END\n\n\n\n";
            */
        };

        output.erase(output.begin() + minIndex);
        result.push_back(min);
    };

    printVector(result);
};

// Сортировка вектора по убыванию
void sortMinus(std::vector<double> output) {
    // Отсортированный массив
    std::vector<double> result = {};

    // Нельзя использовать output.size() в for потому что в процессе добавления элементов в вектор result и удаления элементов из вектора output длина output будет изменяться и итераций будет не длина вектора output а меньше
    int lengthVector = output.size();

    // N итерация для вектора длинной n значений, нужно только n итераций, а само значение переменной не нужно так что ее название это нижнен подчеркивание
    for (short _ = 0; _ < lengthVector; _++) {
        // Взять первое значений значением по умолчанию и дальше проверять его на то самое большое ли это значение в массиве от _ до конца массива, в случае если есть число больше, то перезаписывать max и индекс этого первого элемента, это нужно что бы если первое число это и есть минимальное число что бы можно было его удалить и добавить в вектор result
        double max = output[0];

        // Индекс самого маленького числа, для того что бы удалить его из output
        int maxIndex = 0;

        // Для прохода по вектору и нахождения максимального числа для текущего вектора
        short i = 0;
        while (i < output.size()) {
            // Если число с текущий индексом i вектора output больше чем максимальное число(max), то записать в max это число
            if (output[i] > max) {
                max = output[i];
                maxIndex = i;
            };

            i++;

            // Выаод в консоль для того что бы посмотреть как работает сортировка
            /* std::cout << "START\n";
            std::cout << " текущее index    " << i << "\n";
            printVector(output);
            std::cout << "\n";
            printVector(result);
            std::cout << "\n00000  " << _ << "   "  << output[i] << "   " << min << "   00000\n";
            std::cout << "END\n\n\n\n";
            */
        };

        output.erase(output.begin() + maxIndex);
        result.push_back(max);
    };

    printVector(result);
};


// Если ope == '*', то умножение каждого элемента вектора на некоторое число, если ope == '+', то добавление некоторого числа к каждому элементу вектора, а если ope == '/', то деление каждого элемента вектора на некоторое число
void multiplicationOrAdditionOrDivisionVector(std::vector<double> output, char ope) {
    std::string input;
    double inputNumber;
    std::cin >> input;
    try {
        inputNumber = std::stod(input);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Вы ввели не число\n";

        // Аналог return 0, но ее нельзя использовать потому что это не Функция main
        std::exit(0);
    }
    catch (const std::out_of_range& e) {
        std::cout << "Вы ввели слишком большое или слишком маленькое число\n";

        // Аналог return 0, но ее нельзя использовать потому что это не Функция main
        std::exit(0);
    };

    if (ope == '/' && inputNumber == 0) {
        std::cout << "Делить на ноль нельяз.\n";
        // Аналог return 0, но ее нельзя использовать потому что это не Функция main
        std::exit(0);
    };

    // Вектор в который будут добавляться уже умноженые или сложенное значения оригинального вектора(который был передан в функцию(переменная output))
    std::vector<double> result = {};

    // Проход по каждому значению в векторе output
    for (double number : output) {
        // Проверка на то что должна делать функция с полученным числом, добавлять или умножать, при isMultiplication равном true умножать
        if (ope == '*') {
            // Добавление текущего значения вектора output, умноженого на число которое ввел пользователь
            result.push_back(number * inputNumber);
        }
        else if (ope == '+') {
            // Добавление текущего значения вектора output, сложенного на с числом которое ввел пользователь
            result.push_back(number + inputNumber);
        }
        else if (ope == '/') {
            // Добавление уже деленего текущего значения вектора output на число которое ввел пользователь
            result.push_back(number / inputNumber);
        }
        else {
            std::cout << "МАКАР КАК ТАК, МОЖНО ТОЛЬКО *, + и /, ИСПРАВЛЯЙ БЫСТРО";
            // Аналог return 0, но ее нельзя использовать потому что это не Функция main
            std::exit(0);
        }
    };

    printVector(result);
};

// Все ячейки вектора принимают значение 0
void resettingToZero(std::vector<double> output) {
    for (int i = 0; i < output.size(); i++) {
        std::cout << 0;
        if (i + 1 != output.size()) {
            std::cout << "\t";
        };
    };
};

// Инициализация вектора по новой
void initializationAgain() {
    std::vector<double> result = pushNumbers();

    std::cout << "\n";

    printVector(result);
};

// Функция для n = 7
bool isCorrectNumber(short numberDay, short maxNumberDay) {
    if (numberDay > maxNumberDay || numberDay < 0) {
        std::cout << "Вы ввели не корректное число.\n";
        std::exit(0);
    };

    return true;
};

// Вывод текущего состояние игры для n = 10
void printInterface(short countCurrentNumber, short countAttempt) {
    std::cout << "[+] Угаданных чисел: [" << countCurrentNumber << "/3]\n";
    std::cout << "[+] Попыток: [" << countAttempt << "]\n";
};

// Вывод меню игры и вопроса для n = 12
void printMenuAndQuestionGame(short nQuestion, std::string userName, short countLife, short glasses, std::string question, std::vector<std::string> answerOptions) {
    std::cout << "[+] Игрок: " << userName << "| жизни: " << countLife << " | очки: " << glasses << "\n";
    std::cout << "[" << nQuestion << "]  Вопрос: " << question << "\n";
    for (short i = 1; i <= answerOptions.size(); i++) {
        std::cout << "[" << i << "] " << answerOptions[i - 1];
        if (i % 2 == 0) {
            std::cout << "\n";
        }
        else {
            std::cout << "\t";
        };
    };
    std::cout << "Выберите вариант ответа: ";
};

// Получение нужных даннных и вывод линии, для n принадлежащее [11, 22]
void line() {
    std::cout << "[ + ] Фигура: \"Линия\".\n\n";
    std::cout << "[1] Горизонтальная.\n";
    std::cout << "[2] Вертикальная.\n\n";
    std::cout << "[+] Выберите тип: ";
    int localLocalN = getNumber();

    std::cout << "[length] Длина линии: ";
    int lengthLine = getNumber();
    std::cout << "\n";
    std::cout << "[value] Текстура линии: ";
    char submol;
    std::cin >> submol;
    std::cout << "\n";

    int i = 0;
    if (localLocalN == 1) {
        // Вывод горизонтально
        while (i < lengthLine) {
            std::cout << submol;
            if (i - 1 != lengthLine) {
                std::cout << " ";
            };
            i++;
        };
    }
    else if (localLocalN == 2) {
        // Вывод вертикально
        while (i < lengthLine) {
            std::cout << submol;
            if (i - 1 != lengthLine) {
                std::cout << "\n";
            };
            i++;
        };
    }
    else {
        std::cout << "Такого пункта нету.\n";
        std::exit(0);
    };
};

// Получение нужных даннных и вывод квадрата, для n принадлежащее [11, 22]
void square() {
    std::cout << "[+] Фигура: \"Квадрат\".\n\n";
    std::cout << "[1] Заполненный.\n";
    std::cout << "[2] Пустой.\n\n";
    std::cout << "[+] Выберите тип: ";

    int type;
    type = getNumber();

    std::cout << "[length] Размер: ";
    int lengthLine = getNumber();
    std::cout << "\n";
    std::cout << "[value] Текстура: ";
    char submol;
    std::cin >> submol;
    std::cout << "\n";

    if (type == 1) {
        // Квадрат lengthLine x lengthLine заполненый submol
        for (short i = 0; i < lengthLine; i++) {
            for (short j = 0; j < lengthLine; j++) {
                std::cout << submol;
                if (j != lengthLine - 1) {
                    std::cout << " ";
                };
            };

            std::cout << "\n";
        };
    }
    else if (type == 2) {
        // Квадрат lengthLine x lengthLine с окантовкой submol, а внутри пустой
        for (short i = 0; i < lengthLine; i++) {
            if (i == 0 || i == lengthLine - 1) {
                // Первая или последняя строка квадрата, заполнять полностью
                for (short j = 0; j < lengthLine; j++) {
                    std::cout << submol;
                    if (j != lengthLine - 1) {
                        std::cout << " ";
                    };
                };
            }
            else {
                // Строка которую по бокам заполнять одним submol, а все остальное место внутри пустое
                std::cout << submol;
                short countSpace = (lengthLine - 2) * 2 + 1; // -2 так как с боковом должны выбь символы а не пробелы, *2+1 так как между пробелами должны быть пробелы
                for (short i = 0; i < countSpace; i++) {
                    std::cout << " ";
                };
                std::cout << submol;
            };

            std::cout << "\n";
        };
    }
    else {
        std::cout << "Такого пункта нету.\n";
        std::exit(0);
    };
};

// Получение нужных даннных и вывод прямоугольника, для n принадлежащее [11, 22]
void rectangle() {
    std::cout << "[+] Фигура: \"Прямоугольник\".\n\n";
    std::cout << "[1] Заполненный.\n";
    std::cout << "[2] Пустой.\n\n";
    std::cout << "[+] Выберите тип: ";

    int type = getNumber();

    std::cout << "[+] Ширина: ";
    int width = getNumber();
    std::cout << "\n";

    std::cout << "[+] Высота: ";
    int height = getNumber();
    std::cout << "\n";

    std::cout << "[+] Текстура: ";
    char submol;
    std::cin >> submol;
    std::cout << "\n";

    if (type == 1) {
        // Заполненный
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                std::cout << submol;
                if (j != width - 1) {
                    std::cout << " ";
                };
            };
            std::cout << "\n";
        };
    }
    else if (type == 2) {
        // Пустой
        for (int i = 0; i < height; i++) {
            if (i == 0 || i == height - 1) {
                // Первая или последняя строка прямоугольника, заполненая символом submol
                for (int j = 0; j < width; j++) {
                    std::cout << submol;
                    if (j != width - 1) {
                        std::cout << " ";
                    };
                };
            }
            else {
                std::cout << submol << " ";
                int countSpaceOrDot = (width - 2) * 2 - 1; // -2 так как с боковом должны выбь символы а не пробелы, *2+1 так как между пробелами должны быть пробелы
                for (int j = 1; j <= countSpaceOrDot; j++) {
                    if (j % 2 == 0) {
                        std::cout << " ";
                    }
                    else {
                        std::cout << ".";
                    };
                };
                std::cout << " " << submol;
            };
            std::cout << "\n";
        };
    }
    else {
        std::cout << "Такого пункта нету.\n";
        std::exit(0);
    };
};

// Получение нужных даннных и вывод треугольника, для n принадлежащее [11, 22]
void triangle() {
    std::cout << "[+] Фигура: \"Треугольник\".\n\n";
    std::cout << "[1] Заполненный.\n";
    std::cout << "[2] Пустой.\n\n";
    std::cout << "[+] Выберите тип: ";
    int type = getNumber();
    std::cout << "\n";

    std::cout << "[+] Размер: ";
    int size = getNumber();
    std::cout << "\n";

    std::cout << "[+] Текстура: ";
    char submol;
    std::cin >> submol;
    std::cout << "\n";

    int maxCountSpace = size / 2;
    int sizeTriangle;
    if (size % 2 == 0) {
        sizeTriangle = size / 2;
        maxCountSpace -= 1;
    }
    else {
        sizeTriangle = size / 2 + 1;
    };

    std::cout << size << "    " << maxCountSpace << "    " << sizeTriangle << "\n\n";

    for (int i = 0; i < sizeTriangle; i++) {
        if (i == 0) {
            // Первая строка
            //  Точки до submol
            for (int i = 0; i < maxCountSpace; i++) {
                std::cout << ". ";
            };

            // submol
            for (int i = maxCountSpace + 1; i <= size - maxCountSpace; i++) { // maxCountSpace+1 это начало точек в самом треугольнике, size-maxCountSpace-1 это конец точек в самом треугольнике
                std::cout << submol << " ";
            };

            //  Точки до submol
            for (int i = 0; i < maxCountSpace; i++) {
                std::cout << ". ";
            };
            std::cout << "\n";
        }
        else if (i == sizeTriangle - 1) {
            // Последняя строка
            for (int i = 0; i < size; i++) {
                std::cout << submol;
                if (i != size - 1) {
                    // Для всех символом кроме последнего добавлять пробел после символа
                    std::cout << " ";
                };
            };
            std::cout << "\n";
        }
        else {
            // Любая строка кроме первой и последней
            // Точки от начала до символа
            for (int i = 0; i < maxCountSpace; i++) {
                std::cout << ". ";
            };

            if (type == 2) {
                // Один символ
                std::cout << submol << " ";

                // Точки между первым и вторым символом
                for (int i = maxCountSpace + 1; i < size - maxCountSpace - 1; i++) {
                    std::cout << ". ";
                };

                // Один символ
                std::cout << submol << " ";
            }
            else if (type == 1) {
                // Символы между первым и вторым символом
                for (int i = maxCountSpace; i < size - maxCountSpace; i++) {
                    std::cout << submol << " ";
                };
            }

            // Точки от второго символа до конца
            for (int i = size - maxCountSpace; i < size; i++) {
                std::cout << ".";
                if (i + 1 != size) {
                    std::cout << " ";
                };
            };

            std::cout << "\n";
        };

        maxCountSpace--;
    };

    // Точки после треугольника до конца квадрата
    for (int i = sizeTriangle; i < size; i++) {
        for (int i = 0; i < size; i++) {
            std::cout << ".";
            if (i != size - 1) {
                // Для всех символом кроме последнего добавлять пробел после символа
                std::cout << " ";
            };
        };
        std::cout << "\n";
    };

    // TEST
    std::cout << "\n\n\n\n";
};

// Получение нужных даннных и вывод решетки, для n принадлежащее [11, 22]
void lattice() {
    std::cout << "Фигура: \"Решетка\".\n";

    std::cout << "Размер: ";
    int size = getNumber();

    std::cout << "[+] Текстура: ";
    char submol;
    std::cin >> submol;
    std::cout << "\n";

    for (int i = 1; i <= size; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < size; j++) {
                std::cout << submol;
                if (j + 1 != size) {
                    std::cout << " ";
                };
            };
        }
        else {
            for (int j = 1; j <= size; j++) {
                if (j % 2 == 0) {
                    std::cout << submol;
                }
                else {
                    std::cout << ".";
                };

                if (j != size) {
                    std::cout << " ";
                };
            };
        };

        std::cout << "\n";
    };
};

void cross() {
    std::cout << "[ + ] Фигура: \"Крестик\".\n";
    std::cout << "[+] Размер : ";
    int size = getNumber();

    std::cout << "[+] Текстура : ";
    char submol;
    std::cin >> submol;
    std::cout << "\n";

    // Количество строк которое напечаталось, нужно что бы прекратить выполнение итераций в последнем цикле, когда нужно количество строк вывелось
    int countString = 0;

    // Количесвто точек между началом строки и первым символом, и вторым символом и концом строки
    int countDotStartAndOneSubmolAndCountDotTwoSubmolAndEnd = 0;

    // Количество точек между первым символом и вторым символом
    int countDotBetweenOneSubmolAndTwoSubmol = size - 2; // Потому что в строке всегда все точки кроме двух символов, в начале символы будут в углах и поэтому количесвто точек будет максимально возвожным для строки, т. е. size - 2

    // Первая часть до середины
    for (int i = 0; i < size; i++) {
        // Точки до первого символа
        for (int j = 0; j < countDotStartAndOneSubmolAndCountDotTwoSubmolAndEnd; j++) {
            std::cout << ". ";
        };

        // Первый символ
        std::cout << submol << " ";

        // Точки между первым и вторым символом
        for (int j = 0; j < countDotBetweenOneSubmolAndTwoSubmol; j++) {
            std::cout << ". ";
        };

        // Второй символ
        std::cout << submol << " ";

        // Точки после второго символа
        for (int j = 0; j < countDotStartAndOneSubmolAndCountDotTwoSubmolAndEnd; j++) {
            std::cout << ".";
            if (j + 1 != countDotStartAndOneSubmolAndCountDotTwoSubmolAndEnd) {
                std::cout << " ";
            };
        };

        // Что бы перейти на новую строку
        std::cout << "\n";

        // Увеличение количесвто точек между началом строки и первым символом, и вторым символом и концом строки на 1
        countDotStartAndOneSubmolAndCountDotTwoSubmolAndEnd++;

        // Уменьшить количество точек между первым символом и вторым символом на 2, потому что в строке два символа, они идут от углов к центру, тем самым уменьшая количесвто точек между ними на 2
        countDotBetweenOneSubmolAndTwoSubmol -= 2;

        countString++;

        // Если количество точек которое нужно вывести отрицательное, то выйти из цикла, равно потому что если size четный, то countDotBetweenOneSubmolAndTwoSubmol будет ..., 2, 0, -2, ...
        if (countDotBetweenOneSubmolAndTwoSubmol <= 0) {
            break;
        };
    };


    // Середина
    // От начало до первого символа
    // countDotStartAndOneSubmolAndCountDotTwoSubmolAndEnd потому что если перешло сюда, значит итерация была на середине, а там countDotStartAndOneSubmolAndCountDotTwoSubmolAndEnd = максимальное количесвто точек от начала до первого символа, и от второго символа до конца, т. е. countDotStartAndOneSubmolAndCountDotTwoSubmolAndEnd = size/2; if(size % 2 == 0) { countDotStartAndOneSubmolAndCountDotTwoSubmolAndEnd-- };
    for (int i = 0; i < countDotStartAndOneSubmolAndCountDotTwoSubmolAndEnd; i++) {
        std::cout << ". ";
    };

    // Символ(ы)
    // Один символ если число четное, и два символа если число нечетное
    std::cout << submol << " ";
    if (size % 2 == 0) {
        std::cout << submol << " ";
    };

    // От второго символа до конца
    for (int i = 0; i < countDotStartAndOneSubmolAndCountDotTwoSubmolAndEnd; i++) {
        std::cout << ".";
        if (i + 1 != countDotStartAndOneSubmolAndCountDotTwoSubmolAndEnd) {
            std::cout << " ";
        };
    };

    // Что бы перейти на новую строку
    std::cout << "\n";

    countString++;


    // Вторая часть после середины
    if (size % 2 == 0) {
        countDotBetweenOneSubmolAndTwoSubmol = 2;
    }
    else {
        countDotBetweenOneSubmolAndTwoSubmol = 1;
    };

    countDotStartAndOneSubmolAndCountDotTwoSubmolAndEnd = (size - 2) / 2; // size - 2, потому что два в строке все точки кроме двух символом, а / 2 потому что два одинаковых кколичества точек между началом и первым символом, и вторым символом и концом

    // Если число четное, то количество символом между началом и первым символом, и вторым символом и концом должно быть на 1 меньше, потому что, если не уменьшить, то все сдвинеться на элемента вправо
    if (size % 2 == 0) {
        countDotStartAndOneSubmolAndCountDotTwoSubmolAndEnd--;
    }

    for (int i = 0; i < size; i++) {
        // Точки до первого символа
        for (int j = 0; j < countDotStartAndOneSubmolAndCountDotTwoSubmolAndEnd; j++) {
            std::cout << ". ";
        };

        // Первый символ
        std::cout << submol << " ";

        // Точки между первым и вторым символом
        for (int j = 0; j < countDotBetweenOneSubmolAndTwoSubmol; j++) {
            std::cout << ". ";
        };

        // Второй символ
        std::cout << submol << " ";

        // Точки после второго символа
        for (int j = 0; j < countDotStartAndOneSubmolAndCountDotTwoSubmolAndEnd; j++) {
            std::cout << ".";
            if (j + 1 != countDotStartAndOneSubmolAndCountDotTwoSubmolAndEnd) {
                std::cout << " ";
            };
        };

        // Что бы перейти на новую строку
        std::cout << "\n";

        // Увеличение количесвто точек между началом строки и первым символом, и вторым символом и концом строки на 1
        countDotStartAndOneSubmolAndCountDotTwoSubmolAndEnd--;

        // Уменьшить количество точек между первым символом и вторым символом на 2, потому что в строке два символа, они идут от углов к центру, тем самым уменьшая количесвто точек между ними на 2
        countDotBetweenOneSubmolAndTwoSubmol += 2;

        countString++;

        if (size % 2 == 0) {
            if (countString >= size - 1) {
                break;
            }
        }
        else {
            if (countString >= size) {
                break;
            }
        }
    };
};

void plus() {
    std::cout << "[ + ] Фигура: \"Плюс\".\n";
    std::cout << "[+] Размер : ";
    int size = getNumber();

    std::cout << "[+] Текстура : ";
    char submol;
    std::cin >> submol;
    std::cout << "\n";

    // Если число четное, то убавлять размер на 1
    if (size % 2 == 0) {
        size--;
    };

    int countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd = (size - 1) / 2;

    for (int i = 0; i < size; i++) {
        if (i == size / 2) {
            // Это та строка которая содержит только символы
            for (int j = 0; j < size; j++) {
                std::cout << submol;
                if (j + 1 != size) {
                    std::cout << " ";
                }
            }
        }
        else {
            // Все остальные строки
            // Точки до символа
            for (int j = 0; j < countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd; j++) {
                std::cout << ". ";
            };

            // Символ
            std::cout << submol << " ";

            // Точки после симола
            for (int j = 0; j < countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd; j++) {
                std::cout << ".";
                if (j + 1 != countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd) {
                    std::cout << " ";
                }
            }
        };

        // Переход на новую строку
        std::cout << "\n";
    };
};

void rhombus() {
    std::cout << "[ + ] Фигура: \"Ромб\".\n";
    std::cout << "[+] Размер : ";
    int size = getNumber();

    std::cout << "[+] Текстура : ";
    char submol;
    std::cin >> submol;
    std::cout << "\n";

    bool isEven = size % 2 == 0;

    std::cout << "\n\n\n   " << isEven << "   \n\n\n";

    // Количествоточек между началом строки и символом, и символом и концом строки
    int countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd = size / 2;

    // Количество точек между первым и вторым символами, по умолчанию -1, а если размер четный, то изменить на 0, потому после первой итерации countDotBetweenOneSubmolAndTwoSubmol увеличится на 2
    int countDotBetweenOneSubmolAndTwoSubmol = -1;
    if (isEven) {
        countDotBetweenOneSubmolAndTwoSubmol = 0;
    };

    if (isEven) {
        // Если размер четный убавить один из countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd
        countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd--;
    };

    // Первая верхняя часть до середины не включительно
    for (int i = 0; i < size / 2; i++) {
        if (i == 0 || i + 1 == size) {
            // Первая строка
            // Точки между началом строки и cимволом
            for (int j = 0; j < countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd; j++) {
                std::cout << ". ";
            };

            // Символ
            std::cout << submol << " ";
            // Если размер четный добавить еще один символ
            if (isEven) {
                std::cout << submol << " ";
            };

            // Точки между чисволом и концом строки
            for (int j = 0; j < countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd; j++) {
                std::cout << ".";
                if (j + 1 != countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd) {
                    std::cout << " ";
                };
            };
        }
        else {
            // Все остальные строки
            // Точки между начаоом строки и первым символом
            for (int j = 0; j < countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd; j++) {
                std::cout << ". ";
            };

            // Первый символ
            std::cout << submol << " ";

            // Точки между первым символом и вторым символом
            for (int j = 0; j < countDotBetweenOneSubmolAndTwoSubmol; j++) {
                std::cout << ". ";
            };

            // Второй символ
            std::cout << submol << " ";

            // точки между вторым символом и концом строки
            for (int j = 0; j < countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd; j++) {
                std::cout << ". ";
            };
        }

        // Изменение переменных, что бы ромб менялся, а не был задан програмно
        countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd--;
        countDotBetweenOneSubmolAndTwoSubmol += 2;

        // Переход на новую строку
        std::cout << "\n";

        // Если количесвто точек между началом строки и первым, и вторым символом или концом строки меньше 1 ИЛИ количество точек между первым символом и вторым символом равно размер - 2, потому что два символа в строке не первой и последней это символы
        if (countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd < 1 || countDotBetweenOneSubmolAndTwoSubmol == size - 2) {
            break;
        };
    };

    // Середин(ы)
    // Первая середина
    std::cout << submol << " ";

    for (int j = 0; j < countDotBetweenOneSubmolAndTwoSubmol; j++) {
        std::cout << ". ";
    };

    std::cout << submol;
    std::cout << "\n";

    // Если размер четный, то выводить середину второй раз
    if (isEven) {
        std::cout << submol << " ";

        for (int j = 0; j < countDotBetweenOneSubmolAndTwoSubmol; j++) {
            std::cout << ". ";
        };

        std::cout << submol;
        std::cout << "\n";
    };

    // Изменение переменных, что бы не было два для нечетных и три для четных середин
    countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd++;
    countDotBetweenOneSubmolAndTwoSubmol -= 2;

    // Нижняя часть начиная со середины не включительно до конца фигуры
    for (int i = size / 2 + 1; i < size; i++) {
        if (i + 1 == size) {
            // Последняя строка
            // Точки между началом строки и cимволом
            for (int j = 0; j < countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd; j++) {
                std::cout << ". ";
            };

            // Символ
            std::cout << submol << " ";
            // Если размер четный добавить еще один символ
            if (isEven) {
                std::cout << submol << " ";
            };

            // Точки между чисволом и концом строки
            for (int j = 0; j < countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd; j++) {
                std::cout << ".";
                if (j + 1 != countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd) {
                    std::cout << " ";
                };
            };
        }
        else {
            // Все остальные строки
            // Точки между начаоом строки и первым символом
            for (int j = 0; j < countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd; j++) {
                std::cout << ". ";
            };

            // Первый символ
            std::cout << submol << " ";

            // Точки между первым символом и вторым символом
            for (int j = 0; j < countDotBetweenOneSubmolAndTwoSubmol; j++) {
                std::cout << ". ";
            };

            // Второй символ
            std::cout << submol << " ";

            // точки между вторым символом и концом строки
            for (int j = 0; j < countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd; j++) {
                std::cout << ". ";
            };
        }

        // Изменение переменных, что бы ромб менялся, а не был задан програмно
        countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd++;
        countDotBetweenOneSubmolAndTwoSubmol -= 2;

        // Переход на новую строку
        std::cout << "\n";

        // Если количесвто точек между началом строки и первым, и вторым символом или концом строки меньше 1 ИЛИ количество точек между первым символом и вторым символом равно размер - 2, потому что два символа в строке не первой и последней это символы
        if (countDotBetweenStartAndOneSubmolAndBetweenTwoSubmolAndEnd < 1 || countDotBetweenOneSubmolAndTwoSubmol == size - 2) {
            break;
        };
    };
};

void snake() {
    std::cout << "[ + ] Фигура: \"Змейка\".\n";
    std::cout << "[+] Размер : ";
    int size = getNumber();

    std::cout << "[+] Текстура : ";
    char submol;
    std::cin >> submol;
    std::cout << "\n";

    bool isFirstSubmol = false;

    // size итераций
    for (int i = 1; i <= size; i++) {
        if (i % 2 == 0) {
            //  Строка которая не полностью состоит из символов
            if (isFirstSubmol) {
                // Символ это первый элемент строки
                std::cout << submol << " ";
                for (int j = 0; j < size - 1; j++) { // - 1 потому что один элемент это символ
                    std::cout << ".";
                    if (j + 1 != size) {
                        std::cout << " ";
                    };
                };
            }
            else {
                // Символ это последний элемент строки
                for (int j = 0; j < size - 1; j++) { // - 1 потому что один элемент это символ
                    std::cout << ". ";
                };
                std::cout << submol;
            };

            isFirstSubmol = !isFirstSubmol;
        }
        else {
            for (int j = 0; j < size; j++) {
                std::cout << submol;
                if (j + 1 != size) {
                    std::cout << " ";
                };
            };
        };

        // Переход на новую строку
        std::cout << "\n";
    };
};

/*
* n = 13
# # # # # # # # # # # # #
# . . . . . . . . . . . #
# . # # # # # # # # # . #
# . # . . . . . . . # . #
# . # . . . . . . . # . #
# . # . . . . . . . # . #
# . # . . . # . . . # . #
# . # . . . . . . . # . #
# . # . . . . . . . # . #
# . # . . . . . . . # . #
# . # # # # # # # # # . #
# . . . . . . . . . . . #
# # # # # # # # # # # # #

n = 12
# # # # # # # # # # # #
# . . . . . . . . . . #
# . # # # # # # # # . #
# . # . . . . . . # . #
# . # . . . . . . # . #
# . # . . # # . . # . #
# . # . . # # . . # . #
# . # . . . . . . # . #
# . # . . . . . . # . #
# . # # # # # # # # . #
# . . . . . . . . . . #
# # # # # # # # # # # #

n = 11
# # # # # # # # # # #
# . . . . . . . . . #
# . # # # # # # # . #
# . # . . . . . # . #
# . # . . . . . # . #
# . # . . # . . # . #
# . # . . . . . # . #
# . # . . . . . # . #
# . # # # # # # # . #
# . . . . . . . . . #
# # # # # # # # # # #

n = 10
# # # # # # # # # #
# . . . . . . . . #
# . # # # # # # . #
# . # . . . . # . #
# . # . # # . # . #
# . # . # # . # . #
# . # . . . . # . #
# . # # # # # # . #
# . . . . . . . . #
# # # # # # # # # #

n == 9
# # # # # # # # #
# . . . . . . . #
# . # # # # # . #
# . # . . . # . #
# . # . # . # . #
# . # . . . # . #
# . # # # # # . #
# . . . . . . . #
# # # # # # # # #
*/
void recursiveSquare() {
    std::cout << "[ + ] Фигура: \"Рекурсивный квадрат\".\n";
    std::cout << "[+] Размер : ";
    int size = getNumber();

    std::cout << "[+] Текстура : ";
    char submol;
    std::cin >> submol;
    std::cout << "\n";

    bool isEven = size % 2 == 0;

    for (int i = 0; i < size; i++) {
        if (i == 0 || i + 1 == size) {
            // Первая и последняя строки
            for (int j = 0; j < size; j++) {
                std::cout << submol;
                if (j + 1 != size) {
                    std::cout << " ";
                };
            };
        }
        else if ((i - 1) == 0 || (i + 2) == size) {
            // Вторая с начала и вторая с конца строки
            std::cout << submol << " ";

            for (int j = 0; j < size - 2; j++) {
                std::cout << ". ";
            };

            std::cout << submol;
        }
        else if ((i - 2) == 0 || (i + 3) == size) {
            // Третия с начала и третия с конца строки
            std::cout << submol << " . ";
            for (int j = 0; j < size - 4; j++) {
                std::cout << submol << " ";
            };
            std::cout << ". " << submol;
        }
        else if (size / 2 == i || isEven && size / 2 - 1 == i) {
            // Середина
            std::cout << submol << " . " << submol << " ";
            if (isEven) {
                // Размер четный, значит 2 символа по середине
                for (int j = 0; j < (size - 8) / 2; j++) {
                    std::cout << ". ";
                };
                std::cout << submol << " " << submol << " ";
                for (int j = 0; j < (size - 8) / 2; j++) {
                    std::cout << ". ";
                }
            }
            else {
                // Размер не четный, значит 1 символ по середине
                for (int j = 0; j < (size - 7) / 2; j++) {
                    std::cout << ". ";
                }
                std::cout << submol << " ";
                for (int j = 0; j < (size - 7) / 2; j++) {
                    std::cout << ". ";
                };
            };
            std::cout << submol << " . " << submol;
        }
        else {
            // Четвертая с начала и четвертая с конца строки
            std::cout << submol << " . " << submol << " ";
            for (int j = 0; j < size - 6; j++) {
                std::cout << ". ";
            };
            std::cout << submol << " . " << submol;
        };

        // Переход на новую строку
        std::cout << "\n";
    };
};

void quarterOfSquare() {
    std::cout << "[+] Фигура: \"Четверть квадрата\".\n\n";
    std::cout << "[1] Заполненный.\n";
    std::cout << "[2] Пустой.\n\n";
    std::cout << "[+] Выберите тип: ";
    int type = getNumber();
    std::cout << "\n";

    if (type > 2 || type < 1) {
        std::cout << "Вы ввели не валидный номер типа.\n";
        std::exit(0);
    };

    std::cout << "[+] Размер: ";
    int size = getNumber();
    std::cout << "\n";

    std::cout << "[+] Текстура: ";
    char submol;
    std::cin >> submol;
    std::cout << "\n";

    if (!(size % 2 == 0)) {
        size--;
    };

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            // Элементы четверти
            if ((i >= size / 2 + 1) && (j >= size / 2 + 1)) {
                /*if (type == 1) {
                    std::cout << "#";
                }
                else {
                    if ((size / 2 + 1 == i || size == i) && (size / 2 + 1 == j || size == j)) {
                        std::cout << submol;
                    };
                }; */

                if (type == 1) {
                    // Значит заполненая четверть, нужно добавлять только символы
                    std::cout << submol;
                }
                else {
                    // Значит пустая четверть, нужна проверка на то добавлять точку или символ
                    if ((i == size / 2 + 1) || (i == size) || (j == size / 2 + 1) || (j == size)) {
                        std::cout << submol;
                    }
                    else {
                        std::cout << ".";
                    };
                };
            }
            else {
                std::cout << ".";
            };

            // Должно быть после каждого символа, независимо от i и j
            if (j != size) {
                std::cout << " ";
            };
        };

        // Переход на новую строку
        std::cout << "\n";
    };
};

void fourQuarters() {
    std::cout << "[+] Фигура: \"Четыре четверти\".\n\n";
    std::cout << "[1] Заполненный.\n";
    std::cout << "[2] Пустой.\n\n";
    std::cout << "[+] Выберите тип: ";
    int type = getNumber();
    std::cout << "\n";

    if (type > 2 || type < 1) {
        std::cout << "Вы ввели не валидный номер типа.\n";
        std::exit(0);
    };

    std::cout << "[+] Размер: ";
    int size = getNumber();
    std::cout << "\n";

    std::cout << "[+] Текстура: ";
    char submol;
    std::cin >> submol;
    std::cout << "\n";

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            //if ((((i == 0) || (i == size / 2)) && (j <= size / 2)) || ((j == 0) || ((j == size / 2)) && (i <= size / 2))) 
            if ((size / 2 > i) && (size / 2 > j)) {
                // Элементы первого квадрата
                if ((i == 0) || (i + 1 == size / 2) || (j == 0) || (j + 1 == size / 2) || (type == 1)) {
                    // (Первая или последняя строка, или первый или второй столбец первого квадрата) ИЛИ (выбран заполненый квадрат)
                    std::cout << "\033[92m" << submol << "\033[0m ";
                }
                else {
                    std::cout << ". ";
                };
            }
            else if ((i < size / 2) && (j >= size / 2)) {
                // Элементы второго квадрата
                if ((i == 0) || (i + 1 == size / 2) || (j + 1 == size) || (j == size / 2) || (type == 1)) {
                    // (Первая или последняя строка, или первый или второй столбец второго квадрата) ИЛИ (выбран заполненый квадрат)
                    std::cout << "\033[34m" << submol << "\033[0m";
                }
                else {
                    std::cout << ".";
                };

                if (j + 1 != size) {
                    std::cout << " ";
                }
            }
            else if ((i >= size / 2) && (size / 2 > j)) {
                // Элементы третего квадрата
                if ((j == 0) || (j + 1 == size / 2) || (i + 1 == size) || (i == size / 2) || (type == 1)) {
                    // (Первая или последняя строка, или первый или второй столбец третьего квадрата) ИЛИ (выбран заполненый квадрат)
                    std::cout << "\033[31m" << submol << "\033[0m ";
                }
                else {
                    std::cout << ". ";
                };
            }
            else if ((i >= size / 2) && (j >= size / 2)) {
                // Элементы четвертого квадрата
                if ((j + 1 == size) || (j == size / 2) || (i + 1 == size) || (i == size / 2) || (type == 1)) {
                    // (Первая или последняя строка, или первый или второй столбец четвертого квадрата) ИЛИ (выбран заполненый квадрат)
                    std::cout << "\033[35m" << submol << "\033[0m";
                }
                else {
                    std::cout << ".";
                };

                if (j + 1 != size) {
                    std::cout << " ";
                };
            };
        };

        // Переход на новую строку
        std::cout << "\n";
    };
};

// Вернет чилсо из диапазонa [start, end]
int getRandomNumber(int start, int end) {
    // Регулятор случайных чисел (статический, чтобы не переинициализировать)
    static std::random_device rd;
    static std::mt19937 gen(rd());

    // Задаем диапазон
    std::uniform_int_distribution<> distr(start, end);

    return distr(gen);
}

// Если кто то выиграл, то вернет кто выиграл, первый игрок или второй(или компьютер)(вернет 1 или 2 соответствено), а если никто не выиграл вернет 0
short whoIsWin(std::vector<char> table, char figureOnePlayer, char figureTwoPlayer) {
    std::cout << "\n\nSTART TEST\n";
    for (char e : table) {
        std::cout << (e - '0') - 1 << "   " << e << "\n";
    }
    std::cout << figureOnePlayer << "\n";
    std::cout << figureTwoPlayer << "\n";
    std::cout << "END TEST\n\n";



    if ((table[0] == table[3] && table[3] == table[6])) {
        // Все три фигуры в первом столбце совпадают

        if (table[0] == figureOnePlayer) {
            // Все три совпадающих символы в столбце, это символы первого игрока, значит он победил
            return 1;
        }
        else if (table[0] == figureTwoPlayer) {
            // Все три совпадающих символы в столбце, это символы второго игрока или компьютера, значит он победил
            return 2;
        }
    }
    else if (table[1] == table[4] && table[4] == table[7]) {
        // Все три фигуры во втором столбце совпадают

        if (table[1] == figureOnePlayer) {
            // Все три совпадающих символы в столбце, это символы первого игрока, значит он победил
            return 1;
        }
        else if (table[1] == figureTwoPlayer) {
            // Все три совпадающих символы в столбце, это символы второго игрока или компьютера, значит он победил
            return 2;
        }
    }
    else if (table[2] == table[5] && table[5] == table[8]) {
        // Все три фигуры в третем столбце совпадают

        if (table[2] == figureOnePlayer) {
            // Все три совпадающих символы в столбце, это символы первого игрока, значит он победил
            return 1;
        }
        else if (table[2] == figureTwoPlayer) {
            // Все три совпадающих символы в столбце, это символы второго игрока или компьютера, значит он победил
            return 2;
        }
    }
    
    else if (table[0] == table[1] && table[1] == table[2]) {
        // Все три фигруы в первой строке совпадают

        if (table[0] == figureOnePlayer) {
            // Все три совпадающих символы в строке, это символы первого первого игрока, значит он победил
            return 1;
        }
        else if (table[0] == figureTwoPlayer) {
            // Все три совпадающих символы в строке, это символы второго игрока или компьютера, значит он победил
            return 2;
        }
    }
    else if (table[3] == table[4] && table[4] == table[5]) {
        // Все три фигруы во второй строке совпадают

        if (table[3] == figureOnePlayer) {
            // Все три совпадающих символы в строке, это символы первого первого игрока, значит он победил
            return 1;
        }
        else if (table[3] == figureTwoPlayer) {
            // Все три совпадающих символы в строке, это символы второго игрока или компьютера, значит он победил
            return 2;
        }
    }
    else if (table[6] == table[7] && table[7] == table[8]) {
        // Все три фигруы в третей строке совпадают

        if (table[6] == figureOnePlayer) {
            // Все три совпадающих символы в строке, это символы первого первого игрока, значит он победил
            return 1;
        }
        else if (table[6] == figureTwoPlayer) {
            // Все три совпадающих символы в строке, это символы второго игрока или компьютера, значит он победил
            return 2;
        }
    }

    else if (table[0] == table[4] && table[4] == table[8]) {
        // Все три фигруы в диагонали из левого верхнего угла в правый нижний угол совпадают

        if (table[0] == figureOnePlayer) {
            // Все три символы в диагонали, это символы первого игрока, значит он победил
            return 1;
        }
        else if (table[0] == figureTwoPlayer) {
            // Все три символы в диагонали, это символы второго игрока или компьютера, значит он победил
            return 2;
        }
    }
    else if (table[2] == table[4] && table[4] == table[6]) {
        // Все три фигруы в диагонали из правого верхнего угла в левый нижний угол совпадают

        if (table[2] == figureOnePlayer) {
            // Все три символы в какой то диагонали, это символы первого игрока, значит он победил
            return 1;
        }
        else if (table[2] == figureTwoPlayer) {
            // Все три символы в какой то диагонали, это символы второго игрока или компьютера, значит он победил
            return 2;
        }
    }
    else {
        // Если ни одна проверка не сработала, то никто не победил
        // Цикл который проверят, что в массиве все символы заполены(все символы это какие то фигуры игроков), тоесть никто больше не может добавить числа, и получаеться ничья
        bool isAllFigure = true;
        for (int i = 0; i < table.size(); i++) {
            if (table[i] != figureOnePlayer && table[i] != figureTwoPlayer) {
                // Какой то символ в массиве, это не одна из фигур игроков
                isAllFigure = false;
                break;
            }
        };

        if (isAllFigure) {
            // Все элементы массива фигуры игроков, значит вводить числа больше нельзя, а значит это ничья
            return -1;
        };

        // Ни одна проверка не прошла, значит в таблице есть еще места куда можно добавлять фигуры И никто не победил
        return 0;
    }


    /*if ((table[0] == table[3] && table[3] == table[6]) || (table[1] == table[4] && table[4] == table[7]) || (table[2] == table[5] && table[5] == table[8])) {
        // В каком то столбце все три символа совпадают

        if ((table[0] == figureOnePlayer) || (table[1] == figureOnePlayer) || (table[2] == figureOnePlayer)) {
            // Все три совпадающих символы в каком то столбце, это символы первого игрока, значит он победил
            return 1;
        }
        else if ((table[0] == figureTwoPlayer) || (table[1] == figureTwoPlayer) || (table[2] == figureTwoPlayer)) {
            // Все три совпадающих символы в каком то столбце, это символы второго игрока или компьютера, значит он победил
            return 2;
        }
    } 
    else if ((table[0] == table[1] && table[1] == table[2]) || (table[3] == table[4] && table[4] == table[5]) || (table[6] == table[7] && table[7] == table[8])) {
        // В какой строке все три символа совпадают

        if ((table[0] == figureOnePlayer) || (table[3] == figureOnePlayer) || (table[6] == figureOnePlayer)) {
            // Все три совпадающих символы в какой то строке, это символы первого первого игрока, значит он победил
            return 1;
        }
        else if ((table[0] == figureTwoPlayer) || (table[3] == figureTwoPlayer) || (table[6] == figureTwoPlayer)) {
            // Все три совпадающих символы в какой то строке, это символы второго игрока или компьютера, значит он победил
            return 2;
        }
    }
    else if ((table[0] == table[4] && table[4] == table[8]) || (table[2] == table[4] && table[4] == table[6])) {
        // Все три символы в какой то диагонали совпадает

        if ((table[0] == figureOnePlayer) || (table[2] == figureOnePlayer)) {
            // Все три символы в какой то диагонали, это символы первого игрока, значит он победил
            return 1;
        }
        else if ((table[0] == figureTwoPlayer) || (table[2] == figureTwoPlayer)) {
            // Все три символы в какой то диагонали, это символы второго игрока или компьютера, значит он победил
            return 2;
        }
    }
    else {
        // Если ни одна проверка не сработала, то никто не победил
        // Цикл который проверят, что в массиве все символы заполены(все символы это какие то фигуры игроков), тоесть никто больше не может добавить числа, и получаеться ничья
        bool isAllFigure = true;
        for (int i = 0; i < table.size(); i++) {
            if (table[i] != figureOnePlayer && table[i] != figureTwoPlayer) {
                // Какой то символ в массиве, это не одна из фигур игроков
                isAllFigure = false;
                break;
            }
        };

        if (isAllFigure) {
            // Все элементы массива фигуры игроков, значит вводить числа больше нельзя, а значит это ничья
            return -1;
        };

        // Ни одна проверка не прошла, значит в таблице есть еще места куда можно добавлять фигуры И никто не победил
        return 0;
    }*/
};


int main() {
    // Устанавливаем кодировку UTF-8 для ввода и вывода
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // Обязательно настраиваем вывод std::cout на работу с UTF-8
    std::setlocale(LC_ALL, ".UTF8");



    std::cout << "Выберите номер задания: ";
    std::string nString{};
    int n;
    n = getNumber();

    if (n == 1) {
        for (short i = 0; i < 5; i++) {
            // Char
            char s1 = 'a';
            std::cout << "Значение: " << s1 << ", Тип данных char, размер 1 б.\n";

            // Bool
            bool b1 = true;
            std::cout << "Значение: " << b1 << ", Тип данных bool, размер 1 б.\n";

            // Short
            short sh1 = 1;
            std::cout << "Значение: " << sh1 << ", Тип данных short, размер 1 б.\n";

            // Int
            int i1 = 1;
            std::cout << "Значение: " << i1 << ", Тип данных int, размер 1 б.\n";

            // Float
            float f1 = 1.1;
            std::cout << "Значение: " << f1 << ", Тип данных float, размер 1 б.\n";

            // Doudle
            double d1 = 1.1;
            std::cout << "Значение: " << d1 << ", Тип данных double, размер 1 б.\n";

            // String
            std::string str1 = "ab";
            std::cout << "Значение: " << str1 << ", Тип данных double, размер 1 б.\n";

            std::cout << "\n";
        }
    }
    else if (n == 2) {
        // Массив времен года
        std::vector<std::string> a = { "Лето", "Осень", "Зима", "Весна" };

        std::cout << "Введите номер года(Лето, Осень, Зима, Весна): ";
        std::string localNString{};
        short localN{};
        std::cin >> localNString;
        try {
            localN = std::stoi(localNString);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Вы ввели не число";
            return 0;
        }
        catch (const std::out_of_range& e) {
            std::cout << "Вы ввели слишком большое число.";
            return 0;
        };

        if (localN >= 0 && localN < a.size()) {
            std::cout << "Cейчас: " << a[localN - 1];
        }
        else {
            std::cout << "Вы ввели неизвестное число";
        };
    }
    else if (n == 3) {
        std::cout << "Введите число: ";
        std::string localNString;
        short localN;
        std::cin >> localNString;
        std::cout << "\n";
        try {
            localN = std::stoi(localNString);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.\n";
            return 0;
        }
        catch (const std::out_of_range& e) {
            std::cout << "Вы ввели слишком большое число.\n";
            return 0;
        };

        std::cout << "\n\n\n" << localN << "     " << localNString << "\n\n\n";

        if (localN < 0) {
            std::cout << "Число меньше 0.\n";
            return 0;
        }
        else if (localN > 100) {
            std::cout << "Число больше 100.\n";
            return 0;
        };

        // Массив диапазонов
        std::vector<std::string> a = { "0-10", "11-20", "21-30", "31-40", "41-50", "51-60", "61-70", "71-80", "81-90", "91-100" };

        // Из 19 преобразует сначала в 1.9, а потом в 1 для индексации массива
        float b = std::trunc(localN / 10);
        if (std::trunc(b) == 10) {
            std::cout << "Диапазон: " << a[9] << "\n";
        }
        else {
            short c = std::trunc(b);
            std::cout << "Диапазон: " << a[c] << "\n";
        }
    }
    else if (n == 4) {
        std::cout << "Введите число: ";
        std::string localNString;
        short localN;
        std::cin >> localNString;
        std::cout << "\n";
        try {
            localN = std::stoi(localNString);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.\n";
            return 0;
        }
        catch (const std::out_of_range& e) {
            std::cout << "Вы ввели слишком большое число.\n";
            return 0;
        };

        short i = 1;
        short count = 0;
        while (i <= localN) {
            std::cout << "Пример: " << localN << "*" << i << "\n";
            std::cout << "Дайте ответ на пример вышe: ";
            std::cout << "Введите число: ";
            std::string localNString2;
            short localN2;
            std::cin >> localNString2;
            std::cout << "\n";
            try {
                localN2 = std::stoi(localNString2);
            }
            catch (const std::invalid_argument& e) {
                std::cout << "Вы ввели не число.\n";
                return 0;
            }
            catch (const std::out_of_range& e) {
                std::cout << "Вы ввели слишком большое число.\n";
                return 0;
            };

            if (localN2 == localN * i) {
                std::cout << "Верно\n";
                count++;
            }
            else {
                std::cout << "Неверно\n";
                std::cout << "Количество верных примеров: " << count;
                break;
            }
            i++;
        };
    }
    else if (n == 5) {
        // Массив коректных операторов
        std::vector<std::string> opes = { "+", "-", "/", "*", "%" };

        std::cout << "Введите оператор: ";
        std::string ope{};
        std::string str{};
        std::cin >> str;
        ope = str[0];
        std::cout << "\n";
        std::cout << ope;

        bool isIn = false;
        for (short i = 0; i < opes.size(); i++) {
            if (opes[i] == ope) {
                isIn = true;
                break;
            };
        };

        std::cout << "\n\n\n" << isIn << "    " << ope << "\n\n\n";

        if (isIn == false) {
            std::cout << "Неизвестный оператор\n";
            return 0;
        };

        std::cout << "Введите первое число: ";
        std::string localNString1;
        short localN1;
        std::cin >> localNString1;
        std::cout << "\n";
        try {
            localN1 = std::stoi(localNString1);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.\n";
            return 0;
        }
        catch (const std::out_of_range& e) {
            std::cout << "Вы ввели слишком большое число.\n";
            return 0;
        };

        std::cout << "Введите второе число: ";
        std::string localNString2;
        short localN2;
        std::cin >> localNString2;
        std::cout << "\n";
        try {
            localN2 = std::stoi(localNString2);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.\n";
            return 0;
        }
        catch (const std::out_of_range& e) {
            std::cout << "Вы ввели слишком большое число.\n";
            return 0;
        };

        if (ope == "+") {
            std::cout << localN1 << " + " << localN2 << " = " << localN1 + localN2 << "\n";
        }
        else if (ope == "-") {
            std::cout << localN1 << " - " << localN2 << " = " << localN1 - localN2 << "\n";
        }
        else if (ope == "*") {
            std::cout << localN1 << " * " << localN2 << " = " << localN1 * localN2 << "\n";
        }
        else if (ope == "/") {
            std::cout << localN1 << " / " << localN2 << " = " << localN1 / localN2 << "\n";
        }
        else {
            // Так как было проверкас isIn в начале не нужно еще раз проверять на %, если это не +, не -, не * и не / значит это %
            std::cout << localN1 << " % " << localN2 << " = " << localN1 % localN2 << "\n";
        };
    }
    else if (n == 6) {
        std::string localNString;
        short localN;
        std::cin >> localNString;
        try {
            localN = std::stoi(localNString);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.\n";
            std::exit(0);
        }
        catch (const std::out_of_range& e) {
            std::cout << "Вы ввели слишком большое число.\n";
        };

        switch (localN) {
        case 1:
            std::cout << "Февраль.\n";
            break;
        case 2:
            std::cout << "Январь.\n";
            break;
        case 3:
            std::cout << "Март.\n";
            break;
        case 4:
            std::cout << "Апрель.\n";
            break;
        case 5:
            std::cout << "Май.\n";
            break;
        case 6:
            std::cout << "Июнь.\n";
            break;
        case 7:
            std::cout << "Июль.\n";
            break;
        case 8:
            std::cout << "Август.\n";
            break;
        case 9:
            std::cout << "Сентябрь.\n";
            break;
        case 10:
            std::cout << "Октябрь.\n";
            break;
        case 11:
            std::cout << "Ноябрь.\n";
            break;
        case 12:
            std::cout << "Декабрь.\n";
            break;
        default:
            std::cout << "UNKNOWN NUMBER";
        };
    }
    else if (n == 7) {
        std::cout << "Введите номер месяца.";
        std::string numberMounthString;
        short numberMounth;
        std::cin >> numberMounthString;
        try {
            numberMounth = std::stoi(numberMounthString);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.\n";
            std::exit(0);
        }
        catch (const std::out_of_range& e) {
            std::cout << "Вы ввели слишком большое число.\n";
            std::exit(0);
        };

        std::cout << "Введите номер месяца: ";
        std::string numberDayString;
        short numberDay;
        std::cin >> numberDayString;
        try {
            numberDay = std::stoi(numberDayString);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.\n";
            std::exit(0);
        }
        catch (const std::out_of_range& e) {
            std::cout << "Вы ввели слишком большое число.\n";
            std::exit(0);
        };

        if ((numberMounth < 0) || (numberMounth > 12) || (numberDay < 0) || (numberDay > 31)) {
            std::cout << "Вы ввели не корректное число.\n";
            std::exit(0);
        };

        switch (numberMounth) {
        case 1:
            if (isCorrectNumber(numberDay, 31) == true) {
                std::cout << numberDay << " января.\n";
            };
            break;
        case 2:
            if (isCorrectNumber(numberDay, 29) == true) {
                std::cout << numberDay << " февраля.\n";
            };
            break;
        case 3:
            if (isCorrectNumber(numberDay, 31) == true) {
                std::cout << numberDay << " марта.\n";
            };
            break;
        case 4:
            if (isCorrectNumber(numberDay, 30) == true) {
                std::cout << numberDay << " апреля.\n";
            };
            break;
        case 5:
            if (isCorrectNumber(numberDay, 31) == true) {
                std::cout << numberDay << " майя.\n";
            };
            break;
        case 6:
            if (isCorrectNumber(numberDay, 30) == true) {
                std::cout << numberDay << " июня.\n";
            };
            break;
        case 7:
            if (isCorrectNumber(numberDay, 31) == true) {
                std::cout << numberDay << " июля.\n";
            };
            break;
        case 8:
            if (isCorrectNumber(numberDay, 31) == true) {
                std::cout << numberDay << " августа.\n";
            };
            break;
        case 9:
            if (isCorrectNumber(numberDay, 30) == true) {
                std::cout << numberDay << " cентября.\n";
            };
            break;
        case 10:
            if (isCorrectNumber(numberDay, 31) == true) {
                std::cout << numberDay << " октября.\n";
            };
            break;
        case 11:
            if (isCorrectNumber(numberDay, 30) == true) {
                std::cout << numberDay << " ноября.\n";
            };
            break;
        case 12:
            if (isCorrectNumber(numberDay, 31) == true) {
                std::cout << numberDay << " декабря.\n";
            };
            break;
        default:
            std::cout << "UNKNOWN NUMBER";
        };
    }
    else if (n == 8) {
        const std::vector<std::string> russianWord = { "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять", "десять", "одинадцать", "двенадцать", "тринадцать", "четырнадцать", "пятьнадцать" };
        const std::vector<std::string> englishWord = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "pyatnadtsat" };

        std::cout << "[1] Русские слова.\n";
        std::cout << "[2] Английские слова.\n\n";
        std::cout << "[3] Выйти.\n\n";

        // Выбор русского или английского
        std::cout << "Выберите пункт меню: ";
        std::string localNString1;
        short localN1;
        std::cin >> localNString1;
        std::cout << std::endl;
        try {
            localN1 = std::stoi(localNString1);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.\n";
            std::exit(0);
        }
        catch (const std::out_of_range& e) {
            std::cout << "Вы ввели слишком большое или слишком маленькое число.\n";
            std::exit(0);
        };

        switch (localN1) {
        case 1:
            // Пользователь выбрал русские слова, 16 это длина russinWord, что бы не было обращения к переменной и очень микро оптимизация
            for (short i = 0; i < 15; i++) {
                std::cout << "[" << i + 1 << "]" << " " << russianWord[i] << "\n";
            };
            std::cout << std::endl;
            break;
        case 2:
            // Пользователь выбрал английские слова, 16 это длина englishWord, что бы не было обращения к переменной и очень микро оптимизация
            for (short i = 0; i < 15; i++) {
                std::cout << "[" << i + 1 << "]" << " " << englishWord[i] << "\n";
            };
            std::cout << std::endl;
            break;
        case 3:
            std::cout << "Вы вышли.\n";
            std::exit(0);
            break;
        default:
            std::cout << "Вы ввели не корректное число.\n";
            exit(0);
            break;
        };

        //  Выбор номера слова
        std::cout << "Выберите номер слова для перевода: ";
        std::string localNString2;
        short localN2;
        std::cin >> localNString2;
        std::cout << std::endl;
        try {
            localN2 = std::stoi(localNString2);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.\n";
            std::exit(0);
        }
        catch (const std::out_of_range& e) {
            std::cout << "Вы ввели слишком большое или слишком маленькое число.\n";
            std::exit(0);
        };

        std::cout << "Перевод: ";
        switch (localN1) {
        case 1:
            std::cout << englishWord[localN2 - 1];
            break;
        case 2:
            std::cout << russianWord[localN2 - 1];
            break;
        }
    }
    else if (n == 9) {
        while (true) {
            std::cout << "Введите количество итераций от 1 до 15: ";
            int count;
            std::string countString;
            std::cin >> countString;
            try {
                count = std::stoi(countString);
            }
            catch (const std::invalid_argument& e) {
                std::cout << "Вы ввели не число.\n";
                std::exit(0);
            }
            catch (const std::out_of_range& e) {
                std::cout << "Вы ввели слишком большое или слишком маленькое число.\n";
                std::exit(0);
            };

            if (count == 0) {
                std::cout << "END\n";
                std::exit(0);
            }
            else if (count < 0 || count > 15) {
                std::cout << "Можно только количество итераци в диапазоне [1, 15]\n";
                std::exit(0);
            };

            int i = 1;
            while (i <= count) {
                std::cout << "[+] Цикл отработал. Круг: " << i << ".\n";
                i++;
            };
        };
    }
    else if (n == 10) {
        std::cout << "[0] START GAME\n";
        std::cout << "[1] EXIT\n\n";

        int localN = getNumber();

        if (localN != 0 && localN != 1) {
            std::cout << "Можно вводить только 0 и 1.\n";
            std::exit(0);
        };

        if (localN == 0) {
            // Начальное значение переменных
            short countCurrentNumber = 0;
            short countAttempt = 5;
            std::vector<int> randomNumbers = {};

            // 1. Инициализируем генератор случайных чисел случайным сидом (зерном)
            std::random_device rd;
            std::mt19937 gen(rd());

            // 2. Задаем диапазон [min, max] (включительно с обеих сторон)
            int min = 1;
            int max = 10;
            std::uniform_int_distribution<int> distrib(min, max);

            // Три итерации для трех генераций рандомного числа
            short i = 0;

            while (i < 3) {
                // 3. Генерируем случайное число
                int randomNumber = distrib(gen);

                if (!contains(randomNumbers, randomNumber)) {
                    // Такого числа нету в векторе randomNumbers
                    // увеличивать i и добавлять число в randomNumbers, а если бы число было в векторе пройти это на один раз больше предустановленого три раза
                    i++;
                    randomNumbers.push_back(randomNumber);
                };
            };

            std::cout << "\n\n\n";
            for (int number : randomNumbers) {
                std::cout << number << "\n";
            };

            std::cout << "\n\n\n";

            // Цикл пока не закончаться попытки или пользователь не найдет все числа
            while (true) {
                printInterface(countCurrentNumber, countAttempt);

                std::cout << "Введите число: ";
                int number = getNumber();

                // Если число не из заданного диапазона уведомить об этом пользователя и не снимать попытку
                if (number < 0 || number > 10) {
                    std::cout << "Число может быть только в диапазоне [1, 10].\n";
                    continue;
                };

                // Очистить консоль
                std::cout << "\n\n\n";

                // Если число есть в массиве удалить его из массива, увеличить количество отгадонных числе на 1 и уменьшить количество попыток на 1
                if (contains(randomNumbers, number)) {
                    std::erase(randomNumbers, number);
                    countCurrentNumber++;

                    std::cout << "Верно.\n";
                }
                else {
                    std::cout << "Неверно.\n";
                };


                // Уменьшить количество попыток пользователя на 1
                countAttempt--;

                // Если количество попыток пользователя стало 0 или количество угаданных пользователем чисел стало 3
                if (countAttempt == 0 || countCurrentNumber == 3) {
                    break;
                };
            };

            if (countCurrentNumber == 3) {
                std::cout << "YOU WIN.\n";
            }
            else if (countAttempt == 0) {
                std::cout << "YOU LOSE.\n";

                // Вывод чисел которые не угадал пользователь
                std::cout << "Числа которое вы не угадали: \n";
                for (int number : randomNumbers) {
                    std::cout << number << "\n";
                };
            };

            std::exit(0);
        }
        else {
            std::cout << "END.\n";
            std::exit(0);
        };
    }
    else if (n == 11) {
        std::cout << "[+] Программа - \"Геометрические фигуры\".\n";
        std::cout << "[1] Линия.\n";
        std::cout << "[+] Выберите фигуру: ";
        int localN = getNumber();

        if (localN == 1) {
            std::cout << "\n\n\n";

            line();
        }
        else {
            std::cout << "Такого пункта нету.\n";
            std::exit(0);
        };
    }
    else if (n == 101) {
        std::cout << "Введите число: ";
        int localN = getNumber();

        // Значение общей суммы всех вводимых чисел в начале будет равна localN
        int result = localN;
        while (localN != 0) {
            std::cout << "Введите число: ";
            localN = getNumber();
            result += localN;
        };


        std::cout << "Сумма: " << result << "\n";

    }
    else if (n == 102) {
        std::cout << "Введите число до которого будет производиться обратный отсчет: ";
        int number = getNumber();
        if (number < 1) {
            std::cout << "Вы ввели число от которого нельзя произвести отсчет до нуля.\n";
            std::exit(0);
        };

        while (number != 0) {
            std::cout << number << "\n";
            number--;
        };

        std::cout << "START";
    }
    else if (n == 103) {
        std::cout << "[+] Введите число: ";
        int number = getNumber();

        int count = 0;
        int sum = number;
        while (number != 0) {
            std::cout << "[+] Введите число: ";
            number = getNumber();

            count++;
            sum += number;
        };

        std::cout << "Количество чисел: " << count << "\n";
        std::cout << "Сумма: " << sum << "\n";
    }
    else if (n == 104) {
        std::cout << "[+] Введите число: ";
        int number = getNumber();

        /* std::string string = std::to_string(number);
        std::cout << "[+] Количество цифр: " << string.size() << "\n"; */

        int count = 0;
        while (number != 0) {
            number /= 10;
            count++;
        };

        std::cout << "[+] Количество цифр: " << count << "\n";
    }
    else if (n == 105) {
        std::cout << "[+] Введите число: ";
        int number = getNumber();

        int i = 1;
        while (i != 11) {
            std::cout << number << " * " << i << " = " << number * i << "\n";
            i++;
        };
    }
    else if (n == 106) {
        std::cout << "[+] Введите число: ";
        int number = getNumber();

        int sum = number;
        int count = 1;

        while (true) {
            std::cout << "[+] Введите число: ";
            number = getNumber();

            if (number == 0) {
                break;
            };

            count++;
            sum += number;
        };

        std::cout << "[+] Среднее арифметическое: " << sum / count << "\n";
    }
    else if (n == 107) {
        std::string PASSWORD = "12345";

        std::cout << "Введите пароль: ";
        std::string value;
        std::cin >> value;
        while (value != PASSWORD) {
            std::cout << "Неверный пароль.\n\n";
            std::cout << "Введите пароль: ";
            std::cin >> value;
        };

        std::cout << "WELCOME\n";
    }
    else if (n == 12) {
        // Перeменнные содаржищие значение по умолчанию
        std::string userName = "user";
        int countQuestions = 10;
        short currentAnswer = 0;
        short countLife = 5;
        short glasses = 0;

        std::vector<std::string> vectorQuestions = { "Что такое переменная в программировании?", "Как расшифровывается аббревиатура HTML?", "Какой принцип работы у структуры данных «Стек» (Stack)?", "Какой оператор в большинстве языков программирования используется для проверки равенства двух значений?", "Что делает цикл while?", "акой тип данных лучше всего подходит для хранения логического значения (истина / ложь)?", "Что такое рекурсия?", "Какая система контроля версий является самой популярной в мире?", "Что такое синтаксическая ошибка (Syntax Error)?", "Что такое массив (Array)?", "Какой язык запросов используется реляционными базами данных?", "Что означает комментарий в коде программы?" };
        std::vector<std::vector<std::string>> vectorAnswerOptions = {
            {"Именованная область памяти для хранения данных", "Часть кода, которая всегда выполняется один раз", "Математическая формула без результата", "Ошибка компиляции"},
            {"High Transfer Machine Language", "HyperText Markup Language", "Home Tool Multi Language", "Hyperlink Text Modern Logic"},
            {"FIFO (First In, First Out — первым вошел, первым вышел)", "LIFO (Last In, First Out — последним вошел, первым вышел)", "Случайный порядок извлечения", "Строгая сортировка по возрастанию"},
            {"=", ":=", "==", "<>"},
            {"Выполняет блок кода один раз, если условие истинно", "Повторяет блок кода до тех пор, пока проверяемое условие истинно", "Всегда выполняется бесконечное число раз", "Создает новую функцию"},
            {"String (строка)", "Integer (целое число)", "Boolean (булев тип)", "Float (число с плавающей точкой)"},
            {"Вызов функции самой себя", "Зацикливание программы из-за ошибки в синтаксисе", "Удаление переменной из памяти", "Способ компиляции кода в машинный язык"},
            {"SVN", "Mercurial", "Git", "CVS"},
            {"Ошибка в логике работы алгоритма, когда программа выдает неверный результат", "Нарушение правил написания кода языка программирования, из-за чего он не может быть скомпилирован", "Сбой программы во время работы из-за деления на ноль", "Вирус в исходном коде"},
            {"Неупорядоченный список любых файлов на жестком диске", "Структура данных, хранящая набор элементов в непрерывном участке памяти", "Функция для математических расчетов", "База данных SQL"},
            {"HTML", "Python", "SQL", "CSS"},
            {"Инструкцию для процессора по оптимизации скорости", "Текст, который игнорируется компилятором/интерпретатором и служит для пояснения кода людям", "Команду вывода текста на экран", "Секретный пароль доступа к базе данных"}
        };
        std::vector<int> vectorCorrectAnswers = { 1, 2, 2, 3, 2, 3, 1, 3, 2, 2, 3, 2 };

        bool isBreak = false;
        // Бесконечный цикл, нужен что бы можно было настроить и продолжить играть, а не только настройка, после программа завершаеться и данные нигде не сохраняються
        while (true) {
            if (isBreak) {
                break;
            };
            std::cout << "[0] Начать игру.\n";
            std::cout << "[1] Настройки.\n";
            std::cout << "[2] Правила.\n";
            std::cout << "[3] Выйти.\n";

            std::cout << "Выберите пункт: ";
            int number = getNumber();

            std::cout << "\n";

            if (number == 0) {
                // игра
                while (true) {
                    printMenuAndQuestionGame(currentAnswer + 1, userName, countLife, glasses, vectorQuestions[currentAnswer], vectorAnswerOptions[currentAnswer]);
                    std::string value;
                    std::cin >> value;

                    if (std::stoi(value) == vectorCorrectAnswers[currentAnswer]) {
                        // Пользователь ввел правильный ответ, увеличить количество очков на 1
                        glasses++;
                        std::cout << "Верно\n\n";
                    }
                    else {
                        // Пользователь ввел неправильный ответ, уменьшить количество жизней на 1
                        std::cout << "Неверно.\n";
                        countLife--;
                    };

                    // Увеличить текущий номер вопроса на 1
                    currentAnswer++;

                    if (countLife == 0) {
                        // Количество жизней 0, пользователь проиграл
                        std::cout << "Вы проиграли.\n";

                        // Выйти из текущего цикла while а так же сделать значение флага isBreak равным true что бы в начале следующего глобального цикла проверилось isBreak и выполнилось break
                        isBreak = true;
                        break;
                    }
                    else if (currentAnswer == countQuestions) {
                        // Текущий вопрос был последний, вывести оставшее количесвто жизней и количество очков
                        std::cout << "Вопросы закончились.\n";
                        std::cout << "У вас осталось: " << countLife << " жизней и вы набрали: " << glasses << " очков.\n";

                        // Выйти из текущего цикла while а так же сделать значение флага isBreak равным true что бы в начале следующего глобального цикла проверилось isBreak и выполнилось break
                        isBreak = true;
                        break;
                    };
                };
            }
            else if (number == 1) {
                std::cout << "[0] Редактирование имя игрока.\n";
                std::cout << "[1] Редактирование вопросов в игре. Можно изменить на 8 - 10 - 12.\n";
                std::cout << "[2] EXIT.\n";

                std::cout << "Выберите пункт для изменения или выхода: ";
                int localNumber = getNumber();
                std::cout << "\n";


                if (localNumber == 0) {
                    std::cout << "Введите новое имя: ";
                    std::string newUserName;
                    std::cin >> newUserName;

                    userName = newUserName;
                }
                else if (localNumber == 1) {
                    int newCountQuestions;
                    std::cout << "Введите новое количество вопросов: ";
                    newCountQuestions = getNumber();

                    countQuestions = newCountQuestions;
                }
                else if (localNumber == 2) {
                    // Перейти к следующей итeрации, что бы заново выбрать пункт игры, настроек и тд
                    continue;
                }
                else {
                    std::cout << "Такого пункта нету.\n";
                };

                // очистка консоли что бы меню n-1 не накладывалось на n из за того что заново выводиться меню выбора
                std::cout << "\n\n\n";

                // потому что не работает std::cout << "\n\n\n"; просто выводить переводить стркоу на два вперед
                std::cout << "\n\n";
            }
            else if (number == 2) {
                std::cout << "Игрок получает очки за правильный ответ на вопрос.\n";
                std::cout << "Игрок проходит дальше за правильный ответ.\n";
                std::cout << "Игрок теряет жизнь при неправильном ответе.\n\n";
            }
            else if (number == 3) {
                std::cout << "EXIT.\n";
                std::exit(0);
            }
            else {
                std::cout << "Такого пункта нету.\n";
                std::exit(0);
            };
        };
    }
    else if (n == 301) {
        // Количество очков нужное для победы
        int countGlassesForWin = 3;

        int computerGlasses = 0;
        int userGlasses = 0;

        std::cout << "[1] Начать игру.\n";
        std::cout << "[2] Выйти.\n\n";

        std::cout << "Введите номер: ";
        int choice = getNumber();

        // Очистить буфер ввода, для того что бы можно было ждать нажатия Enter, а не сразу перескакивать на следующую строку
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

        if (choice == 1) {
            while (true) {
                std::cout << "Счет: Игрок: " << userGlasses << ", Компьютер: " << computerGlasses << "\n";
                std::cout << "Нажмите Enter, чтобы бросить кубики";

                // Ждать нажатия Enter
                std::cin.get();

                // Рандомные числа пользователя
                int oneUserNumber = getRandomNumber(1, 6);
                int twoUserNumber = getRandomNumber(1, 6);

                // Рандомные числа компьютера
                int oneComputerNumber = getRandomNumber(1, 6);
                int twoComputerNumber = getRandomNumber(1, 6);

                // Результаты партии
                int resultUser = oneUserNumber + twoUserNumber;
                if (oneUserNumber == twoUserNumber) {
                    resultUser *= 2;
                };

                int resultComputer = oneComputerNumber + twoComputerNumber;
                if (oneComputerNumber == twoComputerNumber) {
                    resultComputer *= 2;
                };

                std::cout << "Ваш бросок: " << oneUserNumber << " + " << twoUserNumber << " = " << resultUser << "\n";
                std::cout << "Бросок компьютера: " << oneComputerNumber << " + " << twoComputerNumber << " = " << resultComputer << "\n";

                // Если одинаковая сумма, то переигрывать
                if (resultUser == resultComputer) {
                    std::cout << "Сумма одинаковая, переигрываем.\n\n\n\n";
                    continue;
                };

                if (resultUser > resultComputer) {
                    std::cout << "YOU.\n";
                    userGlasses++;
                }
                else {
                    std::cout << "NOT YOU.\n";
                    computerGlasses++;
                };

                // Что бы отделить раунды друг от друга визуально
                std::cout << "\n\n\n";

                // Если кто то уже набрал нужно количество очков, то завершать цикл
                if (userGlasses == countGlassesForWin || computerGlasses == countGlassesForWin) {
                    break;
                };
            };

            if (userGlasses > computerGlasses) {
                std::cout << "YOU WIN.\n";
            }
            else {
                std::cout << "NOT YOU WIN.\n";
            };

            std::exit(0);
        }
        else if (choice == 2) {
            std::cout << "ВСЕ.\n";
        }
        else {
            std::cout << "Неизвестное число.\n";
        };

        std::exit(0);
    }
    else if (n == 302) {
        // По умолчанию 100 монет
        int balance = 100;

        while (true) {
            std::cout << "YPUR BALANCE: " << balance << "\n";

            // Получение ставки 
            std::cout << "Enter your bid: ";
            int bid = getNumber();

            // Проверка ставик на вылидность и может ли пользователь постаивть столько 
            if (bid < 1 || bid > balance) {
                std::cout << "Вы ввели недопустимую ставку.\n";
                continue;
            };

            // Получение стороны которую выбирает пользователь
            std::cout << "Выберите сторону (1 - Орел, 2 - Решка): ";
            int side = getNumber();

            // Проверка введeного пользователем числа на корректность
            if (side > 2 || side < 1) {
                std::cout << "Вы ввели недопустимое сторону.\n";
            };


            // Получение рандомного числа
            int randomNumber = getRandomNumber(0, 1);

            // Проверка выиграл ли пользователь или нет
            if (randomNumber == 0) {
                std::cout << "Выпал орел.\n";

                if (side == 1) {
                    // Выпал орел и пользователь поставил на орла, пользователь победил
                    std::cout << "Вы выиграли раунд.\n";
                    balance += bid;
                }
                else {
                    // Выпал орел и пользователь поставил на решку, пользователь проиграл
                    std::cout << "Вы проиграли раунд.\n";
                    balance -= bid;
                }
            }
            else {
                std::cout << "Выпала решка.\n";

                if (side == 1) {
                    // Выпала решка и пользователь поставил на орла, пользователь проиграл
                    std::cout << "Вы проиграли раунд.\n";
                    balance -= bid;
                }
                else {
                    // Выпала решка и пользователь поставил на решку, пользователь выиграл
                    std::cout << "Вы выиграли раунд.\n";
                    balance += bid;
                };
            };

            if (balance == 0) {
                std::cout << "Вы проиграли игру.\n";
                break;
            }
            else if (balance >= 200) {
                std::cout << "Вы выиграли игру.\n";
                break;
            };

            // Длявизуального отличения раундов
            std::cout << "\n\n\n";
        };
    }
    else if (n == 303) {
        // У пользователя 7 попыток
        int attempts = 7;

        // Загадывание рандомного числа
        int computerRandomNumber = getRandomNumber(1, 100);

        while (true) {
            std::cout << "Попыток: " << attempts << "\n";
            std::cout << "Введите число: ";
            int userNumber = getNumber();

            std::cout << "\n";

            if (userNumber < 0 || userNumber > 100) {
                std::cout << "Введите число из диапазона [0, 100].\n";
                continue;
            };

            if (computerRandomNumber == userNumber) {
                std::cout << "Вы угадали.";
                break;
            }
            else if (std::abs(computerRandomNumber - userNumber) > 30) {
                std::cout << "Холодно! (разница больше 30)";
            }
            else if (std::abs(computerRandomNumber - userNumber) > 10 && std::abs(computerRandomNumber - userNumber) < 31) {
                std::cout << "Прохладно! (разница от 11 до 30)";
            }
            else if (std::abs(computerRandomNumber - userNumber) > 5 && std::abs(computerRandomNumber - userNumber) < 11) {
                std::cout << "Тепло! (разница от 6 до 10) ";
            }
            else if (std::abs(computerRandomNumber - userNumber) > 0 && std::abs(computerRandomNumber - userNumber) < 6) {
                std::cout << "Тепло! (разница от 1 до 5)";
            };

            // Добавление больше или меньше введеное число загаданого для каждой записи кроме если число угадано потому что там будет break и до сюда не дойдет выполнение
            std::cout << ", введеное число " << ((computerRandomNumber > userNumber) ? ("меньше") : ("больше")) << " загаданого числа.\n";

            // Уменьшение количества попыток на 1
            attempts--;

            if (attempts == 0) {
                std::cout << "Вы проиграли, загаданое число было " << computerRandomNumber;
                break;
            };
        };
    }
    else if (n == 304) {
        while (true) {
            std::cout << "[0] Exit.\n";
            std::cout << "[1] Generated password.\n\n";

            std::cout << "Введите номер пункта: ";
            int localN = getNumber();

            if (localN == 0) {
                std::cout << "You exit.\n";
                std::exit(0);
            }
            else if (localN == 1) {
                std::cout << "Введите длину пароля в дииапазоне [4, 20]: ";
                int lengthPassword = getNumber();

                // Проверка длины пароля
                if (lengthPassword < 4 && lengthPassword > 20) {
                    std::cout << "Невалидная длина пароля.\n\n\n\n";
                    continue;
                };

                // Получение сколько цифр будет в пароле
                std::cout << "Введите сколько в пароле будет чисел: ";
                int countNumber = getNumber();

                // Получение сколько строчных букв будет в пароле
                std::cout << "Введите сколько в пароле будет строчных букв: ";
                int countSmallLetter = getNumber();

                // Получение сколько заглавных букв будет в пароле
                std::cout << "Введите сколько в пароле будет заглавных букв: ";
                int countBigLetter = getNumber();

                // Проверка на то что сумма введеных количество цифр, строчных и заглавных букв будет равна lengthPassword
                if ((countNumber + countSmallLetter + countBigLetter) != lengthPassword) {
                    std::cout << "Введите количество цифр, строчных и заглавных букв так, что бы их общая сумма была длиной пароля которую вы ввели.\n\n\n\n";
                    continue;
                };

                // Переменная для счетчика в while цикле
                int i = 0;


                // Переменная которая обозначает что такого количества цифр в генерируемом пароле еще нету
                bool correctCountNumber = true;

                // Переменная которая обозначает текущее количество цифр в генерируемом пароле, нужно что бы изменять countNumberInGeneratedPassword = false, когда в генерируемом пароле станет столько цифр сколько нужно, тоесть когда countNumberInGeneratedPassword станет равно countNumber
                int countNumberInGeneratedPassword = 0;


                // Переменная которая обозначает что такого количества строчных букв в генерируемом пароле еще нету
                bool correctCountSmallLetter = true;

                // Переменная которая обозначает текущее количество строчных букв в генерируемом пароле, нужно что бы изменять correctCountSmallLetter = false, когда в генерируемом пароле станет столько цифр сколько нужно, тоесть когда countSmallLetterInGeneratedPassword станет равно countSmallLetter
                int countSmallLetterInGeneratedPassword = 0;


                // Переменная которая обозначает что такого количества заглавных букв в генерируемом пароле еще нету
                bool correctCountBigLetter = true;

                // Переменная которая обозначает текущее количество заглавных букв в генерируемом пароле, нужно что бы изменять correctCountBigLetter = false, когда в генерируемом пароле станет столько цифр сколько нужно, тоесть когда countBigLetterInGeneratedPassword станет равно countBigLetter
                int countBigLetterInGeneratedPassword = 0;


                // Переменная содержащая генерируемый пароль
                std::string password = "";


                while (true) {
                    // Генерация рандомного числа, что бы не было заданого програмно порядка добавления цифр, строчных и заглавных букв в пароль
                    int randomNumber = getRandomNumber(1, 3);

                    if (randomNumber == 1) {
                        // Добавить в пароль число
                        if (correctCountNumber) {
                            // В пароле еще не countNumber цифр
                            int randomNomerNumberInASKII = getRandomNumber(48, 57); // 48 это номер цифры "0", 57 номер цифры "9"
                            char number = randomNomerNumberInASKII;
                            password.push_back(number);
                            countNumberInGeneratedPassword++;
                            i++;
                        };

                        // Если количество цифр в генерируемом пароле станет столько сколь нужно, тоесть countNumber, то изменить correctCountNumber на false, тоесть больше не добавлять в генерируемый пароль цифры
                        if (countNumberInGeneratedPassword == countNumber) {
                            correctCountNumber = false;
                        };
                    }
                    else if (randomNumber == 2) {
                        // Добавить в пароль строчную букву
                        if (correctCountSmallLetter) {
                            // В пароле еще не countNumber цифр
                            int randomNomerNumberInASKII = getRandomNumber(97, 122); // 97 это номер строчной буквы "a", 122 номер строчной буквы "z"
                            char number = randomNomerNumberInASKII;
                            password.push_back(number);
                            countSmallLetterInGeneratedPassword++;
                            i++;
                        };

                        // Если количество цифр в генерируемом пароле станет столько сколь нужно, тоесть countNumber, то изменить correctCountNumber на false, тоесть больше не добавлять в генерируемый пароль цифры
                        if (countSmallLetterInGeneratedPassword == countSmallLetter) {
                            correctCountSmallLetter = false;
                        };
                    }
                    else {
                        // Добавить в пароль заглавную букву
                        if (correctCountBigLetter) {
                            // В пароле еще не countNumber цифр
                            int randomNomerNumberInASKII = getRandomNumber(65, 90); // 65 это номер строчной буквы "A", 90 номер строчной буквы "Z"
                            char number = randomNomerNumberInASKII;
                            password.push_back(number);
                            countBigLetterInGeneratedPassword++;
                            i++;
                        };

                        // Если количество цифр в генерируемом пароле станет столько сколь нужно, тоесть countNumber, то изменить correctCountNumber на false, тоесть больше не добавлять в генерируемый пароль цифры
                        if (countBigLetterInGeneratedPassword == countBigLetter) {
                            correctCountBigLetter = false;
                        };
                    };

                    if (password.size() == lengthPassword) {
                        break;
                    };
                };

                std::cout << "Ваш пароль: " << password << "\n";

                // Вывод надежности пароля взависимости от его длины
                std::cout << "Надежность: ";
                if (lengthPassword < 7) {
                    std::cout << "Низкая.\n\n\n\n";
                }
                else if (lengthPassword > 7 && lengthPassword < 13) {
                    std::cout << "Средняя.\n\n\n\n";
                }
                else if (lengthPassword > 12) {
                    std::cout << "Высокая.\n\n\n\n";
                };
            }
            else {
                std::cout << "Unknown number.\n\n\n\n";
                continue;
            };
        };
    }
    else if (n == 13) {
        std::cout << "[+] Программа - \"Геометрические фигуры\".\n\n";
        std::cout << "[1] Линия.\n";
        std::cout << "[2] Квадрат.\n\n";
        std::cout << "[+] Выберите фигуру: ";

        int localN = getNumber();

        if (localN == 1) {
            std::cout << "\n\n\n";

            line();
        }
        else if (localN == 2) {
            std::cout << "\n\n\n";
            square();
        }
        else {
            std::cout << "Такого пункта нету.\n";
            std::exit(0);
        };
    }
    else if (n == 14) {
        std::cout << "[+] Программа - \"Геометрические фигуры\".\n\n";
        std::cout << "[1] Линия.\n";
        std::cout << "[2] Квадрат.\n";
        std::cout << "[3] Прямоугольник.\n\n";
        std::cout << "[+] Выберите фигуру: ";

        int localN = getNumber();

        if (localN == 1) {
            std::cout << "\n\n\n";

            line();
        }
        else if (localN == 2) {
            std::cout << "\n\n\n";

            square();
        }
        else if (localN == 3) {
            std::cout << "\n\n\n";

            rectangle();
        }
        else {
            std::cout << "Такого пункта нету.\n";
            std::exit(0);
        };
    }
    else if (n == 15) {
        std::cout << "[+] Программа - \"Геометрические фигуры\".\n\n";
        std::cout << "[1] Линия.\n";
        std::cout << "[2] Квадрат.\n";
        std::cout << "[3] Прямоугольник.\n";
        std::cout << "[4] Треугольник.\n\n";
        std::cout << "[+] Выберите фигуру: ";

        int localN = getNumber();
        std::cout << "\n\n";

        if (localN == 1) {
            std::cout << "\n\n\n";

            line();
        }
        else if (localN == 2) {
            std::cout << "\n\n\n";

            square();
        }
        else if (localN == 3) {
            std::cout << "\n\n\n";

            rectangle();
        }
        else if (localN == 4) {
            triangle();
        }
        else {
            std::cout << "Такого пункта нету.\n";
            std::exit(0);
        };
    }
    else if (n == 16) {
        std::cout << "[+] Программа - \"Геометрические фигуры\".\n\n";
        std::cout << "[1] Линия.\n";
        std::cout << "[2] Квадрат.\n";
        std::cout << "[3] Прямоугольник.\n";
        std::cout << "[4] Треугольник.\n";
        std::cout << "[5] Решетка.\n\n";
        std::cout << "[+] Выберите фигуру: ";

        int localN = getNumber();

        if (localN == 1) {
            std::cout << "\n\n\n";

            line();
        }
        else if (localN == 2) {
            std::cout << "\n\n\n";

            square();
        }
        else if (localN == 3) {
            std::cout << "\n\n\n";

            rectangle();
        }
        else if (localN == 4) {
            std::cout << "\n\n\n";

            triangle();
        }
        else if (localN == 5) {
            std::cout << "\n\n\n";

            lattice();
        }
        else {
            std::cout << "Такого пункта нету.\n";
            std::exit(0);
        };
    }
    else if (n == 17) {
        std::cout << "[+] Программа - \"Геометрические фигуры\".\n\n";
        std::cout << "[1] Линия.\n";
        std::cout << "[2] Квадрат.\n";
        std::cout << "[3] Прямоугольник.\n";
        std::cout << "[4] Треугольник.\n";
        std::cout << "[5] Решетка.\n";
        std::cout << "[6] Крестик.\n\n";
        std::cout << "[+] Выберите фигуру: ";

        int localN = getNumber();

        if (localN == 1) {
            std::cout << "\n\n\n";

            line();
        }
        else if (localN == 2) {
            std::cout << "\n\n\n";

            square();
        }
        else if (localN == 3) {
            std::cout << "\n\n\n";

            rectangle();
        }
        else if (localN == 4) {
            std::cout << "\n\n\n";

            triangle();
        }
        else if (localN == 5) {
            std::cout << "\n\n\n";

            lattice();
        }
        else if (localN == 6) {
            std::cout << "\n\n\n";

            cross();
        }
        else {
            std::cout << "Такого пункта нету.\n";
            std::exit(0);
        };
    }
    else if (n == 18) {
        std::cout << "[+] Программа - \"Геометрические фигуры\".\n\n";
        std::cout << "[1] Линия.\n";
        std::cout << "[2] Квадрат.\n";
        std::cout << "[3] Прямоугольник.\n";
        std::cout << "[4] Треугольник.\n";
        std::cout << "[5] Решетка.\n";
        std::cout << "[6] Крестик.\n";
        std::cout << "[7] Плюс.\n\n";
        std::cout << "[+] Выберите фигуру: ";

        int localN = getNumber();

        if (localN == 1) {
            std::cout << "\n\n\n";

            line();
        }
        else if (localN == 2) {
            std::cout << "\n\n\n";

            square();
        }
        else if (localN == 3) {
            std::cout << "\n\n\n";

            rectangle();
        }
        else if (localN == 4) {
            std::cout << "\n\n\n";

            triangle();
        }
        else if (localN == 5) {
            std::cout << "\n\n\n";

            lattice();
        }
        else if (localN == 6) {
            std::cout << "\n\n\n";

            cross();
        }
        else if (localN == 7) {
            std::cout << "\n\n\n";

            plus();
        }
        else {
            std::cout << "Такого пункта нету.\n";
            std::exit(0);
        };
    }
    else if (n == 19) {
        std::cout << "[+] Программа - \"Геометрические фигуры\".\n\n";
        std::cout << "[1] Линия.\n";
        std::cout << "[2] Квадрат.\n";
        std::cout << "[3] Прямоугольник.\n";
        std::cout << "[4] Треугольник.\n";
        std::cout << "[5] Решетка.\n";
        std::cout << "[6] Крестик.\n";
        std::cout << "[7] Плюс.\n";
        std::cout << "[8] Ромб.\n\n";
        std::cout << "[+] Выберите фигуру: ";

        int localN = getNumber();

        if (localN == 1) {
            std::cout << "\n\n\n";

            line();
        }
        else if (localN == 2) {
            std::cout << "\n\n\n";

            square();
        }
        else if (localN == 3) {
            std::cout << "\n\n\n";

            rectangle();
        }
        else if (localN == 4) {
            std::cout << "\n\n\n";

            triangle();
        }
        else if (localN == 5) {
            std::cout << "\n\n\n";

            lattice();
        }
        else if (localN == 6) {
            std::cout << "\n\n\n";

            cross();
        }
        else if (localN == 7) {
            std::cout << "\n\n\n";

            plus();
        }
        else if (localN == 8) {
            std::cout << "\n\n\n";

            rhombus();
        }
        else {
            std::cout << "Такого пункта нету.\n";
            std::exit(0);
        };
    }
    else if (n == 20) {
        std::cout << "[+] Программа - \"Геометрические фигуры\".\n\n";
        std::cout << "[1] Линия.\n";
        std::cout << "[2] Квадрат.\n";
        std::cout << "[3] Прямоугольник.\n";
        std::cout << "[4] Треугольник.\n";
        std::cout << "[5] Решетка.\n";
        std::cout << "[6] Крестик.\n";
        std::cout << "[7] Плюс.\n";
        std::cout << "[8] Ромб.\n";
        std::cout << "[9] Змейка.\n\n";
        std::cout << "[+] Выберите фигуру: ";

        int localN = getNumber();

        if (localN == 1) {
            std::cout << "\n\n\n";

            line();
        }
        else if (localN == 2) {
            std::cout << "\n\n\n";

            square();
        }
        else if (localN == 3) {
            std::cout << "\n\n\n";

            rectangle();
        }
        else if (localN == 4) {
            std::cout << "\n\n\n";

            triangle();
        }
        else if (localN == 5) {
            std::cout << "\n\n\n";

            lattice();
        }
        else if (localN == 6) {
            std::cout << "\n\n\n";

            cross();
        }
        else if (localN == 7) {
            std::cout << "\n\n\n";

            plus();
        }
        else if (localN == 8) {
            std::cout << "\n\n\n";

            rhombus();
        }
        else if (localN == 9) {
            std::cout << "\n\n\n";

            snake();
        }
        else {
            std::cout << "Такого пункта нету.\n";
            std::exit(0);
        };
    }
    else if (n == 21) {
        std::cout << "[+] Программа - \"Геометрические фигуры\".\n\n";
        std::cout << "[1] Линия.\n";
        std::cout << "[2] Квадрат.\n";
        std::cout << "[3] Прямоугольник.\n";
        std::cout << "[4] Треугольник.\n";
        std::cout << "[5] Решетка.\n";
        std::cout << "[6] Крестик.\n";
        std::cout << "[7] Плюс.\n";
        std::cout << "[8] Ромб.\n";
        std::cout << "[9] Змейка.\n";
        std::cout << "[10] Рекурсивный квадрат.\n\n";
        std::cout << "[+] Выберите фигуру: ";

        int localN = getNumber();

        if (localN == 1) {
            std::cout << "\n\n\n";

            line();
        }
        else if (localN == 2) {
            std::cout << "\n\n\n";

            square();
        }
        else if (localN == 3) {
            std::cout << "\n\n\n";

            rectangle();
        }
        else if (localN == 4) {
            std::cout << "\n\n\n";

            triangle();
        }
        else if (localN == 5) {
            std::cout << "\n\n\n";

            lattice();
        }
        else if (localN == 6) {
            std::cout << "\n\n\n";

            cross();
        }
        else if (localN == 7) {
            std::cout << "\n\n\n";

            plus();
        }
        else if (localN == 8) {
            std::cout << "\n\n\n";

            rhombus();
        }
        else if (localN == 9) {
            std::cout << "\n\n\n";

            snake();
        }
        else if (localN == 10) {
            std::cout << "\n\n\n";

            recursiveSquare();
        }
        else {
            std::cout << "Такого пункта нету.\n";
            std::exit(0);
        };
    }
    else if (n == 201) {
        std::cout << "[+] Программа - \"Геометрические фигуры\".\n\n";
        std::cout << "[1] Линия.\n";
        std::cout << "[2] Квадрат.\n";
        std::cout << "[3] Прямоугольник.\n";
        std::cout << "[4] Треугольник.\n";
        std::cout << "[5] Решетка.\n";
        std::cout << "[6] Крестик.\n";
        std::cout << "[7] Плюс.\n";
        std::cout << "[8] Ромб.\n";
        std::cout << "[9] Змейка.\n";
        std::cout << "[10] Рекурсивный квадрат.\n";
        std::cout << "[11] Четверть квадрата.\n\n";
        std::cout << "[+] Выберите фигуру: ";

        int localN = getNumber();

        if (localN == 1) {
            std::cout << "\n\n\n";

            line();
        }
        else if (localN == 2) {
            std::cout << "\n\n\n";

            square();
        }
        else if (localN == 3) {
            std::cout << "\n\n\n";

            rectangle();
        }
        else if (localN == 4) {
            std::cout << "\n\n\n";

            triangle();
        }
        else if (localN == 5) {
            std::cout << "\n\n\n";

            lattice();
        }
        else if (localN == 6) {
            std::cout << "\n\n\n";

            cross();
        }
        else if (localN == 7) {
            std::cout << "\n\n\n";

            plus();
        }
        else if (localN == 8) {
            std::cout << "\n\n\n";

            rhombus();
        }
        else if (localN == 9) {
            std::cout << "\n\n\n";

            snake();
        }
        else if (localN == 10) {
            std::cout << "\n\n\n";

            recursiveSquare();
        }
        else if (localN == 11) {
            std::cout << "\n\n\n";

            quarterOfSquare();
        }
        else {
            std::cout << "Такого пункта нету.\n";
            std::exit(0);
        };
    }
    else if (n == 202) {
        std::cout << "[+] Программа - \"Геометрические фигуры\".\n\n";
        std::cout << "[1] Линия.\n";
        std::cout << "[2] Квадрат.\n";
        std::cout << "[3] Прямоугольник.\n";
        std::cout << "[4] Треугольник.\n";
        std::cout << "[5] Решетка.\n";
        std::cout << "[6] Крестик.\n";
        std::cout << "[7] Плюс.\n";
        std::cout << "[8] Ромб.\n";
        std::cout << "[9] Змейка.\n";
        std::cout << "[10] Рекурсивный квадрат.\n";
        std::cout << "[11] Четверть квадрата.\n";
        std::cout << "[12] Четыре четверти.\n\n";
        std::cout << "[+] Выберите фигуру: ";

        int localN = getNumber();

        if (localN == 1) {
            std::cout << "\n\n\n";

            line();
        }
        else if (localN == 2) {
            std::cout << "\n\n\n";

            square();
        }
        else if (localN == 3) {
            std::cout << "\n\n\n";

            rectangle();
        }
        else if (localN == 4) {
            std::cout << "\n\n\n";

            triangle();
        }
        else if (localN == 5) {
            std::cout << "\n\n\n";

            lattice();
        }
        else if (localN == 6) {
            std::cout << "\n\n\n";

            cross();
        }
        else if (localN == 7) {
            std::cout << "\n\n\n";

            plus();
        }
        else if (localN == 8) {
            std::cout << "\n\n\n";

            rhombus();
        }
        else if (localN == 9) {
            std::cout << "\n\n\n";

            snake();
        }
        else if (localN == 10) {
            std::cout << "\n\n\n";

            recursiveSquare();
        }
        else if (localN == 11) {
            std::cout << "\n\n\n";

            quarterOfSquare();
        }
        else if (localN == 12) {
            std::cout << "\n\n\n";

            fourQuarters();
        }
        else {
            std::cout << "Такого пункта нету.\n";
            std::exit(0);
        };
    }
    else if (n == 22) {
        int arrInt[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        short arrShort[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        long arrLong[10] = { 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1, 10.1 };
        float arrFloat[10] = { 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1, 10.1 };
        double arrDouble[10] = { 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1, 10.1 };
        char arrChar[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
        bool arrBool[10] = { true, true, true, true, true, true, true, true, true, true };
        std::string arrString[10] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10" };

        std::cout << "Массив INT: \n";
        for (int i = 0; i < 10; i++) {
            std::cout << "arrInt[" << i << "] Значение: " << arrInt[i] << "\n";
        };

        std::cout << "Массив Short: \n";
        for (int i = 0; i < 10; i++) {
            std::cout << "arrInt[" << i << "] Значение: " << arrInt[i] << "\n";
        };
        std::cout << "\n";

        std::cout << "Массив Long: \n";
        for (int i = 0; i < 10; i++) {
            std::cout << "arrInt[" << i << "] Значение: " << arrInt[i] << "\n";
        };
        std::cout << "\n";

        std::cout << "Массив Float: \n";
        for (int i = 0; i < 10; i++) {
            std::cout << "arrInt[" << i << "] Значение: " << arrInt[i] << "\n";
        };
        std::cout << "\n";

        std::cout << "Массив Double: \n";
        for (int i = 0; i < 10; i++) {
            std::cout << "arrInt[" << i << "] Значение: " << arrInt[i] << "\n";
        };
        std::cout << "\n";

        std::cout << "Массив Char: \n";
        for (int i = 0; i < 10; i++) {
            std::cout << "arrInt[" << i << "] Значение: " << arrInt[i] << "\n";
        };
        std::cout << "\n";

        std::cout << "Массив Bool: \n";
        for (int i = 0; i < 10; i++) {
            std::cout << "arrInt[" << i << "] Значение: " << arrInt[i] << "\n";
        };
        std::cout << "\n";

        std::cout << "Массив String: \n";
        for (int i = 0; i < 10; i++) {
            std::cout << "arrInt[" << i << "] Значение: " << arrInt[i] << "\n";
        };
        std::cout << "\n";
    }
    else if (n == 23) {
        std::cout << "Вводите числа, обязательно только одно или двузначные, если хотите закончить введите 0.\n";
        std::vector<int> numbers = pushIntNumbers();

        std::cout << "\n\n";

        // Проверка на что каждое число в векторе двузначное или однозначное
        for (int i : numbers) {
            std::cout << "\n\n" << i << "\n\n";
            if (!(i > -100 && i < 100)) {
                std::cout << "Вы ввели не одно или двузначное.  " << i << "  \n";
                std::exit(0);
            };
        }

        std::cout << "\n\n" << numbers.size() << "\n\n";

        // Все остальные строки
        for (int i = 0; i < numbers.size(); i++) {
            // Количество символов "-" между результатами вычисления
            int countSeparator = 0;

            // Количество пробелом в первом столбце
            short oneColumnForNumber = 5; // потому что leftSizeOneColumnForNumber по умолчанию равен 5
            // Слева в любом случае 5, а спрва зависит от длины строки
            short leftSizeOneColumnForNumber = 5;
            short rightSizeOneColumnForNumber;

            // Количество пробелом вo втором столбце
            short twoColumnForNumber = 0;
            short leftSizeTwoColumnForNumber;
            short rightSizeTwoColumnForNumber;


            // Количество пробелом в третем столбце
            short threeColumnForNumber = 0;
            short leftSizeThreeColumnForNumber = 7;
            short rightSizeThreeColumnForNumber;


            if (numbers[i] == 0) {
                std::cout << "Нельзя делить на 0.\n";
                std::exit(0);
            };

            if (numbers[i] > -10 && numbers[i] < 10) {
                // Число однозначное
                rightSizeOneColumnForNumber = 5;
                oneColumnForNumber += 5; // 5 это rightSizeOneColumnForNumber

                // Если число отрицаительное, то размер примера на 4 больше из за минусов и скобок
                if (std::to_string(numbers[i])[0] == '-') {
                    leftSizeTwoColumnForNumber = 9;
                    rightSizeTwoColumnForNumber = 8;

                    twoColumnForNumber += 9 + 8 + 6; // 9 это leftSizeTwoColumnForNumber, 8 это rightSizeTwoColumnForNumber, 6 это однозначные отрицательные числа со скобками, два таких числа

                    oneColumnForNumber += 2; // 2 это длина однозначного отрицательного числа

                    // Первое число это насколько символов сумма длины первого и второго столбцов будет больше чем количество пробелов, сохраненое в переменных left..., right..., второе это насколько символов длина третего столбцов будет больше чем количество пробелов в этом третем столбце
                    countSeparator += (6 + std::to_string(numbers[i] * numbers[i]).size()); // 6 это два раза (однозначеное число с минусов) и скобки вокруг второго раза, std::to_string(numbers[i] * numbers[i]).size() это максимальная длина числа которую можно быть получить и она будет получена в результате умножения, весь третий столбец таблицы постраиваеться под это значение максималтьной длины
                }
                else {
                    leftSizeTwoColumnForNumber = 11;
                    rightSizeTwoColumnForNumber = 10;

                    oneColumnForNumber += 1; // 1 это длина однозначного положительного числа

                    twoColumnForNumber += 11 + 10 + 2; // 11 это leftSizeTwoColumnForNumber, 10 это rightSizeTwoColumnForNumber, 2 это однозначные положительные числа, два таких числа

                    // Первое число это насколько символов сумма длины первого и второго столбцов будет больше чем количество пробелов, сохраненое в переменных left..., right..., второе это насколько символов длина третего столбцов будет больше чем количество пробелов в этом третем столбце
                    countSeparator += (2 + std::to_string(numbers[i] * numbers[i]).size()); // 2 это два однозначных числа, всего 2 потому что число положительно значит нету минусов, а значит и скобок, std::to_string(numbers[i] * numbers[i]).size() это максимальная длина числа которую можно быть получить и она будет получена в результате умножения, весь третий столбец таблицы постраиваеться под это значение максималтьной длины
                }

                rightSizeThreeColumnForNumber = 8;
                threeColumnForNumber += 8 + std::to_string(numbers[i] * numbers[i]).size(); // 8 это rightSizeThreeColumnForNumber, отальное это длина максимальной строки которая может получиться в третем столбце, тооесть умножения
            }
            else if (numbers[i] > -100 && numbers[i] < 100) {
                // Число двузначное
                rightSizeOneColumnForNumber = 4;
                oneColumnForNumber += 4;

                // Если число отрицаительное, то размер примера на 4 больше из за минусов и скобок
                if (std::to_string(numbers[i])[0] == '-') {
                    leftSizeTwoColumnForNumber = 8;
                    rightSizeTwoColumnForNumber = 7;

                    oneColumnForNumber += 3; // 3 это длина двузначного положительного числа

                    twoColumnForNumber += 8 + 7 + 8; // 8 это leftSizeTwoColumnForNumber, 7 это rightSizeTwoColumnForNumber, 8 это двузначные отрицательные числа со скобками, два таких числа

                    // Первое число это насколько символов сумма длины первого и второго столбцов будет больше чем количество пробелов, сохраненое в переменных left..., right..., второе это насколько символов длина третего столбцов будет больше чем количество пробелов в этом третем столбце
                    countSeparator += (8 + std::to_string(numbers[i] * numbers[i]).size()); // 8 это два раза (двузначеное число с минусов) и скобки вокруг второго раза, std::to_string(numbers[i] * numbers[i]).size() это максимальная длина числа которую можно быть получить и она будет получена в результате умножения, весь третий столбец таблицы постраиваеться под это значение максималтьной длины
                }
                else {
                    leftSizeTwoColumnForNumber = 10;
                    rightSizeTwoColumnForNumber = 9;

                    oneColumnForNumber += 2; // 2 это длина двузначного отрицательного числа

                    twoColumnForNumber += 10 + 9 + 4; // 10 это leftSizeTwoColumnForNumber, 9 это rightSizeTwoColumnForNumber, 4 это двузначные положительные числа, два таких числа

                    // Первое число это насколько символов сумма длины первого и второго столбцов будет больше чем количество пробелов, сохраненое в переменных left..., right..., второе это насколько символов длина третего столбцов будет больше чем количество пробелов в этом третем столбце
                    countSeparator += (4 + std::to_string(numbers[i] * numbers[i]).size()); // 4 это два двузначных числа, всего 4 потому что число положительно значит нету минусов, а значит и скобок, std::to_string(numbers[i] * numbers[i]).size() это максимальная длина числа которую можно быть получить и она будет получена в результате умножения, весь третий столбец таблицы постраиваеться под это значение максималтьной длины
                }

                rightSizeThreeColumnForNumber = 7;
                threeColumnForNumber += 7 + std::to_string(numbers[i] * numbers[i]).size(); // 8 это rightSizeThreeColumnForNumber, оcтальное это длина максимальной строки которая может получиться в третем столбце, тооесть умножения
            };

            // Количество пробелов в трех столбцах
            countSeparator += (leftSizeOneColumnForNumber + rightSizeOneColumnForNumber + leftSizeTwoColumnForNumber + rightSizeTwoColumnForNumber + leftSizeThreeColumnForNumber + rightSizeThreeColumnForNumber);

            // 4 это количество символов "|" в строке
            countSeparator += 4;

            // Переменная которая будет содержать "|   Число   |           Пример         |   Результат    |"
            std::string oneString = "";

            /* // Если количество символом в третем столбце для чисел больше чем количество пробелов нужное для третего столбца первой строки
             if (rightSizeThreeColumnForNumber + leftSizeThreeColumnForNumber + std::to_string(numbers[i]).size() > threeColumnForNumber - 9) {
                 threeColumnForNumber = rightSizeThreeColumnForNumber + leftSizeThreeColumnForNumber + std::to_string(numbers[i]).size();
             }; */


             // Если число четное остаивть значения по умолчанию, все красиво разделиться, в противном случае убавить в правого один
            short leftSizeOneColumnForString = (oneColumnForNumber - 5) / 2; // 5 это количество символов в строке "Число"
            short rightSizeOneColumnForString = (oneColumnForNumber - 5) / 2; // 5 это количество символов в строке "Число"
            short leftSizeTwoColumnForString = (twoColumnForNumber - 6) / 2; // 6 это количество символов в строке "Пример"
            short rightSizeTwoColumnForString = (twoColumnForNumber - 6) / 2; // 6 это количество символов в строке "Пример"
            short leftSizeThreeColumnForString = (threeColumnForNumber - 9) / 2; // 9 это количество символов в строке "Результат"
            short rightSizeThreeColumnForString = (threeColumnForNumber - 9) / 2; // 9 это количество символов в строке "Результат"

            if ((oneColumnForNumber - 5) % 2 != 0) { // 5 это количество символов в строке "Число"
                rightSizeOneColumnForString -= 1; // тут левый потому что в остальных строках, если в первых двух столбцах не четный размер, то у левого будет на 1 меньше чем у правого, а в третем столбце в при таком же условии у левого будет на 1 меньше
            };

            if ((twoColumnForNumber - 6) % 2 != 0) { // 6 это количество символов в строке "Пример"
                rightSizeTwoColumnForString -= 1; // тут левый потому что в остальных строках, если в первых двух столбцах не четный размер, то у левого будет на 1 меньше чем у правого, а в третем столбце в при таком же условии у левого будет на 1 меньше
            };

            if ((threeColumnForNumber - 9) % 2 != 0) { // 9 это количество символов в строке "Результат"
                leftSizeThreeColumnForString -= 1; // тут правый потому что в остальных строках, если в первых двух столбцах не четный размер, то у левого будет на 1 меньше чем у правого, а в третем столбце в при таком же условии у левого будет на 1 меньше
            };

            oneString.push_back('|');

            for (int _ = 0; _ < leftSizeOneColumnForString; _++) {
                oneString.push_back(' ');
            };

            oneString += "Число";

            for (int _ = 0; _ < rightSizeOneColumnForString; _++) {
                oneString.push_back(' ');
            };

            oneString.push_back('|');


            for (int _ = 0; _ < leftSizeTwoColumnForString; _++) {
                oneString.push_back(' ');
            };

            oneString += "Пример";


            for (int _ = 0; _ < rightSizeTwoColumnForString; _++) {
                oneString.push_back(' ');
            };

            oneString.push_back('|');

            for (int _ = 0; _ < leftSizeThreeColumnForString; _++) {
                oneString.push_back(' ');
            };

            oneString += "Результат";

            for (int _ = 0; _ < rightSizeThreeColumnForString; _++) {
                oneString.push_back(' ');
            };

            oneString.push_back('|');



            // Вычисления количества элементов в строке так, что бы все значения и первой и всех остальных строк поместились в строке
            if (oneString.size() > countSeparator) {
                countSeparator = oneString.size();
            };

            /*
            // Вычисления количества элементов в первом столбце так, что бы все значения и первой и всех остальных строк поместились в первом столбце
            if (oneColumnForNumber > leftSizeOneColumnForNumber + rightSizeOneColumnForNumber + std::to_string(numbers[i]).size()) {
                leftSizeOneColumnForNumber = oneColumnForNumber / 2;
                leftSizeOneColumnForString = oneColumnForNumber / 2;
                if (oneColumnForNumber % 2 == 0) {
                    // Количество символом которое нужно для отображения всего первого столбца четное, тогда все хорошо делиться и справа и слева от числа будут одинакое количество пробелов
                    rightSizeOneColumnForNumber = oneColumnForNumber / 2;
                }
                else {
                    // Количество символом которое нужно для отображения всего первого столбца нечетное, тогда количество пробелов справа будет на 1 меньше чем слева
                    rightSizeOneColumnForNumber = oneColumnForNumber / 2 - 1;
                };
            };

            // Вычисления количества элементов во втором столбце так, что бы все значения и первой и всех остальных строк поместились во втором столбце

            // Вычисления количества элементов в третем столбце так, что бы все значения и первой и всех остальных строк поместились в третем столбце

            */



            /*
            // Что бы было одинаковое количество пробелов слева от числа в первом столбце
            if (leftSizeOneColumnForString > leftSizeOneColumnForNumber) {
                leftSizeOneColumnForNumber = leftSizeOneColumnForString;
            }
            else {
                leftSizeOneColumnForString = leftSizeOneColumnForNumber;
            };


            // Что бы было одинаковое количество пробелов справа от числа в первом столбце
            if (rightSizeOneColumnForString > rightSizeOneColumnForNumber) {
                rightSizeOneColumnForNumber = rightSizeOneColumnForString;
            }
            else {
                rightSizeOneColumnForString = rightSizeOneColumnForNumber;
            };

            // Что бы было одинаковое количество пробелов слева от примера во втором столбце
            if (leftSizeTwoColumnForString > leftSizeTwoColumnForNumber) {
                leftSizeTwoColumnForNumber = leftSizeTwoColumnForString;
            }
            else {
                leftSizeTwoColumnForString = leftSizeTwoColumnForNumber;
            };

            // Что бы было одинаковое количество пробелов справа от примера во втором столбце
            if (rightSizeTwoColumnForString > rightSizeTwoColumnForNumber) {
                rightSizeTwoColumnForNumber = rightSizeTwoColumnForString;
            }
            else {
                rightSizeTwoColumnForString = rightSizeTwoColumnForNumber;
            };

            // Что бы было одинаковое количество пробелов слева от результата в третем столбце
            if (leftSizeThreeColumnForString > leftSizeThreeColumnForNumber) {
                leftSizeThreeColumnForNumber = leftSizeThreeColumnForString;
            }
            else {
                leftSizeThreeColumnForString = leftSizeThreeColumnForNumber;
            };

            // Что бы было одинаковое количество пробелов справа от результата в третем столбце
            if (rightSizeThreeColumnForString > rightSizeThreeColumnForNumber) {
                rightSizeThreeColumnForNumber = rightSizeThreeColumnForString;
            }
            else {
                rightSizeThreeColumnForString = rightSizeThreeColumnForNumber;
            };

            */



            // TEST
            std::cout << "\n\n\n" << "THISISIISIS22       " << threeColumnForNumber << "   " << std::string("Результат").size() << "\n";
            std::cout << oneColumnForNumber << "      " << twoColumnForNumber << "    " << threeColumnForNumber << "     " << countSeparator << "\n";
            std::cout << threeColumnForNumber << "    " << leftSizeThreeColumnForString << "   " << leftSizeThreeColumnForNumber << "        " << rightSizeThreeColumnForString << "   " << rightSizeThreeColumnForNumber << "\n\n\n";
            // << "  " << leftSizeTwoColumnForString << "   " << leftSizeThreeColumnForString << "    " << rightSizeThreeColumnForString



            std::cout << "Таблица " << i + 1 << "\n";

            // Первая строка каждой таблицы
            for (int _ = 0; _ < countSeparator; _++) {
                std::cout << "-";
            };
            std::cout << "\n";

            std::cout << oneString << "\n";


            // Таблица
            for (int j = 0; j < 4; j++) {
                // Разделитель 
                for (int _ = 0; _ < countSeparator; _++) {
                    std::cout << "-";
                };

                std::cout << "\n";

                std::cout << "|";

                for (int _ = 0; _ < leftSizeOneColumnForNumber; _++) {
                    std::cout << " ";
                };

                std::cout << numbers[i];

                for (int _ = 0; _ < rightSizeOneColumnForNumber; _++) {
                    std::cout << " ";
                };

                std::cout << "|";

                for (int _ = 0; _ < leftSizeTwoColumnForNumber; _++) {
                    std::cout << " ";
                };

                if (j == 0) {
                    if (std::to_string(numbers[i])[0] == '-') {
                        std::cout << numbers[i] << " + (" << numbers[i] << ")";
                    }
                    else {
                        std::cout << numbers[i] << " + " << numbers[i];
                    }
                }
                else if (j == 1) {
                    if (std::to_string(numbers[i])[0] == '-') {
                        std::cout << numbers[i] << " - (" << numbers[i] << ")";
                    }
                    else {
                        std::cout << numbers[i] << " - " << numbers[i];
                    }
                }
                else if (j == 2) {
                    if (std::to_string(numbers[i])[0] == '-') {
                        std::cout << numbers[i] << " / (" << numbers[i] << ")";
                    }
                    else {
                        std::cout << numbers[i] << " / " << numbers[i];
                    };
                }
                else {
                    if (std::to_string(numbers[i])[0] == '-') {
                        std::cout << numbers[i] << " * (" << numbers[i] << ")";
                    }
                    else {
                        std::cout << numbers[i] << " * " << numbers[i];
                    }
                };

                for (int _ = 0; _ < rightSizeTwoColumnForNumber; _++) {
                    std::cout << " ";
                };

                std::cout << "|";

                for (int _ = 0; _ < leftSizeThreeColumnForNumber; _++) {
                    std::cout << " ";
                };

                if (j == 0) {
                    std::cout << numbers[i] + numbers[i];
                }
                else if (j == 1) {
                    std::cout << numbers[i] - numbers[i];
                }
                else if (j == 2) {
                    std::cout << numbers[i] / numbers[i];
                }
                else {
                    std::cout << numbers[i] * numbers[i];
                };

                for (int _ = 0; _ < rightSizeThreeColumnForNumber; _++) {
                    std::cout << " ";
                };

                std::cout << "|\n";
            };

            for (int _ = 0; _ < countSeparator; _++) {
                std::cout << "-";
            };

            std::cout << "\n\n\n";
        };
    }
    else if (n == 24) {
        std::cout << "Тоже самое задание что и 33\n\n";
    }
    else if (n == 25) {
        std::cout << "[ + ] Программа - \"Лабиринт\".\n";
        std::cout << "[+] Размер карты : \n";
        std::cout << "[1] 15 x 15.\n";
        std::cout << "[2] 20 x 20.\n";
        std::cout << "[3] 30 x 30.\n";
        std::cout << "[+] Выберите размер : ";

        // Массив, содержащий инструкцию как выводить лабиринт
        std::vector<std::vector<bool>> output = {};

        int size = getNumber();
        if (size == 1) {
            output = {
                {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1}
            };
        }
        else if (size == 2) {
            output = {
                {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1},
                {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1}
            };
        }
        else if (size == 3) {
            output = {
                { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                { 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                { 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                { 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                { 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                { 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                { 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                { 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                { 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
                { 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1 },
                { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1 },
                { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
                { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
                { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1 },
                { 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
                { 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1 },
                { 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
                { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
                { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1 },
                { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1 },
                { 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
                { 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
                { 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1 },
                { 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1 },
                { 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1 },
                { 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
                { 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
                { 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1 },
                { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
                { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
            };
        }
        else {
            std::cout << "Неизвестный размер.\n";
            std::exit(0);
        };

        for (std::vector<bool> el1 : output) {
            for (bool el2 : el1) {
                if (el2) {
                    std::cout << "#";
                }
                else {
                    std::cout << ".";
                };

                if (el2 != output[0].size()) {
                    std::cout << " ";
                };
            };

            std::cout << "\n";
        }
    }
    else if (n == 33) {
        std::cout << "Введите число\n";
        std::cout << "[0] Закрыть программу\n";
        std::cout << "[1] Внести числа\n";

        // Числа 0 или 1 для закрытия программы и вноски чисел cоответственно
        std::string localNString;
        short localN;
        std::cin >> localNString;
        std::cout << "\n";
        try {
            localN = std::stoi(localNString);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.\n";
            return 0;
        }
        catch (const std::out_of_range& e) {
            std::cout << "Вы ввели слишком большое число.\n";
            return 0;
        };

        // Инициализация массва в котором будут числа который ввел пользователь
        std::vector<double> res = {};

        if (localN == 0) {
            std::cout << "\n\n\n";
            std::cout << "Вы закрыли программу\n";
        }
        else if (localN == 1) {
            std::cout << "\n\n\n";
            std::cout << "[#] Заполнение вектора\n\n";
            res = pushNumbers();

            // TEST
            std::cout << "TEST START\n\n";
            printVector(res);
            std::cout << "\n";
            std::cout << "TEST END\n\n";

            if (res.size() == 0) {
                std::cout << "Произошла ошибка или вы не ввели ни одного числа.";
                return 0;
            };

            std::cout << "[Меню вариантов сортировки]\n\n";
            std::cout << "[#] Настройки вектора: \n\n";
            std::cout << "[1] Сортировка по возрастанию\n";
            std::cout << "[2] Сортировка по убыванию\n";
            std::cout << "[3] Перемножить вектор\n";
            std::cout << "[4] Сложить вектор\n";
            std::cout << "[5] Разделить вектор\n";
            std::cout << "[6] Обнулить вектор\n\n";
            std::cout << "[0] Задать новые значения вектору\n\n";
            std::cout << "[+] Ввод: ";

            std::string localLocalNString;
            short localLocalN;
            std::cin >> localLocalNString;

            // Использовать это вместо \n, потому что std::endl очищает буфер ввода и если до этого ввода произойдет какая то ошибка, то std::cin вообще не выполниться, ошибок не будет и результата не будет
            std::cout << std::endl;
            try {
                localLocalN = std::stoi(localLocalNString);
            }
            catch (const std::invalid_argument& e) {
                std::cout << "Вы ввели не число.\n";
                return 0;
            }
            catch (const std::out_of_range& e) {
                std::cout << "Вы ввели слишком большое число.\n";
                return 0;
            };
            std::cout << localLocalNString << "\n\n";

            std::cout << "Результат: ";

            if (localLocalN == 1) {
                // Сортировка по возрастанию. Выводит значения вектора от самого маленького до самого большого значения;
                sortPlus(res);
            }
            else if (localLocalN == 2) {
                // Сортировка по убыванию. Выводит значения вектора от большого до самого маленького значения;
                sortMinus(res);
            }
            else if (localLocalN == 3) {
                // Перемножение вектора. Пользователь вводит любое целочисленное значение на которое будет умножаться каждая ячейка вектора;
                multiplicationOrAdditionOrDivisionVector(res, '*');
            }
            else if (localLocalN == 4) {
                // Сложение вектора. Пользователь вводит любое целочисленное значение, каждая ячейка вектора складывается с введенным числом;
                multiplicationOrAdditionOrDivisionVector(res, '+');
            }
            else if (localLocalN == 5) {
                // Деление вектора. Пользователь вводит любое целочисленное значение на которое будет делиться каждая ячейка вектора;
                multiplicationOrAdditionOrDivisionVector(res, '/');
            }
            else if (localLocalN == 6) {
                // Обнуление вектора. Все ячейки вектора принимают значение 0;
                resettingToZero(res);
            }
            else if (localLocalN == 0) {
                // Дает пользователю проинициализировать вектор заново.
                initializationAgain();
            }
            else {
                std::cout << "Неверный номер.";

                // return 0 необязательный потому что выполнение сразу выйдет из else этого блока и else родительского блока, и следующее что выполнититься это return 0
                return 0;
            };
        }
        else {
            std::cout << "Неизвестное число\n";

            // return 0 необязательный потому что выполнение сразу выйдет из else этого блока, и следующее что выполнититься это return 0
            return 0;
        };

    }
    else if (n == 1000) {
        srand(std::time(nullptr));

        std::cout << "Введите начало диапазона: ";
        int start = getNumber();
        std::cout << "\n";

        std::cout << "Введите конец диапазона: ";
        int end = getNumber();
        std::cout << "\n";

        // 1
        std::cout << "1):\n";
        std::cout << "RES:    " << rand() % 11 << "\n";
        std::cout << "\n\n";

        // 2
        std::cout << "2):\n";
        std::cout << "RES:    " << rand() % (end + 1);
        std::cout << "\n\n";

        // 3
        std::cout << "3):\n";
        std::cout << "RES:    " << (rand() % 6) + 5;
        std::cout << "\n\n";

        // 4
        std::cout << "4):\n";
        std::cout << "RES:    " << (rand() % 61) + 50;
        std::cout << "\n\n";

        // 5
        std::cout << "5):\n";
        std::cout << "RES:    " << (rand() % ((end + 1) - start)) + start;
        std::cout << "\n\n\n\n";
    }
    else if (n == 10000) {
        // Имена игроков по умолчанию
        std::string nameOnePlayer = "Игрок 1.";
        std::string nameTwoPlayer = "Игрок 2.";

        // Фигуры игроков по умолчанию
        char figureOnePlayer = 'X';
        char figureTwoPlayer = '0';
        char figureComputer = '*';

        // Количество побед первым игроком, вторым игроков и компьютером
        short countWinOnePLayer = 0;
        short countWinTwoPLayer = 0;
        short countWinComputer = 0;

        // Количество поражений первым игроком, вторым игроков и компьютером
        short countLoseOnePlayer = 0;
        short countLoseTwoPlayer = 0;
        short countLoseComputer = 0;

        // Количество ничей первым игроком, вторым игроков и компьютером
        short countDrawOnePlayer = 0;
        short countDrawTwoPlayer = 0;
        short countDrawComputer = 0;

        // Количество очков первым игроком, вторым игроков и компьютером
        float countGlassesOnePlayer = 0;
        float countGlassesTwoPlayer = 0;
        float countGlassesComputer = 0;

        // Количество пробелов между началом строки и началом раздела информация о текущей игре, в саомй игре
        // short countSubmolBetweenStartStringAndStartInformation = 18;

        // Количество пробелов между двумя столбцами в статистке
        short countSpaceBetweenTwoColumns = 15;

        while (true) {
            std::cout << "[0] Начать игру.\n";
            std::cout << "[1] Статистика.\n";
            std::cout << "[2] Настройки.\n";
            std::cout << "[3] Выйти.\n";

            std::cout << "Enter nomer: ";
            int nomer = getNumber();

            std::cout << "\n\n";

            if (nomer == 0) {
                // Начало игры

                while (true) {
                    // Выбор игрок будет играть с компьютером или с чековеком который находиться рядом с ним
                    std::cout << "[0] Одиночная игра(с компьютером).\n";
                    std::cout << "[1] Два игрока(с другом).\n";
                    std::cout << "[2] В главное меню.\n";
                    std::cout << "Введите номер пункта: ";
                    int nomerPola = getNumber();

                    std::cout << "\n\n";

                    // Вектор содержащий то что вводят игроки, по умолчанию просто числа что бы игроки понимали какую цифру вводить что бы поставить на нужное место свою фигуру
                    std::vector<char> table = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

                    // Переменная нужная что бы играли разные игроки, а не один
                    short i = 2;

                    // Вектор, содержащий то что ввели игроки
                    std::vector<int> inputs = {};

                    if (nomerPola == 0) {
                        // Игрок будет играть с компьютером

                        while (true) {
                            std::cout << table[0] << " | " << table[1] << " | " << table[2] << "\n";
                            std::cout << "- - - - -\n";
                            std::cout << table[3] << " | " << table[4] << " | " << table[5] << "\n";
                            std::cout << "- - - - -\n";
                            std::cout << table[6] << " | " << table[7] << " | " << table[8] << "\n\n";


                            // Проверка на что есть ли уже победитель
                            short whoWin = whoIsWin(table, figureOnePlayer, figureComputer);
                            std::cout << "\n\ndsadsad   " << whoWin << "\n\n";
                            if (whoWin == 1) {
                                // Выиграл первый игрок
                                std::cout << "Выиграл " << nameOnePlayer << "\n";

                                // Добавить очки первому игроку, убавить очки второму игроку, добавить первому игроку одну победу и добавить второму игроку одно поражение
                                countGlassesOnePlayer += 5;
                                countGlassesComputer -= 6;
                                countWinOnePLayer++;
                                countLoseComputer++;

                                // Вернуться к выбору сколько игроков будут играть
                                break;
                            }
                            else if (whoWin == 2) {
                                // Выиграл компьютер
                                std::cout << "Выиграл Компьютер\n";

                                // Добавить очки второму игроку, убавить очки первому игроку, добавить второму игроку одну победу и добавить первому игроку одно поражение
                                countGlassesComputer += 5;
                                countGlassesOnePlayer -= 6;
                                countWinComputer++;
                                countLoseOnePlayer++;

                                // Вернуться к выбору сколько игроков будут играть
                                break;
                            }
                            else if (whoWin == -1) {
                                // Больше никуда нельзя написать фигуры игрокам, значит ничья
                                std::cout << "Ничья.\n";
                                // Увелить первому и второму игрокам количество ничей на один, и уменьшить количество очков и первого и второго игроков на один
                                countDrawOnePlayer++;
                                countDrawComputer++;
                                countGlassesOnePlayer -= 1.2;
                                countGlassesComputer  -= 1.2;

                                // Вернуться к выбору сколько игроков будут играть
                                break;
                            }
                            else {
                                // Не выиграл никто
                                // Ничего не делать, потому что если никто не выиграл, то нужно продолжить вывод информации, и получение чисел пользователем
                            };


                            std::cout << "Информация:\n\n";
                            for (int j = 0; j < inputs.size(); j++) {
                                // Если ход четный то ходит первый игрок, а если нет - второй игрок
                                // Это аналог кода:
                                // if(j % 2 == 0) {
                                //   std::cout << nameOnePlayer << " ход на клетку " << inputs[j] << "\n";
                                // else {
                                //   std::cout << "Компьютер ход на клетку " << inputs[j] << "\n";
                                // };
                                // [&nameOnePlayer, &nameTwoPlayer, &j] обязательно потому что [] всегда обязательный для такого кода, и если написать просто [], то переменные nameOnePlayer, nameTwoPlayer и j не будут обьявлены и будет ошибка
                                std::cout << ([&nameOnePlayer, &j]() { if (j % 2 == 0) { return nameOnePlayer; } else { return std::string("Компьютер"); } }()) << " ход на клетку " << inputs[j] << "\n";
                            };

                            std::cout << "\n\n";


                            int move;
                            if (i % 2 == 0) {
                                std::cout << "Ходит " << nameOnePlayer << ": ";
                                move = getNumber();
                            }
                            else {
                                std::cout << "Ходит Компьютер.\n";
                                while (true) {
                                    int localMove = getRandomNumber(1, 9);
                                    if (!contains(inputs, localMove)) {
                                        // Полученого рандомного числа нету в массиве inputs, значит записать localMove в move и завершить бесконечный цикл
                                        move = localMove;
                                        break;
                                    };
                                };
                            };

                            std::cout << "\n";

                            if (move < 1 || move > 9 || contains(inputs, move)) {
                                std::cout << "Невалидное число.\n\n\n";
                                continue;
                            };

                            // Изменить клетке таблицы что бы игроки понимали куда ходить уже нельзя
                            table[move - 1] = (i % 2 == 0) ? (figureOnePlayer) : (figureComputer);

                            // Добавить ход в массив который используеться для вывода информации5
                            inputs.push_back(move);

                            i++;
                        }
                    }
                    else if (nomerPola == 1) {
                        // Игрок будет играть с другом

                        while (true) {
                            std::cout << table[0] << " | " << table[1] << " | " << table[2] << "\n";
                            std::cout << "- - - - -\n";
                            std::cout << table[3] << " | " << table[4] << " | " << table[5] << "\n";
                            std::cout << "- - - - -\n";
                            std::cout << table[6] << " | " << table[7] << " | " << table[8] << "\n\n";


                            // Проверка на что есть ли уже победитель
                            short whoWin = whoIsWin(table, figureOnePlayer, figureTwoPlayer);
                            std::cout << "\n\ndsadsad   " << whoWin << "\n\n";
                            if (whoWin == 1) {
                                // Выиграл первый игрок
                                std::cout << "Выиграл " << nameOnePlayer << "\n";

                                // Добавить очки первому игроку, убавить очки второму игроку, добавить первому игроку одну победу и добавить второму игроку одно поражение
                                countGlassesOnePlayer += 5;
                                countGlassesTwoPlayer -= 6;
                                countWinOnePLayer++;
                                countLoseTwoPlayer++;

                                // Вернуться к выбору сколько игроков будут играть
                                break;
                            }
                            else if (whoWin == 2) {
                                // Выиграл второй игрок
                                std::cout << "Выиграл " << nameTwoPlayer << "\n";

                                // Добавить очки второму игроку, убавить очки первому игроку, добавить второму игроку одну победу и добавить первому игроку одно поражение
                                countGlassesTwoPlayer += 5;
                                countGlassesOnePlayer -= 6;
                                countWinTwoPLayer++;
                                countLoseOnePlayer++;

                                // Вернуться к выбору сколько игроков будут играть
                                break;
                            }
                            else if (whoWin == -1) {
                                // Больше никуда нельзя написать фигуры игрокам, значит ничья
                                std::cout << "Ничья.\n";
                                // Увелить первому и второму игрокам количество ничей на один, и уменьшить количество очков и первого и второго игроков на один
                                countDrawOnePlayer++;
                                countDrawTwoPlayer++;
                                countGlassesOnePlayer -= 1.2;
                                countGlassesTwoPlayer -= 1.2;

                                // Вернуться к выбору сколько игроков будут играть
                                break;
                            }
                            else {
                                // Не выиграл никто
                                // Ничего не делать, потому что если никто не выиграл, то нужно продолжить вывод информации, и получение чисел пользователем
                            };


                            std::cout << "Информация:\n\n";
                            for (int j = 0; j < inputs.size(); j++) {
                                // Если ход четный то ходит первый игрок, а если нет - второй игрок
                                // Это аналог кода:
                                // if(j % 2 == 0) {
                                //   std::cout << nameOnePlayer << " ход на клетку " << inputs[j] << "\n";
                                // else {
                                //   std::cout << nameTwoPlayer << " ход на клетку " << inputs[j] << "\n";
                                // };
                                // [&nameOnePlayer, &nameTwoPlayer, &j] обязательно потому что [] всегда обязательный для такого кода, и если написать просто [], то переменные nameOnePlayer, nameTwoPlayer и j не будут обьявлены и будет ошибка
                                std::cout << ([&nameOnePlayer, &nameTwoPlayer, &j]() { if (j % 2 == 0) { return nameOnePlayer; } else { return nameTwoPlayer; } }()) << " ход на клетку " << inputs[j] << "\n";
                            };

                            std::cout << "\n\n";


                            std::cout << "Ходит " << ([&i, &nameOnePlayer, &nameTwoPlayer]() { if (i % 2 == 0) { return nameOnePlayer; } else { return nameTwoPlayer; }; }()) << ": ";
                            int move = getNumber();

                            if (move < 1 || move > 9 || contains(inputs, move)) {
                                std::cout << "Невалидное число.\n\n\n";
                                continue;
                            };

                            // Изменить клетке таблицы что бы игроки понимали куда ходить уже нельзя
                            table[move - 1] = (i % 2 == 0) ? (figureOnePlayer) : (figureTwoPlayer);

                            // Добавить ход в массив который используеться для вывода информации5
                            inputs.push_back(move);

                            i++;
                        }
                    }
                    else if (nomerPola == 2) {
                        // Выйти в главное меню
                        std::cout << "Вы вышли из режима игры.\n";
                        break;
                    }
                    else {
                        std::cout << "Неизвестный пункт.\n";
                        continue;
                    };


                    // Что бы отделить каждую итерацию
                    std::cout << "\n\n\n\n\n\n\n\n";
                };
            }
            else if (nomer == 1) {
                // Статистика игры


                /*
                int maxLengthName = 0;
                if (nameOnePlayer.size() > nameTwoPlayer.size()) {
                    // Имя первого игрок длинее второго
                    if (nameOnePlayer.size() > utf8_len("Компьютер")) {
                        // Имя первого игрока длинее имя компьютера
                        maxLengthName = nameOnePlayer.size();
                    }
                    else {
                        // Имя компьютера длинее имени первого игрока 
                        maxLengthName = utf8_len("Компьютер");
                    }
                }
                else {
                    // Имя второго игрока длинее имени первого игрока
                    if (nameTwoPlayer.size() > utf8_len("Компьютер")) {
                        // Имя второго игрока длинее имя компьютера
                        maxLengthName = nameTwoPlayer.size();
                    }
                    else {
                        // Имя компьютера длинее имени второго игрока 
                        maxLengthName = utf8_len("Компьютер");
                    }
                }

                // std::string computer = "КомпьютерABC";
                // int maxLengthName = utf8_len(computer);
                std::cout << "\n\n\n\nqwertyytrewq   " << nameOnePlayer.size() << "  " << nameTwoPlayer.size() << "  " << maxLengthName << "\n\n\n\n";


                // Создание первой строки
                std::string oneString = "";
                for (int i = 0; i < 4 + maxLengthName + countSpaceBetweenTwoColumns; i++) { // 4 это "1 | ", "2 | " и "3 | "
                    oneString += " ";
                };
                oneString += "W";
                for (int i = 0; i < countSpaceBetweenTwoColumns - 1; i++) { // -1 потому что один символ это "W"
                    oneString += " ";
                }
                oneString += "L";
                for (int i = 0; i < countSpaceBetweenTwoColumns - 1; i++) { // -1 потому что один символ это "L"
                    oneString += " ";
                }
                oneString += "D";
                for (int i = 0; i < (countSpaceBetweenTwoColumns - 1) / 2; i++) { // -1 потому что один символ это "D", нету проверки на то что (countWinComputer-1) это нечетное число, потому что countWinComputer всегда равно 15, а 15-1=14 и 14 четное число
                    oneString += " ";
                }
                oneString += "|";
                for (int i = 0; i < (countSpaceBetweenTwoColumns - 1) / 2 - 1; i++) { // -1 потому что один символ это "D", нету проверки на то что (countWinComputer-1) это нечетное число, потому что countWinComputer всегда равно 15, а 15-1=14 и 14 четное число, -1 вне скобок нужен потому что один символ это "|"
                    oneString += " ";
                }
                oneString += "Очки";

                // Создание второй строки
                std::string twoString = "";
                twoString += "1 | ";
                twoString += nameOnePlayer;
                for (int i = 0; i < countSpaceBetweenTwoColumns + (maxLengthName - nameOnePlayer.size()); i++) {
                    twoString += " ";
                };
                twoString += countWinOnePLayer;
                for (int i = 0; i < countSpaceBetweenTwoColumns - std::to_string(countWinOnePLayer).size(); i++) {
                    twoString += " ";
                };
                twoString += countLoseOnePlayer;
                for (int i = 0; i < countSpaceBetweenTwoColumns - std::to_string(countLoseOnePlayer).size(); i++) {
                    twoString += " ";
                };
                twoString += countDrawOnePlayer;
                if ((countSpaceBetweenTwoColumns - std::to_string(countDrawOnePlayer).size()) % 2 != 0) {
                    // Количество пробелов после вывода количеста матчей закончившихся ничья первого игрока до символа | не четное, значит до символа будет на один пробел меньше чем после
                    for (int i = 0; i < (countSpaceBetweenTwoColumns - std::to_string(countDrawOnePlayer).size()) / 2; i++) { // - std::to_string(countDrawOnePlayer).size() потому что число не должно добавляться к количесву пробелов меджу вдумя столбцами(переменная countSpaceBetweenTwoColumns со значением 15 всегда), +1 что бы число стало четным, нету проверки на то что (countWinComputer-1) это нечетное число, потому что countWinComputer всегда равно 15, а 15-1=14 и 14 четное число, -1 вне скобок нужен потому что один символ это "|"
                        oneString += " ";
                    };
                    twoString += "|";
                    for (int i = 0; i < (countSpaceBetweenTwoColumns - std::to_string(countDrawOnePlayer).size() + 1) / 2; i++) { // - std::to_string(countDrawOnePlayer).size() потому что число не должно добавляться к количесву пробелов меджу вдумя столбцами(переменная countSpaceBetweenTwoColumns со значением 15 всегда), нету проверки на то что (countWinComputer-1) это нечетное число, потому что countWinComputer всегда равно 15, а 15-1=14 и 14 четное число, -1 вне скобок нужен потому что один символ это "|"
                        oneString += " ";
                    };
                }
                else {
                    // Количество пробелов после вывода количеста матчей закончившихся ничья первого игрока до символа | четное, значит до символа и после будет одинаковое количество пробелов
                    for (int i = 0; i < (countSpaceBetweenTwoColumns - std::to_string(countDrawOnePlayer).size()) / 2; i++) { // -1 потому что один символ это "D", нету проверки на то что (countWinComputer-1) это нечетное число, потому что countWinComputer всегда равно 15, а 15-1=14 и 14 четное число, -1 вне скобок нужен потому что один символ это "|"
                        oneString += " ";
                    };
                    twoString += "|";
                    for (int i = 0; i < (countSpaceBetweenTwoColumns - std::to_string(countDrawOnePlayer).size()) / 2 - 1; i++) { // - std::to_string(countDrawOnePlayer).size() потому что число не должно добавляться к количесву пробелов меджу вдумя столбцами(переменная countSpaceBetweenTwoColumns со значением 15 всегда), нету проверки на то что (countWinComputer-1) это нечетное число, потому что countWinComputer всегда равно 15, а 15-1=14 и 14 четное число, -1 вне скобок нужен потому что один символ это "|"
                        oneString += " ";
                    };
                };
                twoString += countGlassesOnePlayer;


                // Создание третей строки
                std::string threeString = "";
                threeString += "2 | ";
                threeString += nameTwoPlayer;
                for (int i = 0; i < countSpaceBetweenTwoColumns + (maxLengthName - nameTwoPlayer.size()); i++) {
                    threeString += " ";
                };
                threeString += countWinTwoPLayer;
                for (int i = 0; i < countSpaceBetweenTwoColumns - std::to_string(countWinTwoPLayer).size(); i++) {
                    threeString += " ";
                };
                threeString += countLoseTwoPlayer;
                for (int i = 0; i < countSpaceBetweenTwoColumns - std::to_string(countLoseTwoPlayer).size(); i++) {
                    threeString += " ";
                };
                threeString += countDrawTwoPlayer;
                if ((countSpaceBetweenTwoColumns - std::to_string(countDrawTwoPlayer).size()) % 2 != 0) {
                    // Количество пробелов после вывода количеста матчей закончившихся ничья первого игрока до символа | не четное, значит до символа будет на один пробел меньше чем после
                    for (int i = 0; i < (countSpaceBetweenTwoColumns - std::to_string(countDrawTwoPlayer).size()) / 2; i++) { // - std::to_string(countDrawTwoPlayer).size() потому что число не должно добавляться к количесву пробелов меджу вдумя столбцами(переменная countSpaceBetweenTwoColumns со значением 15 всегда), +1 что бы число стало четным, нету проверки на то что (countWinComputer-1) это нечетное число, потому что countWinComputer всегда равно 15, а 15-1=14 и 14 четное число, -1 вне скобок нужен потому что один символ это "|"
                        threeString += " ";
                    };
                    threeString += "|";
                    for (int i = 0; i < (countSpaceBetweenTwoColumns - std::to_string(countDrawTwoPlayer).size() + 1) / 2; i++) { // - std::to_string(countDrawTwoPlayer).size() потому что число не должно добавляться к количесву пробелов меджу вдумя столбцами(переменная countSpaceBetweenTwoColumns со значением 15 всегда), нету проверки на то что (countWinComputer-1) это нечетное число, потому что countWinComputer всегда равно 15, а 15-1=14 и 14 четное число, -1 вне скобок нужен потому что один символ это "|"
                        threeString += " ";
                    };
                }
                else {
                    // Количество пробелов после вывода количеста матчей закончившихся ничья первого игрока до символа | четное, значит до символа и после будет одинаковое количество пробелов
                    for (int i = 0; i < (countSpaceBetweenTwoColumns - std::to_string(countDrawTwoPlayer).size()) / 2; i++) { // -1 потому что один символ это "D", нету проверки на то что (countWinComputer-1) это нечетное число, потому что countWinComputer всегда равно 15, а 15-1=14 и 14 четное число, -1 вне скобок нужен потому что один символ это "|"
                        oneString += " ";
                    };
                    threeString += "|";
                    for (int i = 0; i < (countSpaceBetweenTwoColumns - std::to_string(countDrawTwoPlayer).size()) / 2 - 1; i++) { // - std::to_string(countDrawTwoPlayer).size() потому что число не должно добавляться к количесву пробелов меджу вдумя столбцами(переменная countSpaceBetweenTwoColumns со значением 15 всегда), нету проверки на то что (countWinComputer-1) это нечетное число, потому что countWinComputer всегда равно 15, а 15-1=14 и 14 четное число, -1 вне скобок нужен потому что один символ это "|"
                        oneString += " ";
                    };
                };
                threeString += countGlassesTwoPlayer;

                // Создание четвертой строки
                std::string fourString = "";
                fourString += "3 | ";
                fourString += "Компьютер";
                for (int i = 0; i < countSpaceBetweenTwoColumns + (maxLengthName - std::string("Компьютер").size()); i++) {
                    fourString += " ";
                };
                fourString += countWinComputer;
                for (int i = 0; i < countSpaceBetweenTwoColumns - std::to_string(countWinComputer).size(); i++) {
                    fourString += " ";
                };
                fourString += countLoseComputer;
                for (int i = 0; i < countSpaceBetweenTwoColumns - std::to_string(countLoseComputer).size(); i++) {
                    fourString += " ";
                };
                fourString += countDrawComputer;
                if ((countSpaceBetweenTwoColumns - std::to_string(countDrawComputer).size()) % 2 != 0) {
                    // Количество пробелов после вывода количеста матчей закончившихся ничья первого игрока до символа | не четное, значит до символа будет на один пробел меньше чем после
                    for (int i = 0; i < (countSpaceBetweenTwoColumns - std::to_string(countDrawComputer).size()) / 2; i++) { // - std::to_string(countDrawTwoPlayer).size() потому что число не должно добавляться к количесву пробелов меджу вдумя столбцами(переменная countSpaceBetweenTwoColumns со значением 15 всегда), +1 что бы число стало четным, нету проверки на то что (countWinComputer-1) это нечетное число, потому что countWinComputer всегда равно 15, а 15-1=14 и 14 четное число, -1 вне скобок нужен потому что один символ это "|"
                        fourString += " ";
                    };
                    fourString += "|";
                    for (int i = 0; i < (countSpaceBetweenTwoColumns - std::to_string(countDrawComputer).size() + 1) / 2; i++) { // - std::to_string(countDrawTwoPlayer).size() потому что число не должно добавляться к количесву пробелов меджу вдумя столбцами(переменная countSpaceBetweenTwoColumns со значением 15 всегда), нету проверки на то что (countWinComputer-1) это нечетное число, потому что countWinComputer всегда равно 15, а 15-1=14 и 14 четное число, -1 вне скобок нужен потому что один символ это "|"
                        fourString += " ";
                    };
                }
                else {
                    // Количество пробелов после вывода количеста матчей закончившихся ничья первого игрока до символа | четное, значит до символа и после будет одинаковое количество пробелов
                    for (int i = 0; i < (countSpaceBetweenTwoColumns - std::to_string(countDrawComputer).size()) / 2; i++) { // -1 потому что один символ это "D", нету проверки на то что (countWinComputer-1) это нечетное число, потому что countWinComputer всегда равно 15, а 15-1=14 и 14 четное число, -1 вне скобок нужен потому что один символ это "|"
                        oneString += " ";
                    };
                    fourString += "|";
                    for (int i = 0; i < (countSpaceBetweenTwoColumns - std::to_string(countDrawComputer).size()) / 2 - 1; i++) { // - std::to_string(countDrawTwoPlayer).size() потому что число не должно добавляться к количесву пробелов меджу вдумя столбцами(переменная countSpaceBetweenTwoColumns со значением 15 всегда), нету проверки на то что (countWinComputer-1) это нечетное число, потому что countWinComputer всегда равно 15, а 15-1=14 и 14 четное число, -1 вне скобок нужен потому что один символ это "|"
                        oneString += " ";
                    };
                };
                fourString += countGlassesComputer;


                std::cout << oneString << "\n";
                std::cout << twoString << "\n";
                std::cout << threeString << "\n";
                std::cout << fourString << "\n\n";
                */

                std::cout << "            W      L    D    \n";
                std::cout << nameOnePlayer << "    " << countWinOnePLayer << "    " << countLoseOnePlayer << "    " << countDrawOnePlayer << "    " << countGlassesOnePlayer << "\n";
                std::cout << nameTwoPlayer << "    " << countWinTwoPLayer << "    " << countLoseTwoPlayer << "    " << countDrawTwoPlayer << "    " << countGlassesTwoPlayer << "\n";
                std::cout << "Компьютер" << "    " << countWinComputer << "    " << countLoseComputer << "    " << countDrawComputer << "    " << countGlassesComputer << "\n";
                std::cout << "0 | Назад в главное меню.\n";
                std::cout << "Введите какое нибудь число что бы вернуться в главное меню: ";

                int isZero = getNumber();
                if (isZero) {
                    std::cout << "Вы вышли из режима статистики.\n\n\n\n";
                    continue;
                };
            }
            else if (nomer == 2) {
                //  Настройки

                // Цикл что бы можно было возвращать к выбору игроку для его настройки
                while (true) {
                    std::cout << "[0] Игрок 1.\n";
                    std::cout << "[1] Игрок 2.\n";
                    std::cout << "[2] Вернуться в главноe меню.\n";

                    std::cout << "Введите номер игрока: ";
                    int nomerPlayer = getNumber();

                    std::cout << "\n\n\n";

                    if (nomerPlayer == 0) {
                        std::cout << "Настройки игрока 1.\n";

                        // Тут бесконечный цикл нужен что бы изменять значения и каждый раз не входить сюда из главного меню
                        while (true) {
                            std::cout << "[0] Ник: " << nameOnePlayer << "\n";
                            std::cout << "[1] Фигура: " << figureOnePlayer << "\n";
                            std::cout << "[2] Вернуться к выбору игрока для его последующей настройки.\n";
                            std::cout << "Введите номер поля для изменения: ";

                            int nomerPola = getNumber();

                            if (nomerPola == 0) {
                                // Изменения ника первого игрока
                                std::string newOneNamePlayer = "";
                                std::cout << "Введите новое имя первого игрока(БЕЗ ПРОБЕЛОВ): ";
                                std::cin >> newOneNamePlayer;
                                nameOnePlayer = newOneNamePlayer;
                                std::cout << "Имя первого игрока изменено на: " << newOneNamePlayer << "\n";
                            }
                            else if (nomerPola == 1) {
                                // Изменение фигуры первого игрока
                                char newFigureOnePlayer;
                                std::cout << "Введите новую фигуру которой будет играть первый игрок: ";
                                std::cin >> newFigureOnePlayer;
                                figureOnePlayer = newFigureOnePlayer;
                                std::cout << "Фигура первого игрока изменена на: " << newFigureOnePlayer << "\n";
                            }
                            else if (nomerPola == 2) {
                                // Выход из режима редактирования в главное меню
                                std::cout << "Вы вышли из режима настройки первого игрока.\n";
                                break;
                            };

                            // Что бы визуально отделить итерации самого внутреннего цикла while
                            std::cout << "\n\n";
                        }
                    }
                    else if (nomerPlayer == 1) {
                        std::cout << "Настройки игрока 2.\n";

                        // Тут бесконечный цикл нужен что бы изменять значения и каждый раз не входить сюда из главного меню
                        while (true) {
                            std::cout << "[0] Ник: " << nameTwoPlayer << "\n";
                            std::cout << "[1] Фигура: " << figureTwoPlayer << "\n";
                            std::cout << "[2] Вернуться к выбору игрока для его последующей настройки.\n";
                            std::cout << "Введите номер поля для изменения: ";

                            int nomerPola = getNumber();

                            if (nomerPola == 0) {
                                // Изменения ника вторного игрока
                                std::string newTwoNamePlayer = "";
                                std::cout << "Введите новое имя вторного игрока(БЕЗ ПРОБЕЛОВ): ";
                                std::cin >> newTwoNamePlayer;
                                nameTwoPlayer = newTwoNamePlayer;
                                std::cout << "Имя вторного игрока изменено на: " << newTwoNamePlayer << "\n";
                            }
                            else if (nomerPola == 1) {
                                // Изменение фигуры м игрока
                                char newFigureTwoPlayer;
                                std::cout << "Введите новую фигуру которой будет играть первый игрок: ";
                                std::cin >> newFigureTwoPlayer;
                                figureTwoPlayer = newFigureTwoPlayer;
                                std::cout << "Фигура вторного игрока изменена на: " << newFigureTwoPlayer << "\n";
                            }
                            else if (nomerPola == 2) {
                                // Выход из режима редактирования в главное меню
                                std::cout << "Вы вышли из режима настройки вторного игрока.\n";
                                break;
                            };

                            // Что бы визуально отделить итерации самого внутреннего цикла while
                            std::cout << "\n\n";
                        }
                    }
                    else if (nomerPlayer == 2) {
                        std::cout << "Вы вышли из режима настройки игроков.\n";
                        break;
                    }
                    else {
                        std::cout << "Неизветный номер игрока.\n";
                        continue;
                    };

                    // Что бы визуально отделить итерации среднего цикла while
                    std::cout << "\n\n\n\n";
                }
            }
            else if (nomer == 3) {
                std::cout << "EXIT.\n";
                break;
            }
            else {
                std::cout << "Неизвестный номер.\n";
                continue;
            };

            // Что бы визуально отделить итерации внешнего цикла while
            std::cout << "\n\n\n\n\n\n";
        }
    }
    else if (n == 38) {






#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <format>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <clocale>

#include <stdlib.h>
#include <ctime>

        int main() {
            std::vector<int> array = { 4, 2, 3, 1, 8, 0, 5, 5 };
            std::vector<int> currentArray = {};

            // Переменная нужна что бы считать когда нужно закончить вечный цикл
            int i = 0;

            // Переменная нужна что бы было не n/2 итераций, а n, потому что в ходе работы удаляються элементы и array.size() уменьшаеться, а эта переменная помогает этого избежать
            int lengthArray = array.size();

            // Бесконечный цикл
            while (true) {
                int minNumber = array[0];
                int indexMinNumber = 0;

                // Найти минимальный элемент в векторе
                // Пройтись по вектору, столько раз, сколько чисел в векторе
                for (int j = 0; j < array.size(); j++) {
                    if (array[j] < minNumber) {
                        minNumber = array[j];
                        indexMinNumber = j;
                    }
                };

                // Добавить минимальный элемент в отсортированный вектор
                currentArray.push_back(minNumber);

                // Удалить текущий минимальный элемент, что бы не образовать бесконечный цикл путем брания этого числа всегда
                array.erase(array.begin() + indexMinNumber);

                // Увелить переменную i на 1
                i++;

                // Проверить равна ли вспомогательная переменная длине оргинального вектора
                if (i == lengthArray) {
                    break;
                }
            };

            for (int i = 0; i < currentArray.size(); i++) {
                std::cout << currentArray[i] << " ";
            };
        }





        // Получение пользовательских данных насчет размера массива
        std::cout << "Введите длину строки: ";
        int length = getNumber();
        std::cout << "Введите количество строк: ";
        int height = getNumber();
        std::cout << "\n";


        // Инициалиизация массива рандомных значениями в диапазоне [1, 49]
        std::vector<std::vector<int>> array = {};
        for (int i = 0; i < height; i++) {
            array.push_back({});
            for (int j = 0; j < length; j++) {
                array[i].push_back(getRandomNumber(1, 49));
            };
        };


        // Вывод несортированного массива в консоль
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < length; j++) {
                std::cout << array[i][j];
                if (j != length - 1) {
                    std::cout << " ";
                };
            };
            std::cout << "\n";
        };


        // Получении информации о том как пользовател хочет отсортировать массив, по возрастанию или по убыванию
        std::cout << "Выберите как хотит отсортировать массив.\n";
        std::cout << "[0] По убыванию.\n";
        std::cout << "[1] По возрастанию.\n";
        std::cout << "Пункт: ";
        int p = getNumber();
        
        // Отсортированный массив
        std::vector<std::vector<int>> currentArray = {};

        // Сортировка массива взависимости от того как пользователь выбрал его сортировать
        if (p == 0) {
            // Сортировка по убыванию

            std::vector<int> localCurrentArray = {};

            // Цикл пройдеться по массиву столько раз, сколько строк было введенно пользователем
            for (int i = 0; i < array.size();i++) {
                std::vector<int> arr = {};

                // Цикл пройдеться по массиву столько раз, сколько столбцов в каждой строке
                for (int j = 0; j < arr.size(); j++) {
                    // Найти первое минимальное число массива и его индекс
                    int minNumber = arr[0];
                    int indexMinNumber = 0;
                    for (int j = 0; j < arr.size(); j++) {
                        int localN = arr[j];

                        if (localN < minNumber) {
                            minNumber = localN;
                            indexMinNumber = i;
                        };
                    };

                    std::cout << "\n\n" << minNumber << "  " << indexMinNumber << "\n\n";


                    // Добавить первое минимальное число массива в локальный отсортированный массив
                    localCurrentArray.push_back(minNumber);

                    // Удалить первое минимальное число массива из оригинального массива
                    currentArray[i].erase(currentArray[i].begin() + indexMinNumber);
                };

                currentArray.push_back(localCurrentArray);
            };

        }
        else if (p == 1) {
            // Сортировка по возрастанию
        }
        else {
            // Неизвестный пунтк
            std::cout << "Вы ввели некорректный пункт.\n";
            std::exit(0);
        };


        // Вывод отсортированного массива
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < length; j++) {
                std::cout << currentArray[i][j];
                if (j != length - 1) {
                    std::cout << " ";
                };
            };
            std::cout << "\n";
        }
    }
    else {
        std::cout << "Неизвестный номер задания.\n";
    };

    return 0;
};
