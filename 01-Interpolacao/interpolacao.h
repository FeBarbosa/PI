#ifndef INTERPOLACAO_H
#define INTERPOLACAO_H

#include <QImage>

class interpolacao
{
public:
    interpolacao();

    static void vizinhoAmpliar(QImage&);
    static void vizinhoReduzir(QImage&);
};

#endif // INTERPOLACAO_H
