#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <string>
#include <iomanip>
#include <exception>
#include <functional>
#include "song.h"

#include <iostream>

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

        void swapData(T&,T&);

    public:
        List();

        T getElem(int);
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

        std::string toString();

        int findDataLinear( T&, std::function<int(T&,T& )>);
        int findDataBinary(T&, std::function<int(T&,T& )>);

        void sortDataBubble();
        void sortDataInsert();
        void sortDataSelect();
        void sortDataShell();

        void sortDataBubble(std::function<int(T&,T&)>);
        void sortDataInsert(std::function<int(T&,T&)>);
        void sortDataSelect(std::function<int(T&,T&)>);
        void sortDataShell(std::function<int(T&,T&)>);



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
    else if(index > lastIndex || index < 0) {
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
    if(!blank()) {
        for(int i = lastIndex; i >= 0; i--) {
            arr[i] = arr[i+1];
            }
        lastIndex=-1;
        }
    }


template <class T, int ARRAYSIZE>
T List<T,ARRAYSIZE>::getElem(int pos) {
    return arr[pos];
    }


template <class T, int ARRAYSIZE>
string List<T,ARRAYSIZE>::toString() {
    string txt,temp;

    int i(0);

    temp="Nombre";
    temp.resize(20,' ');
    txt+=temp;

    temp="| Autor";
    temp.resize(20,' ');
    txt+=temp;

    temp="| Interprete";
    temp.resize(20,' ');
    txt+=temp;

    temp="| Nombre de archivo\n";
    temp.resize(20,' ');
    txt+=temp;

    while(i <= last()) {
        txt += arr[i].toString();
        txt+= "\n";
        i++;
        }

    return txt;
    }

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::findDataLinear( T& e, function<int(T&,T& )> cmp) {
    int i(0);

    while(i <= lastIndex) {
        if(cmp(arr[i],e)== 0)
            return i;

        i++;

        }
    return -1;
    }

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::findDataBinary(T& e, function<int(T&,T& )> cmp) {
    int i(0), j(lastIndex),m;

    while(i<= j) {
        m = (i+j)/2;

        if(cmp(arr[m],e) == 0)
            return m;
        if(cmp(arr[m],e) < 0)
            j=m-1;
        else
            i=m+1;
        }
    return -1;
    }

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::swapData(T& a, T& b) {
    T aux(a);

    a = b;
    b=aux;
    }

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataBubble() {
    int i(lastIndex),j;
    bool flag;

    do {
        flag = false;
        j=0;

        while(j<i) {
            if(arr[j]>arr[j+1]) {
                swapData(arr[j],arr[j+1]);
                flag= true;
                }
            j++;
            }
        i--;
        }
    while(flag);
    }

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataInsert() {
    int i(1),j;
    T aux;

    while( i <= lastIndex) {
        aux = arr[i];
        j=i;

        while(j > 0 and aux < arr[j-1]) {
            arr[j]=arr[j-1];
            j--;
            }
        if(i!=j)
            arr[j]=aux;

        i++;
        }
    }

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataSelect() {
    int i(0),j,m;

    while(i<last) {
        m=i;
        j=i+1;
        while(j <= last) {
            if(arr[j] < arr[m])
                m = j;

            j++;

            }
        if(i!=m)
            swapData(arr[i],arr[m]);

        i++;
        }
    }
template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataShell() {
    float factor(0.5);

    int dif((lastIndex+1)*factor),i,j;

    while(dif > 0) {
        i=dif;

        while(i<=lastIndex) {
            j=i;

            while(j>=dif and arr[j-dif] > arr[j]) {
                swapData(arr[j-dif],arr[j]);

                j-=dif;
                }
            }
        dif*=factor;
        }

    }

///Explicit search methods
template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataBubble(function<int(T&,T&)> cmp) {
    int i(lastIndex),j;
    bool flag;

    do {
        flag = false;
        j=0;

        while(j<i) {
            if(cmp(arr[j],arr[j+1])>0) {
                swapData(arr[j],arr[j+1]);
                flag= true;
                }
            j++;
            }
        i--;
        }
    while(flag);
    }

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataInsert(function<int(T&,T&)> cmp) {
    int i(1),j;
    T aux;

    while( i <= lastIndex) {
        aux = arr[i];
        j=i;
        while(j > 0 and cmp(aux,arr[j-1]) < 0) {
            arr[j]=arr[j-1];
            j--;
            }
        if(i!=j)
            arr[j]=aux;

        i++;
        }
    }

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataSelect(function<int(T&,T&)> cmp) {
    int i(0),j,m;

    while(i<lastIndex) {
        m=i;
        j=i+1;
        while(j <= lastIndex) {
            if(cmp(arr[j],arr[m])<0)
                m = j;

            j++;

            }
        if(i!=m)
            swapData(arr[i],arr[m]);

        i++;
        }
    }
template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::sortDataShell(function<int(T&,T&)> cmp) {
    float factor(0.5);

    int dif((lastIndex+1)*factor),i,j;

    while(dif > 0) {
        i=dif;

        while(i<=lastIndex) {
            j=i;

            while(j>=dif and cmp(arr[j-dif],arr[j]) > 0) {
                swapData(arr[j-dif],arr[j]);

                j-=dif;
                }
                i++;
            }
            dif*=factor;
        }

    }


#endif // LIST_H_INCLUDED
