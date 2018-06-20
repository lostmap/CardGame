#ifndef FIELD_HPP
#define FIELD_HPP

#include <QGraphicsItem>

class field : public QGraphicsItem
{
public:
  field(int, int, int, int);

  QRectF boundingRect() const override;
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

  void hoverMoveEvent(QGraphicsSceneHoverEvent*) override;
  void hoverLeaveEvent(QGraphicsSceneHoverEvent*) override;

  void enableHoverPos(QPointF);
  void disableHover();

  int returnPosition(QPointF, int, int);

  void boundingRectOnSceneCalc();
  qreal xtl();
  qreal ytl();
  qreal xbr();
  qreal ybr();
  int     id{0};
private:

  int     lines{0};
  int     columns{0};
  int     cellWidth{0};
  int     cellHeight{0};
  int     fieldWidth{0};
  int     fieldHeight{0};
  bool    hover{false};
  QPointF mousePos;
  QRectF  boundingSceneRect;
};

#endif // FIELD_HPP
