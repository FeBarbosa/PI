#include "sobel.h"

sobel::sobel(){}

//-------------------------------------------------------------------------------------------------
// Trata situações onde o valor do canal está com valor menor que 0 ou maior que 255
int sobel::arredonda(int canal)
{
    if(canal < 0)
        canal = 0;
    else if(canal > 255)
        canal = 255;

    return canal;
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
void sobel::sobelHorizontal(QImage &imagem)
{
    int red,green,blue;
    QColor cor1,cor2,cor3,cor4,cor5,cor6,novacor;
    QImage imagemAux=imagem;

    for (int x = 1; x < imagem.width()-1; x++)
    {
        for (int y = 1; y < imagem.height()-1; y++)
        {
            //horizontal
            cor1 = imagemAux.pixelColor(x-1, y-1);
            cor2 = imagemAux.pixelColor(x-1, y);
            cor3 = imagemAux.pixelColor(x-1, y+1);
            cor4 = imagemAux.pixelColor(x+1, y-1);
            cor5 = imagemAux.pixelColor(x+1, y);
            cor6 = imagemAux.pixelColor(x+1, y+1);


            red = ((-1*cor1.red())+(-2*cor2.red())+(-1*cor3.red())+(1*cor4.red())+(2*cor5.red())+(1*cor6.red()));

            green = ((-1*cor1.green())+(-2*cor2.green())+(-1*cor3.green())+(1*cor4.green())+(2*cor5.green())+(1*cor6.green()));

            blue = ((-1*cor1.blue())+(-2*cor2.blue())+(-1*cor3.blue())+(1*cor4.blue())+(2*cor5.blue())+(1*cor6.blue()));

            novacor = QColor(arredonda(red),arredonda(green),arredonda(blue));
            imagem.setPixel(x, y, novacor.rgb());
        }
    }
}

//-------------------------------------------------------------------------------------------------
void sobel::sobelVertical(QImage &imagem)
{
    int red,green,blue;
    QColor cor1,cor2,cor3,cor4,cor5,cor6,novacor;
    QImage imagemAux=imagem;

    for (int x = 1; x < imagem.width()-1; x++)
    {
        for (int y = 1; y < imagem.height()-1; y++)
        {
            //vertical
            cor1 = imagemAux.pixelColor(x-1, y-1);
            cor2 = imagemAux.pixelColor(x, y-1);
            cor3 = imagemAux.pixelColor(x+1, y-1);
            cor4 = imagemAux.pixelColor(x-1, y+1);
            cor5 = imagemAux.pixelColor(x, y+1);
            cor6 = imagemAux.pixelColor(x+1, y+1);


            red = ((-1*cor1.red())+(-2*cor2.red())+(-1*cor3.red())+(1*cor4.red())+(2*cor5.red())+(1*cor6.red()));

            green = ((-1*cor1.green())+(-2*cor2.green())+(-1*cor3.green())+(1*cor4.green())+(2*cor5.green())+(1*cor6.green()));

            blue = ((-1*cor1.blue())+(-2*cor2.blue())+(-1*cor3.blue())+(1*cor4.blue())+(2*cor5.blue())+(1*cor6.blue()));

            novacor = QColor(arredonda(red),arredonda(green),arredonda(blue));
            imagem.setPixel(x, y, novacor.rgb());
        }
    }
}

//Conversao da imagem para niveis de cinza -------------------------------------------------
void sobel::cinza(QImage &imagem)
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
