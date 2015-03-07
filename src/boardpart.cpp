#include "boardpart.h"

BoardPart::BoardPart(QGraphicsItem *parent) : QGraphicsObject(parent), color(Qt::lightGray), dragOver(false)
{
    setAcceptDrops(true);
}
BoardPart::~BoardPart() { }

void BoardPart::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if(event->mimeData()->hasColor())
    {
        event->setAccepted(true);
        dragOver = true;
        update();
    }
    else
    {
        event->setAccepted(false);
    }
}

void BoardPart::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event);
    dragOver = false;
    update();
}

void BoardPart::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    dragOver = false;
    if(event->mimeData()->hasColor())
    {
        color = qvariant_cast<QColor>(event->mimeData()->colorData());
    }
    update();
}
