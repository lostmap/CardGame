#ifndef MAINSCENE_HPP
#define MAINSCENE_HPP

#include <QGraphicsScene>
#include <QList>
#include "mainfield.hpp"
#include "primaryfield.hpp"
#include "secondaryfield.h"

#include "qhoversensitivebutton.h"



class mainScene : public QGraphicsScene
{
    Q_OBJECT
public:
  mainScene();

  void mousePressEvent(QGraphicsSceneMouseEvent *)  override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent *)   override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *) override;

public slots:
  void handle(QHoverSensitiveButton* btn);

signals:
  void toDel();
  void clicked();
private:
  void _init_primary_field();
  bool _is_moving_hover_primary_field(const QPointF&);

  void _init_secondary_field();
  bool _is_moving_hover_secondary_field(const QPointF&);
private:
  //mainScene *ui;
  QList<QHoverSensitiveButton*> buttonBuff;
  primaryField  _primaryField;
  secondaryField  _secondaryField;
};

#endif // MAINSCENE_HPP
