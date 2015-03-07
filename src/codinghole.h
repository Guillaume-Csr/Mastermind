#ifndef CODINGHOLE_H
#define CODINGHOLE_H

#include "boardpart.h"

class CodingHole : public BoardPart
{
    Q_OBJECT
public:
    CodingHole(QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    int getImageNumber();
    bool getPainted();
    void setPainted(bool paintedBooleanValue);

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);


    QPixmap pixmap;
    QString path;
    bool paintedBoolean;
};

#endif // CODINGHOLE_H
