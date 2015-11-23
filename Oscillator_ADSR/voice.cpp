#include "voice.h"
#include <math.h>

Voice::Voice()
:   isActive(false), onoteNumber(0)
{}

void Voice::setSelectedOscillator(int index){
    oscillator.setType((Oscillator::Type)index);
}

void Voice::setFrequency(float frequency){
    oscillator.setFrequency(frequency);
}

void Voice::setNote(int noteNumber){
    onoteNumber = noteNumber;
    float frequency = 440.0 * pow(2.0, (noteNumber - 69.0)/12.0);
    setFrequency(frequency);
}

void Voice::setGain(float decibel){
    float gain = pow(10, decibel/20.f);
    oscillator.setGain(gain);
}

void Voice::onNoteOn(){
    envelope.setState(Envelope::ATTACK);
}

void Voice::onNoteOff(){
    envelope.setState(Envelope::RELEASE);
}

void Voice::setAttackSeconds(float value){
    envelope.setAttackSeconds(value);
}

void Voice::setDecaySeconds(float value){
    envelope.setDecaySeconds(value);
}

void Voice::setReleaseSeconds(float value){
    envelope.setReleaseSeconds(value);
}

void Voice::setSustain_dB(float value){
    envelope.setSustain_dB(value);
}

float Voice::createSample(){
    if (!isActive) return 0.0;
    float sample = oscillator.getValue();
    sample = envelope.process(sample);
    return sample;
}
