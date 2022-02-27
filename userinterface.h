#ifndef USERINTERFACE_H_INCLUDED
#define USERINTERFACE_H_INCLUDED

#include "song.h"
#include "list.h"

class UserInterface {

    private:
        List<Song>* myList;

        void insertElem();
        void removeElem();
        void getElem();
        void deleteAllElems();
        void findElem();
        void linearSearch(char);
        void binarySearch(char opc);
        void sortElements();




    public:
        UserInterface(List<Song>&);

        void mainMenu();


    };

#endif // USERINTERFACE_H_INCLUDED
