int microfone = 8;
 
int CONT = 0; 
 
void setup() { //rotina ao iniciar o programa 
 pinMode(microfone, INPUT); //inicia os pino do microfone como entrada
 pinMode(13, OUTPUT); //led vermelho
 pinMode(12, OUTPUT); //led verde

 Serial.begin(9600);
 // Se o pino de entrada analógica 0 é deixado desconectado,
 // o ruído aleatório analógico irá causar a chamada de randomSeed()
 //  gerar sementes aleatórias diferentes cada vez que o sketch roda.
 // randomSeed() basicamente "embaralha" a função random().
 randomSeed(analogRead(0));
}
 
void loop() { //rotina infinita

    if(digitalRead(microfone) == HIGH){
        CONT = 1;
    }
    if(digitalRead(microfone) == LOW && CONT == 1 ){
        randNumber = random(300);
        if(randNumber%2 == 0){
            wait(1500);
            digitalWrite(13, HIGH);            
            wait(2000);
            CONT = 0;
        } else {
            wait(1500);
            digitalWrite(12, HIGH);            
            wait(2000);
            CONT = 0;
        }
    }

}