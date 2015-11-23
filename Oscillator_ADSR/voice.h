#ifndef VOICE
#define VOICE

#include "oscillator.h"
#include "envelope.h"

class Voice
{
public:
    Voice();
    friend class OscillatorSource;
    void setSelectedOscillator(int index);
    void setFrequency(float frequency);
    void setNote(int noteNumber);
    void setGain(float decibel);
    void onNoteOn();
    void onNoteOff();
    void setAttackSeconds(float value);
    void setDecaySeconds(float value);
    void setReleaseSeconds(float value);
    void setSustain_dB(float value);

private:
    float createSample();
    Envelope envelope;
    Oscillator oscillator;
    bool isActive;
    int onoteNumber;
};

#endif // VOICE
