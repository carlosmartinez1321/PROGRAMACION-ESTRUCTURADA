#include <iostream>
#include <fstream>
#include <string>
#include <limits>

         //Declaracion de las librerias//
         
               using namespace std;
               
       //Ahora vamos a resalizar nuestra estructura "struct", con l afinalidad de qu nos mustre y represente a un operador que este en sesion activa//
       
               struct Sesion 
               
           {
               int idOperador;
               string Nombre;
               Sesion*siguiente;  //Aqui "Sesion* siguiente" es el apuntador qur nos va a enlazar a la lista de los opoeradores registrados en nuesto sistema PAD-Bienestar 
               
           };
           
     //Declaracion de estructura  para los turnos y la atencion de los beneficicarios//
         struct Turno 
                                { 
           int numeroTurno;
           string Beneficiario;
           string Programa;
           Turno*siguiente;
           };
           
           //Ahora hacemos la estructura del inicio de la lista de los operadores utilizando nullptr//
           
           //Aqui es donde se pone a prueba el FIFO , fIRST IN FIRST OUT//
           
           Sesion*cabeza=nullptr;
           Turno* frente= nullptr;
           Turno* final= nullptr;
           
           int contadorTurnos = 1;
           
           // Aqui estan los "vacios" o void necesarios para el menu, solo queremos que tomen informacion pero que no devuelvan nada//
           
           void menuPrincipal();
           void menuSesiones();
           void menuTurnos();
           
          //Sesiones//
          
          void  iniciarSesion();
          void mostrarSesiones();
           void cerrarSesion();
           
           //Turnos que estan en espera, atendidos etc//
           
           void generarTurno();
           void atenderTurno();
           void  mostrarTurnos();
           
           //Aqui para la bitacora  que es necesara para revisar los moviemientos anterioires si asi se requiere//
           
           void registrarBitacora (string evento);
          void  mostrarBitacora();
          
          int main()
          {
           
           menuPrincipal();
           
            return 0;
            
           }
           
           
           
           void menuPrincipal()
           {
               int opcion;
               do
               {
                   cout << "\n==================================";
                   cout << "\n          PAD - BIENESTAR MEXICO";
                   cout << "\n     Siempre listos , siempre serviciales";
                   cout << "\n==================================";
                   cout << "\n Programa con validez oficial sin fines de lucro";
                   cout << "\n****************************************";
                   
                   
                   cout << "\n1. Gestion de sesiones activas";
                   cout <<"\n2. Gestion de turnos";
                   cout << "\n3. Ver bitacora";
                   cout << " \n4. Salir";
                   
                   cout << "\n\n Seleccione una opcion:  ";
                   cin >> opcion;
                   
                   switch (opcion)
                   {
                       case 1:
                           menuSesiones();
                           break;
                           
                     case 2:
                        menuTurnos();
                        break;
                        
                     case 3:
                     mostrarBitacora();
                     break;
                     
                    case 4:   
                   
                   cout <<"\nSaliendo del sistema en un momento......";
                   cout <<"\n Programa elaborado por:";
                   cout <<"\n ****Alma Delgadillo Solana Gpo:210****";
                   cout <<"\n**** Johan Andres Delgadillo Debora Gpo:208**** ";
                   cout <<"\n****Carlos David Martinez Ramirez Gpo :208**** ";
                   cout <<"\n****Universidad Nacional Rosario Castellanos**** ";
                   cout <<"\n****Licenciatura en Tecnologias de la Comunicacion y la Informacion**** ";
                   
                   break;
                   
                   
                   default :
                   cout << "\nOpcion invalida, ingrese por favor una opcion viable ";
                   break;
                   }
                   
             }while(opcion != 4);
             
                   }      
                    
 void menuSesiones()
{
    int opcion;

    do
    {
        cout << "\n\n===== GESTION DE SESIONES =====";
        cout << "\n1. Iniciar sesion";
        cout << "\n2. Mostrar sesiones activas";
        cout << "\n3. Cerrar sesion";
        cout << "\n4. Regresar";

        cout << "\nSeleccione una opcion: ";
        cin >> opcion;

// Aqui usaremos el switch para desplegar opciones dentro desde menu y los casos que requerimos ante situaciones de seleccion//

        switch(opcion)
        {
            case 1:
                iniciarSesion();
                break;

            case 2:
                mostrarSesiones();
                break;

            case 3:
                cerrarSesion();
                break;

            case 4:
                cout << "\nRegresando al menu principal...";
                break;

            default:
                cout << "\nOpcion invalida.";
        }

    } while(opcion != 4);
}


void iniciarSesion()
{
    Sesion* nuevo = new Sesion;

    cout << "\nIngrese el ID del operador: ";
    cin >> nuevo->idOperador;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Ingrese el nombre del operador: ";
    getline(cin, nuevo->Nombre);

    nuevo->siguiente = nullptr;

    if(cabeza == nullptr)
    {
        cabeza = nuevo;
    }
    else
    {
        Sesion* aux = cabeza;

        while(aux->siguiente != nullptr)
        {
            aux = aux->siguiente;
        }

        aux->siguiente = nuevo;
    }

    cout << "\nSesion iniciada correctamente.\n";

    registrarBitacora("Inicio de sesion: " + nuevo->Nombre);
}


