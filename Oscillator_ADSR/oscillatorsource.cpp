#include <math.h>
#include "oscillatorsource.h"
#include <QDebug>

OscillatorSource::OscillatorSource()
{
    audioFormat.setCodec("audio/pcm");
    audioFormat.setByteOrder(QAudioFormat::LittleEndian);
    audioFormat.setChannelCount(2);
    audioFormat.setSampleSize(32);
    audioFormat.setSampleType(QAudioFormat::Float);
<<<<<<< HEAD
    audioFormat.setSampleRate(44100);
=======
    audioFormat.setSampleRate(sampleRate);
}

const int OscillatorSource::getSampleRate() {
    return sampleRate;
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
}

void OscillatorSource::start(){
    oscillator.initialize(audioFormat.sampleRate());
    envelope.setSampleRate(audioFormat.sampleRate());
}

const QAudioFormat& OscillatorSource::format() const{
    return audioFormat;
}

qint64 OscillatorSource::read(float** buffer, qint64 numFrames){
    // get audio data for left channel
    for(int i = 0; i < numFrames; i++){
        buffer[0][i] = nextSample();
    }
    // copy to other channels
    for(int c = 0; c < audioFormat.channelCount(); c++){
        for(int i = 0; i < numFrames; i++){
            buffer[c][i] = buffer[0][i];
        }
    }
    return numFrames;
}

Voice* OscillatorSource::findFreeVoice() {
    Voice* freeVoice = NULL;
    for (int i = 0; i < NumberOfVoices; i++) {
<<<<<<< HEAD
        voices[i].setInactive();
       //qDebug() << i << " " <<  voices[i].isActive;
=======
            qDebug() << i << " " <<  voices[i].isActive;
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
        if (!voices[i].isActive) {
            freeVoice = &(voices[i]);
            break;
        }
    }
    return freeVoice;
}

<<<<<<< HEAD
void OscillatorSource::setSelectedOscillator(int index){
    osciIndex = index;
}

void OscillatorSource::setAttackSeconds(float value){
    attackSeconds=value;
}

void OscillatorSource::setDecaySeconds(float value){
    decaySeconds=value;
}

void OscillatorSource::setReleaseSeconds(float value){
    releaseSeconds=value;
}

void OscillatorSource::setSustain_dB(float value){
    sustain_dB=value;
}

=======
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
void OscillatorSource::noteOn(const int noteNumber,const int velocity) {
    Voice* voice = findFreeVoice();
    if (!voice) {
        return;
    }
<<<<<<< HEAD
    float vel = velocity-127;
    voice->setGain(-10);
    voice->setNote(noteNumber);
    voice->setSelectedOscillator(osciIndex);
    voice->setAttackSeconds(attackSeconds);
    voice->setDecaySeconds(decaySeconds);
    voice->setReleaseSeconds(releaseSeconds);
    voice->setSustain_dB(sustain_dB);
=======
    int gain = velocity-127;
    voice->setNote(noteNumber);
    voice->setGain(gain);
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
    voice->isActive = true;
    voice->onNoteOn();
}

void OscillatorSource::noteOff(int noteNumber) {
    // Find the voice(s) with the given noteNumber:
    for (int i = 0; i < NumberOfVoices; i++) {
        Voice& voice = voices[i];
        if (voice.isActive && voice.onoteNumber == noteNumber) {
<<<<<<< HEAD
=======
            voice.isActive = false;
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
            voice.onNoteOff();
        }
    }
}

float OscillatorSource::nextSample() {
    float output = 0;
    for (int i = 0; i < NumberOfVoices; i++) {
        Voice& voice = voices[i];
        output += voice.createSample();
    }
    return output;
}

void OscillatorSource::stop(){}
