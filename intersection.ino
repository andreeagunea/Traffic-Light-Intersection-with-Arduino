int greenS4=0;		//Denumirea led-urilor fiecărui semafor
int yellowS4=1;
int redS4=2;
int greenS2=3;
int redS2=4;
int greenS1=5;
int redS1=6;
int redS3=8;
int yellowS3=9;
int greenS3=10;

int buttonS1=11;	//Denumirea butoanelor ce declanșează semafoarele
int val1;
int buttonS2=12;
int val2;

int LDR=A0;		//Fotorezistorul(LDR) – detecteaza lumina/întunericul
int lightVal;

int SIR3=A3;		//Senzorii infraroșii utilizați pentru detectarea
int valSIR3;		// ambuteiajului
int SIR4=A4;
int valSIR4;

void setup() {
  // put your setup code here, to run once:
  pinMode(redS4,OUTPUT);		//valoarea este selectată - output
  pinMode(yellowS4,OUTPUT);
  pinMode(greenS4,OUTPUT);
  pinMode(greenS3,OUTPUT);
  pinMode(yellowS3,OUTPUT);
  pinMode(redS3,OUTPUT);
  pinMode(redS2,OUTPUT);
  pinMode(greenS2,OUTPUT);
  pinMode(redS1,OUTPUT);
  pinMode(greenS1,OUTPUT);
  pinMode(SIR4,INPUT);		//valoarea este primită - input
  pinMode(SIR3,INPUT);
  pinMode(buttonS1,INPUT);
  pinMode(buttonS2,INPUT);
  pinMode(LDR,INPUT);
  Serial.begin(9600);		//port serial cu baud rate egal cu 9600
}

void loop() {
  // put your main code here, to run repeatedly:

    
  lightVal=analogRead(LDR);		//se citește valoarea LDR-ului
  while(lightVal<80)				//dacă acesta returneaza o valoare
  {						//mai mica decât 80, considerăm ca 
  lightVal=analogRead(LDR);		//afară este noapte
  Serial.println("Noapte");
  digitalWrite(greenS3,LOW);		//semafoarele mașinilor intră
  digitalWrite(greenS4,LOW);		// în modul galben intermitent
  digitalWrite(redS1,LOW);
  digitalWrite(redS2,LOW);f
  digitalWrite(yellowS3,HIGH);
  digitalWrite(yellowS4,HIGH);
  delay(500);
  digitalWrite(yellowS3,LOW);
  digitalWrite(yellowS4,LOW);
  delay(500);
  }
  
  Serial.println("Main loop");
  valSIR3=analogRead(SIR3);
  valSIR4=analogRead(SIR4);
  Serial.print("ValSIR3= ");
  Serial.println(valSIR3);
  Serial.print("ValSIR4= ");
  Serial.println(valSIR4);
  digitalWrite(greenS3,HIGH);
  digitalWrite(greenS4,HIGH);
  digitalWrite(redS2,HIGH);
  digitalWrite(redS1,HIGH);
 
  val1=digitalRead(buttonS1);
  val2=digitalRead(buttonS2);
  Serial.print("Val1= ");
  Serial.println(val1);
  Serial.print("Val2= ");
  Serial.println(val2);
  delay(1000);

  if(val1==1||val2==1)				//dacă se apasă vreun buton
  {
      if(valSIR3<150 || valSIR4<150)		//se verifica daca senzorii
      {							//detectează ambuteiaj
      Serial.println("Ambuteiaj");
      delay(5000);					//daca exista ambuteiaj se
      }							//se amână apariția culorii
      pieton();					//verzi pentru pietoni
  }
  
    

} 

void pieton()
{
    Serial.println("Pieton");  
    delay(3000);
    
    digitalWrite(greenS3,LOW);
    digitalWrite(greenS4,LOW);
    digitalWrite(yellowS3,HIGH);
    digitalWrite(yellowS4,HIGH);
    delay(2000);

    digitalWrite(yellowS3,LOW);
    digitalWrite(yellowS4,LOW);
    digitalWrite(redS3,HIGH);
    digitalWrite(redS4,HIGH);
    delay(2000);

    digitalWrite(redS1,LOW);
    digitalWrite(redS2,LOW);
    digitalWrite(greenS1,HIGH);
    digitalWrite(greenS2,HIGH);
    delay(5000);

    digitalWrite(greenS1,LOW);
    digitalWrite(greenS2,LOW);
    delay(500);
    digitalWrite(greenS1,HIGH);
    digitalWrite(greenS2,HIGH);
    delay(500);
    digitalWrite(greenS1,LOW);
    digitalWrite(greenS2,LOW);
    delay(500);
    digitalWrite(greenS1,HIGH);
    digitalWrite(greenS2,HIGH);
    delay(500);
    digitalWrite(greenS1,LOW);
    digitalWrite(greenS2,LOW);
    delay(500);
    digitalWrite(greenS1,HIGH);
    digitalWrite(greenS2,HIGH);
    delay(500);
    digitalWrite(greenS1,LOW);
    digitalWrite(greenS2,LOW);

    digitalWrite(redS1,HIGH);
    digitalWrite(redS2,HIGH);

    delay(2000);
    digitalWrite(yellowS3,HIGH);
    digitalWrite(yellowS4,HIGH);
    delay(2000);
    digitalWrite(redS3,LOW);
    digitalWrite(redS4,LOW);
    digitalWrite(yellowS3,LOW);
    digitalWrite(yellowS4,LOW);}
