
#ifndef ____Kernel__
#define ____Kernel__

#include "MMPtr.h"
#include "MMObject.h"
#include "Task.h"
#include "Logger.h"
#include "ProjectBuildSettings.h"

class Kernel {
public:
    static Kernel &Get();
    
    int Execute();
    
    bool AddTask(MMPtr<Task> &t);
    void SuspendTask(MMPtr<Task> &t);
    void ResumeTask(MMPtr<Task> &t);
    void RemoveTask(MMPtr<Task> &t);
    void KillAllTasks();
    
protected:
    
    Kernel();
    ~Kernel();
    
    std::list< MMPtr<Task> > taskList;
    std::list< MMPtr<Task> > pausedTaskList;
};

#endif /* defined(____Kernel__) */

