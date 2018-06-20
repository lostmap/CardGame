#include "graphicviewexample.hpp"


graphicViewExample::graphicViewExample()
{
  setRenderHint(QPainter::Antialiasing);
  setCacheMode(QGraphicsView::CacheNone);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setWindowTitle("QGraphicsView example");

  //setFrameStyle(0);
  //setFixedSize(1000, 700);

  setSceneRect(0, 0, 500, 500);
  setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));

  setScene(&scene);
}
