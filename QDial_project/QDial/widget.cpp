#include "widget.h"
#include "ui_widget.h"


//https://fishc.com.cn/thread-56597-1-1.html
//https://blog.csdn.net/CLHJSWE/article/details/81448723

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //https://blog.51cto.com/whylinux/1877629
    setWindowIcon(QIcon(QString::fromUtf8(":/mchp_icon.png")));



    QImage* img=new QImage;
    img->load(":/mchp_icon.png"); //加载图像

    QImage smallImg = img->scaled(ui->labelMCHPicon->width(), ui->labelMCHPicon->height(),Qt::KeepAspectRatio);

//    ui->labelMCHPicon->resize(smallImg.width(),smallImg.height());

    ui->labelMCHPicon->setPixmap(QPixmap::fromImage(smallImg));

//    ui->labelMCHPicon->setGeometry(0,0,100,50);


//    https://fishc.com.cn/thread-56597-1-1.html
//    https://blog.csdn.net/CLHJSWE/article/details/81448723


//    dial = new QDial;
//    spinBox = new QSpinBox;

//    dial->setMaximum(60);
//    dial->setMinimum(0);
//    dial->setValue(1);
//    //dial->setNotchTarget(1.0);
//    //dial->setSingleStep(1);
//    //dial->notchTarget();
//    //dial->notchesVisible();
//    //dial->setWrapping(true);

    ui->dial_2->setMaximum(100);
    ui->dial_2->setMinimum(0);
    ui->dial_2->setValue(0);
    ui->dial_2->setPageStep(5);
    ui->dial_2->setNotchTarget(5);
    ui->dial_2->setNotchesVisible(true);

//    ui->dial_2->setStyle(QStyleFactory::create("Windows"));
    ui->dial_2->setStyle(QStyleFactory::create("Fusion"));

//    ui->dial_2->setWrapping(true);





    //dial->setNotchTarget(1.0);
    //dial->setSingleStep(1);
    //dial->notchTarget();
    //dial->notchesVisible();
    //dial->setWrapping(true);

//    spinBox->setMaximum(60);
//    spinBox->setMinimum(0);
//    spinBox->setValue(1);

    connect(ui->dial_2,SIGNAL(valueChanged(int)),ui->lcdNumber,SLOT(display(int)));
//    connect(ui->dial_2,SIGNAL(valueChanged(int)),spinBox,SLOT(setValue(int)));

//    QVBoxLayout *mainLayout = new QVBoxLayout;
//    mainLayout->addWidget(dial);
//    mainLayout->addWidget(spinBox);
//    this->setLayout(mainLayout);

//    this->resize(300,300);


    //Touch test graphic
//    https://blog.csdn.net/humanking7/article/details/88065087
    const QString m_red_SheetStyle = "min-width: 110px; min-height: 110px;max-width: 110px; max-height: 110px; border-radius: 55px;  border:1px solid black;background:red";
    const QString m_green_SheetStyle = "min-width: 110px; min-height: 110px;max-width:110px; max-height: 110px;border-radius: 55px;  border:1px solid black;background:green";

    ui->labelTouch1->move(25,20);
    ui->labelTouch2->move(160,20);
    ui->labelTouch1->setStyleSheet(m_red_SheetStyle);//改成 红色圆形
    ui->labelTouch2->setStyleSheet(m_green_SheetStyle);//改成 红色圆形


    //Andy added 0819
    //init timer
    myTimer = new QTimer(this);
    myTimer->start(1000);                   //以1000毫秒為周期起動定時器
    connect(myTimer,SIGNAL(timeout()),this,SLOT(showTime()));
}

Widget::~Widget()
{
    delete ui;
}
//Andy added 0819
void Widget::showTime()
{
    QTime time = QTime::currentTime();
    QString text=time.toString("hh:mm:ss"); //設定顯示時間格式
    ui->lcdNumber->display(text);

    ui->textBrowserDebug->append(QString("%1").arg(text));

    ui->textBrowserDebug->append(QString("%1, %2").arg(20, 3, 16).toUtf8());
    ui->textBrowserDebug->append(QString().sprintf("%x, %x, %x", 20, 30, 40));
}

void Widget::on_pushButtonClearText_clicked()
{
    ui->textBrowserDebug->clear();
}
