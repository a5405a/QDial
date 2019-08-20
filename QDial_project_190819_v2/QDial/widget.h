#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QDial>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QStyleFactory>

#include <QTimer>
#include <QTime>


QT_BEGIN_NAMESPACE
class QDial;
class QSpinBox;
QT_END_NAMESPACE


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void showTime();  //顯示時間的函式

private:
    Ui::Widget *ui;


    //Andy added 0819
    QTimer *myTimer;

//    QDial *dial;
//    QSpinBox *spinBox;
};

#endif // WIDGET_H
