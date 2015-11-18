#include "voicemanager.h"
#include <QDebug>

VoiceManager::VoiceManager()
{
}

OscillatorSource* VoiceManager::findFreeVoice() {
    OscillatorSource* freeVoice = NULL;
    for (int i = 0; i < NumberOfVoices; i++) {
            qDebug() << i << " " <<  voices[i].isActive;
        if (!voices[i].isActive) {
            freeVoice = &(voices[i]);
            break;
        }
    }
    return freeVoice;
}

void VoiceManager::noteOn(const int noteNumber,const int velocity) {
    OscillatorSource* voice = findFreeVoice();
    if (!voice) {
        return;
    }
    // int gain = velocity-127;
    voice->setNote(noteNumber);
    // voice->setGain(1);
    voice->isActive = true;
    voice->noteOn();
}

void VoiceManager::noteOff(int noteNumber) {
    // Find the voice(s) with the given noteNumber:

    for (int i = 0; i < NumberOfVoices; i++) {
        OscillatorSource& voice = voices[i];
        if (voice.isActive && voice.onoteNumber == noteNumber) {
            voice.isActive = false;
            voice.noteOff();
        }
    }
}
