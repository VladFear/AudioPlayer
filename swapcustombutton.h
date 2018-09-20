#ifndef SWAPCUSTOMBUTTON_H
#define SWAPCUSTOMBUTTON_H

#include <QPushButton>
#include <QEvent>
#include <QStringList>

class SwapCustomButton : public QPushButton
{
  Q_OBJECT
private:
  QString active;
  QString unhover_first_path;
  QString unhover_second_path;
  QString hover_first_path;
  QString hover_second_path;

public:
  explicit SwapCustomButton(QWidget* parent);
  void setFirstHoverIcon(QString icon_path);
  void setSecondHoverIcon(QString icon_path);
  void setFirstBaseIcon(QString icon_path);
  void setSecondBaseIcon(QString icon_path);
  void swapIcon();

protected:
  void enterEvent(QEvent* event) override;
  void leaveEvent(QEvent* event) override;
};

#endif // SWAPCUSTOMBUTTON_H
