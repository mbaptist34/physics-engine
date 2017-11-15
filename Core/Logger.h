
#ifndef ____Logger__
#define ____Logger__

#include <fstream>
#include <string>
#include "ProjectBuildSettings.h"

//These are const ints so that we can binary and them
const int LOG_APP = 1;
const int LOG_CLIENT = 2;
const int LOG_SERVER = 4;

const int LOG_USER = 8;

#define LOG_STRINGS 256

class Logger {
    
private:
    Logger(); //Singleton, can't be instantiated.
    
    std::ofstream appLog;
    std::ofstream clientLog;
    std::ofstream serverLog;
    
    std::string logStrings[LOG_STRINGS];
    bool loadStrings();
    
public:
    static Logger &Get();
    
    bool Init();
    
    void Write(int target, const char *msg, ...);
    void Write(int target, unsigned long msgID, ...);
    
};

#define LOGGER Logger::Get()

#endif /* defined(____Logger__) */
