#include <iostream>
#include <string>

#include  "song.h"
#include "list.h"
#include "userinterface.h";

using namespace std;

int main() {
    List<Song,50> lista;
    UserInterface ui(lista);

    ui.mainMenu();

    return 0;
    }
