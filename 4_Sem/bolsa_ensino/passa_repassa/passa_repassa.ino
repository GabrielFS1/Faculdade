const int buttonRight = 4;
const int buttonLeft = 2;
const int buttonReset = 3;

const int rightLED = 5;
const int leftLED = 6;
const int siren = 7;

int buttonRightState = 0;
int buttonLeftState = 0;
int buttonResetState = 0;

int pauseGame = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(buttonRight, INPUT);
    pinMode(buttonLeft, INPUT);
    pinMode(buttonReset, INPUT);
    
    pinMode(rightLED, OUTPUT);
    pinMode(leftLED, OUTPUT);
    pinMode(siren, OUTPUT);

    digitalWrite(rightLED, LOW);
    digitalWrite(leftLED, LOW);
    digitalWrite(siren, LOW);
}

void loop()
{
    buttonRightState = digitalRead(buttonRight);
    buttonLeftState = digitalRead(buttonLeft);
    buttonResetState = digitalRead(buttonReset);

    if (buttonResetState == HIGH && pauseGame == 1)
    {
        Serial.print("Jogo Resetado\n");
        pauseGame = 0;
        digitalWrite(rightLED, LOW);
        digitalWrite(leftLED, LOW);    
    }
    
    else if (buttonRightState == HIGH && pauseGame == 0)
    {
        Serial.print("Botao Direita");
        pauseGame = 1;
        digitalWrite(rightLED, HIGH);
        playSiren();
    }
    
    else if (buttonLeftState == HIGH && pauseGame == 0)
    {
        Serial.print("Botao Esquerda");
        pauseGame = 1;
        digitalWrite(leftLED, HIGH);
        playSiren();
    }
}

void playSiren()
{
    digitalWrite(siren, HIGH);
    delay(1000);
    digitalWrite(siren, LOW);
}
