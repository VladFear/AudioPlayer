#ifndef CUSTOMSLIDER_H
#define CUSTOMSLIDER_H

#include <QMouseEvent>
#include <QSlider>
#include <QStyleOptionSlider>
#include <QStyle>

class CustomSlider : public QSlider
{
  Q_OBJECT
private:
  bool busy;

private:
  QString initStyle();

public:
  explicit CustomSlider(QWidget* parent);
  explicit CustomSlider(Qt::Orientation orientation, QWidget* parent);
  bool isBusy() const;
  void setBusy(bool value);

protected:
  void mousePressEvent(QMouseEvent* event) override;
  void wheelEvent(QWheelEvent* event) override;
};

#endif // CUSTOMSLIDER_H
