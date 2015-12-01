#ifndef OSCILLATORSOURCE_H
#define OSCILLATORSOURCE_H

#include <vector>

#include "audiosource.h"
#include "voicemanager.h"

class OscillatorSource: public AudioSource
{
public:
    OscillatorSource();
    virtual const QAudioFormat& format() const;
    virtual qint64 read(float** buffer, qint64 numFrames);
private:
    VoiceManager voicemanager;
    QAudioFormat audioFormat;
    const int sampleRate = 44100;
};

#endif // OSCILLATORSOURCE_H
