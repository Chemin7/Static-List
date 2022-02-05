#ifndef SONG_H_INCLUDED
#define SONG_H_INCLUDED

#include <iostream>
#include <string>

class Song{
private:
    std::string name;
    std::string author ;
    unsigned int ranking;

public:
    Song();
    Song(std::string,std::string,unsigned int);

    std::string getName();
    std::string getAuthor();
    unsigned int getRanking();

    void setName(const std::string);
    void setAuthor(const std::string );
    void setRanking(const unsigned int);



    bool operator == (Song);
    bool operator < (Song);

    friend std::ostream& operator <<(std::ostream& out,const Song &s);

};

#endif // SONG_H_INCLUDED