void mostrarSesiones()
{
    if(cabeza == nullptr)
    {
        cout << "\nNo hay sesiones activas.\n";
        return;
    }

    Sesion* aux = cabeza;

    cout << "\n===== OPERADORES ACTIVOS =====";

    while(aux != nullptr)
    {
        cout << "\nID: " << aux->idOperador;
        cout << "\nNombre: " << aux->Nombre;
        cout << "\n-------------------------";

        aux = aux->siguiente;
    }
}

void cerrarSesion()
{
    if(cabeza == nullptr)
    {
        cout << "\nNo existen sesiones activas.\n";
        return;
    }

    int id;

    cout << "\nIngrese el ID del operador a cerrar sesion: ";
    cin >> id;

    Sesion* aux = cabeza;
    Sesion* anterior = nullptr;

    while(aux != nullptr && aux->idOperador != id)   //esta linea es importantisima por que aqui sabemos que null funge como un inicio y alli señalamos que es id de inicio// 
    {
        anterior = aux;
        aux = aux->siguiente;
    }

    if(aux == nullptr)
    {
        cout << "\nOperador no encontrado.\n";
        return;
    }

    string nombre = aux->Nombre;

    if(anterior == nullptr)
    {
        cabeza = aux->siguiente;
    }
    else
    {
        anterior->siguiente = aux->siguiente;
    }

    delete aux;

    cout << "\nSesion cerrada correctamente.\n";

    registrarBitacora("Cierre de sesion: " + nombre);
}

void menuTurnos()
{
    int opcion;

    do
    {
        cout << "\n\n===== GESTION DE TURNOS =====";
        cout << "\n1. Generar turno";
        cout << "\n2. Mostrar turnos";
        cout << "\n3. Atender turno";
        cout << "\n4. Regresar";

        cout << "\nSeleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                generarTurno();
                break;

            case 2:
                mostrarTurnos();
                break;

            case 3:
                atenderTurno();
                break;

            case 4:
                cout << "\nRegresando al menu principal...";
                break;

            default:
                cout << "\nOpcion invalida.";
        }

    } while(opcion != 4);
}

void mostrarBitacora()

{
    ifstream archivo("bitacora.txt");

    string linea;

    cout << "\n===== BITACORA DEL SISTEMA =====\n";

    while(getline(archivo, linea))
    {
        cout << linea << endl;
    }

    archivo.close();
}

void registrarBitacora(string evento)
{
    ofstream archivo("bitacora.txt",ios::app);  // esta linea crea archivo "rom"que leera despues el programa y tomara la informacion de la bitacora //
    
           if(archivo.is_open())
             
      {
          archivo << evento <<endl;
          archivo.close();
          }       
}  

   void generarTurno()
{
    Turno* nuevo = new Turno;

    nuevo->numeroTurno = contadorTurnos++;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nIngrese el nombre de la persona beneficiada: ";
    getline(cin, nuevo->Beneficiario);

    cout << "Ingrese el programa que el beneficiado solicita: ";
    getline(cin, nuevo->Programa);

    nuevo->siguiente = nullptr;

    if(frente == nullptr)
    {
        frente = nuevo;
        final = nuevo;
    }
    else
    {
        final->siguiente = nuevo;
        final = nuevo;
    }

    cout << "\nTurno generado de forma adecuada,por favor continue.";
    cout << "\nNumero de turno: " << nuevo->numeroTurno << endl;

    registrarBitacora(
        "Turno generado: " +
        to_string(nuevo->numeroTurno) +
        " - " +
        nuevo->Beneficiario
    );
}

void mostrarTurnos()
{
    if(frente == nullptr)
    {
        cout << "\nNo existen turnos pendientes.\n";
        return;
    }

    Turno* aux = frente;

    cout << "\n===== TURNOS PENDIENTES QUE REQUIEREN ATENCION =====";

    while(aux != nullptr)
    {
        cout << "\nTurno: " << aux->numeroTurno;
        cout << "\nBeneficiario: " << aux->Beneficiario;
        cout << "\nPrograma: " << aux->Programa;
        cout << "\n---------------------------";

        aux = aux->siguiente;
    }
}

void atenderTurno()
{
    if(frente == nullptr)
    {
        cout << "\nNo hay turnos para atender.\n";
        return;
    }

    Turno* aux = frente;

    cout << "\nAtendiendo turno: " << aux->numeroTurno;
    cout << "\nBeneficiario: " << aux->Beneficiario;
    cout << "\nPrograma: " << aux->Programa << endl;

    registrarBitacora(
        "Turno atendido: " +
        to_string(aux->numeroTurno) +
        " - " +
        aux->Beneficiario
    );

    frente = frente->siguiente;

    if(frente == nullptr)
    {
        final = nullptr;
    }

    delete aux;

    cout << "\nTurno atendido correctamente.\n";
}
                    
                     
                                                   
                           
                   
           
            
           
                                                                                         
               