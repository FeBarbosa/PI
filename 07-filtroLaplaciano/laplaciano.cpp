#include "laplaciano.h"

laplaciano::laplaciano(){}

//-------------------------------------------------------------------------------------------------
// Trata situações onde o valor do canal está com valor menor que 0 ou maior que 255
int laplaciano::arredonda(int canal)
{
    if(canal < 0)
        canal = 0;
    else if(canal > 255)
        canal = 255;

    return canal;
}

//-------------------------------------------------------------------------------------------------
void laplaciano::filtroLaplaciano(QImage &imagem, int &c1, int &c2, int &c3, int &c4, int &c5, int &c6, int &c7, int &c8, int &c9)
{
    int red,green,blue;
    QColor cor1,cor2,cor3,cor4,cor5,cor6,cor7,cor8,cor9,novacor;
    QImage imagemAux=imagem;

    for (int x = 1; x < imagem.width()-1; x++)
    {
        for (int y = 1; y < imagem.height()-1; y++)
        {
            cor1 = imagemAux.pixelColor(x-1, y-1);
            cor2 = imagemAux.pixelColor(x-1, y);
            cor3 = imagemAux.pixelColor(x-1, y+1);
            cor4 = imagemAux.pixelColor(x, y-1);
            cor5 = imagemAux.pixelColor(x, y);
            cor6 = imagemAux.pixelColor(x, y+1);
            cor7 = imagemAux.pixelColor(x+1, y-1);
            cor8 = imagemAux.pixelColor(x+1, y);
            cor9 = imagemAux.pixelColor(x+1, y+1);

            /*
                cada canal recebe a media dos valores da vizinhança 3x3
                multiplicados pela mascara do filtro laplaciano.
            */
            red = ((c1*cor1.red())+(c2*cor2.red())+(c3*cor3.red())+(c4*cor4.red())+(c5*cor5.red())+(c6*cor6.red())+(c7*cor7.red())+(c8*cor8.red())+(c9*cor9.red()))/9;

            green = ((c1*cor1.green())+(c2*cor2.green())+(c3*cor3.green())+(c4*cor4.green())+(c5*cor5.green())+(c6*cor6.green())+(c7*cor7.green())+(c8*cor8.green())+(c9*cor9.green()))/9;

            blue = ((c1*cor1.blue())+(c2*cor2.blue())+(c3*cor3.blue())+(c4*cor4.blue())+(c5*cor5.blue())+(c6*cor6.blue())+(c7*cor7.blue())+(c8*cor8.blue())+(c9*cor9.blue()))/9;

            //o pixel central da vizinhança recebe a media dos valores da vizinhança 3x3 multiplicados pela mascara do filtro laplaciano
            novacor = QColor(arredonda(red),arredonda(green),arredonda(blue));
            imagem.setPixel(x, y, novacor.rgb());
        }
    }
}

//Conversao da imagem para niveis de cinza -------------------------------------------------
void laplaciano::cinza(QImage &imagem)
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



