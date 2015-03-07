#ifndef HOLEREVIEW_H
#define HOLEREVIEW_H

#include "boardpart.h"

class HoleReview : public BoardPart
{
    Q_OBJECT
public:
    HoleReview(QGraphicsItem *parent = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);

    void blackPaint();
    void whitePaint();

private:
    bool black;
    bool white;
};

#endif // HOLEREVIEW_H
