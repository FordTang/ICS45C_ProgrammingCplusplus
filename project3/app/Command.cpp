//Ford Tang
//46564602
//ICS 45C
//Project 3


#include "Command.hpp"

Command::Command()
{
    debug_flag = false;
}

/*
Command::Command(const Command& com)
{

}

Command::~Command()
{

}

Command& Command::operator=(const Command& com)
{

}
*/

void Command::getCommand()
{
    std::string line;
    std::string first;
    std::string second;
    std::string third;
    do
    {
        std::getline(std::cin, line);
        first = "";
        second = "";
        third = "";
        if (line.find(" ") == -1)
            first = line;
        else
        {
            first = line.substr(0, line.find(" "));
            line.erase(0, line.find(" ") + 1);
            if (line.find(" ") == -1)
                second = line;
            else
            {
                second = line.substr(0, line.find(" "));
                line.erase(0, line.find(" ") + 1);
                third = line;
            }
        }
        if (first == "CREATE")
        {
            if (second == "" || third == "")
                std::cout << "INVALID" << std::endl;
            else
                this->create(second, third);
        }
        else if (first == "LOGIN")
        {
            if (second == "")
                std::cout << "INVALID" << std::endl;
            else if (second == "COUNT" && third == "")
                this->loginCount();
            else if (second != "" && third != "")
                this->login(second, third);
            else
                std::cout << "INVALID" << std::endl;
        }
        else if (first == "REMOVE" || first == "DEBUG" || first == "BUCKET" || first == "LOAD")
        {
            if (second == "")
                std::cout << "INVALID" << std::endl;
            else if (first == "REMOVE")
                this->remove(second);
            else if (first == "DEBUG")
                this->debug(second);
            else if (first == "BUCKET" && second == "COUNT")
                this->bucketCount();
            else if (first == "LOAD" && second == "FACTOR")
                this->loadFactor();
            else
                std::cout << "INVALID" << std::endl;
        }
        else if (first == "CLEAR")
            this->clear();
        else if (first == "QUIT")
            this->quit();
        else if (first == "MAX" && second == "BUCKET" && third == "SIZE")
            this->maxBucketSize();
        else
            std::cout << "INVALID" << std::endl;
    }
    while (first != "QUIT");
}

void Command::create(const std::string& username, const std::string& password)
{
    if (map.contains(username))
        std::cout << "EXISTS" <<std::endl;
    else
    {
        map.add(username, password);
        std::cout << "CREATED" << std::endl;
    }
}

void Command::login(const std::string& username, const std::string& password)
{
    if (map.value(username) == password)
        std::cout << "SUCCEEDED" << std::endl;
    else
        std::cout << "FAILED" << std::endl;
}

void Command::remove(const std::string& username)
{
    if (map.contains(username))
    {
        map.remove(username);
        std::cout << "REMOVED" << std::endl;
    }
    else
        std::cout << "NONEXISTENT" << std::endl;
}

void Command::clear()
{
    map.clearBucket();
    std::cout << "CLEARED" << std::endl;
}

void Command::quit()
{
    std::cout << "GOODBYE" << std::endl;
}

void Command::debug(const std::string& onoff)
{
    if (onoff == "ON" && debug_flag)
        std::cout << "ON ALREADY" << std::endl;
    else if (onoff == "ON" && !debug_flag)
    {
        debug_flag = true;
        std::cout << "ON NOW" << std::endl;
    }
    else if (onoff == "OFF" && debug_flag)
    {
        debug_flag = false;
        std::cout << "OFF NOW" << std:: endl;
    }
    else
        std::cout << "OFF ALREADY" << std::endl;
}

void Command::loginCount()
{
    if (debug_flag)
        std::cout << map.size() << std::endl;
    else
        std::cout << "INVALID" << std::endl;
}

void Command::bucketCount()
{   
    if (debug_flag)
        std::cout << map.bucketCount() << std::endl;
    else
        std::cout << "INVALID" << std::endl;
}

void Command::loadFactor()
{
    if (debug_flag)
        std::cout << map.loadFactor() << std::endl;
    else
        std::cout << "INVALID" << std::endl;
}

void Command::maxBucketSize()
{
    if (debug_flag)
        std::cout << map.maxBucketSize() << std::endl;
    else
        std::cout << "INVALID" << std::endl;
}
