#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <format>

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
        } catch(const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.\n";
            return {};
        } catch(const std::out_of_range& e) {
            std::cout << "Вы ввели слишком большое число.\n";
            return {};
        };

        if(localLocalN == 0) {
            break;
        } else {
            localRes.push_back(localLocalN);
            i++;
        };
    };

    return localRes;
};

// Вывод каждого элемента вектора разделяя его табуляцией
void printVector(std::vector<double> res) {
    for(short i=0; i<res.size(); i++) {
        std::cout << res[i];

        // Проверка на то что это любая другая итерация цикла кроме последней и добавление табуляции если это так
        if(i != res.size()) {
            std::cout << "\t";
        };
    };
};

// Сортировка вектора по возростанию
void sortPlus(std::vector<double> output) {
    // Отсортированный массив
    std::vector<double> result = {};

    // N итерацияи для вектора длинной n значений
    for(short _ = 0; _ < output.size(); _++) {
        // Взять первое значений значением по умолчанию и дальше проверять его на то самое ли большое это значение в массиве от _ до конца массива, в случае это есть число больше перезаписывать min и индекс этого первого элемента, это нужно что бы если первое число это и есть минимальное число что бы можно было его удалить и добавить в вектор вывода
        double min = output[0];
        int minIndex = 0;
        
        // Нельзя использовать output.size() в for
        int lengthVector = output.size();

        // Для прохода по вектору и нахождения минимального числа для текущего вектора
        for(short i = 0; i < output.size(); i++) {
            // Если число с текущий индексом i вектора output меньше чем минимальное число(min), то записать в min это число
            if(output[i] < min) {
                min = output[i];
                minIndex = i;
            };
            
            std::cout << "START\n";
            std::cout << *(output.begin() + i) << "\n";
            printVector(output);
            std::cout << "\n";
            printVector(result);
            
            std::cout << "\n00000  " << _ << "   "  << output[i] << "   " << min << "   00000\n";
            std::cout << "END\n\n\n\n";
        };

        output.erase(output.begin() + minIndex);
        result.push_back(min);
    };

    printVector(result);
};

// Сортировка вектора по убыванию
std::vector<double> sortMinus(std::vector<double> output) {};

// Умножение каждого элемента вектора на некоторое число
std::vector<double> multiplicationVector(std::vector<double> output) {};

// Добавление некоторого числа к каждому элементу вектора
std::vector<double> additionVector(std::vector<double> output) {};


// Деление каждого элемента вектора на некоторое число
std::vector<double> divisionVector(std::vector<double> output) {};

// Все ячейки вектора принимают значение 0
std::vector<double> resettingToZero(std::vector<double> output) {};

// Инициализация вектора по новой
std::vector<double> initializationAgain() {};


