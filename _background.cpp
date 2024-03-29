#include "background.h"
#include "player.h"
#include "box.h"
#include "block.h"
#include "main.h"
#include "ground.h"
#include "sokoban.h"

background::background(QWidget *here, int i)
{
    //welcome sokoban
    lab_back = new QLabel(here);
    lab_back->setGeometry(5, 140, 1080, 276);
    QPixmap pix_sokoban(":/res/PNG/sokoban.png");
    lab_back->setPixmap(pix_sokoban);
    lab_back->setScaledContents(true);

    //capoo gif
    //Chen Yen Po 的 PROJECT 2
    QMovie *movie_capoo_gif_400_300 = new QMovie(":/res/PNG/capoo_392_316.gif");
    lab_capoo_gif = new QLabel(here);
    lab_capoo_gif->setGeometry(1060, 130, 392, 316);
    lab_capoo_gif->setMovie(movie_capoo_gif_400_300);
    movie_capoo_gif_400_300->start();
    lab_capoo_gif->show();

    //rule
    lab_rule = new QLabel(here);
    lab_rule->setGeometry(0, 26, 1242, 548);
    QPixmap pix_rule(":/res/PNG/rule.png");
    lab_rule->setPixmap(pix_rule);
    lab_rule->setScaledContents(true);
    lab_rule->hide();

    //player

    if (i != 0)
        lab_back->hide();
    lab_you_win = new QLabel(here);
    lab_special_win = new QLabel(here);

    //font
    QFont font;
    font.setFamily("SetoFont");
    font.setPixelSize(50);
    lab_you_win->setText("YOU WIN!");
    lab_you_win->setGeometry(802, 350, 200, 200);
    lab_you_win->setFont(font);
    lab_you_win->hide();

    QFont font_SP;
    font_SP.setFamily("SetoFont");
    font_SP.setPixelSize(30);
    lab_special_win->setText("SPECIAL WIN!");
    lab_special_win->setGeometry(810, 350, 200, 200);
    lab_special_win->setFont(font_SP);
    lab_special_win->hide();
    //sound
    poke = new QMediaPlayer;
    poke->setMedia(QUrl("qrc:/res/MP3/poke.mp3"));
    poke->setVolume(30);

    running = new QMediaPlayer;
    running->setMedia(QUrl("qrc:/res/MP3/running.mp3"));
    running->setVolume(20);

    eating = new QMediaPlayer;
    eating->setMedia(QUrl("qrc:/res/MP3/eating.mp3"));
    eating->setVolume(30);

    select = new QMediaPlayer;
    select->setMedia(QUrl("qrc:/res/MP3/select.mp3"));
    select->setVolume(30);

    special_open = new QMediaPlayer;
    special_open->setMedia(QUrl("qrc:/res/MP3/iron_door2_O.mp3"));
    special_open->setVolume(50);

    bravo = new QMediaPlayer;
    bravo->setMedia(QUrl("qrc:/res/MP3/clapping_bravo.mp3"));
    bravo->setVolume(50);
}
