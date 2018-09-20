#include "imagelabel.hpp"

ImageLabel::ImageLabel(QWidget *parent) : QLabel(parent)
{
  this->setMinimumSize(1, 1);
  setScaledContents(false);
}

void ImageLabel::setPixmap ( const QPixmap & p)
{
  pix = p;
  QLabel::setPixmap(scaledPixmap());
}

int ImageLabel::heightForWidth( int width ) const
{
  return pix.isNull() ? this->height() : ((qreal)pix.height() * width) / pix.width();
}

QSize ImageLabel::sizeHint() const
{
  int w = this->width();
  return QSize(w, heightForWidth(w));
}

QPixmap ImageLabel::scaledPixmap() const
{
  return pix.scaled(this->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

void ImageLabel::resizeEvent(QResizeEvent * e)
{
  if(!pix.isNull())
      QLabel::setPixmap(scaledPixmap());
}
