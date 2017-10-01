
//Este codigo permite controlar un display de 7 segmentos anodo común
//con NodeMCU, prender todos los segmentos e irlos apagando en orden. 
//Es importante excluir los pines digitales 2 y 8 pues estos
//están reservados el funcionamiento interno del NodeMCU
//
//Los pines corresponden a:
/*16 = D0
 *5  = D1
 *0  = D3
 *2  = D4
 *14 = D5
 *12 = D6
 *13 = D7
 */
int pines[] = {16,5,0,2,14,12,13};

void setup() {
  // put your setup code here, to run once:
    //Primera fila
    for(int o=0;o < sizeof(pines);o++){
        pinMode(pines[o],OUTPUT);
      }  
}

void loop() {
  //Encendiendo segmentos
  for(int j=0; j < sizeof(pines);j++){
      digitalWrite(pines[j],LOW);
      delay(1000);
    }
  //Apagando segmentos
  for(int j=0; j < sizeof(pines);j++){
      digitalWrite(pines[j],HIGH);
      delay(1000); 
    }
    delay(500);
}
