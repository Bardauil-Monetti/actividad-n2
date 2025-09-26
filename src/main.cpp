#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
int seg1[10][7]={
    {1,1,1,1,1,1,0},//0
    {0,1,1,0,0,0,0},//1
    {1,1,0,1,1,0,1},//2
    {1,1,1,1,0,0,1},//3
    {0,1,1,0,0,1,1},//4
    {1,0,1,1,0,1,1},//5
    {1,0,1,1,1,1,1},//6
    {1,1,1,0,0,0,0},//7
    {1,1,1,1,1,1,1},//8
    {1,1,1,0,0,1,1}//9
};
int seg2[10][7]={
    {1,1,1,1,1,1,0},//0
    {0,1,1,0,0,0,0},//1
    {1,1,0,1,1,0,1},//2
    {1,1,1,1,0,0,1},//3
    {0,1,1,0,0,1,1},//4
    {1,0,1,1,0,1,1},//5
    {1,0,1,1,1,1,1},//6
    {1,1,1,0,0,0,0},//7
    {1,1,1,1,1,1,1},//8
    {1,1,1,0,0,1,1}//9
};
int pines1[7]{18,19,21,22,23,27,33};//unidad
int i=0;
int pines2[7]{8,9,10,11,12,13,14};//unidad
volatile bool elecion=true;// sila elecion es uno el display se va a iniciar en uno por defecto
const char* ssid = "Telecentro-da0d";
const char* password = "H4JTRX4NGL9L";
WebServer server(80);
// Funciones para los modos
void funcion_seg1() {
  for(i=0 ;i<9 ; i++){
    digitalWrite(pines1[i],HIGH);
  elecion=false;
  }

}
void funcion_seg2() {
for(i=0 ; i<9 ; i++){
  digitalWrite(pines2[i], HIGH);
  elecion=false;
}
}

void num_0() {
   Serial.print("Request para mostrar 0");
  if (elecion){
    for(i=0 ; i<9 ;i++){
      digitalWrite(pines1[i],seg1[0][i]);
    }
  }else{
   for(i=0 ; i<9 ;i++){
      digitalWrite(pines2[i],seg2[0][i]);
    }
  }
  
  
}

void num_1() {
   Serial.print("Request para mostrar 1");
  if (elecion){
    for(i=0 ; i<9 ;i++){
      digitalWrite(pines1[i],seg1[1][i]);
    }
  }else{
   for(i=0 ; i<9 ;i++){
      digitalWrite(pines2[i],seg2[1][i]);
    }
  }
  }
void num_2() {
   Serial.print("Request para mostrar 2");
  if (elecion){
    for(i=0 ; i<9 ;i++){
      digitalWrite(pines1[i],seg1[2][i]);
    }
  }else{
   for(i=0 ; i<9 ;i++){
      digitalWrite(pines2[i],seg2[2][i]);
    }
  }
  }
void num_3() {
   Serial.print("Request para mostrar 3");
  if (elecion){
    for(i=0 ; i<9 ;i++){
      digitalWrite(pines1[i],seg1[2][i]);
    }
  }else{
   for(i=0 ; i<9 ;i++){
      digitalWrite(pines2[i],seg2[2][i]);
    }
  }
  }

void num_4() {
   Serial.print("Request para mostrar 4");
  if (elecion){
    for(i=0 ; i<9 ;i++){
      digitalWrite(pines1[i],seg1[4][i]);
    }
  }else{
   for(i=0 ; i<9 ;i++){
      digitalWrite(pines2[i],seg2[4][i]);
    }
  }
  }
void num_5() {
   Serial.print("Request para mostrar 5");
  if (elecion){
    for(i=0 ; i<9 ;i++){
      digitalWrite(pines1[i],seg1[5][i]);
    }
  }else{
   for(i=0 ; i<9 ;i++){
      digitalWrite(pines2[i],seg2[5][i]);
    }
  }
  }
