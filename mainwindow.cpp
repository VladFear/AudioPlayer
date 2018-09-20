#include "mainwindow.hpp"

void MainWindow::createInterior()
{
  this->setWindowTitle(tr("Audio Player"));
  this->setFixedSize(700, 810);

  QVBoxLayout* main_layout = new QVBoxLayout;
  main_layout->setMargin(0);
  this->setLayout(main_layout);
  this->setStyleSheet(
  "QWidget"
  "{ background-color: rgb(70, 70, 70); }");

  // Playlist and media_player ------------------------------------------
  media_player = new QMediaPlayer(this);
  playlist = new QMediaPlaylist(media_player);
  media_player->setPlaylist(playlist);
  media_player->setVolume(100);
  playlist->setPlaybackMode(QMediaPlaylist::Loop);
  //---------------------------------------------------------------

  // Table widget -------------------------------------------------
  stacked_widget = new QStackedWidget(this);

  image = new ImageLabel(this);
  image->setPixmap(QPixmap(":/Images/back2.jpg"));

  table = new QTableWidget(0, 2, this);
  table->setSelectionBehavior(QAbstractItemView::SelectRows);
  table->setStyleSheet(
  "QTableWidget"
  "{ "
  "  color: rgb(200, 200, 200);"
  "  selection-background-color: rgb(255, 164, 48);"
  "}"
  "QTableWidget::item:hover"
  "{ color: white; }"
  "QTableWidget::item"
  "{ border-bottom: 1px solid rgb(120, 120, 120); }"
  "QTableWidget::item:pressed"
  "{ color: black; }");
  table->horizontalHeader()->setVisible(false);
  table->setShowGrid(false);
//  QStringList headers;
//  headers << "Title" << "Time";
//  headers << "Title" << "Artist" << "Album" << "Time";
//  table->setHorizontalHeaderLabels(headers);
  table->setEditTriggers(QTableWidget::NoEditTriggers); // Disable cell editing
  table->verticalHeader()->setVisible(false); // Hide numbers on the left
  QHeaderView* header = table->horizontalHeader();
  header->setSectionResizeMode(0, QHeaderView::Stretch); // Stretch headers
//  header->setSectionResizeMode(1, QHeaderView::ResizeToContents);
//  header->setSectionResizeMode(2, QHeaderView::ResizeToContents);
//  header->setSectionResizeMode(3, QHeaderView::ResizeToContents);

  stacked_widget->addWidget(image);
  stacked_widget->addWidget(table);
  //---------------------------------------------------------------

  // Time and slider layout ---------------------------------------
  QHBoxLayout* time_layout = new QHBoxLayout;
  time_widget = new QWidget(this);
  time_widget->setLayout(time_layout);
  time_widget->setMaximumHeight(60);
  time_layout->setMargin(10);
  time_begin_lbl = new QLabel("00:00", this);
  time_begin_lbl->setStyleSheet(
  "QLabel"
  "{ color: white; padding-left: 10px; }");
  song_slider = new CustomSlider(Qt::Horizontal, this);
  song_slider->setFixedWidth(520);

  time_end_lbl = new QLabel("00:00", this);
  time_end_lbl->setStyleSheet(
  "QLabel"
  "{ color: white; padding-right: 10px;}");
  time_layout->addWidget(time_begin_lbl, 0, Qt::AlignLeft);
  time_layout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));
  time_layout->addWidget(song_slider, 0);
  time_layout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));
  time_layout->addWidget(time_end_lbl, 0, Qt::AlignRight);
  //---------------------------------------------------------------

  // Buttons widget -----------------------------------------------
  QHBoxLayout* buttons_layout = new QHBoxLayout;
  buttons_widget = new QWidget(this);
  buttons_widget->setMaximumHeight(60);
  buttons_widget->setLayout(buttons_layout);
  buttons_widget->setStyleSheet(
  "QWidget"
  "{ background-color: rgb(40, 40, 40); }");

  playlist_btn = new CustomButton(buttons_widget);
  playlist_btn->setBaseIcon(":/Icons/playlist_icon_grey.png");
  playlist_btn->setHoverIcon(":/Icons/playlist_icon.png");
  playlist_btn->setIconSize(QSize(20, 20));
  playlist_btn->setStyleSheet(
  "QPushButton"
  "{ padding: 5 5 5 5; }");
  playlist_btn->setFlat(true);

  add_btn = new QPushButton(tr("Add"), buttons_widget);
  add_btn->setStyleSheet(
  "QPushButton "
  "{ color: white; padding: 5 5 5 5; }");
  add_btn->setFlat(true);

  save = new QPushButton(tr("Save"), buttons_widget);
  save->setStyleSheet(
  "QPushButton "
  "{ color: white; padding: 5 5 5 5; }");
  save->setFlat(true);


  previous_btn = new CustomButton(buttons_widget);
  previous_btn->setBaseIcon(":/Icons/back_music_icon_grey.png");
  previous_btn->setHoverIcon(":/Icons/back_music_icon.png");
  previous_btn->setIconSize(QSize(30, 30));
  previous_btn->setFlat(true); // makes transparent

  play_btn = new SwapCustomButton(buttons_widget);
  play_btn->setFixedSize(QSize(40, 40));
  play_btn->setIconSize(QSize(40, 40));
  play_btn->setFirstBaseIcon(":/Icons/play_icon_grey.png");
  play_btn->setSecondBaseIcon(":/Icons/pause_icon_grey.png");
  play_btn->setFirstHoverIcon(":/Icons/play_icon2.png");
  play_btn->setSecondHoverIcon(":/Icons/pause_icon.png");
  play_btn->setFlat(true); // makes transparent

  next_btn = new CustomButton(buttons_widget);
  next_btn->setBaseIcon(":/Icons/next_music_icon_grey.png");
  next_btn->setHoverIcon(":/Icons/next_music_icon.png");
  next_btn->setIconSize(QSize(30, 30));
  next_btn->setFlat(true); // makes transparent

  volume_slider = new QSlider(Qt::Horizontal, buttons_widget);
  volume_slider->setStyleSheet(
  "QSlider::groove:horizontal "
  "{"
  "  border: 1px solid;"
  "  border-color: rgb(50, 50, 50);"
  "  border-radius: 2px;"
  "  height: 3px;"
  "  background: qlineargradient(x1:0, y1:0, x2:1, y2:1,stop:0 orange, stop:1 red);"
  "}"
  ""
  "QSlider::handle:horizontal"
  "{"
  " border-radius: 6px;" //3
  " background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 rgb(145, 145, 145), stop:1 rgb(120, 120, 120));"
  " width: 12px;" // 6
  " margin: -5px 0;"
  "}"
  ""
  "QSlider::add-page:horizontal  "
  "{"
  " border: 1px solid;"
  " border-color: rgb(50, 50, 50);"
  " background: rgb(70, 70, 70);"
  "}");
  volume_slider->setRange(0, 100);
  volume_slider->setValue(100);
  volume_slider->setFixedWidth(100);

  mute_unmute_btn = new SwapCustomButton(buttons_widget);
  mute_unmute_btn->setFixedSize(QSize(25, 25));
  mute_unmute_btn->setIconSize(QSize(20, 20));
  mute_unmute_btn->setFirstBaseIcon(":/Icons/volume_on_grey.png");
  mute_unmute_btn->setSecondBaseIcon(":/Icons/volume_off_grey.png");
  mute_unmute_btn->setFirstHoverIcon(":/Icons/volume_on.png");
  mute_unmute_btn->setSecondHoverIcon(":/Icons/volume_off.png");
  mute_unmute_btn->setFlat(true);

  buttons_layout->addWidget(playlist_btn, 0, Qt::AlignLeft);
  buttons_layout->addWidget(add_btn, 0, Qt::AlignLeft);
  buttons_layout->addWidget(save, 0, Qt::AlignLeft);
  buttons_layout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));
  buttons_layout->addWidget(previous_btn, 0, Qt::AlignRight);
  buttons_layout->addWidget(play_btn, 0, Qt::AlignCenter);
  buttons_layout->addWidget(next_btn, 0, Qt::AlignLeft);
  buttons_layout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));
  buttons_layout->addWidget(volume_slider, 0, Qt::AlignRight);
  buttons_layout->addWidget(mute_unmute_btn, 0, Qt::AlignRight);
  //---------------------------------------------------------------

  main_layout->addWidget(stacked_widget);
  main_layout->addWidget(time_widget, 0, Qt::AlignBottom);
  main_layout->addWidget(buttons_widget, 0, Qt::AlignBottom);
}

