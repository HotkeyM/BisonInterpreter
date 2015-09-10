//© Дмитрий Утямишев, 2011

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "string"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    g = new Graphon(ui->graphicsView);
    d.g = g;
    d.e = ui->textEdit;
    g->Init(10,10, "wall.png", "emp.png","map.txt");
    g->InitRobot(1,1, DDown, "BotU.png","BotD.png","BotL.png","BotR.png");

    ui->lineEdit->setText("r.txt");
   // d.parse(ui->lineEdit->text().toStdString());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString s;
    QFile f(ui->lineEdit->text());
    f.open(QFile::ReadOnly);
    s.append(f.readAll());
    s.toLower();
    f.close();

    QFile f2("tmp.txt");
    f2.open(QFile::WriteOnly);
    f2.write(s.toAscii());
    f2.close();

    d.parse(std::string("tmp.txt"));
    if (g->IsWon()) g->ShowWon("win.png");
    else g->ShowFail("fail.jpg");
    this->close();
}
