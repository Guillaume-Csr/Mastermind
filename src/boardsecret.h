#ifndef BOARDSECRET_H
#define BOARDSECRET_H

#include "boardpart.h"

class BoardSecret : public BoardPart
{
public:
    BoardSecret(QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void setTransparency(int);

private:
    int transparency;
};

#endif // BOARDSECRET_H
