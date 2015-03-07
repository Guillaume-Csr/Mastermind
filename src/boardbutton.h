#ifndef BOARDBUTTON_H
#define BOARDBUTTON_H

#include "boardpart.h"

class BoardButton : public BoardPart
{
    Q_OBJECT

public:
    BoardButton(QGraphicsItem *parent = 0, QString = "Unknown");

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    bool getClick();
    void setClick(bool);

public slots:
    void clickSlot();

signals:
    void clickSignal();
    void mouseReleased();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QString m_text;
    bool click;
};

#endif // BOARDBUTTON_H
