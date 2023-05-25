#include <iostream>
using namespace std;
#include "envio.h"
#include "paquete.h"
int globalcost=10;

int main(){
    Envio envio1("Juan Perez", "Av. Siempre Viva 123", "Springfield", "Ohio", 45501, globalcost);
   
    cout<<envio1.getNombre()<<endl;

}
