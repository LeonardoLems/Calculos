#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDate>

int contador = 0;
int cont = 0;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lcdNumber->display(1);
    ui->labelCont->close();
    ui->label_Coringa->close();

    ui->line->close();

    QDate *data = new QDate();
    *data = data->currentDate();
    ui->Aplicar->close();
    ui->botaoSetaDir->close();
    ui->botaoSetaEsq->close();
    ui->labelDat->setText(data->toString("d ' de ' MMMM yyyy"));

    for(int con = 0;con <= 20;con ++ )
    {
        nf[con] = new notaFiscal();
    }


}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_proximo_clicked()
{
  if(contador < 20)
  {
    nf[contador]->setCnpj(ui->lineEdit->text().toInt(NULL));
    nf[contador]->setDia(ui->lineEdit_2->text().toInt(NULL));
    nf[contador]->setValor(ui->lineEdit_3->text().toDouble(NULL));
    nf[contador]->setNumero(ui->lineEdit_4->text().toLongLong(NULL));
    if(ui->lineEdit_2->text().toInt(NULL) != 0)
    {
        contador++;
    }
  }
  else
  {
      QMessageBox::critical(this,"Atenção","<b><center> O limite de notas foi atingido!</b</center><br>Por favor entre  em contato com seu administrador");
  }

  ui->lineEdit->setText(" ");
  ui->lineEdit_2->setText(" ");
  ui->lineEdit_3->setText(" ");
  ui->lineEdit_4->setText(" ");

  ui->lcdNumber->display(contador+1);
}

void MainWindow::on_actionCalcular_triggered()
{
    int somaCnpj = 0,
        somaDia = 0;
    double somaValor = 0;
    long long somaNum = 0;



    for(int contt = 0; contt <= contador; contt ++)
    {
        somaCnpj += nf[contt]->getCnpj();
        somaDia += nf[contt]->getDia();
        somaValor += nf[contt]->getValor();
        somaNum += nf[contt]->getNumero();
    }
    ui->lineEdit->setText(QString::number(somaCnpj));
    ui->lineEdit_2->setText(QString::number(somaDia));
    ui->lineEdit_3->setText(QString::number(somaValor));
    ui->lineEdit_4->setText(QString::number(somaNum));




    ui->label->setText("Somatório de CNPJ/CPF");
    ui->label_2->setText("Somatótio dos dias em.");
    ui->label_3->setText("Somatótio dos Valores");
    ui->label_4->setText("Somatótio dos Numeros");

    ui->proximo->close();
    ui->labelContNf->setText("Total de Notas calculadas");
    ui->lcdNumber->display(contador);
    ui->label_Coringa->setText("<b><u><font color =blue>As notas foram<br> somadas.</b></br></u></font color>");
    ui->label_Coringa->show();
    ui->line->show();
    ui->line_4->close();
    ui->labelTiInf->close();
    ui->labelInfo->close();
    ui->Aplicar->close();
    ui->labelCont->close();
    ui->botaoSetaDir->close();
    ui->botaoSetaEsq->close();

    ui->actionCalcular->setDisabled(true);
}

void MainWindow::on_actionPular_dia_triggered()
{
    QMessageBox msgBox(
                QMessageBox::Question,
                tr("Confirmação"),tr("<center><b>Tem certeza que deseja iniciar um novo calculo?</center><br>Ao clicar em sim perderá todos os dados Adicionados anteriormente."),
                QMessageBox::Yes | QMessageBox::No);

    msgBox.setButtonText(QMessageBox::Yes, tr("Sim"));
    msgBox.setButtonText(QMessageBox::No, tr("Não"));
    msgBox.setIcon(QMessageBox::Information);

 if (msgBox.exec() == QMessageBox::Yes)
 {

    contador = cont= 0;

    for(int cont = 0 ; cont <= 20 ; cont++)
    {
        nf[cont]->defaultNotas(true);
    }
    ui->lcdNumber->display(1);

    ui->lineEdit->setText(" ");
    ui->lineEdit_2->setText(" ");
    ui->lineEdit_3->setText(" ");
    ui->lineEdit_4->setText(" ");

    ui->proximo->show();
    ui->labelContNf->setText("   Notas Fiscais");
    ui->labelContNf->show();
    ui->lcdNumber->show();
    ui->botaoSetaEsq->close();
    ui->botaoSetaDir->close();
    ui->label_Coringa->close();
    ui->line->close();
    ui->line_4->show();
    ui->Aplicar->close();
    ui->labelCont->close();
    ui->labelTiInf->show();
    ui->labelInfo->show();
    ui->actionCalcular->setEnabled(true);

 }
}

