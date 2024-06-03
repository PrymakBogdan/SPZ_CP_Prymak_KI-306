#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    readFilePaths();

    server.startServer();
    startSending();
    ui->setupUi(this);
    updateList();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bAdd_clicked()
{
    //перевірити чи не пусті поля
    if(!ui->lineWay->text().isEmpty() && !ui->lineName->text().isEmpty())
    {
        saveFilePath(ui->lineWay->text() ,ui->lineName->text());
        readFilePaths();
        updateList();
        ui->lineWay->clear();
        ui->lineName->clear();
    }
}



void MainWindow::setInfo()
{
    splitList.clear();
    if(server.strDate != nullptr )
    {
        splitList = server.strDate.split("|");

        QStringList listStartPrograms;
        for(int i=0;i<splitList.size();i++)
        {
            for(int j = 0; j < listOfNames.size(); j++)
            {
                if(splitList[i]==listOfNames[j])
                {
                    listStartPrograms.push_back(listOfWays[j]);
                    break;
                }
            }
        }
        startPrograms(listStartPrograms);
        server.strDate = nullptr;
    }


    QString strToSend = listOfNames[0];
    for (int i = 1; i < listOfNames.size(); i++)
    {
        strToSend = strToSend + "|" + listOfNames[i];
    }
    qDebug()<<strToSend;
    server.SendToAllClients(strToSend);
}

void MainWindow::startSending()
{
    QObject::connect(&timerToSent, &QTimer::timeout,this, &MainWindow::setInfo);

    timerToSent.start(FIVE_SEC);
}

void MainWindow::stopTimer()
{
    timerToSent.stop();
}

//==================================================


bool MainWindow::saveFilePath(const QString& filePath, const QString& fileName) {
    QFile fileWay("listWay.txt");
    QFile fileNames("listName.txt");

    if (!fileWay.open(QIODevice::Append | QIODevice::Text)) {
        return false;
    }
    if (!fileNames.open(QIODevice::Append | QIODevice::Text)) {
        return false;
    }

    QTextStream out(&fileWay);
    QString newPath = filePath;
    newPath.replace("\\","\\\\");
    out << newPath << "\n";
    fileWay.close();

    QTextStream out2(&fileNames);
    out2 << fileName << "\n";
    fileNames.close();

    return true;
}

bool MainWindow::readFilePaths() {
    //QVector<QString> filePaths;
    listOfWays.clear();
    listOfNames.clear();
    QFile fileWay("listWay.txt");
    QFile fileNames("listName.txt");

    if (!fileWay.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }
    if (!fileNames.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream in(&fileWay);
    while (!in.atEnd()) {
        QString line = in.readLine();
        listOfWays.append(line);
    }

    QTextStream in2(&fileNames);
    while (!in2.atEnd()) {
        QString line = in2.readLine();
        listOfNames.append(line);
    }

    fileWay.close();
    fileNames.close();
    return true;
}

bool MainWindow::deleteFilePath(const QString& targetPath, const QString& fileName) {
    QVector<QString> filePaths;
    QFile file("listWay.txt");
    qDebug()<<fileName;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line != targetPath) {
            filePaths.append(line);
        }
    }
    file.close();

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        return false;
    }
    QTextStream out(&file);
    for (const QString& path : filePaths) {
        out << path <<"\n";
    }
    file.close();
    return true;
}

//===================================================

void  MainWindow::updateList()
{
    QStandardItemModel* model = new QStandardItemModel();

    int rows = listOfNames.size();
    int columns = 2;
    model->setRowCount(rows);
    model->setColumnCount(columns);
    model->setHorizontalHeaderItem(0,new QStandardItem("Path"));
    model->setHorizontalHeaderItem(1,new QStandardItem("Name"));

    for (int row = 0; row < rows; ++row) {
        if (row < listOfWays.size())
        {
            QStandardItem* item = new QStandardItem(listOfWays[row]);
            item->setEditable(false);
            model->setItem(row, 0, item);
        }
        else
        {
            QStandardItem* item = new QStandardItem("");
            item->setEditable(false);
            model->setItem(row, 0, item);
        }

        if (row < listOfNames.size())
        {
            model->setItem(row, 1, new QStandardItem(listOfNames[row]));
        }
        else
        {
            QStandardItem* item = new QStandardItem("");
            item->setEditable(false);
            model->setItem(row, 1, item);
        }
    }
    ui->tList->setModel(model);
}


void MainWindow::startPrograms(const QStringList& programs)
{
    stopPrograms();
    for (const auto& program : programs) {
            STARTUPINFOW si;
            PROCESS_INFORMATION pi;

            ZeroMemory(&si, sizeof(si));
            si.cb = sizeof(si);
            ZeroMemory(&pi, sizeof(pi));

            std::wstring wProgram = program.toStdWString();

            if (!CreateProcessW(NULL,   // ім'я модуля (необов'язкове)
                                &wProgram[0],  // командний рядок
                                NULL,          // дескриптор процесу (необов'язковий)
                                NULL,          // дескриптор потоку (необов'язковий)
                                FALSE,         // наслідування дескрипторів
                                0,             // створення прапорів
                                NULL,          // середовище (необов'язкове)
                                NULL,          // робочий каталог (необов'язковий)
                                &si,           // інформація про запуск
                                &pi)           // інформація про процес
                ) {
                qCritical() << "CreateProcessW failed for" << program << ". Error:" << GetLastError();
            } else {
                processes.push_back(pi);
            }
        }
}

void MainWindow::stopPrograms()
{
    for (auto& pi : processes) {
        if (pi.hProcess != NULL) {
            TerminateProcess(pi.hProcess, 0);
            CloseHandle(pi.hProcess);
        }
        if (pi.hThread != NULL) {
            CloseHandle(pi.hThread);
        }
    }
    processes.clear();
}
