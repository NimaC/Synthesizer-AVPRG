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
    const int getSampleRate();
private:
    const int sampleRate = 44100;
private:
    QAudioFormat audioFormat;
    static const int NumberOfVoices = 64;
    Voice voices[NumberOfVoices];
    Voice* findFreeVoice();
    float nextSample();
    Oscillator oscillator;
    Envelope envelope;
};

#endif // OSCILLATORSOURCE
