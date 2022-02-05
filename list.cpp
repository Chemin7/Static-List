
#include <iostream>
#include <string>

#include "list.h"
#include "song.h"

using namespace std;
/*
template <class T, int ARRAYSIZE>
List<T,ARRAYSIZE>::List()
{
    lastIndex = -1;
}

template <class T, int ARRAYSIZE>
bool List<T,ARRAYSIZE>::blank() const
{
   return (lastIndex == -1) ? true:false;
}

template <class T, int ARRAYSIZE>
bool List<T,ARRAYSIZE>::full() const
{
    return (sizeArr -1 == lastIndex) ? true:false;
}

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::add(T& s, const int index)
{
    if(lastIndex + 1 >= sizeArr || index < 0 || index > lastIndex + 1){
        return;
    }else{
        for(int i = lastIndex;i>=index;i--){
            arr[i+1]=arr[i];
        }
        arr[index] = s;
        lastIndex++;
    }
}

template <class T, int ARRAYSIZE>
void List<T,ARRAYSIZE>::takeOff(const int index)
{
    if(lastIndex == -1 || index > lastIndex){
        return;
    }else{
        for(int i = index;i <= lastIndex;i++){
            arr[i] = arr[i+1];
        }
    }
    lastIndex--;
}

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::first() const
{
    return (lastIndex == -1) ? -1:0;
}

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::last() const
{
    return (lastIndex == -1) ? -1: lastIndex;
}

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::previous( int index)
{
    return (this->blank() || index < 1 || index > lastIndex) ?
        -1: index--;
}

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::next( int index)
{
    return (this->blank()|| index < 0 || index > lastIndex - 1) ?
        -1: index++;
}

template <class T, int ARRAYSIZE>
int List<T,ARRAYSIZE>::locate(T& s)
{
    if(!(this->blank()) ){
        for(int i = 0; i<= lastIndex;i++){
            if(this->arr[i] == s)
                return i;
        }
    }
    return -1;
}
template <class T, int ARRAYSIZE>
T List<T,ARRAYSIZE>::retrieve(int index)
{

    for(int i = 0;i<=lastIndex;i++){

    }
}



template <class T, int ARRAYSIZE>
string List<T,ARRAYSIZE>::toString()
{
    string txt;
    txt.append("Nombre");
    txt.append(10u,' ');
    txt.append("|Autor");
    txt.append(10u,' ');
    txt.append("|Ranking\n");

    for(int i = 0;i < lastIndex+1;i++){
        txt+=arr[i].toString();
        txt+="\n";
    }
    return txt;
}
*/

