int valores[3];
int valoratual = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("DIGITE E ENVIE 3 VALORES INTEIROS: ");
  Serial.println("-----------------------------------\n");
}

void loop() {
  if (valoratual < 3) {
    if (Serial.available()) {
      String incomingString = Serial.readStringUntil('\n');
      //Serial.println(incomingString.toInt());
      valores [valoratual] = incomingString.toInt();
      valoratual++;
      //valores[valoratual++] = Serial.parseInt();
    }
  } else {
    for (int i = 0; i < 2; i++) {
      if (valores[i] > valores [i + 1]) {
        int ed = valores[i];
        valores[i] = valores[i + 1];
        valores[i + 1] = ed;
        i = -1;
      }
    }
    Serial.println("VALORES EM ORDEM CRESCENTE: \n");
    for (int i = 0; i < 3; i++) {
      Serial.print("VALOR ");
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.println(valores[i]);
      Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }
    while (true) {}
  }
}
