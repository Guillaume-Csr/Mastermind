#include "holereview.h"

HoleReview::HoleReview(QGraphicsItem *parent) : BoardPart(parent), black(false), white(false)
{ }

QRectF HoleReview::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void HoleReview::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    if(black)
    {
        painter->setBrush(Qt::black);
        painter->drawEllipse(0, 0, 20, 20);
    }
    else if(white)
    {
        painter->setBrush(Qt::white);
        painter->drawEllipse(0, 0, 20, 20);
    }
    else
    {
        painter->setBrush(Qt::gray);
        painter->drawEllipse(0, 0, 20, 20);
    }
}


void HoleReview::blackPaint()
{
    black = true;
}

void HoleReview::whitePaint()
{
    white = true;
}
