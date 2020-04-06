int greenLED= D6;
int blueLED=D5;
int redLED=D4;
String currentLight="";


void setup() {
    pinMode(greenLED,OUTPUT);
    pinMode(redLED,OUTPUT);
    pinMode(blueLED,OUTPUT);
    digitalWrite(greenLED,LOW);
    digitalWrite(redLED,LOW);
    digitalWrite(blueLED,LOW);
    
    Particle.function("signal", changeSignal);
    Particle.variable("currentLight", currentLight);
    

}

void loop() {

}

int changeSignal(String commandString){
    if(commandString=="green"){
        currentLight="green";
        digitalWrite(greenLED,HIGH);
        digitalWrite(blueLED,LOW);
        digitalWrite(redLED,LOW);
        
        return 1;
    } else if (commandString =="blue"){
        currentLight="blue";
         digitalWrite(greenLED,LOW);
        digitalWrite(blueLED,HIGH);
        digitalWrite(redLED,LOW);
        return 1;
    } else if(commandString=="red"){
        currentLight="red";
         digitalWrite(greenLED,LOW);
        digitalWrite(blueLED,LOW);
        digitalWrite(redLED,HIGH);
        return 1;
    } else{
        return -1;
    }
    
}