void num_6() {
   Serial.print("Request para mostrar 6");
  if (elecion){
    for(i=0 ; i<9 ;i++){
      digitalWrite(pines1[i],seg1[6][i]);
    }
  }else{
   for(i=0 ; i<9 ;i++){
      digitalWrite(pines2[i],seg2[6][i]);
    }
  }
  }
void num_7() {
   Serial.print("Request para mostrar 7");
  if (elecion){
    for(i=0 ; i<9 ;i++){
      digitalWrite(pines1[i],seg1[7][i]);
    }
  }else{
   for(i=0 ; i<9 ;i++){
      digitalWrite(pines2[i],seg2[7][i]);
    }
  }
  }
void num_8() {
   Serial.print("Request para mostrar 8");
  if (elecion){
    for(i=0 ; i<9 ;i++){
      digitalWrite(pines1[i],seg1[8][i]);
    }
  }else{
   for(i=0 ; i<9 ;i++){
      digitalWrite(pines2[i],seg2[8][i]);
    }
  }
  }
void num_9() {
   Serial.print("Request para mostrar 9");
  if (elecion){
    for(i=0 ; i<9 ;i++){
      digitalWrite(pines1[i],seg1[9][i]);
    }
  }else{
   for(i=0 ; i<9 ;i++){
      digitalWrite(pines2[i],seg2[9][i]);
    }
  }
  }

void setup() {
  Serial.begin(115200);
  for(i=0 ; i<7 ; i++){
      pinMode(pines1[i], OUTPUT);
    pinMode(pines2[i], OUTPUT);
    digitalWrite(pines1[i], LOW);
    digitalWrite(pines2[i], LOW);
  }
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado");
  Serial.println(WiFi.localIP());

  // Página principal
  server.on("/", []() {
    String pagina = R"rawliteral(
      <html>
      <body>
      <head>
    <meta charset="utf-8">
    <title>SEMÁFORO</title>
    <style>
      
        }
        .7segmentos1{
             background-color: #ff0000;
        }
        .7segmentos2{
             background-color: #ffff00;

   
    </style>
</head>
        <h1>SEMÁFORO</h1>
   <table border="1">
        <thead>
            <tr>
               <td><a href="/1"><button class="btn">1</button></a></td>
               <td><a href="/2"><button class="btn">2</button></a></td>
               <td><a href="/3"><button class="btn">3</button></a></td>
               </tr>
               </thead>
               <tbody>
            <tr>
               <td><a href="/4"><button class="btn">4</button></a></td>
               <td><a href="/5"><button class="btn">5</button></a></td>
               <td><a href="6"><button class="btn">6</button></a></td>   
               </tr>
            <tr>
               <td><a href="/7"><button class="btn">7</button></a></td>
               <td><a href="/8"><button class="btn">8</button></a></td>
               <td><a href="/9"><button class="btn">9</button></a></td>   
            </tr>
        </tbody>
    </table>
    <td><a href="/7segmentos1"><button class="btn">Display 1</button></a></td>
    <td><a href="/7segmentos2"><button class="btn">Display 2</button></a></td>   
      </body>
      </html>
    )rawliteral";

  });

  // Rutas de control
  server.on("/funcion_seg1", []() {
  funcion_seg1();
    server.sendHeader("Location", "/");
    server.send(302, "text/plain", "");
});

server.on("/funcion_seg2", []() {
    funcion_seg2();
    server.sendHeader("Location", "/");
    server.send(302, "text/plain", "");
});


  server.on("/0",num_0);
  server.on("/1",num_1);
  server.on("/2",num_2);
  server.on("/3",num_3);
  server.on("/4",num_4);
  server.on("/5",num_5);
  server.on("/6",num_6);
  server.on("/7",num_7);
  server.on("/8",num_8);
  server.on("/9",num_9);


  server.begin();
}

void loop() {
  server.handleClient();


}