#include "geometrica.h"

geometrica::geometrica(){}


//-------------------------------------------------------------------------------------------------
/**
    tipo = true -> espelhamento horizontal
    tipo = false -> espelhamento vertical
*/
//Faz o espelhamento (horizontal ou vertical) da imagem
void geometrica::espelhamento(QImage &imagem, bool tipo)
{
    QImage AuxImagem = QImage(imagem.width(), imagem.height(), QImage::Format_RGB32);
    int espelhaHorizontal = 0, espelhaVertical = 0;

    // Define o tipo de espelhamento (horizontal ou vertical)
    if(tipo)
        espelhaHorizontal = imagem.width() -1;
    else
        espelhaVertical = imagem.height() -1;


    for(int i = 0; i < imagem.width(); i++)
        for(int j = 0; j < imagem.height(); j++)
            AuxImagem.setPixel(i, j, imagem.pixelColor(abs(espelhaHorizontal - i), abs(espelhaVertical - j)).rgb());

    imagem = AuxImagem;
}
