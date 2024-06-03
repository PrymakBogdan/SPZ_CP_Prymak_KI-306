#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QVector>
#include <windows.h>

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

     cConnection server;
     QTimer timerToSent;
     QVector<QString> listOfNames;
     QVector<QString> listOfWays;
     QStringList splitList;
     std::vector<PROCESS_INFORMATION> processes;
private slots:
    void startSending();
    void stopTimer();
    void setInfo();
    void updateList();

    void on_bAdd_clicked();

    bool saveFilePath(const QString& filePath, const QString& fileName);
    bool readFilePaths();
    bool deleteFilePath(const QString& targetPath, const QString& fileName);

    void startPrograms(const QStringList& programs);
    void stopPrograms();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
