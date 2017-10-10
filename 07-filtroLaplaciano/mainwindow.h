#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QFile>
#include <QGraphicsItem>
#include <QPixmap>
#include "laplaciano.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_carregar_clicked();

    void on_limpar_clicked();

    void on_cinza_clicked();

    void on_imgOriginal_clicked();

    void on_aplicar_clicked();

    void on_mascaraBox_activated(const QString);

private:
    Ui::MainWindow *ui;

public:
    QImage imagem, imagemOriginal;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
