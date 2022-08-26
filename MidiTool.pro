QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# to deal with header and cpp files in midifile submodules not in some convenient folders
INCLUDEPATH += dependencies/midifile/src \
               dependencies/midifile/include

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    MidiToolMainWindow.cpp \
    dependencies/midifile/src/Binasc.cpp \
    dependencies/midifile/src/MidiEvent.cpp \
    dependencies/midifile/src/MidiEventList.cpp \
    dependencies/midifile/src/MidiFile.cpp \
    dependencies/midifile/src/MidiMessage.cpp \
    dependencies/midifile/src/Options.cpp

HEADERS += \
    MidiToolMainWindow.h \
    dependencies/midifile/include/Binasc.h \
    dependencies/midifile/include/MidiEvent.h \
    dependencies/midifile/include/MidiEventList.h \
    dependencies/midifile/include/MidiFile.h \
    dependencies/midifile/include/MidiMessage.h \
    dependencies/midifile/include/Options.h

FORMS += \
    MidiToolMainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
