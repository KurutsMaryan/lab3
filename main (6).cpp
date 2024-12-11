#include <iostream>
#include <cmath> // Для роботи з математичними функціями

using namespace std;

// Завдання 1. Опис числа
void task_1() {
    int number; // Змінна для зберігання введеного числа
    cout << "Введіть ціле число: ";
    cin >> number;

    string description; // Змінна для опису числа

    if (number == 0) {
        description = "нульове число";
    } else if (number > 0) {
        if (number % 2 == 0) {
            description = "додатне парне число";
        } else {
            description = "додатне непарне число";
        }
    } else { // number < 0
        if (number % 2 == 0) {
            description = "від’ємне парне число";
        } else {
            description = "від’ємне непарне число";
        }
    }

    cout << "Опис числа: " << description << endl;
}

// Завдання 2. Перевірка точки в області
void task_2() {
    float x, y, r; // Змінні для координат точки і радіуса
    cout << "*********** Point in geometry region 16 ********" << endl;
    cout << "Parameters r: ";
    cin >> r;

    // Перевірка коректності введення радіуса
    if (!cin || r <= 0) {
        cout << "Must be numeric, positive, non-zero" << endl;
    } else {
        // Запит координат точки
        cout << "Point x, y: ";
        cin >> x >> y;

        // Перевірка коректності вводу координат
        if (!cin) {
            cout << "Must be numeric!" << endl;
        } else {
            // Перевірка належності до першої області
            if (x > r && y > 0 && y < -x + 2 * r && 
                (x - r) * (x - r) + (y - r) * (y - r) > r * r) {
                cout << "In region!" << endl;
            }
            // Перевірка належності до другої області
            else if (x < -r && y < -x - 2 * r && 
                     (x + r) * (x + r) + (y + r) * (y + r) < r * r) {
                cout << "In region!" << endl;
            } else {
                // Точка не належить жодній з областей
                cout << "Out of region!" << endl;
            }
        }
    }
}

// Завдання 3. Обчислення площі і периметру кола
void task_3() {
    double radius; // Змінна для радіуса
    cout << "Введіть радіус кола: ";
    cin >> radius;

    // Перевірка коректності введення радіуса
    if (radius <= 0) {
        cout << "Радіус має бути більше нуля!" << endl;
        return;
    }

    // Обчислюємо площу та периметр
    double area = M_PI * radius * radius;
    double perimeter = 2 * M_PI * radius;

    // Виведення результатів
    cout << "Площа кола: " << area << endl;
    cout << "Периметр кола: " << perimeter << endl;
}

// Завдання 4. Меню
void menu() {
    int choice; // Змінна для вибору користувача

    do {
        // Виводимо меню
        cout << "\nОберіть завдання:\n";
        cout << "1. Опис числа\n";
        cout << "2. Перевірка точки у фігурі\n";
        cout << "3. Обчислення площі та периметру\n";
        cout << "0. Вихід\n";
        cout << "Введіть номер завдання: ";
        cin >> choice;

        // Виконання завдань залежно від вибору
        switch (choice) {
            case 1:
                task_1();
                break;
            case 2:
                task_2();
                break;
            case 3:
                task_3();
                break;
            case 0:
                cout << "Вихід з програми..." << endl;
                break;
            default:
                cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 0); // повторюємо, поки не вибрано вихід
}

int main() {
    menu(); // Запуск меню
    return 0;
}