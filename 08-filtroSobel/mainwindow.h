#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QFile>
#include <QGraphicsItem>
#include <QPixmap>
#include "sobel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
public:
    QImage imagem, imagemOriginal;
    QGraphicsScene *scene;
private slots:
    void on_carregar_clicked();
    void on_limpar_clicked();
    void on_cinza_clicked();
    void on_imgOriginal_clicked();
    void on_mascaraBox_activated(const QString);
    void on_aplicar_clicked();
};

#endif // MAINWINDOW_H
