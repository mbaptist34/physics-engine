
/*
    Class for handling Memory Management for the game. 
    Almost all classes will inherit from MMObject, this will allow
    all memory to be properly freed when no longer in use. 
    
    Live Objects will be stored in an a static STL List - liveObjects
    Dead Objects will be stored in an a static STL List - deadObjects
 
    Static Methods:
        - collectGarbage() - clears all dead Objects
        - collectRemainingObjects() - clears away remaining Objects
 
    Public Methods:
        - AddRef() - Increments the number of refs to the object
        - Release() - Decrements the number of refs to the object, and marks object for collection if no longer referenced.
        - virtual size() - Reports the size of the object, must be overriden by derived classes.
 
    Protected:
        - virtual ~MMObject() - Allows derived classes to work properly.
        - MMObject() - Adds object to live object list, stores iterator, blocks MMObject from being instatiated
 
    Macro: AUTO_SIZE - Allows for easy implementation of size()
 
    Fields: 
        - private refCount - stores the references to the object
        - private pos - an iterator to pos in liveObject list for O(1) removal
 
*/


#ifndef ____MMObject__
#define ____MMObject__

#include <list>
#include <iterator>
#include "logger.h"
#include "ProjectBuildSettings.h"


#define AUTO_SIZE unsigned long size(){return sizeof(*this);}

class MMObject {

private:
    long refCount;
    unsigned int id;
    static unsigned int objCount;
    std::list<MMObject *>::iterator mmpos;
    
protected:
    MMObject();
    virtual ~MMObject();
    
public:
    void addRef();
    void release();
    int getId();
    virtual unsigned long size() = 0;
    
    static std::list<MMObject *> liveObjects;
    static std::list<MMObject *> deadObjects;
    
    static void collectGarbage();
    static void collectRemainingObjects();
    static int getNewId();
};


#endif /* defined(____MMObject__) */
