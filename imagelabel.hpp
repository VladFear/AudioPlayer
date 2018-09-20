#ifndef IMAGELABEL_H
#define IMAGELABEL_H

#include <QLabel>
#include <QPixmap>
#include <QResizeEvent>

class ImageLabel : public QLabel
{
  Q_OBJECT
private:
  QPixmap pix;

public:
  explicit ImageLabel(QWidget *parent = 0);
  virtual int heightForWidth( int width ) const;
  virtual QSize sizeHint() const;
  QPixmap scaledPixmap() const;

public slots:
  void setPixmap ( const QPixmap & );
  void resizeEvent(QResizeEvent *);
};

#endif // IMAGELABEL_H
