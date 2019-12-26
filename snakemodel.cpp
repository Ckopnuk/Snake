#include "snakemodel.h"

bool snakeModel::getGameOver() const
{
    return gameOver;
}

void snakeModel::setGameOver(bool value)
{
    gameOver = value;
}

int snakeModel::getWidth() const
{
    return Width;
}

int snakeModel::getHight() const
{
    return hight;
}

int snakeModel::getX() const
{
    return x;
}

void snakeModel::setX(int value)
{
    x = value;
}

int snakeModel::getY() const
{
    return y;
}

void snakeModel::setY(int value)
{
    y = value;
}

int snakeModel::getFruitX() const
{
    return fruitX;
}

void snakeModel::setFruitX(int value)
{
    fruitX = value;
}

int snakeModel::getFruitY() const
{
    return fruitY;
}

void snakeModel::setFruitY(int value)
{
    fruitY = value;
}

int snakeModel::getScore() const
{
    return score;
}

void snakeModel::setScore(int value)
{
    score = value;
}

int snakeModel::getNTail() const
{
    return nTail;
}

void snakeModel::setNTail(int value)
{
    nTail = value;
}

snakeModel::snakeModel()
{

}
