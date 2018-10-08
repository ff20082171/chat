#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

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
	ItemData data;
	data.dfTime = QDateTime::currentMSecsSinceEpoch();
	data.iFlag = (int)chatitem::left;
	strcpy(data.szContent,"胖子，干嘛呢");
	m_pChatTable->AddItem(data);
	m_pChatTable->ResizeView();
}

void MainWindow::on_actionAdd_right_triggered()
{
	ItemData data;
	data.dfTime = QDateTime::currentMSecsSinceEpoch();
	data.iFlag = (int)chatitem::right;
	strcpy(data.szContent,"玩手机");
	m_pChatTable->AddItem(data);
	m_pChatTable->ResizeView();
}
