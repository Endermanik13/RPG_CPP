#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <windows.h>
using namespace std;


void SetConsoleWindowSize(int width, int height) { // Код взят с интернета для увеличения окна
    HWND hwnd = GetConsoleWindow();
    if (hwnd != NULL) {

        RECT rect;
        GetWindowRect(hwnd, &rect);


        int newWidth = width;
        int newHeight = height;
        MoveWindow(hwnd, 0, 0, newWidth, newHeight, TRUE);


        CONSOLE_FONT_INFOEX cfi;
        cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
        GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);


        int newFontSizeX = (newWidth / 20);
        int newFontSizeY = (newHeight / 35);
        cfi.dwFontSize.X = newFontSizeX;
        cfi.dwFontSize.Y = newFontSizeY;


        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    }
} // Увеличение окна
void printMaze(int maze[][28], int rows, int cols) { // Вывод карты
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (maze[i][j] == 0)
                cout << ". ";
            else if (maze[i][j] == 1)
                cout << "# ";
            else if (maze[i][j] == 2)
                cout << "P ";
            else if (maze[i][j] == 3)
                cout << "C ";
            else if (maze[i][j] == 4)
                cout << "M ";
        }
        cout << endl;
    }
} // Вывод карты

int main() {

    setlocale(LC_ALL, "");
    SetConsoleWindowSize(1200, 1000);
    int maze[20][28] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 2, 0, 4, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    int playerX = 1;
    int playerY = 1;
    int hp = 10;
    int lechilki = 1;
    int sword = 1;
    int money = 0;
    while (true) {
        cout << "Тест: 0.7" << endl;
        cout << "Выберите функцию" << endl;
        cout << "[1] Посмотреть карту" << endl;
        cout << "[2] Управление" << endl;
        cout << "[3] Магазин" << endl;
        cout << "[4] Инвентарь" << endl;
        cout << "[0] Выход" << endl;

        int command;
        cout << "Введение команды: ";
        cin >> command;

        if (command == 0) {
            system("cls");
            cout << "Выход из программы. До свидания!" << endl;
            break;
        }
        if (command == 1) {
            system("cls");
            printMaze(maze, 20, 28);
        }
        else if (command == 2) {
            system("cls");
            printMaze(maze, 20, 28);

            while (true) {
                cout << "Лечебные зелья: " << lechilki << endl;
                cout << "Ваше ХП: " << hp << "/10" << endl;
                cout << "Ваш урон: " << sword << endl << endl;
                cout << "Ваш балланс: " << money << endl;
                cout << "Выберите направление" << endl;
                cout << "[1] Вверх" << endl;
                cout << "[2] Влево" << endl;
                cout << "[3] Вниз" << endl;
                cout << "[4] Вправо" << endl;
                cout << "[5] Инвентарь" << endl;
                cout << "[0] Вернуться в меню" << endl;

                int direction;
                cout << "Введите направление: ";
                cin >> direction;

                if (direction == 0) {
                    system("cls");
                    break;
                }
                if (direction == 5) {
                    system("cls");
                    while (true) {
                        int option;
                        cout << "Лечебные зелья: " << lechilki << endl;
                        cout << "Ваше ХП: " << hp << "/10" << endl;
                        cout << "Ваш урон: " << sword << endl << endl;
                        cout << "[1] Использовать Зелье Лечения" << endl;
                        cout << "[0] Выйти из инвентаря" << endl;
                        cout << "Выберите опцию: ";
                        cin >> option;
                        if (option == 0) {
                            system("cls");
                            break;
                        }
                        if (option == 1) {

                            if (lechilki == 0) {
                                system("cls");
                                cout << "У вас нету Зелья Лечения" << endl;
                            }
                            else {
                                if (hp >= 10) {
                                    system("cls");
                                    cout << "Вы не можете поспользоваться хилкой!" << endl;
                                    cout << "Ваше ХП уже 10/10" << endl;
                                }
                                else {
                                    system("cls");
                                    lechilki--;
                                    hp++;
                                    cout << "Вы воспользовались зельем лечения" << endl;
                                }

                            }
                        }
                        else {
                            system("cls");
                            cout << "Неправельная команда!" << endl;
                        }
                    }
                }
                int newX = playerX;
                int newY = playerY;

                if (direction == 1) newX--;
                else if (direction == 2) newY--;
                else if (direction == 3) newX++;
                else if (direction == 4) newY++;
                if (newX < 0 || newX >= 20 || newY < 0 || newY >= 28) {
                    system("cls");
                    printMaze(maze, 20, 28);
                    continue;
                }

                if (maze[newX][newY] == 0 || maze[newX][newY] == 2) {
                    maze[playerX][playerY] = 0;
                    maze[newX][newY] = 2;
                    playerX = newX;
                    playerY = newY;
                    system("cls");
                    printMaze(maze, 20, 28);

                }

                if (maze[newX][newY] == 3) {
                    maze[playerX][playerY] = 0;
                    maze[newX][newY] = 2;
                    playerX = newX;
                    playerY = newY;
                    system("cls");
                    printMaze(maze, 20, 28);

                    money++;
                    cout << "Вы нашли монетку!" << endl;

                }
                if (maze[newX][newY] == 4) {
                    maze[playerX][playerY] = 0;
                    maze[newX][newY] = 2;
                    playerX = newX;
                    playerY = newY;
                    system("cls");
                    cout << "Вы наткнулись на Монстра" << endl;
                    int info = 0; // Известно ли игроку о монстре?
                    while (true) {
                        cout << "Бой с монстром" << endl;
                        
                        cout << "Ваше ХП: " << hp << "/10" << endl;
                        cout << "Ваш урон: " << sword << endl << endl;
                        if (info == 0) {
                            cout << "Здоровье врага: ???" << endl;
                        }
                        if (info == 1) {
                            cout << "Здоровье врага: 3/3" << endl;
                        }
                        int option;
                        cout << "[1] Атаковать" << endl;
                        cout << "[2] Действие" << endl; // Там можно оценить монстра, т.е. узнать что это за монстр, и так же увидеть его хп
                        cout << "[3] Вещи" << endl; // Инвентарь
                        cout << "[4] Убежать" << endl; // Шанс на скип монстра 50%
                        cout << "[0] Выйти (DEV)" << endl;
                        cout << "Что вы будете делать: ";
                        cin >> option;
                        if (option == 0) {
                            system("cls");
                            printMaze(maze, 20, 28);
                            break;
                        }
                        if (option == 2) {
                            system("cls");
                            while (true) {
                                
                                int poption;
                                cout << "Ваше ХП: " << hp << "/10" << endl;
                                cout << "Ваш урон: " << sword << endl << endl;
                                if (info == 0) {
                                    cout << "Здоровье врага: ???" << endl;
                                }
                                if (info == 1) {
                                    cout << "Здоровье врага: 3/3" << endl;
                                }
                                cout << endl;
                                if (info == 0) {
                                    cout << "[1] Изучить монстра" << endl;
                                }
                                cout << "[2] Назад" << endl << endl;
                                cout << "Введение команды: ";
                                cin >> poption;
                                if (info == 0) {
                                    if (poption == 1) {
                                        system("cls");
                                        info = 1;
                                    }
                                    else {
                                        system("cls");
                                        cout << "Неверная команда, попробуйте снова." << endl;
                                    }
                                }
                                else if (poption == 2) {
                                    system("cls");
                                    break;
                                }
                                else {
                                    system("cls");
                                    cout << "Неверная команда, попробуйте снова." << endl;
                                }
                            }
                        }
                        if (option == 1) {
                            while (true) {
                                system("cls");
                                int act;
                                cout << "Ваше ХП: " << hp << "/10" << endl;
                                cout << "Ваш урон: " << sword << endl << endl;
                                if (info == 0) {
                                    cout << "Здоровье врага: ???" << endl;
                                }
                                if (info == 1) {
                                    cout << "Здоровье врага: 3/3" << endl;
                                }
                                cout << endl;
                                cout << "[1] Быстрый удар" << endl;
                                cout << "[2] Сильный удар" << endl;
                                cout << "[3] Защищаться" << endl;
                                cout << "[0] Назад" << endl << endl;
                                cout << "- - Правила сражения - -" << endl;
                                cout << "Бой тут в стиле 'Камень > Ножницы > Бумага' как то так." << endl << endl;
                                cout << "Быстрый удар > Сильный удар" << endl;
                                cout << "Сильный удар > Защита" << endl;
                                cout << "Защиты > Быстрый удар" << endl << endl;
                                cout << "Введение команды: ";
                                cin >> act;
                                if (act == 0) {
                                    system("cls");
                                    break;
                                }
                                else {
                                    system("cls");
                                    cout << "Неверная команда, попробуйте снова." << endl;
                                }
                            }
                        }
                        else {
                            system("cls");
                            cout << "Неверная команда, попробуйте снова." << endl;
                        }
                    }
                }
                if (maze[newX][newY] == 1) {

                    system("cls");
                    printMaze(maze, 20, 28);
                    cout << "Вы не можете пройти, так как перед вами стена" << endl;

                }
            }
        }
        else if (command == 3) {
            system("cls");
            while (true) {
                cout << "Торговец: Здравствуй, путник! Желаешь ли что-то купить?" << endl;
                int option;
                cout << "Лечебные зелья: " << lechilki << endl;
                cout << "Ваше ХП: " << hp << "/10" << endl;
                cout << "Ваш урон: " << sword << endl << endl;
                cout << "Ваш баланс: " << money << endl << endl;
                cout << "[1] Зелье лечения (Хиллит на 3)" << endl;
                cout << "       Стоит: 1 монету" << endl << endl;
                cout << "[2] Улучшить меч (+2 к урону)" << endl;
                cout << "       Стоит: 3 монеты" << endl << endl;
                cout << "[0] Вернуться в меню" << endl;
                cout << "Выберите товар: ";
                cin >> option;

                if (option == 0) {
                    system("cls");
                    break;
                }
                else if (option == 1) {
                    if (money >= 1) {
                        system("cls");
                        cout << "Вы купили зелье лечения!" << endl;
                        lechilki++;
                        money--;
                    }
                    else {
                        system("cls");
                        cout << "Вам не хватает денег!" << endl;
                    }
                }
                else if (option == 2) {
                    if (money >= 3) {
                        system("cls");
                        cout << "Вы купили улучшение меча!" << endl;
                        sword += 2;
                        money -= 3;
                    }
                    else {
                        system("cls");
                        cout << "Вам не хватает денег!" << endl;
                    }
                }
                else {
                    system("cls");
                    cout << "Неверная команда, попробуйте снова." << endl;
                }
            }
        }
        else if (command == 4) {
            system("cls");
            while (true) {
                int option;
                cout << "Лечебные зелья: " << lechilki << endl;
                cout << "Ваше ХП: " << hp << "/10" << endl;
                cout << "Ваш урон: " << sword << endl << endl;
                cout << "[1] Использовать Зелье Лечения" << endl;
                cout << "[0] Выйти из инвентаря" << endl;
                cout << "Выберите опцию: ";
                cin >> option;
                if (option == 0) {
                    system("cls");
                    break;
                }
                if (option == 1) {

                    if (lechilki == 0) {
                        system("cls");
                        cout << "У вас нету Зелья Лечения" << endl;
                    }
                    else {
                        if (hp >= 10) {
                            system("cls");
                            cout << "Вы не можете поспользоваться хилкой!" << endl;
                            cout << "Ваше ХП уже 10/10" << endl;
                        }
                        else {
                            system("cls");
                            lechilki--;
                            hp++;
                            cout << "Вы воспользовались зельем лечения" << endl;
                        }

                    }
                }
                else {
                    system("cls");
                    cout << "Неправельная команда!" << endl;
                }
            }
        }
        else {
            system("cls");
            cout << "Неверная команда, попробуйте снова." << endl;
        }
    }

    return 0;
}