#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QAudioInput>
#include <QAudioDecoder>
#include <QAudioFormat>
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , audioPlayer(this)

{
    ui->setupUi(this);
    initializeAudio();
    initializeMidi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeMidi(){
    QStringList connections = midiInput.connections(true);
    ui->comboBox->addItems(connections);
    if (connections.size() > 0){
        on_comboBox_activated(ui->comboBox->currentText());
    }

    connect(&midiInput, SIGNAL(midiNoteOn(const int, const int, const int)), this, SLOT(onMidiNoteOn(const int, const int, const int)));
    connect(&midiInput, SIGNAL(midiNoteOff(const int, const int, const int)), this, SLOT(onMidiNoteOff(const int, const int, const int)));

}

void MainWindow::initializeAudio(){
    on_frequencySlider_valueChanged(ui->frequencySlider->value());
    on_gainSlider_valueChanged(ui->gainSlider->value());
    on_dialAttack_valueChanged(ui->dialAttack->value());
    ui->labelAttack->setNum(ui->dialAttack->value());
    on_dialDecay_valueChanged(ui->dialDecay->value());
    ui->labelDecay->setNum(ui->dialDecay->value());
    on_dialSustain_valueChanged(ui->dialSustain->value());
    ui->labelSustain->setNum(ui->dialSustain->value());
    on_dialRelease_valueChanged(ui->dialRelease->value());
    ui->labelRelease->setNum(ui->dialRelease->value());

    audioPlayer.setAudioSource(&OscillatorSource);
    audioPlayer.start();
}

void MainWindow::on_comboBox_activated(const QString &string)
{
    midiInput.open(string);
}

void MainWindow::on_frequencySlider_valueChanged(int value)
{
    // 0 ... 100% --> 100Hz ... 10000Hz
    float scaledValue = 2 * value / 100.f + 2;
    float frequency = pow(10, scaledValue);

    ui->frequencyLabel->setText(QString::number((int)frequency));
    oscillator.setFrequency(frequency);
}

void MainWindow::on_waveformCombobox_activated(int index)
{
<<<<<<< HEAD
    OscillatorSource.setSelectedOscillator(index);
=======
    Voice.setSelectedOscillator(index);
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
}

void MainWindow::on_gainSlider_valueChanged(int value)
{
    Voice.setGain(value);
}

void MainWindow::onMidiNoteOff(const int chan, const int note, const int vel){
    OscillatorSource.noteOff(note);
}

void MainWindow::onMidiNoteOn(const int chan, const int note, const int vel){
    if (vel == 0){
        onMidiNoteOff(chan,note,vel);
    }
    else {
    OscillatorSource.noteOn(note,vel);
    }
}

void MainWindow::on_note_1_clicked(bool checked)
{
    qDebug() << "note 1";

    if (checked){
        OscillatorSource.noteOn(60,127);
    }
    else{
        OscillatorSource.noteOff(60);
    }
}

void MainWindow::on_note_2_clicked(bool checked)
{
    if (checked){
        OscillatorSource.noteOn(61,127);
    }
    else{
        OscillatorSource.noteOff(61);
    }
}

void MainWindow::on_note_3_clicked(bool checked)
{
    if (checked){
<<<<<<< HEAD
        OscillatorSource.noteOn(62,127);
    }
    else{
        OscillatorSource.noteOff(62);
=======
        OscillatorSource.noteOn(61,127);
    }
    else{
        OscillatorSource.noteOff(61);
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
    }
}
void MainWindow::on_note_4_clicked(bool checked)
{
    if (checked){
<<<<<<< HEAD
        OscillatorSource.noteOn(63,127);
    }
    else{
        OscillatorSource.noteOff(63);
=======
        OscillatorSource.noteOn(61,127);
    }
    else{
        OscillatorSource.noteOff(61);
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
    }
}
void MainWindow::on_note_5_clicked(bool checked)
{
    if (checked){
<<<<<<< HEAD
        OscillatorSource.noteOn(64,127);
    }
    else{
        OscillatorSource.noteOff(64);
=======
        OscillatorSource.noteOn(61,127);
    }
    else{
        OscillatorSource.noteOff(61);
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
    }
}
void MainWindow::on_note_6_clicked(bool checked)
{
    if (checked){
<<<<<<< HEAD
        OscillatorSource.noteOn(65,127);
    }
    else{
        OscillatorSource.noteOff(65);
=======
        OscillatorSource.noteOn(61,127);
    }
    else{
        OscillatorSource.noteOff(61);
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
    }
}
void MainWindow::on_note_7_clicked(bool checked)
{
    if (checked){
<<<<<<< HEAD
        OscillatorSource.noteOn(66,127);
    }
    else{
        OscillatorSource.noteOff(66);
=======
        OscillatorSource.noteOn(61,127);
    }
    else{
        OscillatorSource.noteOff(61);
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
    }
}
void MainWindow::on_note_8_clicked(bool checked)
{
    if (checked){
<<<<<<< HEAD
        OscillatorSource.noteOn(67,127);
    }
    else{
        OscillatorSource.noteOff(67);
=======
        OscillatorSource.noteOn(61,127);
    }
    else{
        OscillatorSource.noteOff(61);
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
    }
}
void MainWindow::on_note_9_clicked(bool checked)
{
    if (checked){
<<<<<<< HEAD
        OscillatorSource.noteOn(68,127);
    }
    else{
        OscillatorSource.noteOff(68);
=======
        OscillatorSource.noteOn(61,127);
    }
    else{
        OscillatorSource.noteOff(61);
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
    }
}
void MainWindow::on_note_10_clicked(bool checked)
{
    if (checked){
<<<<<<< HEAD
        OscillatorSource.noteOn(69,127);
    }
    else{
        OscillatorSource.noteOff(69);
=======
        OscillatorSource.noteOn(61,127);
    }
    else{
        OscillatorSource.noteOff(61);
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
    }
}
void MainWindow::on_note_11_clicked(bool checked)
{
    if (checked){
<<<<<<< HEAD
        OscillatorSource.noteOn(70,127);
    }
    else{
        OscillatorSource.noteOff(70);
=======
        OscillatorSource.noteOn(61,127);
    }
    else{
        OscillatorSource.noteOff(61);
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
    }
}
void MainWindow::on_note_12_clicked(bool checked)
{
    if (checked){
<<<<<<< HEAD
        OscillatorSource.noteOn(71,127);
    }
    else{
        OscillatorSource.noteOff(71);
=======
        OscillatorSource.noteOn(61,127);
    }
    else{
        OscillatorSource.noteOff(61);
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
    }
}

void MainWindow::on_dialAttack_valueChanged(int value)
{
<<<<<<< HEAD
    OscillatorSource.setAttackSeconds(value/100.f);
=======
    Voice.setAttackSeconds(value/100.f);
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
}

void MainWindow::on_dialDecay_valueChanged(int value)
{
<<<<<<< HEAD
    OscillatorSource.setDecaySeconds(value/100.f);
=======
    Voice.setDecaySeconds(value/100.f);
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
}

void MainWindow::on_dialSustain_valueChanged(int value)
{
<<<<<<< HEAD
    OscillatorSource.setSustain_dB(value - 100);
=======
    Voice.setSustain_dB(value - 100);
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
}

void MainWindow::on_dialRelease_valueChanged(int value)
{
<<<<<<< HEAD
    OscillatorSource.setReleaseSeconds(value/20.f);
=======
    Voice.setReleaseSeconds(value/100.f);
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
}
