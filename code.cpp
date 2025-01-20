#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <windows.h>
using namespace std;
void SetConsoleWindowSize(int width, int height) {
    HWND hwnd = GetConsoleWindow();
    if (hwnd != NULL) {

        RECT rect;
        GetWindowRect(hwnd, &rect);
        MoveWindow(hwnd, rect.left, 0, width, height, TRUE);
    }
}







void printMaze(int maze[][14], int rows, int cols) { // Вывод карты
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
        }
        cout << endl;
    }
}





int main() {

    setlocale(LC_ALL, "");
    SetConsoleWindowSize(1200, 1000);
    int maze[10][14] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 2, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1},
        {1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 3, 1},
        {1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1},
        {1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 3, 1},
        {1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    int playerX = 1;
    int playerY = 1;
    int money = 0;
    while (true) {
        cout << "Выберите функцию" << endl;
        cout << "[1] Посмотреть карту" << endl;
        cout << "[2] Управление" << endl;
        cout << "[3] Магазин" << endl;
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
            printMaze(maze, 10, 14);
        }
        else if (command == 2) {
            system("cls");
            printMaze(maze, 10, 14);
            
            while (true) {

                cout << "Ваш балланс: " << money << endl;
                cout << "Выберите направление" << endl;
                cout << "[1] Вверх" << endl;
                cout << "[2] Влево" << endl;
                cout << "[3] Вниз" << endl;
                cout << "[4] Вправо" << endl;
                cout << "[0] Вернуться в меню" << endl;

                int direction;
                cout << "Введите направление: ";
                cin >> direction;

                if (direction == 0) {
                    system("cls");
                    break;
                }

                int newX = playerX;
                int newY = playerY;

                if (direction == 1) newX--;
                else if (direction == 2) newY--;
                else if (direction == 3) newX++;
                else if (direction == 4) newY++;
                if (newX < 0 || newX >= 10 || newY < 0 || newY >= 14) {
                    system("cls");
                    printMaze(maze, 10, 14);
                    continue;
                }

                if (maze[newX][newY] == 0 || maze[newX][newY] == 2) {
                    maze[playerX][playerY] = 0;
                    maze[newX][newY] = 2;
                    playerX = newX;
                    playerY = newY;
                    system("cls");
                    printMaze(maze, 10, 14);
                    
                }

                if (maze[newX][newY] == 3) {
                    maze[playerX][playerY] = 0;
                    maze[newX][newY] = 2;
                    playerX = newX;
                    playerY = newY;
                    system("cls");
                    printMaze(maze, 10, 14);
                    
                    money++;
                    cout << "Вы нашли монетку!" << endl;
                    
                }
                if (maze[newX][newY] == 1) {

                    system("cls");
                    printMaze(maze, 10, 14);
                    cout << "Вы не можете пройти, так как перед вами стена" << endl;
                    
                }
            }
        }
        else if (command == 3) {
            system("cls");
            while (true) {
                cout << "Торговец: Здравствуй путник! Желаешь ли что то купить?" << endl;
                int option;
                cout << "Ваш балланс: " << money << endl << endl;
                cout << "[1] Зелье лечения (Хиллит на 3)" << endl;
                cout << "       Стоит: 1 монету" << endl << endl;
                cout << "[2] Улучшить меч (+2 к урону)" << endl;
                cout << "       Стоит: 3 монеты" << endl << endl << endl;
                cout << "[0] Вернуться в меню" << endl;
                cout << "Выберите товар:";
                cin >> option;
                if (option == 0) {
                    system("cls");
                    break;
                }
                else if (option == 1) {
                    if (money >= 1) {
                        system("cls");
                        cout << endl;
                        cout << "Вы купили зелье лечения!" << endl;
                    }
                    else {
                        system("cls");
                        cout << endl;
                        cout << "Вам не хватает денег!" << endl << endl;
                    }
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