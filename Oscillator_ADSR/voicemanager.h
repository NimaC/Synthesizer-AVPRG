#ifndef VOICEMANAGER
#define VOICEMANAGER
#include "oscillatorsource.h"

class VoiceManager
{
public:
    VoiceManager();
    void noteOn(const int note, const int vel);
    void noteOff(const int note);
private:
    static const int NumberOfVoices = 64;
    OscillatorSource voices[NumberOfVoices];
    OscillatorSource* findFreeVoice();
    };
#endif // VOICEMANAGER