void MainWindow::on_actionConferir_Notas_triggered()
{
    ui->proximo->close();
    ui->labelContNf->close();
    ui->lcdNumber->close();
    ui->label_Coringa->setText("<font color = blue><b><center>Conferencia<br> de <br>Notas</font color></u></b>");
    ui->label_Coringa->show();
    ui->line->close();
    ui->labelCont->setText(QString::number(cont+1)+"de"+QString::number(contador));
    ui->labelCont->show();
    ui->line->show();
    ui->botaoSetaEsq->show();
    ui->botaoSetaDir->show();
    ui->line_4->close();
    ui->labelTiInf->close();
    ui->labelInfo->close();
    ui->Aplicar->show();
    ui->actionCalcular->setEnabled(true);

    ui->lineEdit->setText(QString::number(nf[cont]->getCnpj()));
    ui->lineEdit_2->setText(QString::number(nf[cont]->getDia()));
    ui->lineEdit_3->setText(QString::number(nf[cont]->getValor()));
    ui->lineEdit_4->setText(QString::number(nf[cont]->getNumero()));



}

void MainWindow::on_botaoSetaEsq_clicked()
{
    if(cont >= 1)
    {
        cont--;
        ui->lineEdit->setText(QString::number(nf[cont]->getCnpj()));
        ui->lineEdit_2->setText(QString::number(nf[cont]->getDia()));
        ui->lineEdit_3->setText(QString::number(nf[cont]->getValor()));
        ui->lineEdit_4->setText(QString::number(nf[cont]->getNumero()));
        ui->labelCont->setText(QString::number(cont+1)+"de"+QString::number(contador));


    }
}

void MainWindow::on_botaoSetaDir_clicked()
{
    if(cont < contador-1)
    {
        cont++;
        ui->lineEdit->setText(QString::number(nf[cont]->getCnpj()));
        ui->lineEdit_2->setText(QString::number(nf[cont]->getDia()));
        ui->lineEdit_3->setText(QString::number(nf[cont]->getValor()));
        ui->lineEdit_4->setText(QString::number(nf[cont]->getNumero()));
        ui->labelCont->setText(QString::number(cont+1)+"de"+QString::number(contador));



    }


}

void MainWindow::on_Aplicar_clicked()
{
    QMessageBox msgBox(
                QMessageBox::Question,
                tr("Aplicar edição?"),tr("Ao clicar em sim ,o conteúdo editado será aplicado!"),
                QMessageBox::Yes | QMessageBox::No);

    msgBox.setButtonText(QMessageBox::Yes, tr("Sim"));
    msgBox.setButtonText(QMessageBox::No, tr("Não"));

 if (msgBox.exec() == QMessageBox::Yes)
 {
    nf[cont]->setCnpj(ui->lineEdit->text().toInt(NULL));
    nf[cont]->setDia(ui->lineEdit_2->text().toInt(NULL));
    nf[cont]->setValor(ui->lineEdit_3->text().toDouble(NULL));
    nf[cont]->setNumero(ui->lineEdit_4->text().toLongLong(NULL));



 }
}

void MainWindow::on_actionSomatorio_de_Re_triggered()
{
    ui->lcdNumber->display(contador);

    ui->lineEdit->setText(" ");
    ui->lineEdit_2->setText(" ");
    ui->lineEdit_3->setText(" ");
    ui->lineEdit_4->setText(" ");

    ui->proximo->show();
    ui->labelContNf->setText("   Notas Fiscais");
    ui->labelContNf->show();
    ui->lcdNumber->show();
    ui->botaoSetaEsq->close();
    ui->botaoSetaDir->close();
    ui->label_Coringa->close();
    ui->line->close();
    ui->line_4->show();
    ui->Aplicar->close();
    ui->labelCont->close();
    ui->labelTiInf->show();
    ui->labelInfo->show();
    ui->actionCalcular->setEnabled(true);
}

void MainWindow::on_actionAjuda_triggered()
{
    Ajuda *open = new Ajuda(this);
    open->exec();
}
