#ifndef MEDIA_H
#define MEDIA_H

#include <QImage>
#include<math.h>
#include <string>

class media
{
public:
    media();

    static void filtroMedia(QImage&); //aplica o filtro da media na imagem com uma mascara de 3x3 (vizinhança 3x3)
    static void cinza(QImage&); //converte a imagem para niveis de cinza
};

#endif // MEDIA_H
