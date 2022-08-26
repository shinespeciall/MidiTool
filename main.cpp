#include "MidiToolMainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MidiToolMainWindow w;
    w.show();
    return a.exec();
}
