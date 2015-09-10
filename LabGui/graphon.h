//© Дмитрий Утямишев, 2011

#ifndef GRAPHON_H
#define GRAPHON_H

#include <windows.h>
#include <QGraphicsScene>
#include <QtCore>
#include <QString>
#include <QVector>
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QtCore>
#include <QTime>

enum Direction
{
    DUp = 0, DDown = 1, DLeft = 2, DRight = 3
};

class Graphon
{
public:
    Graphon();
    Graphon(QGraphicsScene *scene)
    {
        s = scene;
    }

    Graphon(QGraphicsView *vi)
    {
        v = vi;
        won = false;
    }

    bool ProcessWin(void)
    {
        if ((robposx == 0) || (robposy == 0) || (robposy == (sizey - 1)) || (robposx == (sizex - 1)))
        {
            this->won = true;
            return true;
        }
        else return false;

    }

    bool IsWon()
    {
        return won;
    }

    void Init(int x, int y, QString WallTile, QString EmpTile, QString Map)
    {
        sizex = x;
        sizey = y;
        s = new QGraphicsScene();
        mp.resize(y);
        for (int i =0 ; i < y; ++i)
        {
            mp[i].resize(x);
        }
        QFile file(Map);
        file.open(QFile::ReadOnly);
        QTextStream st(&file);
        QString tmp;
        char *buf = new char[x + 1];
        for (int yy = 0; yy < y; ++yy)
        {
        tmp = st.readLine();
        //file.readLine(buf, x + 1);
        for (int i = 0; i < x; ++i)
            {
            if (tmp[i] == 'W') mp[yy][i] = true;
            else mp[yy][i] = false;
            }
        }

        QPixmap *pixfull = new QPixmap(WallTile);
        QPixmap *pixemp = new QPixmap(EmpTile);

        for (int yy = 0; yy < y; ++yy)
        {
            for (int xx = 0; xx < x; ++xx)
            {
                QGraphicsPixmapItem *tile;
                if  (mp.at(yy).at(xx))
                {
                    tile = s->addPixmap(*pixfull);
                    tile->setPos(xx * 32, yy * 32);
                }
                else
                {
                    tile = s->addPixmap(*pixemp);
                    tile->setPos(xx * 32, yy * 32);
                }

            }
        }
        v->setScene(s);
    }

    void InitRobot(int xpos, int ypos, Direction di, QString tileU, QString tileD, QString tileL
                   ,QString tileR)
    {
        this->robposx = xpos;
        this->robposy = ypos;
        robDir = di;
        this->tD = new QPixmap(tileD);
        tU = new QPixmap(tileU);
        tL = new QPixmap(tileL);
        tR = new QPixmap(tileR);

        rob = s->addPixmap(*tD);

        if (robDir == DUp) this->rob->setPixmap(*tU);
        if (robDir == DRight) this->rob->setPixmap(*tR);
        if (robDir == DDown) this->rob->setPixmap(*tD);
        if (robDir == DLeft) this->rob->setPixmap(*tL);

        rob->setPos(robposx * 32, robposy * 32);
    }

    void ShowFail(QString failfile)
    {
        fail = new QPixmap(failfile);
        s->addPixmap(*fail);

        QTime dieTime = QTime::currentTime().addMSecs(5000);
        while( QTime::currentTime() < dieTime )
        {

            v->update();
            v->repaint();
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }
    }

    void ShowWon(QString wonfile)
    {
        win = new QPixmap(wonfile);
        s->addPixmap(*win);

        QTime dieTime = QTime::currentTime().addMSecs(5000);
        while( QTime::currentTime() < dieTime )
        {

            v->update();
            v->repaint();
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
        }


    }

    int Step()
    {
        if(this->ProcessWin()) return 1;
        if (robDir == DUp)
        {
            if (mp.at(robposy - 1).at(robposx) == false)
            {
                Move(robposx, robposy, robposx, robposy - 1);
                robposy--;
                return 1;
            }
            else return 0;
        }
         if (robDir == DDown)
            {
             b = mp.at(robposy + 1).at(robposx);
             if (b == false)
             {

                 Move(robposx, robposy, robposx, robposy + 1);
                 robposy++;
                 return 1;
             }
             else return 0;
            }
         if (robDir == DRight)
            {
             if (mp.at(robposy).at(robposx + 1) == false)
             {

                 Move(robposx, robposy, robposx + 1, robposy);
                 robposx++;
                 return 1;
             }
             else return 0;
            }
         if (robDir == DLeft)
            {
             if (mp.at(robposy).at(robposx - 1) == false)
             {

                 Move(robposx, robposy, robposx - 1, robposy);
                 robposx--;
                 return 1;
             }
             else return 0;
            }

    }


    void Move (int fromx, int fromy, int tox, int toy)
    {
        int time = GetTickCount();
       // while (GetTickCount() < (time + 500))
       // float speed = 0.1;
       // {
       //     rob->setPos((fromx * 32) + ((GetTickCount() - time)/500) * 32 * (tox-fromx),
       //                (fromy * 32) + ((GetTickCount() - time)/500) * 32* (toy-fromy));
       // }

       // rob->setPos(tox * 32, toy * 32);
        int dx = tox-fromx;
        int dy = toy - fromy;
        QTime dieTime = QTime::currentTime().addMSecs(500);
        QTime startTime = QTime::currentTime();
        while( QTime::currentTime() < dieTime )
        {
           //QTime::msecsTo(QTime::currentTime()) - QTime::msecsTo(startTime)
           // rob->setPos((fromx * 32) + ((startTime.msecsTo(QTime::currentTime()))/500) * 32 * (tox-fromx),
           //             (fromy * 32) + ((startTime.msecsTo(QTime::currentTime()))/500) * 32 * (toy-fromy));
            rob->setPos((fromx*32) + dx* (32 - 32*(QTime::currentTime().msecsTo(dieTime)/500)),
                        (fromy*32) + dy* (32 - 32*(QTime::currentTime().msecsTo(dieTime)/500)));
            v->update();
            v->repaint();
            QCoreApplication::processEvents(QEventLoop::AllEvents, 50);
        }

        v->update();
        v->repaint();


    }

