#include <ESP8266WiFi.h>

#include <WiFiClient.h>

#include <ThingSpeak.h>

#include <ESP8266HTTPClient.h>

const char* ssid = "F41"; //Your Network SSID

const char* password = "mr12345678"; //Your Network Password

int val;

const char* tsServer = "api.thingspeak.com";

int LDRpin = A0; //LDR Pin Connected at A0 Pin


float t=0;
WiFiClient client;

unsigned long myChannelNumber = 2366956; //Your Channel Number (Without Brackets)

const char * myWriteAPIKey = "26QH508FWECJGNBE"; //Your Write API Key

//unsigned long myChannelNumber1 = 2310977; //Your Channel Number (Without Brackets)

//const char * myWriteAPIKey1 = "223FDGIZHHDEG8KA"; //Your Write API Key

void setup()

{

Serial.begin(115200);
       delay(10);
       // Connect to WiFi network

WiFi.begin(ssid, password);

Serial.println("");
Serial.println("WiFi connected");
Serial.println("NodeMCU Local IP is : ");
Serial.println(WiFi.localIP()); // Get the local IP address

ThingSpeak.begin(client);

}



void loop()

{

t = analogRead(A0);//Read Analog values and Store in val variable

Serial.print("Airquality = ");


Serial.print(t); //Print on Serial Monitor


ThingSpeak.writeField(myChannelNumber, 1,t, myWriteAPIKey); //Update in ThingSpeak

ThingSpeak.writeField(myChannelNumber, 2,1001, myWriteAPIKey);

Serial.println(t);

delay(1000);
 }
