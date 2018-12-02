#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    x = 1;
    y = 1;
    timerid = startTimer(30);
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    x += 1;
    y += 1;
    repaint();
    if(x == 500) {
        killTimer(timerid);
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{

    Q_UNUSED(event);
    //create a QPainter and pass a pointer to the device.
    //A paint device can be a QWidget, a QPixmap or a QImage

    QPainter painter(this);

/*
    //a simple line
    painter.drawLine(x, y, 100, 100);

    //create a black pen that has solid line
    //and the width is 2.
*/
    QPen myPen(Qt::black, 2, Qt::SolidLine);
/*
    painter.setPen(myPen);
    painter.drawLine(100,100,100,1);
*/
    //draw a point
    myPen.setColor(Qt::red);
    painter.drawPoint(x,1);
    painter.drawPoint(x,2);
    painter.drawPoint(x,3);
    painter.drawPoint(x,4);
    painter.drawPoint(x,5);
    painter.drawPoint(x,6);
    painter.drawPoint(x,7);
    painter.drawPoint(x,8);
    painter.drawPoint(x,9);
    painter.drawPoint(x,10);
/*
    //draw a polygon
    QPolygon polygon;
    polygon << QPoint(130, 140) << QPoint(180, 170)
             << QPoint(180, 140) << QPoint(220, 110)
             << QPoint(140, 100);
     painter.drawPolygon(polygon);

     //draw an ellipse
     //The setRenderHint() call enables antialiasing, telling QPainter to use different
     //color intensities on the edges to reduce the visual distortion that normally
     //occurs when the edges of a shape are converted into pixels
     painter.setRenderHint(QPainter::Antialiasing, true);
     painter.setPen(QPen(Qt::black, 3, Qt::DashDotLine, Qt::RoundCap));
     painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
     painter.drawEllipse(200, 80, 400, 240);
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}
