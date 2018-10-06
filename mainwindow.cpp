#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pChatTable = ui->widget;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAdd_triggered()
{
    m_pChatTable->AddItem(chatitem::left);
    m_pChatTable->ResizeView();
}

void MainWindow::on_actionAdd_right_triggered()
{
    m_pChatTable->AddItem(chatitem::right);
    m_pChatTable->ResizeView();
}
