////https://gist.github.com/dogrocker/f998dde4dbac923c47c1
//https://github.com/chriscook8/esp-arduino-apboot
/* Create a WiFi access point and provide a web server on it. */
extern "C" {//FOR SOFT RESET
#include "user_interface.h" //FOR SOFT RESET
//http://www.esp8266.com/viewtopic.php?p=13165
}

#define D1 10
#define D2 2
#define D3 0
#define D4 4
#define D5 5
#define D6 9
#define D7 13
#define D8 12
#define D9 14
#define D10 16
char flag1;

 String esid;
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <EEPROM.h>
#include <WiFiUDP.h>

 
 
 String s ="";
 String s0 ="";
  String string1 ="";
   String s1 = "1";
  String s2 = "2";
  
 
     String s9 = "9";
  String s10 = "10";
     String s11 = "11";
  String s12 = "12";
 String s13 = "13";
  String s14 = "14";
 
 

ESP8266WebServer server(8888);
    unsigned int localPort = 8888;
    WiFiUDP UDP;
    boolean udpConnected = false;
    char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,
 
    char ReplyBuffer[] = "5"; // a string to send back
int serv0=0;;
int serv1=0;;
    int serv=0;
  int serv2=0;
 int led3=0; 
  int led2=0; 
  int led1=0; 
/* Just a little test message.  Go to http://192.168.4.1 in a web browser
 * connected to this access point to see it.
 * 
 */
 const int analogInPin = A0;                                                                                                                                       
boolean connectUDP();

void handleRoot() {
  server.send(200, "text/html", "<h1>You are connected</h1>");
}  
void setup() 
{
//  delay(10);//1000
  Serial.begin(115200);
   EEPROM.begin(512);
  Serial.println();
  pinMode(D1,OUTPUT);//JUST FOR ESP12E
 digitalWrite(D1,LOW);
 
     pinMode(D2,OUTPUT);
    digitalWrite(D2,LOW);

      pinMode(D3,OUTPUT);
    digitalWrite(D3,LOW);
    
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  //WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
    udpConnected = connectUDP();
    if (udpConnected)
    {
        
    }
    
}

void loop() 
{
  server.handleClient();
  if(udpConnected)
  {
    // if thereâ€™s data available, read a packet
    int packetSize = UDP.parsePacket();
 
    if(packetSize)
    {
    Serial.println("");
    Serial.print("Received packet of size ");
    Serial.print("From ");
    IPAddress remote = UDP.remoteIP();
    for (int i =0; i < 4; i++)
    {
    Serial.print(remote[i], DEC);
    if (i < 3)
    {
      
    Serial.print(".");
    }
    }
    Serial.print(", port ");
    Serial.println(UDP.remotePort());

    // read the packet into packetBufffer
    UDP.read(packetBuffer,UDP_TX_PACKET_MAX_SIZE);
    Serial.println("Contents:");



if(packetSize>1 && packetSize<3)
    {
      
     serv0=packetBuffer[0];
     serv0= serv0-48;
      serv1=packetBuffer[1];
     
 serv1= serv1-48;

serv=  serv1 +(serv0*10);
     
    }

if(packetSize>2 && packetSize<4)
    {
      
     serv0=packetBuffer[0];
     serv0= serv0-48;
      serv1=packetBuffer[1];
      
 serv1= serv1-48;
     serv2=packetBuffer[2];
      
 serv2= serv2-48;

serv=  serv2+(serv1*10) +(serv0*100);
     
    }

if(packetSize>3 && packetSize<5)
    {
      
     serv0=packetBuffer[0];
     serv0= serv0-48;
      serv1=packetBuffer[1];
      
 serv1= serv1-48;
     serv2=packetBuffer[2];
      
 serv2= serv2-48;
   char serv3=packetBuffer[3];
    serv3= serv3-48;


serv= serv3+ (serv2*10)+(serv1*100) +(serv0*1000);
    }

if(packetSize>0 && packetSize<2)
    {

    
serv=packetBuffer[0];

   serv=serv-48;
    }

  
           s =""; 
    for(int j=0;j<packetSize;j++)
    {
  
      s += (String)packetBuffer[j];
  
    }

 Serial.println("string");
 Serial.println(s);
   string1 =s;

      s ="";
   
  
 


  if(serv==9 )
   {
 led1=1;
   digitalWrite(D1,HIGH);
  UDP.println("9");
    serv=0;
    }
     if(serv==10)
    {
    led1=0;
        digitalWrite(D1,LOW);
UDP.println("10");
      serv=0;
   }

 

if(serv==11)
   {
 led2=1;
 digitalWrite(D2,HIGH);
 
  UDP.println("11");
    serv=0;
    
    }
     if(serv==12)
    {
     led2=0;
       digitalWrite(D2,LOW);
UDP.println("12");
      serv=0;
   }

 
  if(serv==13)
   {
 led3=1;
 digitalWrite(D3,HIGH);
 
  UDP.println("13");
    serv=0;
    
    }
     if(serv==14)
    {
     led3=0;
       digitalWrite(D3,LOW);
UDP.println("14");
      serv=0;
   }
  
  
      
}
 boolean connectUDP(){
    boolean state = false;

  //  Serial.println("");
    //Serial.println("Connecting to UDP");

    if(UDP.begin(localPort) == 1){
   // Serial.println("Connection successful");
    state = true;
    }
    else{
  
    }
    return state;
    }


  


  