void MainWindow::connectSlots()
{
  connect(add_btn, &QPushButton::clicked, this, &MainWindow::addClicked);
  connect(next_btn, &QPushButton::clicked, playlist, &QMediaPlaylist::next);
  connect(previous_btn, &QPushButton::clicked, playlist, &QMediaPlaylist::previous);
  connect(volume_slider, &QSlider::valueChanged, [this]() { media_player->setVolume(volume_slider->value()); });
  connect(song_slider, &CustomSlider::sliderPressed, [this]() { song_slider->setBusy(true); });  // cant move slider if it pressed
  connect(media_player, SIGNAL(metaDataChanged()), this, SLOT(metaDataChanged()));
  connect(media_player, &QMediaPlayer::positionChanged, this, &MainWindow::mediaPositionChanged);
  connect(playlist_btn, &QPushButton::clicked, [this]() { stacked_widget->currentIndex() == 0 ? stacked_widget->setCurrentIndex(1) : stacked_widget->setCurrentIndex(0); });
  connect(media_player, &QMediaPlayer::durationChanged, this, &MainWindow::mediaDurationChanged);
  connect(table, &QTableWidget::cellDoubleClicked, [this](int row, int col)
  {
    if (col == 0)
      playlist->setCurrentIndex(row);
  });
  connect(mute_unmute_btn, &QPushButton::clicked, [this]()
  {
    mute_unmute_btn->swapIcon();
    if (media_player->isMuted())
      media_player->setMuted(false);
    else
      media_player->setMuted(true);
  });
  connect(song_slider, &QSlider::sliderReleased, [this]()
  {
    song_slider->setBusy(false);
    if (!media_player->currentMedia().isNull())
      media_player->setPosition(song_slider->value() * 1000);
    else
      song_slider->setValue(0);
  });
  connect(play_btn, &SwapCustomButton::clicked, [this]()
  {
    if (playlist->isEmpty())
      return;

    play_btn->swapIcon();
    if (media_player->state() == QMediaPlayer::PlayingState)
      media_player->pause();
    else if (media_player->state() == QMediaPlayer::PausedState || media_player->state() == QMediaPlayer::StoppedState)
      media_player->play();
  });
  connect(save, &QPushButton::clicked, [this]()
  {
    QUrl url = QFileDialog::getSaveFileUrl(this, tr("Save playlist"));
    playlist->save(url, "m3u");
  });
}

