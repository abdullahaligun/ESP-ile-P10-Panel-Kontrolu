
#include <ESP8266WebServer.h>
#include <EEPROM.h>
#include <DMDESP.h>
#include <fonts/ElektronMart6x8.h>
#include <fonts/Mono5x7.h>
#include <fonts/Arial_Black_16.h>
#include <fonts/ArialBlack10.h>
//----------------------------------------
#include "PageIndex.h"
//----------------------------------------Make a wifi name and password as access point
const char* ssid = "ADTECHWPFG";
const char* password = "88888888";
//----------------------------------------

ESP8266WebServer server(80); //--> Server on port 80
bool txt = false;
int sayac = 100;
//----------------------------------------DMD Configuration (P10 Panel)
#define DISPLAYS_WIDE 4 //--> Panel Columns
#define DISPLAYS_HIGH 1 //--> Panel Rows
DMDESP Disp(DISPLAYS_WIDE, DISPLAYS_HIGH);  //--> Number of Panels P10 used (Column, Row)
//----------------------------------------

String price_1_txt = ""; //--> Variable to hold the text that is sent from a web server (web page)
String price_2_txt = "";
String price_3_txt = "";
String price_4_txt = "";
//========================================================================This routine is executed when you open NodeMCU ESP8266 IP Address in browser
void handleRoot() {
  server.send(200, "text/html", MAIN_page); //--> Send web page
}
//========================================================================

//========================================================================Subroutines to handle incoming Text Data
void price_1() {
  String temp = server.arg("price1");
  if(temp.length() <= 4){
    txt = true;
    sayac = 100;
  price_1_txt = temp;
  Serial.println("price 1 : ");
  Serial.println(price_1_txt);
  server.send(200, "text/plane", ""); //--> Send web page
  EEPROM.put(1, price_1_txt);
  Disp.clear();
  }
}
void price_2() {
  String temp = server.arg("price2");
  if(temp.length() <= 4){
    txt = true;
    sayac = 100;
  price_2_txt = temp;
  Serial.println("price 2 : ");
  Serial.println(price_2_txt);
  server.send(200, "text/plane", ""); //--> Send web page
  EEPROM.put(2, price_2_txt);
  Disp.clear();
  }
}
void price_3() {
String temp = server.arg("price3");
  if(temp.length() <= 4){
    txt = true;
    sayac = 100;
  price_3_txt = temp;
  Serial.println("price 3 : ");
  Serial.println(price_3_txt);
  server.send(200, "text/plane", ""); //--> Send web page
  EEPROM.put(3, price_3_txt);
  Disp.clear();
  }
}
void price_4() {
  String temp = server.arg("price4");
  if(temp.length() <= 4){
    txt = true;
    sayac = 100;
  price_4_txt = temp;
  Serial.println("price 4 : ");
  Serial.println(price_4_txt);
  server.send(200, "text/plane", ""); //--> Send web page
  EEPROM.put(4, price_4_txt);
  Disp.clear();
  }
}

//========================================================================VOID SETUP()
void setup(){
  
  Serial.begin(115200);
  delay(500);
  EEPROM.begin(512);
  delay(500);
  //----------------------------------------DMDESP Setup
  Disp.start(); //--> Run the DMDESP library
  Disp.setBrightness(100); //--> Brightness level
  Disp.setFont(Arial_Black_16); //--> Determine the font used
  //----------------------------------------
  delay(500);
  
  WiFi.softAP(ssid, password);  //--> Start Making ESP8266 NodeMCU as an access point
  Serial.println("");
  delay(100);
  IPAddress apip = WiFi.softAPIP(); //--> Get the IP server
  Serial.print("Connect your wifi laptop/mobile phone to this NodeMCU Access Point : ");
  Serial.println(ssid);
  Serial.print("Visit this IP : ");
  Serial.print(apip); //--> Prints the IP address of the server to be visited
  Serial.println(" in your browser.");
  delay(100);
  server.on("/", handleRoot); //--> Routine to handle at root location. This is to display web page.
  delay(100);
  server.on("/setTexq", price_1);  //--> Routine to handle handle_Iprice_1_txtSubroutines
  delay(100);
  server.on("/setText", price_2);
  delay(100);
  server.on("/setTexe", price_3);
  delay(100);
  server.on("/setTexr", price_4);
  delay(100);
  server.begin(); //--> Start server
  delay(100);
  Serial.println("HTTP server started");
  //EEPROM.get(1,price_2_txt);
  delay(100);
  //EEPROM.get(2,price_2_txt);
  delay(100);
  //EEPROM.get(3,price_3_txt);
  delay(100);
  //EEPROM.get(4,price_4_txt);
  delay(100);
}

void loop(){
  server.handleClient();
  
  Disp.loop();
  Disp.drawText(1, 0, price_1_txt);
  Disp.drawText(33, 0, price_2_txt); //--> Display text "Disp.drawText(x position, y position, text)"
  Disp.drawText(65, 0, price_3_txt);
  Disp.drawText(97, 0, price_4_txt);
  
  /*Disp.drawText(130, 0, price_3_txt);
  Disp.drawText(162, 0, price_3_txt);
  Disp.drawText(194, 0, price_4_txt);
  Disp.drawText(226, 0, price_4_txt);*/
}
//=================================================================================================
