#ifndef CHATITEM_H
#define CHATITEM_H

#include <QGraphicsItem>
#include "itemstruct.h"
class chatitem : public QGraphicsItem
{
public:
	enum Type{left = 0, right};
	chatitem(ItemData& sData);
	QRectF boundingRect() const;
	void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
	static int GetHeight();
private:
	static QRectF m_rect;
private:
	ItemData    m_sData;
	int         m_iconsize;
};

#endif // CHATITEM_H
