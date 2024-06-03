#include "mainwindow.h"
#include "TCPConnection.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onComboBoxShowPopup()
{
    ui->comboBox->addItems(splitList);
}

void MainWindow::on_bConnect_clicked()
{
    if (!clientSock.isSocketConnected(clientSock.socket))
    {



        clientSock.conClient();
        if (clientSock.conClToHost() == true)
        {
            QMessageBox *msgBox = new QMessageBox();
            msgBox->setText("wait a couple of seconds, if not connected, try to again");

            msgBox->show();

            //clientSock.sendStringToHost(clientName);

            if(!clientSock.socket->waitForDisconnected(5000))
            {
                ui->lConnectionState->setStyleSheet("QLabel { background-color : green; }");
                startTimer();
            }
            else clientSock.sockDisc();
        }

    }
}


void MainWindow::on_bStart_clicked()
{
    QString strToSend;
    if (!listToStart.empty())
    {
        strToSend = listToStart[0];
        for (int i=1; i < listToStart.size(); i++)
            strToSend = strToSend + "|" + listToStart[i];
        clientSock.sendStringToHost(strToSend);
        listToStart.clear();
        updateList();
    }

}

void MainWindow::startTimer()
{
    QObject::connect(&timer, &QTimer::timeout,this, &MainWindow::setInfo);
    timer.start(FIVE_SEC);
}

void MainWindow::stopTimer()
{
    timer.stop();
}

bool MainWindow::setInfo()
{
    if(clientSock.strDate != nullptr )
    {
        if(clientSock.isClientConnected(clientSock.socket))
        {
            //ui->comboBox->clear();
            splitList.clear();
            splitList = clientSock.strDate.split("|");

            //updateList();
            return true;
        }
        else
        {
            stopTimer();
            ui->lConnectionState->setStyleSheet("QLabel { background-color : red; }");
            return false;
        }
    }
    else
    {
        qDebug()<<"Empty strDate";
        return false;
    }
    return false;
}

void  MainWindow::updateList()
{
    QStandardItemModel* model = new QStandardItemModel();

    int rows = listToStart.size();
    int columns = 1;
    model->setRowCount(rows);
    model->setColumnCount(columns);
    model->setHorizontalHeaderItem(0,new QStandardItem("Name"));

    for (int row = 0; row < rows; ++row) {
        if (row < listToStart.size())
        {
            QStandardItem* item = new QStandardItem(listToStart[row]);
            item->setEditable(false);
            model->setItem(row, 0, item);
        }
        else
        {
            QStandardItem* item = new QStandardItem("");
            item->setEditable(false);
            model->setItem(row, 0, item);
        }
    }
    ui->tList->setModel(model);
}







void MainWindow::on_bUpdBox_clicked()
{
    ui->comboBox->clear();
    ui->comboBox->addItems(splitList);
}


void MainWindow::on_bAddAppToList_clicked()
{
    bool p = false;
    for(int i = 0; i<listToStart.size();i++)
        if (listToStart[i]==ui->comboBox->currentText())
            p = true;
    if (p == false)
    {
        listToStart.push_back(ui->comboBox->currentText());
        updateList();
    }
}


void MainWindow::on_bClear_clicked()
{
    listToStart.clear();
    updateList();
}
