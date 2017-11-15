#include "Kernel.h"

//I removed "task exists in list" validation from the below functions, this is dangerous and probably incorrect, but I was unsatisfied with O(N) time complexity. -Matthew Baptist

Kernel::Kernel() {
    SDL_Init(0);
}

Kernel::~Kernel() {
    SDL_Quit();
}

Kernel &Kernel::Get() {
    static Kernel instance;
    return instance;
    
}

int Kernel::Execute() {
    
    LOGGER.Write(LOG_APP, "Kernel executing.");
    
    while (taskList.size()) {
        Task *t;
        std::list< MMPtr<Task> >::iterator it;
        
        for (it = taskList.begin(); it != taskList.end(); ) {
            t = (*it);
            it++;
            if (!t->canKill) t->Update();
        }
        
        for (it = taskList.begin(); it != taskList.end(); ) {
            t = (*it);
            it++;
            if (t->canKill) {
                t->Stop();
                taskList.erase(t->pos);
                
                std::string rslt = "Task ID: " + std::to_string(t->getId()) + " removed.";
                LOGGER.Write(LOG_APP, rslt.c_str());
                
                t = 0;
            }
        }
      
        //TODO: Move this to a garbage collection task.
        MMObject::collectGarbage();
    }
    return 0;
}

bool Kernel::AddTask(MMPtr<Task> &t){
   

    
    if(!t->Start()) return false;
    
    //loop through to get task at correct priority
    std::list < MMPtr<Task> >::iterator it;
    for (it = taskList.begin(); it != taskList.end(); it++) {
        if (t->priority > (*it)->priority) {
            break;
        }
    }
    
    t->pos = taskList.insert(it, t);
    
    std::string rslt = "Task ID: " + std::to_string(t->getId()) + " added.";
    LOGGER.Write(LOG_APP, rslt.c_str());
    
    
    return true;
}

void Kernel::SuspendTask(MMPtr<Task> &t) {
    
    t->OnSuspend();
    taskList.erase(t->pos);
    pausedTaskList.push_back(t);
    t->pos = std::next(pausedTaskList.end(), -1);
}

void Kernel::ResumeTask(MMPtr<Task> &t) {
    
    t->OnResume();
    pausedTaskList.erase(t->pos);
    
    //loop through to get task at correct priority
    std::list < MMPtr<Task> >::iterator it;
    for (it = taskList.begin(); it != taskList.end(); it++) {
        if (t->priority > (*it)->priority) {
            break;
        }
    }
    
    t->pos = taskList.insert(it, t);
}

void Kernel::RemoveTask(MMPtr<Task> &t) {
    
    t->canKill = true;
    
    std::string rslt = "Task ID: " + std::to_string(t->getId()) + " dead.";
    LOGGER.Write(LOG_APP, rslt.c_str());
}

void Kernel::KillAllTasks() {
    
    for (std::list< MMPtr<Task> >::iterator it = taskList.begin(); it != taskList.end(); it++) {
        (*it)->canKill = true;
    }
}

