#ifndef BOARDDESIGN_H
#define BOARDDESIGN_H

#include "boardpart.h"

class BoardDesign : public BoardPart
{
public:
    BoardDesign(QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
};

#endif // BOARDDESIGN_H
