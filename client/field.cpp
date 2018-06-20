#include <QPainter>
#include <QGraphicsSceneHoverEvent>
#include "field.hpp"
#include <QDebug>

field::field(int _lines, int _columns, int _cellWidth, int _cellHeight)
  :lines(_lines)
  ,columns(_columns)
  ,cellWidth(_cellWidth)
  ,cellHeight(_cellHeight)
  ,fieldWidth(_columns * _cellWidth)
  ,fieldHeight(_lines * _cellHeight)
{
  setAcceptHoverEvents(true);
  setAcceptedMouseButtons(Qt::MouseButton::LeftButton);
}
QRectF field::boundingRect() const
{
  return QRectF(0, 0, fieldWidth, fieldHeight);
}
void field::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  for(int l = 0; l <= lines; ++l)
    painter->drawLine(QLineF(0, l * cellHeight, fieldWidth, l * cellHeight));

  for(int c = 0; c <= columns; ++c)
    painter->drawLine(QLineF(c * cellWidth, 0, c * cellWidth, fieldHeight));

  if(hover)
  {
    int x = mousePos.x()/cellWidth;
    int y = mousePos.y()/cellHeight;

    painter->setPen(QColor(255, 0, 0));
    painter->drawRoundedRect(x * cellWidth,
                             y * cellHeight,
                             cellWidth,
                             cellHeight,
                             2, 2);
  }
}
int field::returnPosition(QPointF pos, int xOff, int yOff)
{
    //int count = fieldWidth / cellWidth;
    int posX = pos.x() - xOff;
    //int posY = pos.y() - yOff;
    //qDebug() << count << "\n";
    if (pos.x() >= xOff
       && pos.x() <= xOff + fieldWidth
       && pos.y() >= yOff
       && pos.y() <= yOff + fieldHeight) {
        return int (posX / cellWidth);
      }
    return -1;
}
void field::boundingRectOnSceneCalc()
{
  QPointF pos  = scenePos();
  QRectF  rect = boundingRect();

  QPointF topLeft{pos.x() + rect.x(), pos.y() + rect.y()};
  QPointF bottomRight{topLeft.x() + rect.width(),topLeft.y() + rect.height()};

  boundingSceneRect.setTopLeft(topLeft);
  boundingSceneRect.setBottomRight(bottomRight);
}
qreal field::xtl()
{
  return boundingSceneRect.topLeft().x();
}
qreal field::ytl()
{
  return boundingSceneRect.topLeft().y();
}
qreal field::xbr()
{
  return boundingSceneRect.bottomRight().x();
}
qreal field::ybr()
{
  return boundingSceneRect.bottomRight().y();
}
void field::hoverMoveEvent(QGraphicsSceneHoverEvent *apEvent)
{
  mousePos = apEvent->pos();
  hover = true;
  QGraphicsItem::update();
}
void field::hoverLeaveEvent(QGraphicsSceneHoverEvent*)
{
  hover = false;
  QGraphicsItem::update();
}
void field::enableHoverPos(QPointF aPos)
{
  hover = true;
  mousePos = mapFromScene(aPos);
  QGraphicsItem::update();
}
void field::disableHover()
{
  hover = false;
  QGraphicsItem::update();
}


