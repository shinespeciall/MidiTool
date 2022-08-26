#include "MidiToolMainWindow.h"
#include "ui_MidiToolMainWindow.h"

#include <QTextEdit>


MidiToolMainWindow::MidiToolMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MidiToolMainWindow)
{
    ui->setupUi(this);
}

MidiToolMainWindow::~MidiToolMainWindow()
{
    delete ui;
}


void MidiToolMainWindow::on_pushButton_LoadFile_clicked()
{
    midifile->read(ui->lineEdit_FilePath->text().toStdString());
    if (!midifile->status())
    {
        ui->textEdit->append("Problem reading MIDI file!");
        return;
    }
}


void MidiToolMainWindow::on_pushButton_MergeAllTracks_clicked()
{
    midifile->joinTracks();
}


void MidiToolMainWindow::on_pushButton_saveMidiFile_clicked()
{
    midifile->write(ui->lineEdit_FilePath->text().toStdString());
}

