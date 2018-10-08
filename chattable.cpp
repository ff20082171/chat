#include "chattable.h"
#include "ui_chattable.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "chatitem.h"
#include <QResizeEvent>

chattable::chattable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chattable)
{
    ui->setupUi(this);
    m_pscen = new QGraphicsScene(this);
    m_pView = new QGraphicsView(m_pscen,this);
    m_pView->show();
}

chattable::~chattable()
{
    delete ui;
}

void chattable::AddItem(ItemData sData)
{
    int nums = m_pscen->items().size();
    int val = chatitem::GetHeight();
	chatitem* pChat = new chatitem(sData);
    m_pscen->addItem(pChat);
	if(sData.iFlag == chatitem::left)
        pChat->setPos(0,val*nums);
    else
    {
        int width = this->rect().width() - pChat->boundingRect().width();
        pChat->setPos(width,val*nums);
    }
}

void chattable::ResizeView()
{
    int nums = m_pscen->items().size();
    int height = nums*chatitem::GetHeight() > this->size().height()? nums*chatitem::GetHeight():this->size().height();
    m_pscen->setSceneRect(0,0,this->rect().width(),height);
}

void chattable::resizeEvent(QResizeEvent *event)
{
    QSize size = event->size();
    m_pView->setFixedSize(size.width(),size.height());
    m_pView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ResizeView();

}
