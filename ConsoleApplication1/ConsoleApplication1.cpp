#include <iostream>
#include <cstdlib>  // для rand() и srand()
#include <ctime>    // для time()
#include <locale>   // для настройки локали

int main() {
    // Настройка русской локали (для корректного вывода кириллицы)
#ifdef _WIN32
    setlocale(LC_ALL, "Russian");
#else
    setlocale(LC_ALL, "ru_RU.UTF-8");
#endif

    // Инициализация генератора случайных чисел
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Загадываем число от 1 до 100
    int secretNumber = std::rand() % 100 + 1;
    int guess = 0;
    int attempts = 0;

    std::cout << "Добро пожаловать в игру «Угадай число»!\n";
    std::cout << "Я загадал число от 1 до 100. Попробуйте угадать!\n";

    // Основной игровой цикл
    while (guess != secretNumber) {
        std::cout << "Ваш вариант: ";
        std::cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            std::cout << "Слишком мало! Попробуйте больше.\n";
        }
        else if (guess > secretNumber) {
            std::cout << "Слишком много! Попробуйте меньше.\n";
        }
        else {
            std::cout << "Поздравляем! Вы угадали число " << secretNumber
                << " за " << attempts << " попыток!\n";
        }
    }

    return 0;
}
