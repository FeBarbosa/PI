#include "aritmetica.h"

aritmetica::aritmetica()
{

}

//-------------------------------------------------------------------------------------------------
// Trata situações onde o valor do canal está com valor menor que 0 ou maior que 255
int aritmetica::aredonda(int canal)
{
    if(canal < 0)
        canal = 0;
    else if(canal > 255)
        canal = 255;

    return canal;
}

//-------------------------------------------------------------------------------------------------
/**
  OBS: fator representa o fator da operação
    fator = 1 -> soma
    fator = -1 -> subtração
*/
//Aplica uma a operação de soma ou a operação de subtração entre as imagens dependendo do tipo (fator)
void aritmetica::operacao(QImage &imagem1, QImage &imagem2, int fator)
{
    QColor novaCor, cor1, cor2;
    int canalR, canalG, canalB;

    for(int i = 0; i < imagem1.width() && i < imagem2.width(); i++)
        for(int j = 0; j < imagem1.height() && j < imagem2.height(); j++)
        {
            //Armazena as cores dos pixels correspondes de cada imagem
            cor1.setRgb(imagem1.pixelColor(i,j).rgb());
            cor2.setRgb(imagem2.pixelColor(i,j).rgb());

            std::cout << cor1.red() << std::endl;

            //Faz o cálculo da operação para cada canal RGB
            canalR = aredonda(cor1.red() + fator*cor2.red());
            canalG = aredonda(cor1.green() + fator*cor2.green());
            canalB = aredonda(cor1.blue() + fator*cor2.blue());

            std::cout << canalR << std::endl << std::endl;

            //Define a novaCor
            novaCor.setRgb(canalR, canalG, canalB);

            //Define o pixel com a nova cor
            imagem1.setPixelColor(i, j, novaCor);
        }
}
