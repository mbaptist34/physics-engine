
#include "MMObject.h"

MMObject::MMObject() {
    
    liveObjects.push_back(this);
    refCount = 0;
    mmpos = std::next(liveObjects.end(), -1);
    id = getNewId();
    
#ifdef DEBUGMM
    std::string rslt = "MMObject ID: " + std::to_string(id) + " created.";
    LOGGER.Write(LOG_APP, rslt.c_str());
    
#endif
}

int MMObject::getId() {
    return id;
}

MMObject::~MMObject() {
    //Emptyyyy for inheritance purposes.
}

void MMObject::addRef() {
    refCount++;
}

void MMObject::release() {
    refCount--;
    
    if (refCount <= 0) {
        deadObjects.push_back(this);
        liveObjects.erase(this->mmpos); //Removes from liveObject in O(1)
#ifdef DEBUGMM
        std::string rslt = "MMObject ID: " + std::to_string(id)  + " dead.";
        LOGGER.Write(LOG_APP, rslt.c_str());
#endif
    }
}

void MMObject::collectGarbage() {
    
#ifdef DEBUGMM
    LOGGER.Write(LOG_APP, "Collecting Garbage.");
#endif
    
    for (std::list<MMObject *>::iterator it = deadObjects.begin(); it != deadObjects.end(); it++ ) {
        
#ifdef DEBUGMM
        std::string rslt = "MMObject ID: " + std::to_string((*it)->id) + " collected.";
        LOGGER.Write(LOG_APP, rslt.c_str());
#endif
        delete (*it);
    }
    deadObjects.clear();
}

void MMObject::collectRemainingObjects() {

    collectGarbage();
  

    for (std::list<MMObject *>::iterator it = liveObjects.begin(); it != liveObjects.end(); it++) {
      
#ifdef DEBUGMM
        std::string rslt = "MMObject ID: " + std::to_string((*it)->id) + " dead.";
        LOGGER.Write(LOG_APP, rslt.c_str());
        rslt = "MMObject ID: " + std::to_string((*it)->id) + " collected.";
        LOGGER.Write(LOG_APP, rslt.c_str());
#endif

        delete(*it);
        (*it) = NULL;
    }
    
    liveObjects.clear();
    collectGarbage();
}

int MMObject::getNewId() {
    LOGGER.Write(LOG_APP, "ID Assigned.");
    return ++objCount;
}

unsigned int MMObject::objCount = 0;

std::list<MMObject *> MMObject::liveObjects;
std::list<MMObject *> MMObject::deadObjects;

