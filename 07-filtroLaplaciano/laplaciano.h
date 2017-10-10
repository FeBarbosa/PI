#ifndef LAPLACIANO_H
#define LAPLACIANO_H

#include <QImage>
#include<math.h>
#include <string>

class laplaciano
{
public:
    laplaciano();

    static void filtroLaplaciano(QImage&,int&,int&,int&,int&,int&,int&,int&,int&,int&); //
    static void cinza(QImage&);
    static int arredonda(int);
};

#endif // LAPLACIANO_H
