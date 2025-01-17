#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <windows.h>
using namespace std;
void SetConsoleWindowSize(int width, int height) {
    HWND hwnd = GetConsoleWindow();  // Получаем дескриптор окна консоли
    if (hwnd != NULL) {
        // Устанавливаем размер окна консоли
        RECT rect;
        GetWindowRect(hwnd, &rect);  // Получаем текущие размеры окна
        MoveWindow(hwnd, rect.left, 0, width, height, TRUE);  // Перемещаем окно в верхнюю часть экрана
    }
}


void printMaze(int maze[][7], int rows, int cols) { // Вывод карты
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

void one() {
    cout << "                                                                                                                " << endl;
    cout << "                                                                                                                " << endl;
    cout << "                                                                                                                " << endl;
    cout << "                                              +xxxxxxxxxxxxxxxxxxxx:             xxxxxxxxx                      " << endl;
    cout << "                        x$$$$$$$$$$$$+;;;;;;;;;                    :;;;;;;;;;;;;;        :;;;&X                " << endl;
    cout << "                       x;                                                                     :X               " << endl;
    cout << "                      .X;                                                                     :X               " << endl;
    cout << "                       x;                                                                     :X               " << endl;
    cout << "                       x;                                                                     :X               " << endl;
    cout << "                       x;                                                                     .++              " << endl;
    cout << "                       x;                                :xxxxxxxxxxx                         .x:              " << endl;
    cout << "                       x;                   ;$$&&&&&&&&&&&&&&&&&&&&&&&&&.                      ;+              " << endl;
    cout << "                       x;                 .&&&&&&&&&&&&&&&&&&&&&&&&&&&&&.                      ;+              " << endl;
    cout << "                        X.                &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&.                      ;+              " << endl;
    cout << "                        X.                &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&.                      .x.             " << endl;
    cout << "                        X.                &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&.                       x:             " << endl;
    cout << "                        X:               X&&&&&&&&&&&&&&&&&&&&&&&&&&&&&;                        x:             " << endl;
    cout << "                         &               X&&&&&&&&&&&&&&&&&&&&&&&&&&&&&;                        x:             " << endl;
    cout << "                         &               X&&&&&&&&&&&&&&&&&&&&&&&&&&&&&;                        x:             " << endl;
    cout << "                         &               X&&&&&&&&&&&&&&&&&&&&&&&&&&&&&;                        x:             " << endl;
    cout << "                         &               X&&&&&&&&&&&&&&&&&&&&&&&&&&&&&;                        x:             " << endl;
    cout << "                         ;$             ;&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&X.                       x:             " << endl;
    cout << "                          $            ;x  :::::::::::::::::::.        X.                       x:             " << endl;
    cout << "                          $            ;x                            +&$.                       x:             " << endl;
    cout << "                          $             +&xxxxx+   .xxxxxx$&&&&&&&&&&&$xx                       x:             " << endl;
    cout << "                          $          x$$$&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&$.                   x:             " << endl;
    cout << "                          $      .&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&                  ;+              " << endl;
    cout << "                          $      $&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&                  ;+              " << endl;
    cout << "                          $       ++X&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&X+.                 :X               " << endl;
    cout << "                          $            .:::$+&&&&&&&&&&&&&&&&&&&&::$::::.                     :X               " << endl;
    cout << "                          $                :x:.    .:::::::::   :+;                           &               " << endl;
    cout << "                          $               +xX&&&&&&&&&&&&&&&&&&&xx:                          ++               " << endl;
    cout << "                          $            :$&&&&&&&&&&&&&&&&&&&&&&&&&&&&x                       &                 " << endl;
    cout << "                          :x          .&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&x.                    X:                 " << endl;
    cout << "                          :x         $&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&;                   .x.                 " << endl;
    cout << "                          :x        ;&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&.                  ++                  " << endl;
    cout << "                          :x        x&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&.                 :X.                  " << endl;
    cout << "                          :&+      ;&&&&&;&&&&&&&&&&&&&&&&&&&&&&&xX&&&&&.                 ;x                   " << endl;
    cout << "                           ++     .X&&&&&;&&&&&&&&&&&&&&&&&&&&&&&;&&&&&&&                 $                     " << endl;
    cout << "                           ++     .&&&&&&;&&&&&&&&&&&&&&&&&&&&&&&;&&&&&&&                X:                     " << endl;
    cout << "                           ++     &&&&&&&;&&&&&&&&&&&&&&&&&&&&&&&;&&&&&&&                &                      " << endl;
    cout << "                           ++     &&&&&&&;&&&&&&&&&&&&&&&&&&&&&&Xx&&&&&&&               X.                      " << endl;
    cout << "                           ++    $&&&&&&xX&&&&&&&&&&&&&&&&&&&&&&.&&&&&&&&               X.                      " << endl;
    cout << "                           ++    $&&&&&&xX&&&&&&&&&&&&&&&&&&&&&&.+&&&&&&&              +;.                      " << endl;
    cout << "                           ++    $&&&&&$ X&&&&&&&&&&&&&&&&&&&&&& ;&&&&&&&              +;                       " << endl;
    cout << "                           :x.  ;&x&&&&&x$&&&&&&&&&&&&&&&&&&&&&&xX&&&&&&&             :x:                       " << endl;
    cout << "                            X:   $     $+&&&&&&&&&&&&&&&&&&&&&&&.X :;;;;&             ;x                        " << endl;
    cout << "                            X:   $.   .X+&&&&&&&&&&&&&&&&&&&&&&&&;+.    &             &x                        " << endl;
    cout << "                            +&    X$;;& +&&&&&&&&&&&&&&&&&&&&&&&&  x;::;X             $                         " << endl;
    cout << "                             &          +&&&&&&&&&&&;&&&&&&&&&&&&    .:              X;                         " << endl;
    cout << "                             &          +&&&&&&&&&&&;&&&&&&&&&&&.                    &                          " << endl;
    cout << "                             &          +&&&&&&&&&& :&&&&&&&&&&&&                    &                          " << endl;
    cout << "                             +&        :X&&&&&&&&&&  x&&&&&&&&&&&                    &                          " << endl;
    cout << "                              &        ;&&&&&&&&&&&  x&&&&&&&&&&&                   x&                          " << endl;
    cout << "                              &X       ;&&&&&&&&&&&  x&&&&&&&&&&&                    &                          " << endl;
    cout << "                             ;&        ;&&&&&&&&&&&  x&&&&&&&&&&&:                   X$                         " << endl;
    cout << "                            ++         ;&&&&&&&&&&&  x&&&&&&&&&&&X                    +;                        " << endl;
    cout << "                           ++.         &&&&&&&&&&&&  x&&&&&&&&&&&X                    .+;                       " << endl;
    cout << "                          &+           &&&&&&&&&&&:  x&&&&&&&&&&&&+                    ;&.                      " << endl;
    cout << "                         &+            &&&&&&&&&&&:   $&&&&&&&&&&&+                     ;x                      " << endl;
    cout << "                        X.            $&&&&&&&&&&&:   $&&&&&&&&&&&$:                     &x                     " << endl;
    cout << "                       x;             &&&&&&&&&&&&:   $&&&&&&&&&&&&;                      $.                    " << endl;
    cout << "                      +x              &&&&&&&&&&&&:   $&&&&&&&&&&&&+                      :X.                   " << endl;
    cout << "                     X;               &&&&&&&&&&&&:   $&&&&&&&&&&&&&                       +$.                  " << endl;
    cout << "                   +&:               $&&&&&&&&&&&&:   $&&&&&&&&&&&&&                                            " << endl;
    cout << "                                       $&&&&&&&&&&:   $&&&&&&&&&&&&&&                                           " << endl;
    cout << "                                           xxxxxX+    $&&&&&&&&&&&&&&                                           " << endl;
    cout << "                                                       :;x&&&&&&&&&&&:                                          " << endl;
    cout << "                                                                                                                " << endl;
    cout << "                                                                                                                " << endl;
}
void two() {
    cout << "                                                                                                                                         " << endl;
    cout << "                                                                                                                                         " << endl;
    cout << "                                                                                                                                         " << endl;
    cout << "                                                            <@@@@@@@@@@@@@@@@@@.                                                          " << endl;
    cout << "                                                            @@@@@@@@@@@@@@@@@@@:                                                          " << endl;
    cout << "   -         :+++#[[[[[[[[[[[=                              @@@@@@@@@@@@@@@@@@@:                                        [[[[>++++++++++  " << endl;
    cout << "   -                              -#                       {@@@@@@@@@@@@@@@@@@@                       -({                             +  " << endl;
    cout << "   -                               #                       {@@@@@@@@@@@@@@@@@@@                       }                               +  " << endl;
    cout << "    %                             ~                        {@@@@@@@@@@@@@@@@@@@                        ^                             -=  " << endl;
    cout << "    %                             ~                        %@@@@@@@@@@@@@@@@@@@.                       ^                             {   " << endl;
    cout << "    %                             ~                       %                  .~:                       ^                             {   " << endl;
    cout << "    ::                             #                       @[[[^  [[[[%@@@@@@@[[                      <-                             >   " << endl;
    cout << "    ::                             #                  :@@@@@@@@@@@@@@@@@@@@@@@@@@@:                   }                              ~   " << endl;
    cout << "    ::                             #                  @@@@@@@@@@@@@@@@@@@@@@@@@@@@^                   }                              ~   " << endl;
    cout << "    ::                             #                      }{@%@@@@@@@@@@@@%{@{{.                      }                              ~   " << endl;
    cout << "    .@                             #                         )+   [[[[[[  [=                          }                             (~   " << endl;
    cout << "     %                             #                      ~#@@@@@@@@@@@@@@@@@~                        }                             #    " << endl;
    cout << "     %                             #                     [@@@@@@@@@@@@@@@@@@@@[                       }                             #    " << endl;
    cout << "      -                            #                    +@@@@@@@@@@@@@@@@@@@@@@:                      }                             -    " << endl;
    cout << "      -                            #                   -@@@>@@@@@@@@@@@@@@@)@@@:                      }                             -    " << endl;
    cout << "      -                            #                   *@@@~@@@@@@@@@@@@@@(@@@@@                      }                             -    " << endl;
    cout << "      ]                            #                  =@@@@~@@@@@@@@@@@@@@(@@@@@                      }                             -    " << endl;
    cout << "      #                            #                  +@@@@~@@@@@@@@@@@@@@(@@@@@                      }                            @     " << endl;
    cout << "      #                            #                  @@@@@{@@@@@@@@@@@@@@^@@@@@                      }                            @     " << endl;
    cout << "      [=                           #                  @@@@:{@@@@@@@@@@@@@@ @@@@@                      }                           .@     " << endl;
    cout << "       =                          ~                  -[+++*%@@@@@@@@@@@@@@)+@@@@                      =^                          :      " << endl;
    cout << "       =                          ~                   }  ~.@@@@@@@@@@@@@@@((   %                       ^                          :      " << endl;
    cout << "       =                          ~                    +++ @@@@@@@>@@@@@@@( :*+.                       ^                          :      " << endl;
    cout << "       }                          +                        @@@@@@@~@@@@@@@                             ^                          %      " << endl;
    cout << "       }                          {                        @@@@@@} @@@@@@@(                            (                          %      " << endl;
    cout << "       }:                         {                       %@@@@@@} @@@@@@@(                            (                          %      " << endl;
    cout << "        +                         {                       %@@@@@@} @@@@@@@(                            (                         ~       " << endl;
    cout << "        +                         @~                      @@@@@@@} @@@@@@@@                            [                         ~       " << endl;
    cout << "        }                           +[                    @@@@@@@= @@@@@@@@<                         %+                          ~       " << endl;
    cout << "          %-                           (~                 @@@@@@@  :@@@@@@@[                      +                            ~{        " << endl;
    cout << "            %                            -#              @@@@@@@@  :@@@@@@@@                   +}=                           ^~          " << endl;
    cout << "              }                             ~%           @@@@@@@@  :@@@@@@@@{               -(^                            -{            " << endl;
    cout << "                %-                            .@[       -@@@@@@@@  :@@@@@@@@{             (^:                            ]*              " << endl;
    cout << "                  %:                                       {@@@@%  :@@@@@@@@@                                          +}                 " << endl;
    cout << "                                                                    ++@@@@@@@+                                        +                   " << endl;
}


int main() {
    
    setlocale(LC_ALL, "");
    SetConsoleWindowSize(1200, 1000);
    int maze[5][7] = {
        {1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 3, 0, 0, 1},
        {1, 0, 1, 1, 1, 0, 1},
        {1, 0, 0, 2, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1}
    };
    int playerX = 3;
    int playerY = 3;

    while (true) {
        cout << "Выберите функцию" << endl;
        cout << "[1] Посмотреть карту" << endl;
        cout << "[2] Управление" << endl;
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
            printMaze(maze, 5, 7);
        }
        else if (command == 2) {
            system("cls");
            printMaze(maze, 5, 7);
            while (true) {



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

                if (newX < 0 || newX >= 5 || newY < 0 || newY >= 7) {
                    system("cls");
                    printMaze(maze, 5, 7);
                    continue;
                }

                if (maze[newX][newY] == 0 || maze[newX][newY] == 2) {
                    maze[playerX][playerY] = 0;
                    maze[newX][newY] = 2;
                    playerX = newX;
                    playerY = newY;

                    system("cls");
                    printMaze(maze, 5, 7);
                }

                if (maze[newX][newY] == 3) {
                    maze[playerX][playerY] = 0;
                    maze[newX][newY] = 2;
                    playerX = newX;
                    playerY = newY;
                    system("cls");
                    printMaze(maze, 5, 7);
                    
                    one();
                    cout << "Вы наступили на клетку 3! Выполняется взаимодействие." << endl;
                }
                if (maze[newX][newY] == 1) {

                    system("cls");
                    printMaze(maze, 5, 7);
                    cout << "Впереди стенка" << endl;
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