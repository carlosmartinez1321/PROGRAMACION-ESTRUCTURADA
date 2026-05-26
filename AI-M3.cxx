#include <iostream>
#include <cstdlib> // Necesario para usar malloc y free

using namespace std;//Como ya sabemos esto es para que los espacios entre lineas se den sin necesidad de mover todo

// Estructura del nodo para cada turno,es decir aqui usamls struct para definir dicha estructura del nodo 
struct Turno {
    int numeroTurno;      // Guarda el número del turno
    Turno *siguiente;     // Apuntador al siguiente nodo
};

// Apuntadores globales para inicio y final de la cola
Turno *inicio = NULL;
Turno *fin = NULL;


// Función para agregar un nuevo turno a la cola para eso usamos void, que como sabemos solo regresa nada en este caso.
void agregarTurno() {

    Turno *nuevo;

    // Reserva memoria dinámica para un nuevo nodo
    nuevo = (Turno*) malloc(sizeof(Turno));

    if(nuevo == NULL){
        cout << "\nError: no hay memoria disponible\n";
        return;
    }

    cout << "\nIngrese numero de turno: ";
    cin >> nuevo->numeroTurno;

    nuevo->siguiente = NULL;

    // Si la cola está vacía, inicio y fin apuntan al mismo nodo
    if(inicio == NULL){

        inicio = nuevo;
        fin = nuevo;

    }else{

        // Se enlaza el nuevo nodo al final
        fin->siguiente = nuevo;

        // Se actualiza el puntero final
        fin = nuevo;
    }

    cout << "Turno agregado con éxito\n";
}



// Función para atender al primer usuario (FIFO) o sea primero en entrar ,primero en salir por sus siglas en ingles.
void atenderTurno(){

    // Validación si la cola está vacía
    if(inicio == NULL){

        cout<<"\nNo hay turnos pendientes,todos han sido a5endidos correctamente\n";
        return;
    }

    Turno *aux = inicio;

    cout << "\nAtendiendo turno con numero: "
         << inicio->numeroTurno;

    // El inicio avanza al siguiente nodo
    inicio = inicio->siguiente;

    // Si ya no quedan elementos
    if(inicio == NULL){

        fin = NULL;
    }

    // Libera memoria del nodo eliminado
    free(aux);

    cout<<"\nTurno atendido correctamente,por favor continue.\n";
}



// Función para mostrar la cola completa
void mostrarCola(){

    // Verifica si existen turnos
    if(inicio == NULL){

        cout<<"\nLa cola esta vacia,alguien mas puede ocupar la fila o invite a los interesados a tomar turno\n";
        return;
    }

    Turno *aux = inicio;

    cout<<"\n--- TURNOS EN ESPERA,AGRADECEMOS SU PACIENCIA ---\n";

    // Recorre toda la cola
    while(aux != NULL){

        cout<<"Turno: "
            <<aux->numeroTurno
            <<endl;

        aux = aux->siguiente;
    }
}



// Menú principal
int main(){

    int opcion;

    do{

        cout<<"\n===== *****PAD-BIENESTAR ,SIEMPRE LISTOS,SIEMPRE SERVICIALES*****=====";
        cout<<"\n1. Agregar turno";
        cout<<"\n2. Atender turno";
        cout<<"\n3. Mostrar cola";
        cout<<"\n4. Salir";
        cout<<"\nSeleccione opcion: ";
        cin>>opcion;

        switch(opcion){

            case 1:
                agregarTurno();
                break;

            case 2:
                atenderTurno();
                break;

            case 3:
                mostrarCola();
                break;

            case 4:
                cout<<"\nSaliendo del sistema...";
                break;

            default:
                cout<<"\nOpcion invalida";
        }

    }while(opcion!=4);
    
    cout<<"MUCHAS GRACIAS POR CONFIAR EN NOSOTROS, ORGULLOSAMENTE ROSARIO CASTELLANOS ";
    cout<<"REALIZÓ: ===JOHAN DEBORA===,===ALMA ROSA DELGADILLO SOLANO,===CARLOS DAVID MARTINEZ RAMIREZ===";

    return 0;
}