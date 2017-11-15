
#ifndef ____Task__
#define ____Task__

#include "MMObject.h"
#include <list>
#include "MMPtr.h"

class Task : public MMObject {

    
public:
    Task() { canKill = false; priority = 5000; }
    virtual bool Start() = 0;
    virtual void OnResume(){};
    virtual void Stop() = 0;
    virtual void OnSuspend(){};
    virtual void Update() = 0;
    
    bool canKill;
    long priority;
    
    std::list< MMPtr<Task> >::iterator pos; //Keeps track of position in task pool.
};


#endif /* defined(____Task__) */
