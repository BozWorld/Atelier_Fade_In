//variable about the potentiomètre
int pot = 0;
int tempPot = 0;
//variable for the button and his state
int button = 4;
int buttonState = 0;
int lastButtonState = 0;
int buttonPushCounter = 0;
//Led and is lightning
int led = 3;
int brightness = 0;
//Variable for the delay
int time;
int wait;
int start;

void setup()
{
    pinMode(button, INPUT_PULLUP);
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop()
{

    tempPot = analogRead(pot);
    buttonState = digitalRead(button);
    time = map(tempPot, 0, 1023, 500, 5000);
    start = millis();
    wait = 0;
    if (buttonState == lastButtonState && buttonState == LOW)
    {
        buttonPushCounter++;
        while (wait <= time)
        {
            brightness = map(wait, 0, time, 0, 255);
            analogWrite(led, brightness);
            wait = millis() - start;
        }
        buttonState = buttonPushCounter;
    }
    lastButtonState = buttonState;
    if (buttonState != lastButtonState && buttonState == LOW)
    {
        while (brightness != 0)
        {
            Serial.print(lastButtonState);
            brightness = map(wait, 0, time, 255, 0);
            analogWrite(led, brightness);
            wait = millis() - start;
        }
    }
}