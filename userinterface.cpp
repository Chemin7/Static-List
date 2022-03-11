#include "userinterface.h"
#include "functional"
#include "list.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include <ctime>

using namespace std::chrono_literals;

using namespace std;
using namespace std::chrono;


void UserInterface::mainMenu() {
    static List<int,100000> listBubble,listInsert,listSelect,listShell,listMerge,listQuick;

    uniform_int_distribution<int> distribution(0,100);
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    int j;

    for(int i = 0; i <100000; i++) {
        j= distribution(generator);
        listBubble.add(j,0);
        listInsert.add(j,0);
        listSelect.add(j,0);
        listShell.add(j,0);
        listMerge.add(j,0);
        listQuick.add(j,0);
        }

    cout<<"Ordenando..."<<endl;

///---------------------------------------------------------------
    cout<<endl;
    (listBubble.isSorted()) ? (cout<<"Lista ordenada"<<endl) : (cout<<"Esta desordenada"<<endl);
    cout<<"Bubble: ";
    auto tiempoInicio = system_clock::now();
    listBubble.sortDataBubble();
    auto tiempoFin = system_clock::now();
    duration<float,milli> tiempo = tiempoFin - tiempoInicio;
    cout<<fixed<<setprecision(4) <<tiempo.count()<<" milisegs"<<endl;
    (listBubble.isSorted()) ? (cout<<"Esta ordenada"<<endl) : (cout<<"Esta desordenada"<<endl);
    cout<<endl;


    cout<<endl;
    (listInsert.isSorted()) ? (cout<<"Lista ordenada"<<endl) : (cout<<"Esta desordenada"<<endl);
    cout<<"Insert: ";
    tiempoInicio = system_clock::now();
    listInsert.sortDataInsert();
    tiempoFin = system_clock::now();
    tiempo = tiempoFin - tiempoInicio;
    cout<<fixed<<setprecision(4) <<tiempo.count()<<" milisegs"<<endl;
    (listInsert.isSorted()) ? (cout<<"Lista ordenada"<<endl) : (cout<<"Esta desordenada"<<endl);
    cout<<endl;


    cout<<endl;
    (listSelect.isSorted()) ? (cout<<"Lista ordenada"<<endl) : (cout<<"Esta desordenada"<<endl);
    cout<<"Select: ";
    tiempoInicio = system_clock::now();
    listSelect.sortDataSelect();
    tiempoFin = system_clock::now();
    tiempo = tiempoFin - tiempoInicio;
    cout<<fixed<<setprecision(4) <<tiempo.count()<<" milisegs"<<endl;
    (listSelect.isSorted()) ? (cout<<"Lista ordenada"<<endl) : (cout<<"Esta desordenada"<<endl);
    cout<<endl;


    cout<<endl;
    (listShell.isSorted()) ? (cout<<"Lista ordenada"<<endl) : (cout<<"Esta desordenada"<<endl);
    cout<<"Shell: ";
    tiempoInicio = system_clock::now();
    listShell.sortDataShell();
    tiempoFin = system_clock::now();
    tiempo = tiempoFin - tiempoInicio;
    cout<<fixed<<setprecision(4) <<tiempo.count()<<" milisegs"<<endl;
    (listShell.isSorted()) ? (cout<<"Lista ordenada"<<endl) : (cout<<"Esta desordenada"<<endl);
    cout<<endl;


    cout<<endl;
    (listMerge.isSorted()) ? (cout<<"Lista ordenada"<<endl) : (cout<<"Esta desordenada"<<endl);
    cout<<"Merge: ";
    tiempoInicio = system_clock::now();
    listMerge.sortDataMerge();
    tiempoFin = system_clock::now();
    tiempo = tiempoFin - tiempoInicio;
    cout<<fixed<<setprecision(4) <<tiempo.count()<<" milisegs"<<endl;
    (listMerge.isSorted()) ? (cout<<"Lista ordenada"<<endl) : (cout<<"Esta desordenada"<<endl);
    cout<<endl;


    cout<<endl;
    (listQuick.isSorted()) ? (cout<<"Lista ordenada"<<endl) : (cout<<"Esta desordenada"<<endl);
    cout<<"Quick: ";
    tiempoInicio = system_clock::now();
    listQuick.sortDataQuick();
    tiempoFin = system_clock::now();
    tiempo = tiempoFin - tiempoInicio;
    cout<<fixed<<setprecision(4) <<tiempo.count()<<" milisegs"<<endl;
    (listQuick.isSorted()) ? (cout<<"Lista ordenada"<<endl) : (cout<<"Esta desordenada"<<endl);
    cout<<endl;
///--------------------------------------------------------------

    }
