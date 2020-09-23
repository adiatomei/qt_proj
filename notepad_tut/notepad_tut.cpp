#include "notepad_tut.h"
#include "ui_notepad_tut.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>


Notepad_tut::Notepad_tut(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad_tut)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

Notepad_tut::~Notepad_tut()
{
    delete ui;
}


void Notepad_tut::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString());
}

void Notepad_tut::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open file");
    QFile file(filename);
    currentFile = filename;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
        return;
    }
    setWindowTitle(filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();

}

void Notepad_tut::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();

}

void Notepad_tut::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer Name");
    QPrintDialog pDialog(&printer, this);
    if(pDialog.exec() == QDialog::Rejected){
        QMessageBox::warning(this, "Warning", "Cannot Acces printer");
        return;
    }
    ui->textEdit->print(&printer);

}

void Notepad_tut::on_actionExit_triggered()
{
    QApplication::quit();

}

void Notepad_tut::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void Notepad_tut::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void Notepad_tut::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void Notepad_tut::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}
