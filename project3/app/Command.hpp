//Ford Tang
//46564602
//ICS 45C
//Project 3


#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <iostream>
#include "HashMap.hpp"

class Command
{
public:

    Command();

//    Command(const Command& com);

//    ~Command();

//    Command& operator=(const Command& com);

    void getCommand();

private:

    bool debug_flag;
    HashMap map;

    void create(const std::string& username, const std::string& password);

    void login(const std::string& username, const std::string& password);

    void remove(const std::string& username);

    void clear();

    void quit();

    void debug(const std::string& onoff);

    void loginCount();

    void bucketCount();

    void loadFactor();

    void maxBucketSize();
};



#endif
