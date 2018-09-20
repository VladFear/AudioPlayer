#include "customslider.hpp"

QString CustomSlider::initStyle()
{
   return "QSlider::groove:horizontal "
          "{"
          "  border: 1px solid;"
          "  border-color: rgb(50, 50, 50);"
          "  border-radius: 2px;"
          "  height: 3px;"
          "  background: qlineargradient(x1:0, y1:0, x2:1, y2:1,stop:0 orange, stop:1 red);"
          "}"
          "QSlider::handle:horizontal"
          "{"
          "  border-radius: 6px;" //3
          "  background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 rgb(145, 145, 145), stop:1 rgb(120, 120, 120));"
          "  width: 12px;" // 6
          "  margin: -5px 0;"
          "}"
          "QSlider::add-page:horizontal  "
          "{"
          "  border: 1px solid;"
          "  border-color: rgb(50, 50, 50);"
          "  background: rgb(70, 70, 70);"
          "}";
}

CustomSlider::CustomSlider(QWidget *parent) : QSlider(parent), busy(false)
{
  setStyleSheet(initStyle());
}

CustomSlider::CustomSlider(Qt::Orientation orientation, QWidget *parent) : QSlider(orientation, parent), busy(false)
{
  setStyleSheet(initStyle());
}

bool CustomSlider::isBusy() const
{
  return busy;
}

void CustomSlider::setBusy(bool value)
{
  busy = value;
}

void CustomSlider::mousePressEvent(QMouseEvent *event)
{
  QStyleOptionSlider opt;
  initStyleOption(&opt);
  QRect sr = style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderHandle, this);

  if (event->button() == Qt::LeftButton && sr.contains(event->pos()) == false)
  {
    int newVal;
    double halfHandleWidth = (0.5 * sr.width()) + 0.5; // Correct rounding
    int adaptedPosX = event->x();
    if (adaptedPosX < halfHandleWidth)
      adaptedPosX = halfHandleWidth;
    if (adaptedPosX > width() - halfHandleWidth)
      adaptedPosX = width() - halfHandleWidth;
    // get new dimensions accounting for slider handle width
    double newWidth = (width() - halfHandleWidth) - halfHandleWidth;
    double normalizedPosition = (adaptedPosX - halfHandleWidth)  / newWidth ;

    newVal = minimum() + ((maximum()-minimum()) * normalizedPosition);

    if (invertedAppearance() == true)
        setValue( maximum() - newVal );
    else
        setValue(newVal);

    event->accept();
  }
    QSlider::mousePressEvent(event);
}

void CustomSlider::wheelEvent(QWheelEvent *event)
{
  event->ignore(); // ignores wheel
}
