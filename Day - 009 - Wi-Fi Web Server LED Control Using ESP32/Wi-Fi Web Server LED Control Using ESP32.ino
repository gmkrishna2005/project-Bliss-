#include <WiFi.h>

const char* ssid = "realme 8";
const char* password = "100ipl23";

WiFiServer server(80);

const int ledPin = 14;
bool ledState = false;

void setup() {

  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.println("Connecting to Wi-Fi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Connected!");

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {

  WiFiClient client = server.available();

  if (client) {

    String request = client.readStringUntil('\r');
    client.flush();

    if (request.indexOf("/LED=ON") != -1) {
      ledState = true;
      digitalWrite(ledPin, HIGH);
    }

    if (request.indexOf("/LED=OFF") != -1) {
      ledState = false;
      digitalWrite(ledPin, LOW);
    }

    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();

 client.println("<!DOCTYPE html>");
client.println("<html lang='en'>");

client.println("<head>");
client.println("<meta charset='UTF-8'>");
client.println("<meta name='viewport' content='width=device-width, initial-scale=1.0'>");
client.println("<title>ESP32 Smart Control</title>");

client.println("<style>");
client.println("body{margin:0;font-family:'Segoe UI',Arial,sans-serif;background:linear-gradient(135deg,#0f172a,#1e3a8a,#2563eb);height:100vh;display:flex;justify-content:center;align-items:center;color:white;}");
client.println(".card{background:rgba(255,255,255,0.12);backdrop-filter:blur(15px);padding:40px;border-radius:20px;box-shadow:0 10px 30px rgba(0,0,0,.3);width:340px;text-align:center;}");
client.println("h1{margin-bottom:10px;font-size:30px;}");
client.println("p{color:#d1d5db;margin-bottom:25px;}");
client.println(".status{display:inline-block;padding:10px 25px;border-radius:30px;font-size:20px;font-weight:bold;");
client.print(ledState ?
"background:#16a34a;color:white;" :
"background:#dc2626;color:white;");
client.println("}");
client.println(".btn{display:block;width:100%;padding:16px;margin-top:18px;border:none;border-radius:12px;font-size:18px;font-weight:bold;text-decoration:none;color:white;transition:.3s;}");
client.println(".on{background:#22c55e;}");
client.println(".on:hover{background:#16a34a;}");
client.println(".off{background:#ef4444;}");
client.println(".off:hover{background:#dc2626;}");
client.println("footer{margin-top:25px;font-size:13px;color:#cbd5e1;}");
client.println("</style>");

client.println("</head>");

client.println("<body>");

client.println("<div class='card'>");

client.println("<h1>ESP32 Smart Controller</h1>");
client.println("<p>Wi-Fi LED Control Dashboard</p>");

client.print("<div class='status'>");
client.print(ledState ? "LED ON" : "LED OFF");
client.println("</div>");

client.println("<a class='btn on' href='/LED=ON'>Turn ON</a>");
client.println("<a class='btn off' href='/LED=OFF'>Turn OFF</a>");

client.println("<footer>");
client.println("Powered by ESP32");
client.println("</footer>");

client.println("</div>");

client.println("</body>");
client.println("</html>");
    delay(1);
    client.stop();
  }
}