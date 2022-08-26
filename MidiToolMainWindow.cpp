#include "MidiToolMainWindow.h"
#include "ui_MidiToolMainWindow.h"

#include <QTextEdit>
#include <QInputDialog>
#include <QMessageBox>

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
    midifile.read(ui->lineEdit_FilePath->text().toStdString());
    if (!midifile.status())
    {
        ui->textEdit->append("Problem reading MIDI file!");
        return;
    }
    midifile.doTimeAnalysis();
    midifile.linkNotePairs();

    updateMidiFileDataToTextBox();
}

void MidiToolMainWindow::on_pushButton_MergeAllTracks_clicked()
{
    midifile.joinTracks();

    updateMidiFileDataToTextBox();
}

void MidiToolMainWindow::on_pushButton_saveMidiFile_clicked()
{
    if (!ui->textEdit->toPlainText().size())
    {
        QMessageBox::information(this, tr("MidiTool"), tr("no opened file!"));
        return;
    }

    midifile.write(ui->lineEdit_FilePath->text().toStdString());

    QMessageBox::information(this, tr("MidiTool"), tr("save to the same file successfully!"));
}

void MidiToolMainWindow::on_pushButton_merge_tracks_clicked()
{
    int tracks = midifile.getTrackCount();
    int firstTrackId = QInputDialog::getInt(this, tr("MidiTool"), tr("input the first track id:"),
                                            0, 0, midifile.getNumTracks() - 1);
    if (firstTrackId >= tracks)
    {
        QMessageBox::information(this, tr("MidiTool"), tr("invalid Track ID!"));
        return;
    }
    int secondTrackId = QInputDialog::getInt(this, tr("MidiTool"), tr("input the second track id:"),
                                             0, 0, midifile.getNumTracks() - 1);
    if (firstTrackId >= tracks)
    {
        QMessageBox::information(this, tr("MidiTool"), tr("invalid Track ID!"));
        return;
    }

    midifile.mergeTracks(firstTrackId, secondTrackId);
    updateMidiFileDataToTextBox();
}

void MidiToolMainWindow::updateMidiFileDataToTextBox()
{
    int tracks = midifile.getTrackCount();
    QString output;
    output += "TPQ: " + QString::number(midifile.getTicksPerQuarterNote()) + "\n";
    if (tracks > 1)
    {
        output += "TRACKS: " + QString::number(tracks) + "\n";
    }
    for (int track = 0; track < tracks; track++)
    {
        if (tracks > 1) output += "\nTrack " + QString::number(track) + "\n";
        output += "Tick\tSeconds\tDur\tMessage\n";
        for (int event = 0; event < midifile[track].size(); event++)
        {
            output += QString::number(midifile[track][event].tick);
            output += '\t' + QString::number(midifile[track][event].seconds);
            output += '\t';
            if (midifile[track][event].isNoteOn())
            {
                output += QString::number(midifile[track][event].getDurationInSeconds());
            }
            output += '\t';
            for (int i = 0; i < (int)midifile[track][event].size(); i++)
            {
                output += QString::number(midifile[track][event][i]) + " ";
            }
            output += '\n';
        }
    }
    ui->textEdit->setText(output);
}

