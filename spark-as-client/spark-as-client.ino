TCPClient client;
byte server[] = { 74, 125, 224, 72 }; // Google
void setup()
{
  
  pinMode(D7, OUTPUT);     // output means information out of the spark device

  // Make sure your Serial Terminal app is closed before powering your Core
 // Serial.begin(9600);
  // Now open your Serial Terminal, and hit any key to continue!
  //while(!Serial.available()) 
  
  //SPARK_WLAN_Loop();

  //Serial.println("connecting...");

  if (client.connect(server, 80))
  {

  
   // Serial.println("connected");
    client.println("GET /search?q=unicorn HTTP/1.0");
    client.println("Host: www.google.com");
    client.println("Content-Length: 0");
    client.println();
  }
  else
  {
    //Serial.println("connection failed");
  }
}

void loop()
{
  if (client.available())
  {
    digitalWrite(D7, HIGH);  // send 1 high 0 low
    char c = client.read();
    Serial.print(c);
  }

  if (!client.connected())
  {
    //Serial.println();
    //Serial.println("disconnecting.");
    client.stop();
    for(;;);     // what the heck does this do???
  }
}
