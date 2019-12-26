#ifndef SNAKEMODEL_H
#define SNAKEMODEL_H

class snakeModel
{
    bool gameOver;
    int const Width = 20;
    int const hight = 20;
    int x;
    int y;
    int fruitX;
    int fruitY;
    int score;
    int nTail = 0;

public:
    snakeModel();
    bool getGameOver() const;
    void setGameOver(bool value);
    int getWidth() const;
    int getHight() const;
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    int getFruitX() const;
    void setFruitX(int value);
    int getFruitY() const;
    void setFruitY(int value);
    int getScore() const;
    void setScore(int value);
    int getNTail() const;
    void setNTail(int value);
};



#endif // SNAKEMODEL_H
