#include "boardbutton.h"

#include <QtWidgets>

BoardButton::BoardButton(QGraphicsItem *parent, QString text) : BoardPart(parent), m_text(text), click(false)
{
    setCursor(Qt::OpenHandCursor);
    setAcceptedMouseButtons(Qt::LeftButton);
}

QRectF BoardButton::boundingRect() const
{
    return QRectF(0, 0, 90, 50);
}

void BoardButton::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->drawRoundedRect(0, 0, 90, 50, 25, 25, Qt::RelativeSize);

    QFont font = painter->font() ;
    font.setPointSize( 14 );
    painter->setFont(font);
    painter->scale(1, 1.5);
    painter->drawText(-5, -35, 100, 100, Qt::AlignCenter, QString(m_text));
}

bool BoardButton::getClick()
{
    return click;
}

void BoardButton::setClick(bool booleanValue)
{
    click = booleanValue;
}

void BoardButton::clickSlot()
{
    click = true;
    emit clickSignal();
}

void BoardButton::mousePressEvent(QGraphicsSceneMouseEvent *)
{
    setCursor(Qt::ClosedHandCursor);
}

void BoardButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::OpenHandCursor);

    if(event->button() == Qt::LeftButton)
    {
        emit mouseReleased();
        click = true;
        QGraphicsObject::mouseReleaseEvent(event); // call default implementation
    }
    else
    {
        QGraphicsObject::mouseReleaseEvent(event); // call default implementation
    }
}

void BoardButton::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
}
