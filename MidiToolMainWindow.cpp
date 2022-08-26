#include "MidiToolMainWindow.h"
#include "ui_MidiToolMainWindow.h"

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

