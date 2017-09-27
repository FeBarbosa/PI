#include "intensidade.h"

intensidade::intensidade(){}

//Transformaçao Power Law para alteraçao da intensidade -------------------------------------
/*
    equaçao para transformaçao: s=cr^gama

    s: intensidade transformada do pixel, c: constante, r: intensidade do pixel, gama(γ): constante
*/
void intensidade::transformacaoPowerLaw(QImage &imagem, int &c, double &gama)
{
    double red,green,blue;
    QColor cor;

    for (int x = 0; x < imagem.width(); x++)
    {
        for (int y = 0; y < imagem.height(); y++)
        {
            cor = imagem.pixelColor(x, y);

            red = c * (std::pow((double (cor.red())/255), gama))*255; //red = s, s=cr^gama
            green = c * (std::pow((double (cor.green())/255), gama))*255;//green = s, s=cr^gama
            blue = c * (std::pow((double (cor.blue())/255),gama))*255;//blue = s, s=cr^gama
            cor = QColor(red, green,blue);
            imagem.setPixel(x, y,cor.rgb());
        }
    }
}

//------------------------------------------------------------------------------------------

//Conversao da imagem para niveis de cinza -------------------------------------------------
void intensidade::cinza(QImage &imagem)
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
