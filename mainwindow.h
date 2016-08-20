#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"notafiscal.h"
#include<QMessageBox>
#include"ajuda.h"

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





    void on_proximo_clicked();

    void on_actionCalcular_triggered();

    void on_actionPular_dia_triggered();

    void on_actionConferir_Notas_triggered();

    void on_botaoSetaEsq_clicked();

    void on_botaoSetaDir_clicked();

    void on_Aplicar_clicked();

    void on_actionSomatorio_de_Re_triggered();

    void on_actionAjuda_triggered();

private:

    notaFiscal *nf[21];
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
