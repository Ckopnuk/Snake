#include <iostream>
#include "snakemodel.h"
#include <conio.h>

enum direction {STOP = 0, LEFT, RIGHT, UP, DOWN};
direction dir;
int tailXY[100][2];

void setup(snakeModel& obj) {
    obj.setGameOver(false);
    obj.setX(obj.getWidth()/2 - 1);
    obj.setY(obj.getHight()/2 - 1);
    obj.setFruitX(rand() % obj.getWidth());
    obj.setFruitY(rand() % obj.getHight());
    obj.setScore(0);
}

void draw(snakeModel& obj)
{
    system("cls");
    for (int i = 0; i < obj.getWidth() + 1; ++i) std::cout << "#";
    std::cout << std::endl;
    for (int j = 0; j < obj.getHight(); ++j)
    {
        std::cout << "#";
        for (int n = 0; n < obj.getWidth() - 1; ++n)
        {
            if (n == (obj.getX()) && j == (obj.getY()))
            {
                std::cout << "O";
            }
            else if (n == (obj.getFruitX()) && j == (obj.getFruitY()))
            {
                std::cout << "f";
            }
            else
            {
                bool print = false;
                for (int k = 0; k < obj.getNTail(); k++)
                {
                    if (tailXY[k][0] == j && tailXY[k][1] == n)
                    {
                        print = true;
                        std::cout << "o";
                    }
                }
                if (!print)
                {
                    std::cout << " ";
                }
            }
        }
                             std::cout << "#" << std::endl;
    }
            for (int i = 0; i < obj.getWidth() + 1; ++i) std::cout << "#";
            std::cout << std::endl;
            std::cout << obj.getScore();
}

        void input()
        {
            if (_kbhit())
            {
                switch (_getch())
                {
                case 'a':
                    dir = LEFT;
                    break;
                case 's':
                    dir = DOWN;
                    break;
                case 'd':
                    dir = RIGHT;
                    break;
                case 'w':
                    dir = UP;
                    break;
                }
            }
        }

        void logic(snakeModel& obj)
        {
            int prevX = tailXY[0][0];
            int prevY = tailXY[0][1];
            int prev2X, prev2Y;
            tailXY[0][0] = obj.getY();
            tailXY[0][1] = obj.getX();
            for (int i = 1; i < obj.getNTail(); i++)
            {
                prev2X = tailXY[i][0];
                prev2Y = tailXY[i][1];
                tailXY[i][0] = prevX;
                tailXY[i][1] = prevY;
                prevX = prev2X;
                prevY = prev2Y;
            }

            switch (dir)
            {
            case LEFT:
                obj.setX(obj.getX() - 1);
                break;
            case RIGHT:
                obj.setX(obj.getX() + 1);
                break;
            case UP:
                obj.setY(obj.getY() - 1);
                break;
            case DOWN:
                obj.setY(obj.getY() + 1);
                break;
            }

            if (obj.getX() >= obj.getWidth()) {
                obj.setX(0);
            }
            else if (obj.getX() < 0) {
                obj.setX(obj.getWidth()-1);
            }

            if (obj.getY() >= obj.getHight()) {
                obj.setY(0);
            }
            else if (obj.getY() < 0) {
                obj.setY(obj.getHight()-1);
            }

            for (int i = 0; i < obj.getNTail(); i++)
            {
                if (tailXY[i][0] == obj.getY() && tailXY[i][1] == obj.getX()) {
                    obj.setGameOver(true);
                }
            }

            if (obj.getX() == obj.getFruitX() && obj.getY() == obj.getFruitY())
            {
                obj.setScore(obj.getScore()+10);
                obj.setNTail(obj.getNTail() + 1);
                obj.setFruitX(rand() % obj.getWidth());
                obj.setFruitY(rand() % obj.getHight());
            }
        }

        int main()
        {
            snakeModel model;
            setup(model);
            while (!model.getGameOver())
            {
                draw(model);
                input();
                logic(model);
            }

            return 0;
        }
