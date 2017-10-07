#include "media.h"

media::media(){}

//Suavizaçao da imagem com a aplicaçao do filtro da media----------------------------------
/*
     filtroMedia suaviza a imagem atraves da aplicaçao do filtro da media na imagem,
     com uma mascara de 3x3 (vizinhança 3x3).

     O tratamento da borda e feito atraves da replicaçao dos pixels das bordas da imagem.
 */
void media::filtroMedia(QImage &imagem)
{
    double red,green,blue;
    QColor cor1,cor2,cor3,cor4,cor5,cor6,cor7,cor8,cor9,novacor;
    QImage imagemAux=imagem;

    for (int x = 1; x < imagem.width()-1; x++)
    {
        for (int y = 1; y < imagem.height()-1; y++)
        {
            cor1 = imagemAux.pixelColor(x-1, y-1);
            cor2 = imagemAux.pixelColor(x, y-1);
            cor3 = imagemAux.pixelColor(x+1, y-1);
            cor4 = imagemAux.pixelColor(x-1, y);
            cor5 = imagemAux.pixelColor(x, y);
            cor6 = imagemAux.pixelColor(x+1, y);
            cor7 = imagemAux.pixelColor(x-1, y+1);
            cor8 = imagemAux.pixelColor(x, y+1);
            cor9 = imagemAux.pixelColor(x+1, y+1);

            //media das cores da vizinhança 3x3 da imagem
            red = std::round((cor1.red()+cor2.red()+cor3.red()+cor4.red()+cor5.red()+cor6.red()+cor7.red()+cor8.red()+cor9.red())/9.0);
            green = std::round((cor1.green()+cor2.green()+cor3.green()+cor4.green()+cor5.green()+cor6.green()+cor7.green()+cor8.green()+cor9.green())/9.0);
            blue = std::round((cor1.blue()+cor2.blue()+cor3.blue()+cor4.blue()+cor5.blue()+cor6.blue()+cor7.blue()+cor8.blue()+cor9.blue())/9.0);

            //o pixel central da vizinhança recebe a media das cores da vizinhança 3x3
            novacor = QColor(red,green,blue);
            imagem.setPixel(x, y, novacor.rgb());
        }
    }
}
//------------------------------------------------------------------------------------------

//Conversao da imagem para niveis de cinza -------------------------------------------------
void media::cinza(QImage &imagem)
{
    int r,g,b,cinza;
    QColor pixel;

    for (int x = 0; x < imagem.width(); x++) {
        for (int y = 0; y < imagem.height(); y++) {
            pixel = imagem.pixelColor(x,y);
            r = pixel.red();
            g = pixel.green();
            b = pixel.blue();
            cinza = (r+g+b)/3;
            imagem.setPixel(x,y,QColor(cinza,cinza,cinza).rgb());
        }
    }
}
//------------------------------------------------------------------------------------------
