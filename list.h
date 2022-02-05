#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <string>
#include <iomanip>
#include <exception>

#include "song.h"

class ListException : public std::exception {
    private:
        std::string msg;
    public:
        explicit ListException(const char* message) : msg(message) {}

        explicit ListException(const std::string& message) : msg(message) {}

        virtual ~ListException() throw () {}

        virtual const char* what() const throw () {
            return msg.c_str();
            }
    };

template <class T, int ARRAYSIZE=50>
class List {
    private:

        T arr[ARRAYSIZE];
        int lastIndex;

    public:
        List();

        bool blank() const;
        bool full() const;
        void add(T&,const int);
        void takeOff(const int);
        int first() const;
        int last() const;
        int previous( int);
        int next( int);
        T retrieve(int);
        void deleteAll();

        void print();



    };
using namespace std;

template <class T, int ARRAYSIZE>
List<T,ARRAYSIZE>::List() {
    lastIndex = -1;
    }

template <class T, int ARRAYSIZE>
bool List<T,ARRAYSIZE>::blank() const {
    return (lastIndex == -1) ? true:false;
    }

template <class T, int ARRAYSIZE>
bool List<T,ARRAYSIZE>::full() const {
    return (ARRAYSIZE -1 == lastIndex) ? true:false;
    }

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::add(T& s, const int index) {
    if(full()) {
        throw ListException("Espacio lleno, add");
        }
    if(index < 0 || index > lastIndex + 1) {
        throw ListException("Posicion invalida, add");
        }

    for(int i = lastIndex; i>=index; i--) {
        arr[i+1]=arr[i];
        }
    arr[index] = s;
    lastIndex++;

    }

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::takeOff(const int index) {
    if(lastIndex == -1 || index > lastIndex) {
        return;
        }
    else {
        for(int i = index; i < lastIndex; i++) {
            arr[i] = arr[i+1];
            }
        }
    lastIndex--;
    }

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::first() const {
    return (lastIndex == -1) ? -1:0;
    }

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::last() const {
    return (lastIndex == -1) ? -1: lastIndex;
    }

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::previous( int index) {
    return (this->blank() || index < 1 || index > lastIndex) ?
           -1: index--;
    }

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::next( int index) {
    return (this->blank()|| index < 0 || index > lastIndex - 1) ?
           -1: index++;
    }

template <class T, int ARRAYSIZE>
T List<T,ARRAYSIZE>::retrieve(int index) {

    if(blank()) {
    throw ListException("No hay elementos que recuperar, retrieve");
        }
    else if(index > lastIndex || index < 0){
        throw ListException("No hay elementos en esa posicion, retrieve");
    }
    else {
        for(int i = 0; i<=lastIndex; i++) {
            if(index == i) {
                return arr[i];
                }
            }
        }
    }

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::deleteAll() {
    if(!blank()){
    for(int i = lastIndex; i >= 0; i--) {
        arr[i] = arr[i+1];
        }
    lastIndex=-1;
    }
}


template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::print() {
    cout<<left;
    cout<<setw(17)<<"NOMBRE";
    cout<<setw(17)<<"AUTOR";
    cout<<setw(17)<<"RANKING";
    cout<<endl;


    for(int i = 0; i < lastIndex+1; i++) {
        cout<<arr[i]<<endl;
        }


    }

#endif // LIST_H_INCLUDED
