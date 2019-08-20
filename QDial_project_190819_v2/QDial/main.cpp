#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

//    https://blog.csdn.net/chenlong12580/article/details/7428733
    QStringList keyList = QStyleFactory::keys();

    for(int i = 0; i < keyList.length(); i++)
    {
        qDebug(keyList.at(i).toUtf8());
    }



    return a.exec();
}
