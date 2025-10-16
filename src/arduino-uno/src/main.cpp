// Exemple MPU6050

#include <Adafruit_MPU6050.h> // Pour l'accéléromètre MPU6050
#include <Adafruit_Sensor.h>  // Pour les capteurs Adafruit
#include <Wire.h>             // pour la communication I2C (SDA et SCL)

#define DEBUG

#define PERIODE_ATTENTE  5000 // Période d'attente entre deux mesures en ms
#define BROCHE_LED_VERTE 2    // Broche de la Led verte

Adafruit_MPU6050 mpu;

void setup(void)
{
    Serial.begin(115200);

    Serial.println("Test MPU6050");

    // initialisation de l'accéléromètre
    if(!mpu.begin())
    {
        Serial.println("MPU6050 non détecté !");
        while(1) /* true : boucle infinie */
        {
            delay(10);
        }
    }
    Serial.println("MPU6050 détecté !");

    // configuration de l'accéléromètre
    // mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
    Serial.print("Plage de l'accéléromètre définie sur : ");
    switch(mpu.getAccelerometerRange())
    {
        case MPU6050_RANGE_2_G:
            Serial.println("+-2G");
            break;
        case MPU6050_RANGE_4_G:
            Serial.println("+-4G");
            break;
        case MPU6050_RANGE_8_G:
            Serial.println("+-8G");
            break;
        case MPU6050_RANGE_16_G:
            Serial.println("+-16G");
            break;
    }

    // initialisation de la Led verte
    pinMode(BROCHE_LED_VERTE, OUTPUT);
}

void loop()
{
    sensors_event_t event;

    // lecture de l'accéléromètre
    mpu.getAccelerometerSensor()->getEvent(&event);

    // allumer la Led verte
    digitalWrite(BROCHE_LED_VERTE, HIGH);

#ifdef DEBUG
    Serial.print("[");
    Serial.print(millis());
    Serial.print("] X: ");
    Serial.print(event.acceleration.x);
    Serial.print(", Y: ");
    Serial.print(event.acceleration.y);
    Serial.print(", Z: ");
    Serial.print(event.acceleration.z);
    Serial.println(" m/s^2");
#endif

    // éteindre la Led verte
    delay(100);
    digitalWrite(BROCHE_LED_VERTE, LOW);

    // attente périodique en ms
    delay(PERIODE_ATTENTE);
}
