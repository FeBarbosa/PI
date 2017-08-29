#include "mainwindow.h"
#include "ui_mainwindow.h"

QImage imagemOriginal;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_carregar_clicked()
{
    QFileDialog dialog;

    dialog.exec();

    imagemOriginal = QImage(dialog.selectedFiles().first()); // Carrega a Imagem para a variável imagemOriginal

    this->imagem = imagemOriginal;

    ui->imagem->setPixmap(QPixmap::fromImage(this->imagem));
}

void MainWindow::on_limpar_clicked()
{
    this->imagem = QImage(ui->imagem->width(), ui->imagem->height(), QImage::Format_RGB32);
    this->imagem.fill(QColor(255, 255, 255));
    ui->imagem->setPixmap(QPixmap::fromImage(this->imagem));
}

void MainWindow::on_aplicar_clicked()
{
    if ( ui->ampliar->isChecked() )
    {            // AMPLIAR A IMAGEM

        ampliar();

    }
    else if ( ui->reduzir->isChecked() )
    {     // REDUZIR A IMAGEM

        reduzir();

    }
}

void MainWindow::ampliar()
{
    QImage image;
    QColor pixel_cor;
    int width,height,EixoX,EixoY;
    width = this->imagem.width();
    height = this->imagem.height();
    image = QImage(ui->imagem->width()*2, ui->imagem->height()*2, QImage::Format_RGB32);

    if( ui->vizinho->isChecked() )
    {  // VIZINHO MAIS PROXIMO

        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                EixoX = (x*2);
                EixoY = (y*2);

                pixel_cor = this->imagem.pixelColor(x,y);
                image.setPixel( EixoX, EixoY, pixel_cor.rgb() );
                image.setPixel( EixoX+1, EixoY, pixel_cor.rgb() );
                image.setPixel( EixoX, EixoY+1, pixel_cor.rgb() );
                image.setPixel( EixoX+1, EixoY+1, pixel_cor.rgb() );
            }
        }
    }
    ui->imagem->setPixmap(QPixmap::fromImage(image));
    this->imagem = image;
}

void MainWindow::reduzir()
{

}