    int Look()
    {
        if (robDir == DUp)
        {
            int i;
            for (i = 0; i < 32; ++i)
            {
                if (this->robposy-i < 0) return i;
                if (mp.at(this->robposy-i).at(robposx) == true)
                    break;
            }
            return i;
        }
         if (robDir == DDown)
            {
             int i;
             for (i = 0; i < 32; ++i)
             {
                 if (this->robposy+i > mp.size()) return i;
                 if (mp.at(this->robposy+i).at(robposx) == true)
                     break;
             }
             return i;
            }
         if (robDir == DRight)
            {
             int i;
             for (i = 0; i < 32; ++i)
             {
                 if (this->robposx+i > mp.at(0).size()) return i;
                 if (mp.at(this->robposy).at(robposx+i) == true)
                     break;
             }
             return i;
            }
         if (robDir == DLeft)
            {
             int i;
             for (i = 0; i < 32; ++i)
             {
                 if (this->robposx-i < 0) return i;
                 if (mp.at(this->robposy).at(robposx-i) == true)
                     break;
             }
             return i;
            }
    }

    void Back(void)
    {
        if (robDir == DLeft)
        {robDir = DRight;
            this->rob->setPixmap(*tR);
            QTime dieTime = QTime::currentTime().addMSecs(500);
            while( QTime::currentTime() < dieTime )
            {

                v->update();
                v->repaint();
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            }

        }
         if (robDir == DRight)
        {robDir = DLeft;
             rob->setPixmap(*tL);
             QTime dieTime = QTime::currentTime().addMSecs(500);
             while( QTime::currentTime() < dieTime )
             {

                 v->update();
                 v->repaint();
                 QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
             }
         }
          if (robDir == DUp)
         {robDir = DDown;
              rob->setPixmap(*tD);
              QTime dieTime = QTime::currentTime().addMSecs(500);
              while( QTime::currentTime() < dieTime )
              {

                  v->update();
                  v->repaint();
                  QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
              }
          }
          if (robDir == DDown) {
              robDir = DUp;
              rob->setPixmap(*tU);
              QTime dieTime = QTime::currentTime().addMSecs(500);
              while( QTime::currentTime() < dieTime )
              {

                  v->update();
                  v->repaint();
                  QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
              }
          }

    }

    void Left(void)
    {
        if (robDir == DLeft)
        {robDir = DDown;
            this->rob->setPixmap(*tD);
            QTime dieTime = QTime::currentTime().addMSecs(500);
            while( QTime::currentTime() < dieTime )
            {

                v->update();
                v->repaint();
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            }
            return;

        }
         if (robDir == DRight)
        {robDir = DUp;
             rob->setPixmap(*tU);
             QTime dieTime = QTime::currentTime().addMSecs(500);
             while( QTime::currentTime() < dieTime )
             {

                 v->update();
                 v->repaint();
                 QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
             }
             return;
         }
          if (robDir == DUp)
         {robDir = DLeft;
              rob->setPixmap(*tL);
              QTime dieTime = QTime::currentTime().addMSecs(500);
              while( QTime::currentTime() < dieTime )
              {

                  v->update();
                  v->repaint();
                  QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
              }
              return;
          }
          if (robDir == DDown) {
              robDir = DRight;
              rob->setPixmap(*tR);
              QTime dieTime = QTime::currentTime().addMSecs(500);
              while( QTime::currentTime() < dieTime )
              {

                  v->update();
                  v->repaint();
                  QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
              }
              return;
          }
            }

    void Right(void)
    {
        if (robDir == DLeft)
        {robDir = DUp;
            this->rob->setPixmap(*tU);
            QTime dieTime = QTime::currentTime().addMSecs(500);
            while( QTime::currentTime() < dieTime )
            {

                v->update();
                v->repaint();
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            }
            return;

        }
         if (robDir == DRight)
        {robDir = DDown;
             rob->setPixmap(*tD);
             QTime dieTime = QTime::currentTime().addMSecs(500);
             while( QTime::currentTime() < dieTime )
             {

                 v->update();
                 v->repaint();
                 QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
             }
             return;
         }
          if (robDir == DUp)
         {robDir = DRight;
              rob->setPixmap(*tR);
              QTime dieTime = QTime::currentTime().addMSecs(500);
              while( QTime::currentTime() < dieTime )
              {

                  v->update();
                  v->repaint();
                  QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
              }
              return;
          }
          if (robDir == DDown) {
              robDir = DLeft;
              rob->setPixmap(*tL);
              QTime dieTime = QTime::currentTime().addMSecs(500);
              while( QTime::currentTime() < dieTime )
              {

                  v->update();
                  v->repaint();
                  QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
              }
              return;
          }
    }

private:
    QVector <QVector <bool> > mp;
    QGraphicsScene *s;
    QGraphicsView *v;

    bool b;
    QGraphicsPixmapItem * rob;

    Direction robDir;

    int robposx, robposy;

    QPixmap *tU;
    QPixmap *tD;
    QPixmap *tL;
    QPixmap *tR;

    QPixmap *Begin;

    QPixmap *win;
    QPixmap *fail;
    bool won;

    int sizex, sizey;
};

#endif // GRAPHON_H
