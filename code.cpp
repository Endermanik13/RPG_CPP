#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <ctime>
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
        {1, 2, 0, 4, 0, 0, 0, 3, 0, 0, 1, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 3, 1, 0, 1, 1, 1, 1, 1, 0, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 0, 3, 1, 0, 1, 0, 1, 0, 1, 3, 1, 3, 0, 0, 4, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1},
        {1, 3, 0, 0, 1, 0, 1, 0, 0, 4, 1, 3, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 1, 3, 1, 1, 1, 0, 1, 1, 1, 3, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 3, 1, 0, 0, 0, 4, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1},
        {1, 0, 3, 0, 4, 0, 1, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, 0, 0, 0, 3, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    int playerX = 1;
    int playerY = 1;
    int hp = 10;
    int lechilki = 1;
    int sword = 1;
    int money = 0;
    int kills = 0;
    while (true) {
        if (kills == 7) {
            system("cls");
            cout << "Поздравляем! Вы прошли игру!" << endl;
            cout << "Ваш финальный счёт: " << money << " монет" << endl;

            ofstream scoreFile("score.txt");
            if (scoreFile.is_open()) {
                scoreFile << "Финальный счёт: " << money << " монет" << endl;
                scoreFile.close();
            }
            else {
                cout << "Ошибка при сохранении счёта!" << endl;
            }

            break;
        }


        cout << "Выберите функцию" << endl;
        cout << "[1] Посмотреть карту" << endl;
        cout << "[2] Управление" << endl;
        cout << "[3] Магазин" << endl;
        cout << "[4] Инвентарь" << endl;
        cout << "[5] Об игре" << endl;
        cout << "[0] Выход" << endl;

        int command;
        cout << "Введение команды: ";
        cin >> command;

        if (command == 0) {
            system("cls");
            cout << "Выход из программы. До свидания!" << endl;
            break;
        }
        if (hp == 0) {
            system("cls");
            cout << "Вы умерли" << endl;
            cout << "Игра окончена" << endl;
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
                if (kills == 7) {
                    break;
                }
                if (hp == 0) {
                    system("cls");
                    cout << "Вы умерли" << endl;
                    cout << "Игра окончена" << endl;
                    break;
                }
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
                        if (hp == 0) {
                            system("cls");
                            cout << "Вы умерли" << endl;
                            cout << "Игра окончена" << endl;
                            break;
                        }
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
                if (kills == 7) {
                    break;
                }
                if (maze[newX][newY] == 4) {
                    maze[playerX][playerY] = 0;
                    maze[newX][newY] = 2;
                    playerX = newX;
                    playerY = newY;
                    system("cls");
                    cout << "Вы наткнулись на Монстра" << endl;
                    int info = 0; // Известно ли игроку о монстре?
                    srand(time(0));
                    int EnemyHp = rand() % 3 + 3;
                    int maxhp = EnemyHp;

                    while (true) {
                        if (EnemyHp == 0) {
                            system("cls");
                            cout << "Вы убили монстра!" << endl;
                            cout << "Вы получили 5 монет" << endl;
                            cout << "Введите что нибудь, чтобы продолжить...";
                            int megasupernazvanie; // Это ни на что не влияет, просто нужно чтобы игрок что то сделал чтобы продолжить, тем самым сделав так чтобвы высвечивалось сообщение.
                            cin >> megasupernazvanie;
                            system("cls");
                            printMaze(maze, 20, 28);
                            break;
                        }
                        cout << "Бой с монстром" << endl;

                        cout << "Ваше ХП: " << hp << "/10" << endl;
                        cout << "Ваш урон: " << sword << endl << endl;
                        if (info == 0) {
                            cout << "Здоровье врага: ???" << endl;
                        }
                        if (info == 1) {
                            cout << "Здоровье врага: " << EnemyHp << "/" << maxhp << endl;
                        }
                        int option;
                        cout << "[1] Атаковать" << endl;
                        cout << "[2] Действие" << endl; // Там можно оценить монстра, т.е. узнать что это за монстр, и так же увидеть его хп
                        cout << "[3] Вещи" << endl; // Инвентарь
                        // Раньше здесь была функция DEV - Выйти из боя
                        cout << "Что вы будете делать: ";
                        cin >> option;


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
                                    cout << "Здоровье врага: " << EnemyHp << "/" << maxhp << endl;
                                }
                                cout << endl;
                                if (info == 0) {
                                    cout << "[1] Изучить монстра" << endl;
                                }
                                cout << "[0] Назад" << endl << endl;
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
                                else if (poption == 0) {
                                    system("cls");
                                    break;
                                }
                                else {
                                    system("cls");
                                    cout << "Неверная команда, попробуйте снова." << endl;
                                }
                            }
                            if (hp == 0) {
                                system("cls");
                                cout << "Вы умерли" << endl;
                                cout << "Игра окончена" << endl;
                                break;
                            }
                            if (EnemyHp == 0) {
                                system("cls");
                                break;
                            }
                        }
                        else if (option == 1) {
                            system("cls");
                            while (true) {

                                int act;
                                int enemyAct = rand() % 3 + 1;
                                cout << "Ваше ХП: " << hp << "/10" << endl;
                                cout << "Ваш урон: " << sword << endl << endl;
                                if (info == 0) {
                                    cout << "Здоровье врага: ???" << endl;
                                }
                                if (info == 1) {
                                    cout << "Здоровье врага: " << EnemyHp << "/" << maxhp << endl;
                                }
                                cout << endl;
                                cout << "[1] Быстрый удар" << endl;
                                cout << "[2] Сильный удар" << endl;
                                cout << "[3] Защищаться" << endl;
                                cout << "[0] Назад" << endl << endl;
                                cout << "Враг выбрал: ";
                                if (info == 1) {
                                    if (enemyAct == 1) {
                                        cout << "Быстрый удар" << endl;
                                    }
                                    if (enemyAct == 2) {
                                        cout << "Сильный удар" << endl;
                                    }
                                    if (enemyAct == 3) {
                                        cout << "Защита" << endl;
                                    };
                                }
                                else {
                                    cout << "???" << endl;
                                }

                                cout << "Введение команды: ";
                                cin >> act;
                                if (act == 0) {
                                    system("cls");
                                    break;
                                }
                                if (act == 1 && enemyAct == 1) {
                                    system("cls");
                                    cout << "Вы оба нанесли быстрые удары одновременно!" << endl;
                                    cout << "Удары отразили друг друга." << endl;
                                }
                                else if (act == 1 && enemyAct == 3) {
                                    system("cls");
                                    cout << "Вы ударили врага быстрой атакой, но он защитился!" << endl;
                                    cout << "Вы не нанесли врагу урон." << endl;
                                }
                                else if (act == 3 && enemyAct == 3) {
                                    system("cls");
                                    cout << "Вы оба встали в защиту..." << endl;
                                    cout << "Вы не нанесли врагу урон." << endl;
                                }
                                else if (act == 2 && enemyAct == 2) {
                                    system("cls");
                                    cout << "Вы оба ударили с огромной силой!" << endl;
                                    cout << "Удары разлетелись в стороны, и оба остались на месте." << endl;
                                }
                                else if (act == 1 && enemyAct == 2) {
                                    system("cls");
                                    EnemyHp--;
                                    cout << "Ваш быстрый удар был быстрее, чем его сильный замах!" << endl;
                                    cout << "Враг получил урон." << endl;
                                }
                                else if (act == 2 && enemyAct == 1) {
                                    system("cls");
                                    hp--;
                                    cout << "Вы попытались нанести сильный удар, но враг был быстрее." << endl;
                                    cout << "Вы пропустили удар." << endl;
                                }
                                else if (act == 2 && enemyAct == 3) {
                                    system("cls");
                                    EnemyHp--;
                                    cout << "Вы размахнулись и пробили его защиту!" << endl;
                                    cout << "Враг получил урон." << endl;
                                }
                                else if (act == 3 && enemyAct == 2) {
                                    system("cls");
                                    hp--;
                                    cout << "Вы подняли защиту, но мощный удар врага пробил её!" << endl;
                                    cout << "Вы получили урон." << endl;
                                }
                                else if (act == 3 && enemyAct == 1) {
                                    system("cls");
                                    cout << "Вы встали в защиту, блокируя быстрый удар врага." << endl;
                                    cout << "Вы не получили урон." << endl;
                                }
                                else {
                                    system("cls");
                                    cout << "Неверная команда, попробуйте снова." << endl;
                                };
                                if (EnemyHp == 0) {
                                    system("cls");
                                    cout << "Вы убили монстра!" << endl;
                                    money++;
                                    money++;
                                    money++;
                                    money++;
                                    money++;
                                    kills++;
                                    cout << "Вы получили 5 монет" << endl;
                                    break;
                                }
                                if (hp == 0) {
                                    system("cls");
                                    cout << "Вы умерли" << endl;
                                    cout << "Игра окончена" << endl;
                                    break;
                                }

                            }
                        }
                        else if (option == 3) {
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
                        if (hp == 0) {
                            system("cls");
                            cout << "Вы умерли" << endl;
                            cout << "Игра окончена" << endl;
                            break;
                        }
                    }
                }
                if (maze[newX][newY] == 1) {

                    system("cls");
                    printMaze(maze, 20, 28);
                    cout << "Вы не можете пройти, так как перед вами стена" << endl;

                }
                if (hp == 0) {
                    system("cls");
                    cout << "Вы умерли" << endl;
                    cout << "Игра окончена" << endl;
                    break;
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
        else if (command == 5) {
            system("cls");
            while (true) {

                cout << "Само собой эта игра интересная. Но опытный программист взглянув на код, ужаснётся и скажет убрать то, убрать это, только ради оптимизации." << endl << endl;
                cout << "Суть игры, это пройтись по подземельям, и УБИТЬ всех врагов" << endl;
                cout << "[0] Назад" << endl;
                cout << "Введите команду: ";
                int option;
                cin >> option;
                if (option == 0) {
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

    return 0;
}