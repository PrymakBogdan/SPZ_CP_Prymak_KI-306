#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QMessageBox>
#include <QTimer>
#include <QStandardItemModel>
#include <QTextStream>
#include <QString>
#include <QVector>
#include <QWidget>
#include <QVBoxLayout>
#include <QComboBox>

#include "TCPConnection.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    cConnection clientSock;
    QTimer timer;
    QStringList splitList;

    QStringList listToStart;

private slots:
    void startTimer();
    void stopTimer();
    bool setInfo();
    void on_bConnect_clicked();

    void on_bStart_clicked();

    void updateList();
    void onComboBoxShowPopup();
    void on_bUpdBox_clicked();

    void on_bAddAppToList_clicked();

    void on_bClear_clicked();

private:
    Ui::MainWindow *ui;
};






#endif // MAINWINDOW_H
