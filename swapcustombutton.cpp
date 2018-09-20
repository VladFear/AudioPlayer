#include "swapcustombutton.h"

SwapCustomButton::SwapCustomButton(QWidget *parent) : QPushButton(parent)
{

}

void SwapCustomButton::setFirstHoverIcon(QString icon_path)
{
  hover_first_path = icon_path;
  active = hover_first_path;
}

void SwapCustomButton::setSecondHoverIcon(QString icon_path)
{
  hover_second_path = icon_path;
}

void SwapCustomButton::setFirstBaseIcon(QString icon_path)
{
  unhover_first_path = icon_path;
  QPushButton::setIcon(QIcon(unhover_first_path));
}

void SwapCustomButton::setSecondBaseIcon(QString icon_path)
{
  unhover_second_path = icon_path;
}

void SwapCustomButton::swapIcon()
{
  if (active == hover_first_path)
    active = hover_second_path;
  else
    active = hover_first_path;
  QPushButton::setIcon(QIcon(active));
}

void SwapCustomButton::enterEvent(QEvent *event)
{
  QPushButton::setIcon(QIcon(active));
}

void SwapCustomButton::leaveEvent(QEvent *event)
{
  if (active == hover_first_path)
    QPushButton::setIcon(QIcon(unhover_first_path));
  else
    QPushButton::setIcon(QIcon(unhover_second_path));
}
