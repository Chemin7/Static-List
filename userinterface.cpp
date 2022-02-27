#include "song.h"
#include <iostream>
#include <string>
#include <functional>

#include "userinterface.h"

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
        cout<<"6) Encontrar elemento "<<endl;
        cout<<"7) Ordenar elementos "<<endl;
        cout<<"8) Salir"<<endl;
        cout<<"Seleccione una opcion: ";
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
                cout<<myList->toString();
                break;
            case 6:
                findElem();
                break;
            case 7:
                sortElements();
                break;
            case 8:
                cout<<"Saliendo..."<<endl;
                j++;
                break;
            default:
                cout<<"Opcion invalida"<<endl;
            }
        if(j==0) {
            cout<<"si quieres continuar presiona 1: ";
            cin>>i;
            cout<<endl;
            }
        system("cls");
        }
    while(i==1);

    }

void UserInterface::insertElem() {
    string n,a,in,mp3;
    int index;
    char opc;

    do {
        cin.ignore();
        cout<<"Ingrese el nombre de la cancion: ";
        getline(cin,n);
        cout<<"Ingrese el autor de la cancion: ";
        getline(cin,a);
        cout<<"Ingrese el interprete de la cancion: ";
        getline(cin,in);
        cout<<"Ingrese el nombre del archivo mp3: ";
        getline(cin,mp3);
        cout<<"Ingresa la posicion en donde lo quire agregar: ";
        cin>>index;
        Song s;
        s.setName(n);
        s.setAuthor(a);
        s.setInterpreter(in);
        s.setMp3(mp3);

        myList->add(s,index);
        cout<<endl;


        do {
            cout<<"Continuar agregado elementos: [S]i o [N]o: "<<endl;
            cin>>opc;
            }
        while( !(opc == 's' || opc == 'n'));
        }
    while(opc== 's');



    }

void UserInterface::removeElem() {
    int index;
    cout<<"Introduce la posicion del elemento que quieres remover: ";
    cin>>index;

    myList->takeOff(index);
    myList->toString();
    }

void UserInterface::getElem() {
    int index;
    cout<<"Introduce la posicion del elemento que quieres obtener: ";
    cin>>index;
    cout<<endl;
    cout<<"Cancion obtenida: "<<endl;
    cout<<myList->toString()<<endl;

    }

void UserInterface::deleteAllElems() {
    myList->deleteAll();
    cout<<"Lista vacia"<<endl;
    }

void UserInterface::linearSearch(char opc) {
    Song mySong;
    string str, findBy;
    int pos;
    if(opc == 'c')
        findBy="cancion";
    else
        findBy="interprete";

    cout<<"Introduce el elemento a buscar por "<<findBy<<": "<<endl;
    cin.ignore();
    getline(cin,str);



    if(opc == 'c') {
        mySong.setName(str);
        pos = myList->findDataLinear(mySong,Song::compareByName);
        }
    else {
        mySong.setInterpreter(str);
        pos =  myList->findDataLinear(mySong,Song::compareByInterpreter);
        }
    if(pos == -1) {
        cout<<"Elemento en la lista no encontrado. "<<endl;
        }
    else {
        cout<<"Elemento encontrado en la pos "<<pos<<": "<<endl;
        cout<<myList->getElem(pos).toString()<<endl;;
        }


    }


void UserInterface::binarySearch(char opc) {
    Song mySong;
    string str, findBy;
    int pos;
    if(opc == 'c')
        findBy="cancion";
    else
        findBy="interprete";

    cout<<"Introduce el elemento a buscar por "<<findBy<<": "<<endl;
    cin.ignore();
    getline(cin,str);



    if(opc == 'c') {
        mySong.setName(str);
        pos = myList->findDataBinary(mySong,&mySong.compareByName);
        }

    else {
        mySong.setInterpreter(str);
        pos =  myList->findDataBinary(mySong,&mySong.compareByInterpreter);
        }
    if(pos == -1) {
        cout<<"Elemento en la lista no encontrado. "<<endl;
        }
    else {
        cout<<"Elemento encontrado en la pos "<<pos<<": "<<endl;
        cout<<myList->getElem(pos).toString()<<endl;;
        }


    }


void UserInterface::findElem() {
    char opc;
    int method;
    do {
        cout<<"Encontrar elemento por nombre de : "<<endl;
        cout<<"[C]ancion"<<endl;
        cout<<"[I]nterpete"<<endl;
        cout<<"Seleccione una opcion :";
        cin>>opc;
        }
    while( !(opc == 'c' || opc == 'i') );


    do {
        cout<<"Metodo a usar"<<endl;
        cout<<"1) Lineal"<<endl;
        cout<<"2) Binario"<<endl;
        cout<<"Seleccione una opcion :" ;
        cin>>method;
        }
    while( !(method == 1 || method == 2) );


    switch(method) {
        case 1:
            linearSearch(opc);
            break;
        case 2:
            binarySearch(opc);
            break;
        }
    }

void UserInterface::sortElements() {
    int opc1,opc2;
    cout<<"Ordenar por :\n"
        <<"1) Nombre\n"
        <<"2) Interprete\n"
        <<"Selecciona una opcion: ";
    cin>>opc1;

    cout<<"Metodo a usar: \n"
        <<"1) Bubble\n"
        <<"2) Insert\n"
        <<"3) Select\n"
        <<"4) Shell\n"
        <<"Seleccione una opcion: ";
    cin>>opc2;

    if(opc1 == 1) {
        switch(opc2) {
            case 1:
                myList->sortDataBubble(Song::compareByName);
                break;
            case 2:
                myList->sortDataInsert(Song::compareByName);
                break;
            case 3:
                myList->sortDataSelect(Song::compareByName);
                break;
            case 4:
                myList->sortDataShell(Song::compareByName);
                break;
            }
        }
    else if(opc1 == 2) {
        switch(opc2) {
            case 1:
                myList->sortDataBubble(Song::compareByInterpreter);
                break;
            case 2:
                myList->sortDataInsert(Song::compareByInterpreter);
                break;
            case 3:
                myList->sortDataSelect(Song::compareByInterpreter);
                break;
            case 4:
                myList->sortDataShell(Song::compareByInterpreter);
                break;
            }
        }

    cout<<myList->toString()<<endl;
    }

