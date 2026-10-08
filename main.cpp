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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер ввода
    };

    return number;
}

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
            for (int i = 0; i < size; i++) {
                std::cout << submol;
                if (i + 1 != size) {
                    std::cout << " ";
                };
            };
        }
        else {
            for (int i = 1; i <= size; i++) {
                if (i % 2 == 0) {
                    std::cout << ".";
                }
                else {
                    std::cout << submol;
                };

                if (i + 1 != size) {
                    std::cout << " ";
                };
            };
        };

        std::cout << "\n";
    };
};


int main() {
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
        } else {
            std::cout << "Такого пункта нету.\n";
            std::exit(0);
        };
    } else if (n == 33) {
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

    };

    return 0;
}
