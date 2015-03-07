#include "codinghole.h"

#include "QDebug"
CodingHole::CodingHole(QGraphicsItem *parent) : BoardPart(parent), paintedBoolean(false)
{ }

QRectF CodingHole::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void CodingHole::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    if (pixmap.isNull())
    {
        painter->setBrush(dragOver ? color.light(130) : color);
        painter->drawEllipse(0, 0, 50, 50);
    }
    else
    {
        painter->scale(1,1);
        painter->drawPixmap(QPointF(0, 0), pixmap);
    }
}

int CodingHole::getImageNumber()
{
    if( path == ":/images/rsz_circle-blue.png")
    {
        return 0;
    }
    else if ( path == ":/images/rsz_circle-green.png" )
    {
        return 1;
    }
    else if ( path == ":/images/rsz_circle-grey.png" )
    {
        return 2;
    }
    else if ( path == ":/images/rsz_circle-orange.png" )
    {
        return 3;
    }
    else if ( path == ":/images/rsz_circle-purple.png" )
    {
        return 4;
    }
    else if ( path == ":/images/rsz_circle-red.png" )
    {
        return 5;
    }
    else if ( path == ":/images/rsz_circle-yellow.png" )
    {
        return 6;
    }
    else if ( path == ":/images/rsz_circle-tan.png" )
    {
        return 7;
    }
    else
    {
        return -1;
    }
}

bool CodingHole::getPainted()
{
    return paintedBoolean;
}

void CodingHole::setPainted(bool paintedBooleanValue)
{
    paintedBoolean = paintedBooleanValue;
}


/* Note : For performance reasons,
 *        depending on the complexity
 *        of what is painted, it can
 *        often be faster to draw the
 *        head as an image rather than
 *        using a sequence of vector
 *        operations.
 */

void CodingHole::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if(event->mimeData()->hasImage())
    {
        event->setAccepted(true);
        dragOver = true;
        update();
    }
    else
    {
        BoardPart::dragEnterEvent(event);
    }
}

void CodingHole::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    if(event->mimeData()->hasImage())
    {
        dragOver = false;
        pixmap = qvariant_cast<QPixmap>(event->mimeData()->imageData());
        path = qvariant_cast<QString>(event->mimeData()->text());
        setPainted(true);
        update();

        event->acceptProposedAction();
    }
    else
    {
        BoardPart::dropEvent(event);
    }
}