int main() {
    
    std::cout << "\n\n\n";

	std::vector<double> a = {123, 781253, 18275, -1247, 832.4, -3284.4};
	sortPlus(a);



    std::cout << "\t\n\n\n\n\n";

    
    std::cout << "Выберите номер задания: ";
    std::string nString{};
    short n{};
    std::cin >> nString;
    try {
        n = std::stoi(nString);
    } catch(const std::invalid_argument& e) {
        std::cout << "Вы ввели не число";
        return 0;
    } catch(const std::out_of_range& e) {
        std::cout << "Вы ввели слишком большое число.";
        return 0;
    };
    std::cout << "\n";

    if(n == 1) {
        for(short i=0;i<5;i++) {
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
    } else if(n == 2) {
        // Массив времен года
        std::vector<std::string> a = { "Лето", "Осень", "Зима", "Весна" };

        std::cout << "Введите номер года(Лето, Осень, Зима, Весна): ";
        std::string localNString{};
        short localN{};
        std::cin >> localNString;
        try {
            localN = std::stoi(localNString);
        } catch(const std::invalid_argument& e) {
            std::cout << "Вы ввели не число";
            return 0;
        } catch(const std::out_of_range& e) {
            std::cout << "Вы ввели слишком большое число.";
            return 0;
        };

        if(localN >= 0 && localN < a.size()) {
            std::cout << "Cейчас: " << a[localN-1];
        } else {
            std::cout << "Вы ввели неизвестное число";
        };
    } else if(n == 3) {
        std::cout << "Введите число: ";
        std::string localNString;
        short localN;
        std::cin >> localNString;
        std::cout << "\n";
        try {
            localN = std::stoi(localNString);
        } catch(const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.\n";
            return 0;
        } catch(const std::out_of_range& e) {
            std::cout << "Вы ввели слишком большое число.\n";
            return 0;
        };

        std::cout << "\n\n\n" << localN << "     " << localNString << "\n\n\n";

        if(localN < 0) {
            std::cout << "Число меньше 0.\n";
            return 0;
        } else if(localN > 100) {
            std::cout << "Число больше 100.\n";
            return 0;
        };

        // Массив диапазонов
        std::vector<std::string> a = {"0-10", "11-20", "21-30", "31-40", "41-50", "51-60", "61-70", "71-80", "81-90", "91-100"};

        // Из 19 преобразует сначала в 1.9, а потом в 1 для индексации массива
        float b = std::trunc(localN / 10);
        if(std::trunc(b) == 10) {
            std::cout << "Диапазон: " << a[9] << "\n";
        } else {
            short c = std::trunc(b);
            std::cout << "Диапазон: " << a[c] << "\n";
        }
    } else if(n == 4) {
        std::cout << "Введите число: ";
        std::string localNString;
        short localN;
        std::cin >> localNString;
        std::cout << "\n";
        try {
            localN = std::stoi(localNString);
        } catch(const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.\n";
            return 0;
        } catch(const std::out_of_range& e) {
            std::cout << "Вы ввели слишком большое число.\n";
            return 0;
        };

        short i=1;
        short count = 0;
        while(i <= localN) {
            std::cout << "Пример: " << localN << "*" << i << "\n";
            std::cout << "Дайте ответ на пример вышe: ";
            std::cout << "Введите число: ";
            std::string localNString2;
            short localN2;
            std::cin >> localNString2;
            std::cout << "\n";
            try {
                localN2 = std::stoi(localNString2);
            } catch(const std::invalid_argument& e) {
                std::cout << "Вы ввели не число.\n";
                return 0;
            } catch(const std::out_of_range& e) {
                std::cout << "Вы ввели слишком большое число.\n";
                return 0;
            };

            if(localN2 == localN * i) {
                std::cout << "Верно\n";
                count++;
            } else {
                std::cout << "Неверно\n";
                std::cout << "Количество верных примеров: " << count;
                break;
            }
            i++;
        };
    } else if(n == 5) {
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
        for(short i = 0; i < opes.size(); i++) {
            if(opes[i] == ope) {
                isIn = true;
                break;
            };
        };

        std::cout << "\n\n\n" << isIn << "    " << ope << "\n\n\n";

        if(isIn == false) {
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
        } catch(const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.\n";
            return 0;
        } catch(const std::out_of_range& e) {
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
        } catch(const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.\n";
            return 0;
        } catch(const std::out_of_range& e) {
            std::cout << "Вы ввели слишком большое число.\n";
            return 0;
        };

        if(ope == "+") {
            std::cout << localN1 << " + " << localN2 << " = " << localN1 + localN2 << "\n";
        } else if(ope == "-") {
            std::cout << localN1 << " - " << localN2 << " = " << localN1 - localN2 << "\n";
        }  else if(ope == "*") {
            std::cout << localN1 << " * " << localN2 << " = " << localN1 * localN2 << "\n";
        }  else if(ope == "/") {
            std::cout << localN1 << " / " << localN2 << " = " << localN1 / localN2 << "\n";
        }  else {
            // Так как было проверкас isIn в начале не нужно еще раз проверять на %, если это не +, не -, не * и не / значит это %
            std::cout << localN1 << " % " << localN2 << " = " << localN1 % localN2 << "\n";
        };
    } else if(n == 33) {
        std::cout << "Введите число\n";
        std::cout << "[0] Закрыть программу\n";
        std::cout << "[1] Внести числа\n";

        // Числа 0 или 1 для закрытия программы и вноски чисел коответственно
        std::string localNString;
        short localN;
        std::cin >> localNString;
        std::cout << "\n";
        try {
            localN = std::stoi(localNString);
        } catch(const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.\n";
            return 0;
        } catch(const std::out_of_range& e) {
            std::cout << "Вы ввели слишком большое число.\n";
            return 0;
        };

        // Инициализация массва в котором будут числа который ввел пользователь
        std::vector<double> res = {};

        if(localN == 0) {
            system("clear");
            std::cout << "Вы закрыли программу\n";
        } else if(localN == 1) {
            system("clear");
            std::cout << "[#] Заполнение вектора\n\n";
            short i = 0;
            res = pushNumbers();

            // TEST
            printVector(res);
            
            if(res.size() == 0) {
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
            std::cout << "\n";
            try {
                localLocalN = std::stoi(localLocalNString);
            } catch(const std::invalid_argument& e) {
                std::cout << "Вы ввели не число.\n";
                return 0;
            } catch(const std::out_of_range& e) {
                std::cout << "Вы ввели слишком большое число.\n";
                return 0;
            };

            std::cout << "Результат:\n";

            if(localLocalN == 1) {
                // Сортировка по возрастанию. Выводит значения вектора от самого маленького до самого большого значения;
                sortPlus(res);
            } else if(localLocalN == 2) {
                // Сортировка по убыванию. Выводит значения вектора от большого до самого маленького значения;
                sortMinus(res);
            } else if(localLocalN == 3) {
                // Перемножение вектора. Пользователь вводит любое целочисленное значение на которое будет умножаться каждая ячейка вектора;
                multiplicationVector(res);
            } else if(localLocalN == 4) {
                // Сложение вектора. Пользователь вводит любое целочисленное значение, каждая ячейка вектора складывается с введенным числом;
                additionVector(res);
            } else if(localLocalN == 5) {
                // Деление вектора. Пользователь вводит любое целочисленное значение на которое будет делиться каждая ячейка вектора;
                divisionVector(res);
            } else if(localLocalN == 6) {
                // Обнуление вектора. Все ячейки вектора принимают значение 0;
                resettingToZero(res);
            } else if(localLocalN == 0) {
                // Дает пользователю проинициализировать вектор заново.
                initializationAgain();
            }
        } else {
            std::cout << "Неизвестное число\n";
            return 0;
        };

    } else {
        std::vector<double> a = {123, 781253, 18275, -1247, 832.4, -3284.4};
        sortPlus(a);
    };

    return 0;
}
