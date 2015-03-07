#ifndef SECRETHOLE_H
#define SECRETHOLE_H

#include "boardpart.h"

class SecretHole : public BoardPart
{
public:
    SecretHole(QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    int getImageNumber();

private:
    QString file;
    int imageNumber;
};

#endif // SECRETHOLE_H
