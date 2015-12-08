#ifndef OSCILLATORSOURCE_H
#define OSCILLATORSOURCE_H

#include <vector>
#include "audiosource.h"
#include "voicemanager.h"
#include "oscillator.h"
#include "envelope.h"
#include "voice.h"

class OscillatorSource: public AudioSource
{
public:
    OscillatorSource();
    virtual void start();
    virtual void stop();
    virtual const QAudioFormat& format() const;
    virtual qint64 read(float** buffer, qint64 numFrames);
    void noteOn(const int note, const int vel);
    void noteOff(const int note);
<<<<<<< HEAD
    void setAttackSeconds(float value);
    void setDecaySeconds(float value);
    void setReleaseSeconds(float value);
    void setSustain_dB(float value);
    void setSelectedOscillator(int index);
    void setGain(float decibel);
private:
=======
    const int getSampleRate();
private:
    const int sampleRate = 44100;
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
private:
    QAudioFormat audioFormat;
    static const int NumberOfVoices = 64;
    Voice voices[NumberOfVoices];
    Voice* findFreeVoice();
    float nextSample();
    Oscillator oscillator;
    Envelope envelope;
<<<<<<< HEAD
    float releaseSeconds;
    float attackSeconds;
    float decaySeconds;
    float sustain_dB;
    int osciIndex;
=======
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
};

#endif // OSCILLATORSOURCE
