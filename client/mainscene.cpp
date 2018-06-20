#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "mainscene.hpp"
#include "qhoversensitivebutton.h"

mainScene::mainScene()
{
  setItemIndexMethod(QGraphicsScene::NoIndex);

  _init_primary_field();
  _init_secondary_field();
}

void mainScene::handle(QHoverSensitiveButton* btn)
{
    //qDebug() << "btn size before " << buttonBuff.size();;
    if (!buttonBuff.isEmpty()) {
        buttonBuff.clear();
        qDebug() << "btn size on full " << buttonBuff.size();
    }
    buttonBuff.push_back(btn);
    //qDebug() << "btn size after " << buttonBuff.size();
    qDebug() << "do smthing with" << btn->getId();
}
void mainScene::_init_primary_field()
{
  _primaryField.setPos(10, 310);
  _primaryField.boundingRectOnSceneCalc();
  addItem(&_primaryField);
}
void mainScene::_init_secondary_field()
{
   _secondaryField.setPos(10, 10);
   _secondaryField.boundingRectOnSceneCalc();
   addItem(&_secondaryField);
}

void mainScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    QPointF point = event->scenePos();
    int xPrimaryOffset = _primaryField.pos().x();
    int yPrimaryOffset = _primaryField.pos().y();
    int cellPosPrimary = _primaryField.returnPosition(point, xPrimaryOffset, yPrimaryOffset);
    if (cellPosPrimary != -1) {
        qDebug() << cellPosPrimary << "primary";
    }
    QHoverSensitiveButton* btn = buttonBuff.back();
    qDebug() << btn->getId() << " written\n";
    btn->setText(QString::number(btn->getId()));
   // btn->setGeometry(btn);
    QGraphicsTextItem *text = this->addText(QString::number(btn->getId()));
    text->setPos(point);
    //emit toDel();
    emit clicked();
    //emit destroyed();
    //connect(this, &QGra:, btn, SLOT(del()));
    //graphicsView = new QGraphicsView(this);

    int xSecondaryOffset = _secondaryField.pos().x();
    int ySecondaryOffset = _secondaryField.pos().y();
    int cellPosSecondary = _secondaryField.returnPosition(point, xSecondaryOffset, ySecondaryOffset);
    if (cellPosSecondary != -1) {
        qDebug() << cellPosSecondary << "secondary";
    }
    qDebug() << " x " << point.x() << "y " << point.y()  << "\n";
}
void mainScene::mouseMoveEvent(QGraphicsSceneMouseEvent *apEvent)
{
  bool primaryHover = _is_moving_hover_primary_field(apEvent->scenePos());

  if(primaryHover)
    _primaryField.enableHoverPos(apEvent->scenePos());

  bool secondaryHover = _is_moving_hover_secondary_field(apEvent->scenePos());

  if(secondaryHover)
    _secondaryField.enableHoverPos(apEvent->scenePos());
}
bool mainScene::_is_moving_hover_primary_field(const QPointF &aPos)
{
  return (aPos.x() >= _primaryField.xtl())
      && (aPos.x() <= _primaryField.xbr())
      && (aPos.y() >= _primaryField.ytl())
      && (aPos.y() <= _primaryField.ybr());
}
bool mainScene::_is_moving_hover_secondary_field(const QPointF &aPos)
{
  return (aPos.x() >= _secondaryField.xtl())
      && (aPos.x() <= _secondaryField.xbr())
      && (aPos.y() >= _secondaryField.ytl())
      && (aPos.y() <= _secondaryField.ybr());
}
void mainScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
}
