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
    audioFormat.setSampleRate(sampleRate);
}

const int OscillatorSource::getSampleRate() {
    return sampleRate;
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
            qDebug() << i << " " <<  voices[i].isActive;
        if (!voices[i].isActive) {
            freeVoice = &(voices[i]);
            break;
        }
    }
    return freeVoice;
}

void OscillatorSource::noteOn(const int noteNumber,const int velocity) {
    Voice* voice = findFreeVoice();
    if (!voice) {
        return;
    }
    int gain = velocity-127;
    voice->setNote(noteNumber);
    voice->setGain(gain);
    voice->isActive = true;
    voice->onNoteOn();
}

void OscillatorSource::noteOff(int noteNumber) {
    // Find the voice(s) with the given noteNumber:
    for (int i = 0; i < NumberOfVoices; i++) {
        Voice& voice = voices[i];
        if (voice.isActive && voice.onoteNumber == noteNumber) {
            voice.isActive = false;
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
