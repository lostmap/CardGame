#include "qhoversensitivebutton.h"

void QHoverSensitiveButton::del()
{
  emit clear();
  deleteLater();
}
QHoverSensitiveButton::~QHoverSensitiveButton()
{

}
QHoverSensitiveButton::QHoverSensitiveButton(QWidget *parent, int id) : QPushButton(parent), id(id)
{
    setMouseTracking(true);
    setAttribute(Qt::WA_Hover);
}

int QHoverSensitiveButton::getId() const
{
    return id;
}
void QHoverSensitiveButton::setId(int value)
{

    id = value;
}

void QHoverSensitiveButton::hoverEnter(QHoverEvent *)
{
    this->setStyleSheet("QPushButton { border-style: inset; border-width: 1px; border-color: magenta }");
}

void QHoverSensitiveButton::hoverLeave(QHoverEvent *)
{
    this->setStyleSheet("");
}

void QHoverSensitiveButton::hoverMove(QHoverEvent *)
{
    this->setStyleSheet("QPushButton { border-style: inset; border-width: 1px; border-color: magenta }");
}

bool QHoverSensitiveButton::event(QEvent *event)
{
    switch(event->type())
    {
    case QEvent::HoverEnter:
        hoverEnter(static_cast<QHoverEvent*>(event));
        return true;
        break;
    case QEvent::HoverLeave:
        hoverLeave(static_cast<QHoverEvent*>(event));
        return true;
        break;
    case QEvent::HoverMove:
        hoverMove(static_cast<QHoverEvent*>(event));
        return true;
        break;
    default:
        break;
    }
    return QWidget::event(event);
}

void del() {

}
