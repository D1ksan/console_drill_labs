#include <iostream>
#include <windows.h>  // Sleep()
#include <ctime>  // для инициализации генератора случайных чисел, 
#include <cstdlib>  //для генерации случайных чисел и их модуля, std::rand и std::abs

using namespace std;

// класс для представленя двумерной точки, расчитыват расстояние до другой точки
class Point2D {
public:
    int x;
    int y;
    Point2D(int x = 0, int y = 0) : x(x), y(y) {}
    void move(int dx, int dy) {  // Метод для перемещения точки на указанные значения по осям
        x += dx;
        y += dy;
    }
    int distanceTo(const Point2D& other) const {  // Метод для вычисления расстояния между точками
        return static_cast<int>(sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y)));
    }
};


// Базовый класс для персонажей
class Character {
public:
    Point2D position;

    Character(int x = 0, int y = 0) : position(x, y) {}

    void setPosition(int x, int y) {  // Установка позиции персонажа
        position.x = x;
        position.y = y;
    }

    Point2D getPosition() const {  // Получение текущей позиции персонажа
        return position;
    }

    virtual void move(int dx, int dy) {  // Виртуальный метод для перемещения персонажа
        position.move(dx, dy);
    }
};

// Класс для жертвы, наследующийся от базового класса Character
class Prey : public Character {
public:
    Prey(int x = 0, int y = 0) : Character(x, y) {}

    void autoMove(int width, int height) {  // Автоматическое движение жертвы
        int random = rand() % 4;  // Генерация случайного числа от 0 до 3
        switch (random) {
        case 0: move(0, 1); break;
        case 1: move(0, -1); break;
        case 2: move(1, 0); break;
        case 3: move(-1, 0); break;
        }

        // Проверка и коррекция позиции, чтобы не выйти за границы
        if (position.x < 0)
            position.x = 0;
        else if (position.x >= width)
            position.x = width - 1;

        if (position.y < 0)
            position.y = 0;
        else if (position.y >= height)
            position.y = height - 1;
    }
};

// Класс для хищника, наследующийся от базового класса Character
class Predator : public Character {
public:
    Predator(int x = 0, int y = 0) : Character(x, y) {}

    void moveTowardPrey(const Point2D& preyPos) {  // Движение к жертве
        int step = 1;
        if (abs(preyPos.x - position.x) > abs(preyPos.y - position.y)) {
            if (preyPos.x < position.x)
                position.x -= step;
            else
                position.x += step;
        }
        else {
            if (preyPos.y < position.y)
                position.y -= step;
            else
                position.y += step;
        }
    }
};

// Класс для арены
class Arena {
public:
    const int width;
    const int height;
    const int movesLimit;
    Prey prey;
    Predator predator;

    Arena(int width, int height, int movesLimit)
        : width(width), height(height), movesLimit(movesLimit), prey(), predator() {
        srand(time(NULL));
        prey.setPosition(rand() % width, rand() % height);

        int max_distance = static_cast<int>(sqrt(width * width + height * height)) / 2;
        int distance = rand() % max_distance + 1;

        do {
            predator.setPosition(rand() % width, rand() % height);
        } while (prey.getPosition().distanceTo(predator.getPosition()) < distance);
    }

    void display() const {  // Отображение состояния арены
        system("cls");
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (x == predator.getPosition().x && y == predator.getPosition().y)
                    cout << "H ";
                else if (x == prey.getPosition().x && y == prey.getPosition().y)
                    cout << "P ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
        cout << "Prey - P    Predator - H" << endl;
    }

    bool checkCollision() const {  // Проверка столкновения жертвы и хищника
        return prey.getPosition().x == predator.getPosition().x && prey.getPosition().y == predator.getPosition().y;
    }
};

int main() {
    // Инициализация игры
    setlocale(LC_ALL, "Russian");

    int width, height, movesLimit;

    // Ввод параметров арены
    cout << "Введите ширину поля: ";
    cin >> width;
    cout << "Введите высоту поля: ";
    cin >> height;
    cout << "Максимальное количество ходов: ";
    cin >> movesLimit;

    // Проверка на корректность параметров
    if (width <= 0 || height <= 0 || movesLimit <= 0) {
        cout << "Неверные параметры. Завершение работы программы." << endl;
        return 1;
    }

    // Создание арены
    Arena arena(width, height, movesLimit);
    bool validUserInput;
    char ch;

    do {
        validUserInput = true;
        cout << "Выберите героя:" << endl;
        cout << "1. Хищник" << endl;
        cout << "2. Жертва" << endl;
        cin >> ch;

        if (ch == '1') {
            // Логика для хищника
            cout << "Хищник" << endl;
            srand(time(nullptr));
            int limit = movesLimit;

            while (limit > 0) {
                arena.display();
                int step;
                cout << "Сколько шагов (1, 2, 3): ";
                cin >> step;
                if (step != 1 && step != 2 && step != 3) {
                    step = 1;
                }

                char direction;
                cout << "Направление:" << endl;
                cout << "               w - вверх" << endl;
                cout << "a - налево    s - вниз   d - направо" << endl;
                cin >> direction;

                // Логика движения хищника
                switch (direction) {
                case 'w':
                    arena.predator.move(0, -step);
                    break;
                case 's':
                    arena.predator.move(0, step);
                    break;
                case 'a':
                    arena.predator.move(-step, 0);
                    break;
                case 'd':
                    arena.predator.move(step, 0);
                    break;
                }

                // Проверка на столкновения
                if (arena.checkCollision()) {
                    cout << "ИГРА ОКОНЧЕНА." << endl;
                    Sleep(5000);
                    break;
                }

                arena.prey.autoMove(width, height);  // Автоматическое движение жертвы

                if (arena.checkCollision()) {
                    cout << "ИГРА ОКОНЧЕНА." << endl;
                    Sleep(5000);
                    break;
                }

                limit--;
            }
        }
        else if (ch == '2') {
            // Логика для жертвы
            cout << "Жертва" << endl;
            srand(time(nullptr));
            int limit = movesLimit;

            while (limit > 0) {
                arena.display();

                if (arena.checkCollision()) {
                    cout << "ИГРА ОКОНЧЕНА." << endl;
                    Sleep(5000);
                    break;
                }

                char direction;
                cout << "Направление:" << endl;
                cout << "q - влево-вверх    w - вверх    e - вправо-вверх" << endl;
                cout << "a - влево          s - вниз      d - вправо" << endl;
                cout << "z - влево-вниз               c - вправо-вниз" << endl;
                cin >> direction;

                // Логика движения жертвы
                switch (direction) {
                case 'w':
                    arena.prey.move(0, -1);
                    break;
                case 's':
                    arena.prey.move(0, 1);
                    break;
                case 'a':
                    arena.prey.move(-1, 0);
                    break;
                case 'd':
                    arena.prey.move(1, 0);
                    break;
                case 'q':
                    arena.prey.move(-1, -1);
                    break;
                case 'e':
                    arena.prey.move(1, -1);
                    break;
                case 'z':
                    arena.prey.move(-1, 1);
                    break;
                case 'c':
                    arena.prey.move(1, 1);
                    break;
                }

                // Проверка на столкновения
                if (arena.checkCollision()) {
                    cout << "ИГРА ОКОНЧЕНА." << endl;
                    Sleep(5000);
                    break;
                }

                limit--;
            }
        }
        else {
            validUserInput = false;
        }
    } while (!validUserInput);

    return 0;
}
