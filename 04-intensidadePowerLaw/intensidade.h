#ifndef INTENSIDADE_H
#define INTENSIDADE_H

#include <QImage>
#include<math.h>
#include <string>

class intensidade
{
public:
    intensidade();

    static void transformacaoPowerLaw(QImage&,int&,double&); //transformaçao power law, entrada: imagem,constante c e cosntante gama
    static void cinza(QImage&);
};

#endif // INTENSIDADE_H
