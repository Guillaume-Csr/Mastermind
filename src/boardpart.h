#ifndef BOARDPART_H
#define BOARDPART_H

#include <QGraphicsObject>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>
#include <QPainter>

class BoardPart : public QGraphicsObject
{
public:
    BoardPart(QGraphicsItem *parent = 0);
    ~BoardPart();

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);

    QColor color;
    bool dragOver;
};

#endif // BOARDPART_H
