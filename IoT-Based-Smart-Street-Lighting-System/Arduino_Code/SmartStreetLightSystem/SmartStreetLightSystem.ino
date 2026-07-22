#define BLYNK_TEMPLATE_ID "YOUR_BLYNK_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Smart Street Light"
#define BLYNK_AUTH_TOKEN "4AyB17v36qX4V1DbPEBpU15xAgVTUX0o"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ThingSpeak.h>

//---------------- WiFi ----------------//
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

//---------------- ThingSpeak ----------------//
unsigned long channelID = 3330664;
const char *writeAPIKey = "I0RE01BR7XM059T6";

WiFiClient client;

//---------------- Pins ----------------//
#define LDR_PIN 34
#define LED_PIN 26

//---------------- Variables ----------------//
int ldrValue = 0;
int manualMode = 0;      // V0
int manualState = 0;     // V1
int brightness = 255;    // V2 slider

// PWM
const int pwmChannel = 0;
const int pwmFreq = 5000;
const int pwmResolution = 8;

//------------------------------------------------
// BLYNK
//------------------------------------------------

BLYNK_WRITE(V0)
{
  manualMode = param.asInt();
}

BLYNK_WRITE(V1)
{
  manualState = param.asInt();
}

BLYNK_WRITE(V2)
{
  brightness = param.asInt();
}

//------------------------------------------------

void setup()
{
  Serial.begin(115200);

  ledcSetup(pwmChannel, pwmFreq, pwmResolution);
  ledcAttachPin(LED_PIN, pwmChannel);

  WiFi.begin(ssid, pass);

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  ThingSpeak.begin(client);
}

//------------------------------------------------

void loop()
{
  Blynk.run();

  ldrValue = analogRead(LDR_PIN);

  int outputBrightness = 0;
  String period = "";
  String lightStatus = "";

  //---------------- AUTO MODE ----------------//

  if (manualMode == 0)
  {

    if (ldrValue > 3200)
    {
      outputBrightness = 0;
      period = "DAY";
      lightStatus = "OFF";
    }

    else if (ldrValue > 1800)
    {
      outputBrightness = 80;
      period = "EVENING";
      lightStatus = "DIM";
    }

    else
    {
      outputBrightness = 255;
      period = "NIGHT";
      lightStatus = "BRIGHT";
    }
  }

  //---------------- MANUAL MODE ----------------//

  else
  {
    if (manualState == 1)
    {
      outputBrightness = brightness;
      period = "MANUAL";
      lightStatus = "ON";
    }
    else
    {
      outputBrightness = 0;
      period = "MANUAL";
      lightStatus = "OFF";
    }
  }

  //---------------- LED ----------------//

  ledcWrite(pwmChannel, outputBrightness);

  //---------------- SERIAL ----------------//

  Serial.println("--------------------------------");

  Serial.print("LDR Value      : ");
  Serial.println(ldrValue);

  Serial.print("Mode           : ");
  if (manualMode == 0)
    Serial.println("AUTO");
  else
    Serial.println("MANUAL");

  Serial.print("Time           : ");
  Serial.println(period);

  Serial.print("Street Light   : ");
  Serial.println(lightStatus);

  Serial.print("Brightness     : ");
  Serial.println(outputBrightness);

  //---------------- BLYNK ----------------//

  Blynk.virtualWrite(V3, ldrValue);
  Blynk.virtualWrite(V4, outputBrightness);
  Blynk.virtualWrite(V5, period);
  Blynk.virtualWrite(V6, lightStatus);

  //---------------- THINGSPEAK ----------------//

  ThingSpeak.setField(1, ldrValue);
  ThingSpeak.setField(2, outputBrightness);

  ThingSpeak.writeFields(channelID, writeAPIKey);

  delay(15000);     // ThingSpeak limit
}