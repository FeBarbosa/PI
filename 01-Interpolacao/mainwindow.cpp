#include "mainwindow.h"
#include "ui_mainwindow.h"

//QImage imagemOriginal;

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
    scene = new QGraphicsScene();

    dialog.exec();

    this->imagem = QImage(dialog.selectedFiles().first()); // Carrega a Imagem para a variável imagemOriginal

//    this->imagem = imagemOriginal;

    //this->imagem = imagemOriginal;
    //scene->setBackgroundBrush(QPixmap::fromImage(this->imagem).scaled(this->imagem.width(), this->imagem.height(), Qt::IgnoreAspectRatio));

    // QGraphicsPixmapItem item(QPixmap::fromImage(imagemOriginal));
    //scene->addItem(&item);

    QPixmap pixmap = QPixmap::fromImage(this->imagem);
    scene->addPixmap(pixmap);

    ui->imagem->setScene(scene);
}

void MainWindow::on_limpar_clicked()
{   
    this->imagem = QImage(ui->imagem->width(), ui->imagem->height(), QImage::Format_RGB32);
    this->imagem.fill(QColor(255, 255, 255));
    //ui->imagem->setScene(QPixmap::fromImage(this->imagem));
}

void MainWindow::on_aplicar_clicked()
{
    if(ui->vizinho->isChecked())
    {
        if (ui->ampliar->isChecked())// AMPLIAR A IMAGEM
        {

            interpolacao::vizinhoAmpliar(this->imagem);

        }
        else if ( ui->reduzir->isChecked()) // REDUZIR A IMAGEM
        {
            interpolacao::vizinhoReduzir(this->imagem);
        }
    }
    else if(ui->bilinear->isChecked())
    {
        if (ui->ampliar->isChecked())// AMPLIAR A IMAGEM
        {
            interpolacao::BilinearAmpliar(this->imagem);

        }
        else if ( ui->reduzir->isChecked()) // REDUZIR A IMAGEM
        {
            interpolacao::BilinearReduzir(this->imagem);
        }
    }

    QPixmap pixmap = QPixmap::fromImage(this->imagem);

    this->scene->clear();
    this->scene->addPixmap(pixmap);

    ui->imagem->setScene(this->scene);
}
