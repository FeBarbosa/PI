#include "interpolacao.h"

interpolacao::interpolacao(){}


//Interpolação por vizinho mais próximo para ampliação -------------------------------------
void interpolacao::vizinhoAmpliar(QImage &imagem)
{
    QImage AuxImagem = QImage(imagem.width()*2, imagem.height()*2, QImage::Format_RGB32);

    for (int x = 0; x < imagem.width(); x++)
    {
        for (int y = 0; y < imagem.height(); y++)
        {
            AuxImagem.setPixel( 2*x, 2*y, imagem.pixelColor(x,y).rgb() );
            AuxImagem.setPixel( 2*x+1, 2*y, imagem.pixelColor(x,y).rgb() );
            AuxImagem.setPixel( 2*x, 2*y+1, imagem.pixelColor(x,y).rgb() );
            AuxImagem.setPixel( 2*x+1, 2*y+1, imagem.pixelColor(x,y).rgb() );
        }
    }

    imagem = AuxImagem;
}
//------------------------------------------------------------------------------------------

// Interpolação por vizinho mais próximo para redução --------------------------------------
void interpolacao::vizinhoReduzir(QImage &imagem)
{
    QImage AuxImagem = QImage(imagem.width()/2, imagem.height()/2, QImage::Format_RGB32);

    for (int x = 0; x < imagem.width(); x = x+2)
    {
        for (int y = 0; y < imagem.height(); y = y+2)
        {
            AuxImagem.setPixel( x/2, y/2, imagem.pixelColor(x,y).rgb() );
        }
    }

    imagem = AuxImagem;
}

// Interpolação bilinear para ampliação ----------------------------------------------------
void interpolacao::BilinearAmpliar(QImage &imagem)
{
    QImage AuxImagem = QImage(imagem.width()*2, imagem.height()*2, QImage::Format_RGB32);
    QColor cor1, cor2, cor3, cor4, novacor;

    for (int x = 0; x < AuxImagem.width(); x++)
    {
        for (int y = 0; y < AuxImagem.height(); y++)
        {
            if(x == AuxImagem.width()-1 || y == AuxImagem.height()-1)
            {

            }
            else
            {
                if(x%2 == 0) // Linha par
                {
                    if(y%2 == 0) // Linha par e coluna par
                    {
                        AuxImagem.setPixel(x, y, imagem.pixelColor(x/2, y/2).rgb());
                    }
                    else
                    {
                        cor1 = imagem.pixelColor(x/2, (y-1)/2);
                        cor2 = imagem.pixelColor(x/2, (y+1)/2);
                        novacor = QColor((cor1.red()+cor2.red())/2, (cor1.green()+cor2.green())/2, (cor1.blue()+cor2.blue())/2);
                        AuxImagem.setPixel(x, y, novacor.rgb());
                    }
                }
                else // Linha ímpar
                {
                    if(y%2 == 0) // Linha par
                    {
                        cor1 = imagem.pixelColor((x-1)/2, y/2);
                        cor2 = imagem.pixelColor((x+1)/2, y/2);
                        novacor = QColor((cor1.red()+cor2.red())/2, (cor1.green()+cor2.green())/2, (cor1.blue()+cor2.blue())/2);
                        AuxImagem.setPixel(x, y, novacor.rgb());
                    }
                    else // Linha ímpar e coluna ímpar
                    {
                        cor1 = imagem.pixelColor((x-1)/2, (y-1)/2);
                        cor2 = imagem.pixelColor((x-1)/2, (y+1)/2);
                        cor3 = imagem.pixelColor((x+1)/2, (y-1)/2);
                        cor4 = imagem.pixelColor((x+1)/2, (y+1)/2);
                        novacor = QColor((cor1.red()+cor2.red()+cor3.red()+cor4.red())/4, (cor1.green()+cor2.green()+cor3.green()+cor4.green())/4, (cor1.blue()+cor2.blue()+cor3.blue()+cor4.blue())/4);
                        AuxImagem.setPixel(x, y, novacor.rgb());
                    }
                }

            }
        }
    }

    imagem = AuxImagem;
}
