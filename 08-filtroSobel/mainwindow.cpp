#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mascaraBox->addItem("Selecione");
    ui->mascaraBox->addItem("Horizontal");
    ui->mascaraBox->addItem("Vertical");
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

void MainWindow::on_limpar_clicked()
{
    this->scene->clear();

    ui->imagem->setScene(this->scene);
}

void MainWindow::on_cinza_clicked()
{
    sobel::cinza(this->imagem); //cornversao da imagem para niveis de cinza

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
    if((ui->mascaraBox->currentText())=="Horizontal")
    {
        QPixmap pix("/home/rosivania/Área de Trabalho/mascaras/horizontal.png");
        ui->mascara->setPixmap(pix);
    }
    else if((ui->mascaraBox->currentText())=="Vertical")
    {
        QPixmap pix("/home/rosivania/Área de Trabalho/mascaras/vertical.png");
        ui->mascara->setPixmap(pix);
    }
}

void MainWindow::on_aplicar_clicked()
{
    if((ui->mascaraBox->currentText())=="Horizontal")
        {
            sobel::sobelHorizontal(this->imagem); //aplicaçao do filtro sobel na imagem
        }
        else if((ui->mascaraBox->currentText())=="Vertical")
        {
            sobel::sobelVertical(this->imagem); //aplicaçao do filtro sobel na imagem
        }

            QPixmap pixmap = QPixmap::fromImage(this->imagem);
            this->scene->clear();
            this->scene->addPixmap(pixmap);

            ui->imagem->setScene(this->scene);
}
