#include "chatitem.h"
#include <QPainter>
#include "font/fontawesomeicons.h"

QRectF chatitem::m_rect = QRectF(0,0,200,50);
chatitem::chatitem(int type):m_type((Type)type)
{
    m_iconsize = 50;
}

QRectF chatitem::boundingRect() const
{
    return m_rect;
}

void chatitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //绘制icon
    if(m_type == right)
    {
        painter->save();
        painter->translate(QPoint(115,0));
    }
    painter->setPen(QColor("#000000"));
    QFont font =  FontAwesomeIcons::Instance().getFont();
    font.setPointSize(25);
    painter->setFont(font);
    painter->drawText(QRect(0,0,m_iconsize,m_iconsize), Qt::AlignCenter, FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_helicopter));

    //绘制矩形小三角形
    if(m_type == left)
    {
        painter->translate(QPoint(m_iconsize,0));
    }
    else
    {
        painter->restore();
    }
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    painter->setRenderHint(QPainter::Antialiasing, true);

    QPainterPath drawPath;
    // 小三角区域;
    QPolygon trianglePolygon;
    if(m_type == left)
    {
        trianglePolygon << QPoint(0 + 15, 25 + 10);
        trianglePolygon << QPoint(0, 25);
        trianglePolygon << QPoint(0 + 15, 25-10);
    }
    else
    {
        trianglePolygon << QPoint(100, 25 + 10);
        trianglePolygon << QPoint(100+15, 25);
        trianglePolygon << QPoint(100, 25-10);
    }

    //矩形区域
    QRect inforect(0,0,100,50);
    if(m_type == left)
    {
        drawPath.addRoundedRect(inforect.adjusted(15,0,15,0),15,15);
    }
    else
    {
        drawPath.addRoundedRect(inforect,15,15);
    }
    drawPath.addPolygon(trianglePolygon);
    painter->drawPath(drawPath);
}

int chatitem::GetHeight()
{
    return m_rect.height() +10;
}
