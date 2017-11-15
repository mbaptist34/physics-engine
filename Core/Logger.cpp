
#include "Logger.h"


Logger::Logger() {
    //Emptyyyy
}

Logger & Logger::Get() {
    static Logger Log;
    return Log;
}


bool Logger::Init() {
        
    appLog.open("applog.txt");
    clientLog.open("clntlog.txt");
    serverLog.open("srvrlog.txt");
    
    //load the strings file
    if(!loadStrings())return false;
    
    return true;
}


bool Logger::loadStrings()
{
    std::ifstream in("strings.txt");
    if(!in.is_open())return false;
    
    unsigned int index=0;
    
    while(!in.eof())
    {
        char szBuf[1024];
        in.getline(szBuf,1024);
        logStrings[index++]=szBuf;
    }
    
    return true;
}


void Logger::Write(int target, const char *msg, ...)
{
    va_list args; va_start(args,msg);
    char szBuf[1024];
    vsprintf(szBuf,msg,args);
    
    if(target&LOG_APP)
    {
        appLog<<szBuf<<"\n";
#ifdef DEBUG
        appLog.flush();
#endif
    }
    if(target&LOG_CLIENT)
    {
        clientLog<<szBuf<<"\n";
#ifdef DEBUG
        clientLog.flush();
#endif
    }
    if(target&LOG_SERVER)
    {
        serverLog<<szBuf<<"\n";
#ifdef DEBUG
        serverLog.flush();
#endif
    }
    if(target&LOG_USER)
    {
        //Does nothing... TODO
    }
}

void Logger::Write(int target, unsigned long msgID, ...)
{
    va_list args; va_start(args, msgID);
    char szBuf[1024];
    vsprintf(szBuf,logStrings[msgID].c_str(),args);
    Write(target,szBuf);
}


