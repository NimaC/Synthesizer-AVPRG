#ifndef ENVELOPE_H
#define ENVELOPE_H


class Envelope
{
public:
    enum State{OFF, ATTACK, DECAY, SUSTAIN, RELEASE};
    Envelope();
    void setSampleRate(float sampleRate);
    float process(float input);
    void setState(State state);
    void setReleaseSeconds(float seconds);
    void setAttackSeconds(float seconds);
    void setDecaySeconds(float seconds);
    void setSustain_dB(float sustain_dB);
<<<<<<< HEAD
    bool isOff();
=======
>>>>>>> 2373887b5c6b253f4256e0c99fadcf80f2be6b33
private:
    State state;
    float sampleRate;
    float gain;
    float gainChange;
    float releaseSeconds;
    float attackSeconds;
    float decaySeconds;
    float sustain_dB;
    float sustainGain;
    float minGain_dB;
    float minGain;
};

#endif // ENVELOPE_H
