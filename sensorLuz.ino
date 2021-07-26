const int pinoLDR = A0;
int leitura = 0;
float tensao = 0.0;
const int pinoLed = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(pinoLDR, INPUT);
  pinMode(pinoLed, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  leitura = analogRead(pinoLDR);
  // Serial.print("Leitura: %d \t" + leitura); -->>Deu bug essa porra aqui....


 // imprime valor lido pelo arduino (0 a 1023)
  Serial.print("Leitura: ");
  Serial.print(leitura);
  Serial.print("\t"); // tabulacao

  //converter e imprimir o valor em tensão elétrica
  tensao = leitura * 5.0 / 1024.0;
  if(tensao <= 0.9){
    digitalWrite(pinoLed, HIGH);
  } else{
    digitalWrite(pinoLed, LOW);
  }
  Serial.print("Tensao: ");
  Serial.print(tensao);
  Serial.print("V");
  Serial.println();
  delay(1000);

}
