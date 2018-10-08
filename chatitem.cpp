#include "chatitem.h"
#include <QPainter>
#include "font/fontawesomeicons.h"
#include <QDateTime>

QRectF chatitem::m_rect = QRectF(0,0,200,70);
chatitem::chatitem(ItemData& sData)
{
	m_iconsize = 50;
	memcpy(&m_sData, &sData, sizeof(ItemData));
}

QRectF chatitem::boundingRect() const
{
	return m_rect;
}

void chatitem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	Type type = (Type)m_sData.iFlag;
	int icontorect = 15;
	int rectwidth = 120, rectheight = 50, rectround = 15,timeheight = 20;
	//绘制icon
	if(type == right)
	{
		painter->save();
		painter->translate(QPoint(icontorect+rectwidth,0));
	}
	painter->setPen(QColor("#000000"));
	QFont font = FontAwesomeIcons::Instance().getFont();
	font.setPointSize(25);
	painter->setFont(font);
	painter->drawText(QRect(0,20,m_iconsize,m_iconsize), Qt::AlignCenter, FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_helicopter));

	//绘制矩形小三角形
	if(type == left)
	{
		painter->translate(QPoint(m_iconsize,0));
	}
	else
	{
		painter->restore();
	}
	painter->setPen(Qt::NoPen);
	painter->setBrush(Qt::lightGray);
	painter->setRenderHint(QPainter::Antialiasing, true);

	QPainterPath drawPath;
	// 小三角区域;
	QPolygon trianglePolygon;
	int startx,center = rectheight*0.5;
	int height = 10;
	if(type == left)
	{
		startx = 0;
		trianglePolygon << QPoint(startx+icontorect, center+height+timeheight);
		trianglePolygon << QPoint(startx, center+timeheight);
		trianglePolygon << QPoint(startx+icontorect, center-height+timeheight);
	}
	else
	{
		startx = rectwidth;
		trianglePolygon << QPoint(startx, center+height+timeheight);
		trianglePolygon << QPoint(startx+icontorect, center+timeheight);
		trianglePolygon << QPoint(startx, center-height+timeheight);
	}

	//矩形区域
	QRect inforect(0,timeheight,rectwidth,rectheight);
	if(type == left)
	{
		inforect = inforect.adjusted(rectround,0,rectround,0);
		drawPath.addRoundedRect(inforect,rectround,rectround);
	}
	else
	{
		drawPath.addRoundedRect(inforect,rectround,rectround);
	}
	drawPath.addPolygon(trianglePolygon);
	painter->drawPath(drawPath);

	//时间绘制区域
	QRect timerect;
	QRect timeiconrect;
	if(type == left)
	{
		timeiconrect = QRect(rectround,0,timeheight,timeheight);
		timerect = QRect(rectround+timeheight,0,rectwidth,timeheight);
	}
	else
	{
		timeiconrect = QRect(0,0,timeheight,timeheight);
		timerect = QRect(timeheight,0,rectwidth,timeheight);
	}
	//绘制时间图标
	painter->setPen(Qt::black);
	font.setPointSize(10);
	painter->setFont(font);
	painter->drawText(timeiconrect, Qt::AlignCenter, FontAwesomeIcons::Instance().getIconChar(FontAwesomeIcons::IconIdentity::icon_time));
	//显示时间文字
	font.setFamily("Arial");
	painter->setFont(font);
	painter->drawText(timerect,QDateTime::fromMSecsSinceEpoch(m_sData.dfTime).toString("hh:mm:ss"));
	//显示消息内容
	font.setFamily("隶书");
	painter->setFont(font);
	painter->drawText(inforect,Qt::AlignCenter,m_sData.szContent);
}

int chatitem::GetHeight()
{
	return m_rect.height() +10;
}
