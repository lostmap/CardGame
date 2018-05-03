#ifndef QHOVERSENSITIVEBUTTON_H
#define QHOVERSENSITIVEBUTTON_H

#include <QtWidgets>
#include <QString>

class QHoverSensitiveButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QHoverSensitiveButton(QWidget *parent = 0, int id = 0);
   // explicit QHoverSensitiveButton()
    int getId() const;
    void setId(int value);
    ~QHoverSensitiveButton();
protected:
    void hoverEnter(QHoverEvent *event);
    void hoverLeave(QHoverEvent *event);
    void hoverMove(QHoverEvent *event);
    bool event(QEvent *event);

signals:
    void clear();

public slots:
    void del();
private:
    int id;
    int power;
    QString description;
   // int cardImage;
   // int cardCover;
};

#endif // QHOVERSENSITIVEBUTTON_H
