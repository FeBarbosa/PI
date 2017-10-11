#ifndef SOBEL_H
#define SOBEL_H

#include <QImage>
#include<math.h>
#include <string>

class sobel
{
public:
    sobel();

    static void sobelHorizontal(QImage&);
    static void sobelVertical(QImage&);
    static void cinza(QImage&);
    static int arredonda(int);
};
#endif // SOBEL_H
