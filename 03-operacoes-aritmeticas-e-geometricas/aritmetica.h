#ifndef ARITMETICA_H
#define ARITMETICA_H

#include <QImage>
#include <iostream>

class aritmetica
{
public:
    aritmetica();

    static void operacao(QImage &, QImage &, int);

private:
    static int aredonda(int);
};

#endif // ARITMETICA_H
