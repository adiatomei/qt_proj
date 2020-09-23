#ifndef NOTEPAD_TUT_H
#define NOTEPAD_TUT_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Notepad_tut; }
QT_END_NAMESPACE

class Notepad_tut : public QMainWindow
{
    Q_OBJECT

public:
    Notepad_tut(QWidget *parent = nullptr);
    ~Notepad_tut();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

private:
    Ui::Notepad_tut *ui;
    QString currentFile = "";
};
#endif // NOTEPAD_TUT_H
