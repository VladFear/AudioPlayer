#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QMediaMetaData>
#include <QTableWidget>
#include <QSlider>
#include <QHeaderView>
#include <QLabel>
#include <QDebug>
#include <QFileDialog>
#include <QGridLayout>
#include <QMediaMetaData>
#include <QTime>
#include <QStackedWidget>
#include <QStringList>
#include <QUrl>

#include "imagelabel.hpp"
#include "customslider.hpp"
#include "custombutton.h"
#include "swapcustombutton.h"

class MainWindow : public QWidget
{
  Q_OBJECT
private:
  QWidget* time_widget;
  QWidget* buttons_widget;
  QMediaPlayer* media_player;
  QMediaPlaylist* playlist;
  QTableWidget* table;
  CustomSlider* song_slider;
  QSlider* volume_slider;
  QLabel* time_begin_lbl;
  QLabel* time_end_lbl;
  CustomButton* previous_btn;
  CustomButton* next_btn;
  CustomButton* playlist_btn;
  SwapCustomButton* play_btn;
  SwapCustomButton* mute_unmute_btn;
  QPushButton* add_btn;
  QPushButton* save;
  ImageLabel* image;
  QStackedWidget* stacked_widget;

private:
  void createInterior();
  void connectSlots();

private slots:
  void addClicked();
  void metaDataChanged();
  void mediaPositionChanged(quint64 pos);
  void mediaDurationChanged(quint64 dur);

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
