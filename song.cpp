
#include "song.h"
#include <iomanip>

using namespace std;

Song::Song()
{

}
Song::Song(std::string n, std::string a, unsigned int r)
{
    name = n;
    author = a;
    ranking = r;
}


string Song::getName()
{
    return name;
}

string Song::getAuthor()
{
    return author;
}

unsigned int Song::getRanking()
{
    return ranking;
}

void Song::setName(const std::string n)
{
    name = n;
}

void Song::setAuthor(const std::string a)
{
    author = a;
}

void Song::setRanking(const unsigned int r)
{
    ranking = r;
}

bool Song::operator==(Song s)
{
    if(this->author == s.getAuthor() && this->name == s.getName() && this->ranking==s.getRanking() ){
        return true;
    }else{
        return false;
    }
}



bool Song::operator<(Song s)
{
    if(this->ranking <  s.getRanking()){
        return true;
    }else
        return false;
}

ostream& operator <<(ostream& out,const Song &s){

    out<<left;
    out<<setw(18)<<s.author;
    out<<setw(18)<<s.name;
    out<<setw(18)<<s.ranking;

    return out;
}




