#ifndef CHATTABLE_H
#define CHATTABLE_H

#include <QWidget>
#include "chatitem.h"

class QGraphicsScene;
class QGraphicsView;
namespace Ui {
class chattable;
}

class chattable : public QWidget
{
    Q_OBJECT

public:
    explicit chattable(QWidget *parent = 0);
    ~chattable();
    void AddItem(int flag);
    void ResizeView();
private:
    Ui::chattable *ui;
    void resizeEvent(QResizeEvent*event);
    QGraphicsScene* m_pscen;
    QGraphicsView*  m_pView;
};

#endif // CHATTABLE_H
