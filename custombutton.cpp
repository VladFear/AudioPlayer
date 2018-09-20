#include "custombutton.h"

CustomButton::CustomButton(QWidget *parent) : QPushButton(parent)
{

}

void CustomButton::setHoverIcon(QString icon_path)
{
  hover_path = icon_path;
}

void CustomButton::setBaseIcon(QString icon_path)
{
  unhover_path = icon_path;
  QIcon icon(icon_path);
  QPushButton::setIcon(icon);
}

void CustomButton::enterEvent(QEvent *event)
{
  QPushButton::setIcon(QIcon(hover_path));
}

void CustomButton::leaveEvent(QEvent *event)
{
  QPushButton::setIcon(QIcon(unhover_path));
}
