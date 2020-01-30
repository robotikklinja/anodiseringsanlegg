typedef enum {
    DEPTH,
    WIDTH,
    LENGTH
} MotorTypes;

class StepMotor {
private:
    const int alm;
    const int dir;
    const int pul;
    const MotorTypes type;
public:
    StepMotor(MotorTypes, int, int, int);
    void alarm(bool) const;
    void direction(bool) const;
    void pull(bool) const;
};

StepMotor::StepMotor(MotorTypes type, int alm, int dir, int pul)
    : alm(alm), dir(dir), pul(pul), type(type) {
    pinMode(alm, OUTPUT);
    pinMode(dir, OUTPUT);
    pinMode(pul, OUTPUT);
}

void StepMotor::alarm(bool state) const {
    digitalWrite(alm, state);
}

void StepMotor::direction(bool state) const {
    digitalWrite(dir, state);
}

void StepMotor::pull(bool state) const {
    digitalWrite(pul, state);
}

class Controller {
public:
    const static StepMotor servos[];
    Controller();
};

const StepMotor Controller::servos[] = { StepMotor(WIDTH, 3, 2, 4) };

Controller::Controller() {
  servos[0].alarm(true);
}

void setup() {
    Controller controller;
}

void loop() {

}
