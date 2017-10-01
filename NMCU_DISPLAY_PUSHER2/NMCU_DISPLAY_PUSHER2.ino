int contador;  //Variable asociada al contador
int presionado1; //Variable para el antirrebote del pulsador aumentar
int presionado2; //Variable para el antirrebote del pulsador disminuir

int pulsador_aumentar = 29; //Pulsador conectado a pin 29
int pulsador_disminuir = 30; //Pulsador conectado al pin 30


void encender(int a, int b, int c, int d, int e, int f, int g)
{
  //Funcion que permite mostrar los numeros del 0 al 9
  //Asigna un segmento del display a cada pin

  digitalWrite(22, a);  //Asigna el segmento 'a' al pin 22
  digitalWrite(23, b);  //Asigna el segmento 'b' al pin 23
  digitalWrite(24, c);  //Asigna el segmento 'c' al pin 24
  digitalWrite(25, d);  //Asigna el segmento 'd' al pin 25
  digitalWrite(26, e);  //Asigna el segmento 'e' al pin 26
  digitalWrite(27, f);  //Asigna el segmento 'f' al pin 27
  digitalWrite(28, g);  //Asigna el segmento 'g' al pin 28
}

void setup() {

  //Inicializa los pines como entradas/salidas digitales

  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, INPUT);  //Pulsador aumentar como entrada digital
  pinMode(30, INPUT);  //Pulsador disminuir como entrada digital
}

void loop() {

  //Condicionales para antirrebote y uso del pulsador aumentar

  if (digitalRead(pulsador_aumentar) == LOW)
  {
    presionado1 = 1;   //Variable del antirrebote que cambia cuando se presiona el pulsador
  }
  if (digitalRead(pulsador_aumentar) == HIGH && presionado1 == 1)
  {
    presionado1 = 0;  //Se reinicia la variable antirrebote
    contador++;       //Aumenta el contador
    if(contador > 9)
    {
      contador =9;  //Si el contador esta en 9 y se aumenta, sigue mostrando el 9
    }
  }

  //Condicionales para antirrebote y uso del pulsador disminuir

  if (digitalRead(pulsador_disminuir) == LOW)
  {
    presionado2 = 1;    //Variable del antirrebote que cambia cuando se presiona el pulsador
  }
  if (digitalRead(pulsador_disminuir) == HIGH && presionado2 == 1)
  {
    presionado2 = 0;   //Se reinicia la variable antirrebote
    contador--;        //Disminuye el contador 
    
    if(contador < 0)  //Si el contador esta en 0 y se disminuye, sigue mostrando el 0
    {
      contador =0;   
    }   
  }

  switch (contador)
  {
    //Dependiendo del contador, se muestra el numero indicado
    //Envia estados (1 y 0) al display dependiendo del numero a mostrar

    case 0:
       encender (0, 0, 0, 0, 0, 0, 1); //Muestra el numero 0
      break;

    case 1:
       encender (1, 0, 0, 1, 1, 1, 1); //Muestra el numero 1
      break;

    case 2:
      encender (0, 0, 1, 0, 0, 1, 0); //Muestra el numero 2
      break;

    case 3:
      encender (0, 0, 0, 0, 1, 1, 0); //Muestra el numero 3
      break;

    case 4:
      encender (1, 0, 0, 1, 1, 0, 0); //Muestra el numero 4
      break;

    case 5:
      encender (0, 1, 0, 0, 1, 0, 0); //Muestra el numero 5
      break;

    case 6:
      encender (0, 1, 0, 0, 0, 0, 0); //Muestra el numero 6
      break;

    case 7:
      encender (0, 0, 0, 1, 1, 1, 1); //Muestra el numero 7
      break;

    case 8:
      encender (0, 0, 0, 0, 0, 0, 0); //Muestra el numero 8
      break;

    case 9:
      encender (0, 0, 0, 1, 1, 0, 0); //Muestra el numero 9
      break;
  }
}
