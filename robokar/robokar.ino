// == pins configuration ==
int MOTOR_LEFT = 5;
int MOTOR_LEFT_BACKWARD = 7;
int MOTOR_LEFT_FORWARD = 6;
int MOTOR_RIGHT = 10;
int MOTOR_RIGHT_BACKWARD = 9;
int MOTOR_RIGHT_FORWARD = 8;

// == car movement ==
int WHEELS_LEFT = 1;               // 01
int WHEELS_RIGHT = 2;              // 10
int WHEELS_DIRECTION_BRAKE = 0;    // 00
int WHEELS_DIRECTION_FORWARD = 1;  // 01
int WHEELS_DIRECTION_BACKWARD = 2; // 10
int WHEELS_STATUS_ON = HIGH;
int WHEELS_STATUS_OFF = LOW;

// == startup configuration ==
void setup()
{
    // set motor pins
    pinMode(MOTOR_LEFT, OUTPUT);
    pinMode(MOTOR_LEFT_BACKWARD, OUTPUT);
    pinMode(MOTOR_LEFT_FORWARD, OUTPUT);
    pinMode(MOTOR_RIGHT, OUTPUT);
    pinMode(MOTOR_RIGHT_BACKWARD, OUTPUT);
    pinMode(MOTOR_RIGHT_FORWARD, OUTPUT);
}

// == main program ==
void loop()
{
    test_wheels();
    delay(1000);
}

// == wheels test ==
void test_wheels(void)
{
    move(WHEELS_LEFT | WHEELS_RIGHT, WHEELS_DIRECTION_FORWARD, WHEELS_STATUS_ON);
    delay(500);
    move(WHEELS_LEFT | WHEELS_RIGHT, WHEELS_DIRECTION_FORWARD, WHEELS_STATUS_OFF);
    delay(500);
    move(WHEELS_LEFT | WHEELS_RIGHT, WHEELS_DIRECTION_BACKWARD, WHEELS_STATUS_ON);
    delay(500);
    move(WHEELS_LEFT | WHEELS_RIGHT, WHEELS_DIRECTION_BACKWARD, WHEELS_STATUS_OFF);
    delay(500);
    move(WHEELS_LEFT, WHEELS_DIRECTION_FORWARD, WHEELS_STATUS_ON);
    delay(500);
    move(WHEELS_LEFT | WHEELS_RIGHT, WHEELS_DIRECTION_FORWARD, WHEELS_STATUS_OFF);
    delay(500);
    move(WHEELS_RIGHT, WHEELS_DIRECTION_FORWARD, WHEELS_STATUS_ON);
    delay(500);
    move(WHEELS_LEFT | WHEELS_RIGHT, WHEELS_DIRECTION_FORWARD, WHEELS_STATUS_OFF);
    delay(500);
    move(WHEELS_RIGHT, WHEELS_DIRECTION_FORWARD, WHEELS_STATUS_ON);
    move(WHEELS_LEFT, WHEELS_DIRECTION_BACKWARD, WHEELS_STATUS_ON);
    delay(500);
    move(WHEELS_LEFT | WHEELS_RIGHT, WHEELS_DIRECTION_FORWARD, WHEELS_STATUS_OFF);
    delay(500);
}

// == move the car ==
// wheels: wheels to move, left or right. for all wheels use 'left | right'
// direction: movement direction - forward, backward or brake
// status: wheels status - on or off
// braking will stop the car faster than turning the motors off
void move(int wheels, int direction, int status)
{
    if (wheels & WHEELS_LEFT)
    {
        // left wheels
        digitalWrite(MOTOR_LEFT, status);
        digitalWrite(MOTOR_LEFT_BACKWARD, direction & WHEELS_DIRECTION_BACKWARD);
        digitalWrite(MOTOR_LEFT_FORWARD, direction & WHEELS_DIRECTION_FORWARD);
    }
    if (wheels & WHEELS_RIGHT)
    {
        // right wheels
        digitalWrite(MOTOR_RIGHT, status);
        digitalWrite(MOTOR_RIGHT_BACKWARD, direction & WHEELS_DIRECTION_BACKWARD);
        digitalWrite(MOTOR_RIGHT_FORWARD, direction & WHEELS_DIRECTION_FORWARD);
    }
}
