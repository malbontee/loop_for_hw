#include <iostream>
#include <cmath> 
using namespace std;

int main() {
    int choice;


    while (true) {
        cout << "\nChoose a task:\n";
        cout << "1. Find divisors of a number\n";
        cout << "2. Guess the number game\n";
        cout << "3. Calculate scholarship and expenses\n";
        cout << "4. Generate calendar for a year\n";
        cout << "5. Draw a Christmas tree\n";
        cout << "6. Exit\n";
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Task 1: Найти делители числа
            int number;
            cout << "Enter a number to find its divisors: ";
            cin >> number;

            cout << "Numbers that divide " << number << " without remainder: ";
            for (int i = 1; i <= number; i++) {
                if (number % i == 0) {
                    cout << i << " ";
                }
            }
            cout << "\n";

        }
        else if (choice == 2) {
            // Task 2: Угадай число
            int lower_bound = 0, upper_bound = 5000, current_guess, attempts = 0;
            char answer;

            cout << "Think of a number between 0 and 5000. I'll try to guess it.\n";

            while (lower_bound <= upper_bound) {
                current_guess = (lower_bound + upper_bound) / 2;
                cout << "Is your number " << current_guess << "? (if less enter < , > if more, = if correct): ";
                cin >> answer;
                attempts++;

                if (answer == '=') {
                    cout << "I guessed the number in " << attempts << " attempts!\n";
                    break;
                }
                else if (answer == '<') {
                    upper_bound = current_guess - 1;
                }
                else if (answer == '>') {
                    lower_bound = current_guess + 1;
                }
            }

        }
        else if (choice == 3) {
            // Task 3: Расчет стипендии и расходов
            double monthly_scholarship, monthly_expenses, total = 0;
            cout << "Enter the scholarship amount (UAH): ";
            cin >> monthly_scholarship;
            cout << "Enter monthly living expenses (UAH): ";
            cin >> monthly_expenses;

            for (int month = 1; month <= 10; month++) {
                total += monthly_expenses - monthly_scholarship;
                monthly_expenses *= 1.03; // увеличение расходов на 3% каждый месяц
            }

            cout << "You need to ask your parents for " << total << " UAH.\n";

        }
        else if (choice == 4) {
            // Task 4: Сделать календарь
            int year;
            cout << "Enter a year: ";
            cin >> year;

            int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

            // Проверка на високосный год
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                days_in_month[1] = 29; // Для февраля (високосный год = 29 дней)
            }

            cout << "Calendar for the year " << year << ":\n";
            for (int month = 0; month < 12; month++) {
                cout << "Month " << month + 1 << ": " << days_in_month[month] << " days\n";
            }

        }
        else if (choice == 5) {
            // Task 5:  Ёлочка
            int tiers, height;
            cout << "Enter the number of tiers: ";
            cin >> tiers;
            cout << "Enter the height of each tier: ";
            cin >> height;

            // Цикл по ярусам
            for (int t = 0; t < tiers; t++) {
                // Высота каждого яруса
                for (int h = 1; h <= height; h++) {
                    // Пробельчики
                    for (int space = 0; space < tiers * height - h - t; space++) {
                        cout << " ";
                    }
                    // Звездочки
                    for (int star = 0; star < 2 * h + 2 * t - 1; star++) {
                        cout << "*";
                    }
                    cout << "\n";
                }
            }

            // Ствол ёлочки
            for (int i = 0; i < 3; i++) {
                for (int space = 0; space < tiers * height - 2; space++) {
                    cout << " ";
                }
                cout << "***\n";
            }

        }
        else if (choice == 6) {

            break;
        }
        else {
            cout << "Invalid choice, please try again.\n";
        }
    }
}
