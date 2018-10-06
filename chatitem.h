#ifndef CHATITEM_H
#define CHATITEM_H

#include <QGraphicsItem>

class chatitem : public QGraphicsItem
{
public:
    enum Type{left = 0, right};
    chatitem(int type);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    static int GetHeight();
private:
    static QRectF m_rect;
    int m_iconsize;
    Type m_type;
};

#endif // CHATITEM_H
