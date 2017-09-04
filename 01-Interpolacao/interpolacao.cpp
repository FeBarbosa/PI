#include "interpolacao.h"

interpolacao::interpolacao(){}

void interpolacao::vizinhoAmpliar(QImage &imagem)
{
    QColor pixel_cor;
    int EixoX,EixoY;
    QImage AuxImagem = QImage(imagem.width()*2, imagem.height()*2, QImage::Format_RGB32);

    for (int x = 0; x < imagem.width(); x++)
    {
        for (int y = 0; y < imagem.height(); y++)
        {
            EixoX = (x*2);
            EixoY = (y*2);

            pixel_cor = imagem.pixelColor(x,y);
            AuxImagem.setPixel( EixoX, EixoY, pixel_cor.rgb() );
            AuxImagem.setPixel( EixoX+1, EixoY, pixel_cor.rgb() );
            AuxImagem.setPixel( EixoX, EixoY+1, pixel_cor.rgb() );
            AuxImagem.setPixel( EixoX+1, EixoY+1, pixel_cor.rgb() );
        }
    }

    imagem = AuxImagem;
}

void interpolacao::vizinhoReduzir(QImage &imagem)
{
    QColor pixel_cor;
    int EixoX,EixoY;
    QImage AuxImagem = QImage(imagem.width()/2, imagem.height()/2, QImage::Format_RGB32);

    for (int x = 0; x < imagem.width(); x = x+2)
    {
        for (int y = 0; y < imagem.height(); y = y+2)
        {
            EixoX = (x/2);
            EixoY = (y/2);

            pixel_cor = imagem.pixelColor(x,y);
            AuxImagem.setPixel( EixoX, EixoY, pixel_cor.rgb() );
        }
    }

    imagem = AuxImagem;
}
