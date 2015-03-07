#include "graphicsview.h"

GraphicsView::GraphicsView(QGraphicsScene *scene) : QGraphicsView(scene)
{
    setRenderHint(QPainter::Antialiasing);
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    setBackgroundBrush(QColor(181, 181, 181));
}

void GraphicsView::resizeEvent(QResizeEvent *)
{ }
