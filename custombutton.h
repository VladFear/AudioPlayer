#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QEvent>
#include <QIcon>

class CustomButton : public QPushButton
{
  Q_OBJECT
private:
  QString unhover_path;
  QString hover_path;

public:
  explicit CustomButton(QWidget* parent);
  void setHoverIcon(QString icon_path);
  void setBaseIcon(QString icon_path);

protected:
  void enterEvent(QEvent* event) override;
  void leaveEvent(QEvent* event) override;
};

#endif // CUSTOMBUTTON_H