void MainWindow::addClicked()
{
  QStringList files = QFileDialog::getOpenFileNames(NULL, tr("Open Files"), QDir::homePath(), tr("Audio Files (*.mp3)"));

  if (!files.isEmpty())
  {
    foreach (QString file, files)
    {
      table->insertRow(table->rowCount());
      table->setItem(table->rowCount() - 1, 0, new QTableWidgetItem(QDir(file).dirName())); // song name
      playlist->addMedia(QUrl::fromLocalFile(file));
    }
  }
}

void MainWindow::metaDataChanged()
{
//  QStringList string_list = media_player->availableMetaData();
//  QString duration_str = media_player->metaData("Duration").toString();
//  int channer_count = media_player->metaData("ChannelCount").toInt();
//  QString audio_codec = media_player->metaData("AudioCodec").toString();
//  int sample_rate = media_player->metaData("SampleRate").toInt();
//  int audio_bit_rate = media_player->metaData("AudioBitRate").toInt();
//  QStringList auther_list = media_player->metaData("Author").toStringList();
//  QString album_title = media_player->metaData("AlbumTitle").toString();
//  QStringList genre = media_player->metaData("Genre").toStringList();
//  int track_number = media_player->metaData("TrackNumber").toInt();
//  int year = media_player->metaData("Year").toInt();
//  QStringList contributing_artist = media_player->metaData("ContributingArtist").toStringList();
  QString title = media_player->metaData(QMediaMetaData::Title).toString();

  qDebug() << "Title" << title;
  this->setWindowTitle(title);
}

void MainWindow::mediaPositionChanged(quint64 pos)
{
  pos = pos / 1000;
  QString tStr;
  if (pos || media_player->duration())
  {
    QTime currentTime((pos / 3600) % 60, (pos / 60) % 60,
      pos % 60, (pos * 1000) % 1000);

    QString format = "mm:ss";
    if (media_player->duration() / 1000 > 3600)
      format = "hh:mm:ss";

    tStr = currentTime.toString(format);
  }
  time_begin_lbl->setText(tStr);
  if (!song_slider->isBusy()) // cant move slider if it pressed
    song_slider->setValue(pos);
}

void MainWindow::mediaDurationChanged(quint64 dur)
{
  dur = dur / 1000;
  QString time_end;
  QTime totalTime((dur / 3600) % 60, (dur / 60) % 60,
    dur % 60, (dur * 1000) % 1000);

  QString format = "mm:ss";
  if (dur / 1000 > 3600)
    format = "hh:mm:ss";

  time_end = totalTime.toString(format);
  this->time_end_lbl->setText(time_end);
  song_slider->setRange(0, dur);
}

MainWindow::MainWindow(QWidget *parent): QWidget(parent)
{
  createInterior();
  connectSlots();
}

MainWindow::~MainWindow()
{

}
