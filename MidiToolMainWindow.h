#ifndef MIDITOOLMAINWINDOW_H
#define MIDITOOLMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MidiToolMainWindow; }
QT_END_NAMESPACE

class MidiToolMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MidiToolMainWindow(QWidget *parent = nullptr);
    ~MidiToolMainWindow();

private:
    Ui::MidiToolMainWindow *ui;
};
#endif // MIDITOOLMAINWINDOW_H
