#ifndef MIDITOOLMAINWINDOW_H
#define MIDITOOLMAINWINDOW_H

#include <QMainWindow>

#include "MidiFile.h"

using namespace std;
using namespace smf;

QT_BEGIN_NAMESPACE
namespace Ui { class MidiToolMainWindow; }
QT_END_NAMESPACE

class MidiToolMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MidiToolMainWindow(QWidget *parent = nullptr);
    ~MidiToolMainWindow();

private slots:
    void on_pushButton_LoadFile_clicked();
    void on_pushButton_MergeAllTracks_clicked();
    void on_pushButton_saveMidiFile_clicked();

private:
    Ui::MidiToolMainWindow *ui;
    MidiFile *midifile = nullptr;
};
#endif // MIDITOOLMAINWINDOW_H
