#include <ESP8266WiFi.h>
 
const char* ssid = "Tecnologia";
const char* password = "big7550@dm";
 
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  // prepare GPIO2
  
  pinMode(16, OUTPUT);
  digitalWrite(16, 0);
  
  pinMode(5, OUTPUT);
  digitalWrite(5, 0);
  
  pinMode(4, OUTPUT);
  digitalWrite(4, 0);
  
  pinMode(0, OUTPUT);
  digitalWrite(0, 0);
 
  pinMode(2, OUTPUT);
  digitalWrite(2, 0);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
  Serial.println(WiFi.localIP());
}
 
void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
 
  String buf = "";
 
  buf += "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n";
  buf += "<html lang=\"en\"><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1, user-scalable=no\"/>\r\n";
  buf += "<title>ESP8266 Web Server</title>";
  buf += "Access-Control-Allow-Origin: *";
  buf += "<style>.c{text-align: center;} div,input{padding:5px;font-size:1em;} input{width:80%;} body{text-align: center;font-family:verdana;} button{border:0;border-radius:0.3rem;background-color:#1fa3ec;color:#fff;line-height:2.4rem;font-size:1.2rem;width:100%;} .q{float: right;width: 64px;text-align: right;}</style>";
  buf += "</head>";
  buf += "<h3>ESP8266 Web Server - System Logs</h3>";
  buf += "GPIO1 <a href=\"?function=led1_on\"><button>ON</button></a> <br /> <a href=\"?function=led1_off\"><button>OFF</button></a><br /><br />";
  buf += "GPIO2 <a href=\"?function=led2_on\"><button>ON</button></a> <br /> <a href=\"?function=led2_off\"><button>OFF</button></a><br /><br />";
  buf += "GPIO3 <a href=\"?function=led3_on\"><button>ON</button></a> <br /> <a href=\"?function=led3_off\"><button>OFF</button></a><br /><br />";
  buf += "GPIO4 <a href=\"?function=led4_on\"><button>ON</button></a> <br /> <a href=\"?function=led4_off\"><button>OFF</button></a><br /><br />";
  buf += "</html>\n";
 
  client.print(buf);
  client.flush();
 
  if (req.indexOf("led1_on") != -1)
    digitalWrite(16, 1);
  else if (req.indexOf("led1_off") != -1)
    digitalWrite(16, 0);
    
  else if (req.indexOf("led2_on") != -1)
    digitalWrite(5, 1);
  else if (req.indexOf("led2_off") != -1)
    digitalWrite(5, 0);

  else if (req.indexOf("led3_on") != -1)
    digitalWrite(4, 1);
  else if (req.indexOf("led3_off") != -1)
    digitalWrite(4, 0);

  else if (req.indexOf("led4_on") != -1)
    digitalWrite(0, 1);
  else if (req.indexOf("led4_off") != -1)
    digitalWrite(0, 0);
    
  else {
    Serial.println("invalid request");
    client.stop();
  }
  Serial.println("Client disonnected");
}

