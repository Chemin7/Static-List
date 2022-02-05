#include <iostream>
#include <string>

#include "userinterface.h"

#include "song.h"
#include "list.h"

using namespace std;


UserInterface::UserInterface(List<Song>& l) {
    myList = &l;
    }

void UserInterface::mainMenu() {

    int opc,i,j;

    i=0,j=0;
    do {
        cout<<"Lista de canciones exitosas"<<endl;
        cout<<"1) Insertar una cancion"<<endl;
        cout<<"2) Elimina una cancion"<<endl;
        cout<<"3) Obten una cancion"<<endl;
        cout<<"4) Borrar lista"<<endl;
        cout<<"5) Mostrar lista"<<endl;
        cout<<"6) Salir"<<endl;
        cin>>opc;

        switch(opc) {
            case 1:
                insertElem();
                break;
            case 2:
                removeElem();
                break;
            case 3:
                getElem();
                break;
            case 4:
                deleteAllElems();
                break;
            case 5:
                myList->print();
                break;
            case 6:
                cout<<"Saliendo..."<<endl;
                j++;
                break;
            default:
                cout<<"Opcion invalida"<<endl;
            }
            if(j==0){
        cout<<"si quieres continuar presiona 1: ";
        cin>>i;
        cout<<endl;
            }
        system("cls");
        }
    while(i==1);

    }

void UserInterface::insertElem() {
    string n,a;
    unsigned int r;
    int i,index;

    i=0;
    do {
        cout<<"Ingrese el nombre de la cancion: ";
        cin.ignore();
        getline(cin,n);
        cout<<"Ingrese el autor de la cancion: ";
        getline(cin,a);
        cout<<"Ingrese el ranking de la cancion: ";
        cin>>r;
        cout<<"Ingresa la posicion en donde lo quire agregar: ";
        cin>>index;
        Song s(a,n,r);
        myList->add(s,index);
        cout<<endl;
        myList->print();
        cout<<endl;

        cout<<"Si quires agregar otro elemento presiona 1: ";
        cin>>i;
        cout<<endl;

        }
    while(i==1);



    }

void UserInterface::removeElem() {
    int index;
    cout<<"Introduce la posicion del elemento que quieres remover: ";
    cin>>index;

    myList->takeOff(index);
    myList->print();
    }

void UserInterface::getElem() {
    int index;
    cout<<"Introduce la posicion del elemento que quieres obtener: ";
    cin>>index;
    cout<<endl;
    cout<<"Cancion obtenida: "<<endl;
    cout<<myList->retrieve(index)<<endl;

    }

void UserInterface::deleteAllElems() {
        myList->deleteAll();
        cout<<"Lista vacia"<<endl;
    }


