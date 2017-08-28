#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QImage>

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
    void on_CarregarImg_clicked();

    void on_LimparTela_clicked();

private:
    Ui::MainWindow *ui;
    QImage imagem;
};

#endif // MAINWINDOW_H
