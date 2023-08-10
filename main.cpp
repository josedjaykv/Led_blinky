/* Ejemplo 3LED_bliny para cusos universitarios
 */

#include "mbed.h"
#include <iostream>
#include <numeric>
using namespace std;

int gcd(int a, int b) {
  while (b != 0) {
    int temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}

int mcd3(int a, int b, int c) {
  return gcd(gcd(a, b), c);
}

// Periodo de parpadeo máximo común divisor - MCD - para los LEDs del LED RGB  
#define BLINKING_UNITS      "ms"
#define BLINKING_RATE       20ms    // Falta concatenación de BLINKING_PERIOD y BLINKING_UNITS 
// Objeto para establecer la comunicación serial con el Pc
//BufferedSerial serial(USBTX, USBRX, 9600);
UnbufferedSerial serial(USBTX, USBRX, 9600);



int main()
{
    cout << "Frecuencia del led Rojo" << "\n" << "Por favor ingrese un valor:" << "\n";
   int R;
   cin >> R; 

   cout << "Frecuencia del led Rojo" << "\n" << "Por favor ingrese un valor:" << "\n";
   int G;
   cin >> G; 

   cout << "Frecuencia del led Rojo" << "\n" << "Por favor ingrese un valor:" << "\n";
   int B;
   cin >> B; 

    int mcd = mcd3(R,G,B);

    // Initialise the digital pin LED1 as an output
    DigitalOut ledR(LED1, 1);
    DigitalOut ledG(LED2, 1);
    DigitalOut ledB(LED3, 1);
    // Variable contador - periodos del mcm de los LEDs
    int count = 0;

    while (true) {
        if(count % (R/mcd) == 0) {
            ledR = !ledR;
            cout << "LedR = " << count*mcd << BLINKING_UNITS << endl;
        }
        if(count % (G/mcd) == 0) {
            ledG = !ledG;
            cout << "LedG = " << count*mcd << BLINKING_UNITS << endl;
        }
        if(count % (B/mcd) == 0) {
            ledB = !ledB;
            cout << "LedB = " << count*mcd << BLINKING_UNITS << endl;
        }

        ThisThread::sleep_for(BLINKING_RATE);
        count += 1;
    }
}
