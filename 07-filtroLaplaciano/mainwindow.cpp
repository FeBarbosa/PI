#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mascaraBox->addItem("Selecione");
    ui->mascaraBox->addItem("1");
    ui->mascaraBox->addItem("2");
    ui->mascaraBox->addItem("3");
    ui->mascaraBox->addItem("4");
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

    this->imagemOriginal = QImage(dialog.selectedFiles().first()); // Carrega a imagem para a variável imagemOriginal
    this->imagem = this->imagemOriginal; //faz uma copia da imagemOriginal para a variavel imagem
    QPixmap pixmap = QPixmap::fromImage(this->imagem);
    scene->addPixmap(pixmap);

    ui->imagem->setScene(scene);
}

void MainWindow::on_aplicar_clicked()
{
    int c1,c2,c3,c4,c5,c6,c7,c8,c9; //declaraçao dos valores da mascara do filtro laplaciano

    if((ui->mascaraBox->currentText())=="1")
    {
        c1=0; c2=1; c3=0; c4=1; c5=-4; c6=1; c7=0; c8=1; c9=0; //declaraçao da mascara do filtro laplaciano
        laplaciano::filtroLaplaciano(this->imagem,c1,c2,c3,c4,c5,c6,c7,c8,c9); //aplicaçao do filtro laplaciano na imagem
    }
    else if((ui->mascaraBox->currentText())=="2")
    {
        c1=1; c2=1; c3=1; c4=1; c5=-8; c6=1; c7=1; c8=1; c9=1; //declaraçao da mascara do filtro laplaciano
        laplaciano::filtroLaplaciano(this->imagem,c1,c2,c3,c4,c5,c6,c7,c8,c9); //aplicaçao do filtro laplaciano na imagem
    }
    else if((ui->mascaraBox->currentText())=="3")
    {
        c1=0; c2=-1; c3=0; c4=-1; c5=4; c6=-1; c7=0; c8=-1; c9=0; //declaraçao da mascara do filtro laplaciano
        laplaciano::filtroLaplaciano(this->imagem,c1,c2,c3,c4,c5,c6,c7,c8,c9); //aplicaçao do filtro laplaciano na imagem
    }
    else if((ui->mascaraBox->currentText())=="4")
    {
        c1=-1; c2=-1; c3=-1; c4=-1; c5=8; c6=-1; c7=-1; c8=-1; c9=-1; //declaraçao da mascara do filtro laplaciano
        laplaciano::filtroLaplaciano(this->imagem,c1,c2,c3,c4,c5,c6,c7,c8,c9); //aplicaçao do filtro laplaciano na imagem
    }

        QPixmap pixmap = QPixmap::fromImage(this->imagem);
        this->scene->clear();
        this->scene->addPixmap(pixmap);

        ui->imagem->setScene(this->scene);
}

void MainWindow::on_limpar_clicked()
{
    this->scene->clear();

    ui->imagem->setScene(this->scene);
}

void MainWindow::on_cinza_clicked()
{
    laplaciano::cinza(this->imagem); //cornversao da imagem para niveis de cinza

    QPixmap pixmap = QPixmap::fromImage(this->imagem);
    this->scene->clear();
    this->scene->addPixmap(pixmap);

    ui->imagem->setScene(this->scene);
}

void MainWindow::on_imgOriginal_clicked()
{
    this->imagem = this->imagemOriginal; // restaurar a imagem para a imagemOriginal

    QPixmap pixmap = QPixmap::fromImage(this->imagemOriginal);
    this->scene->clear();
    this->scene->addPixmap(pixmap);

    ui->imagem->setScene(this->scene);
}

void MainWindow::on_mascaraBox_activated(const QString)
{
    if((ui->mascaraBox->currentText())=="1")
    {
        QPixmap pix("/home/rosivania/Área de Trabalho/mascaras/mascara1.png");
        ui->mascara->setPixmap(pix);
    }
    else if((ui->mascaraBox->currentText())=="2")
    {
        QPixmap pix("/home/rosivania/Área de Trabalho/mascaras/mascara2.png");
        ui->mascara->setPixmap(pix);
    }
    else if((ui->mascaraBox->currentText())=="3")
    {
        QPixmap pix("/home/rosivania/Área de Trabalho/mascaras/mascara3.png");
        ui->mascara->setPixmap(pix);
    }
    else if((ui->mascaraBox->currentText())=="4")
    {
        QPixmap pix("/home/rosivania/Área de Trabalho/mascaras/mascara4.png");
        ui->mascara->setPixmap(pix);
    }
}
