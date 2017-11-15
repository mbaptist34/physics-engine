
/* Template for pointers to objects derived from MMObject
    
    e.g. MMPtr<myDerivedObject> ptr = new myDerivedObject();
 
    Essentially a pointer wrapper that works with the memory manager.
 
    Must go out of scope before final garbage collection. 
 
 */

#ifndef ____MMPtr__
#define ____MMPtr__

#include <assert.h>
#include "MMObject.h"
#include "ProjectBuildSettings.h"

template <class T>
class Weak_MMPtr;

template <class T>
class MMPtr {
    
protected:
    T* obj;
    
public:
    MMPtr() { //Empty Construction
        obj = 0;
    }
    
    MMPtr(T *target) { //Construction with a pointer
        obj = 0;
        *this = target;
    }
    
    MMPtr(const MMPtr<T> &target) { //Copy construction
        obj = 0;
        *this = target;
    }
    
    ~MMPtr() {
        if (obj) obj->release();
        obj = 0;
    }
    
    //inline to increase speed at the cost of program size
    inline void operator = (T * target) {
        if (obj) obj->release();
        obj = target;
        if (obj) obj->addRef();
    }
    
    inline void operator = (MMPtr<T> &target) {
        if (obj) obj->release();
        obj = target.obj;
        if (obj) obj->addRef();
    }
    
    inline T* operator -> () const {
        assert(obj!= 0);
        return (obj);
    }
    
    inline T& operator *() const {
        assert(obj!= 0);
        return (*obj);
    }
    inline operator T*() const {
        return obj;
    }
    
    inline bool isValid() const {
        return (obj!=0);
    }
    inline bool operator !() {
        return !(obj);
    }
    inline bool operator ==(const MMPtr<T> &p) const {
        return (obj==p.obj);
    }
    inline bool operator ==(const T* o) const {
        return (obj==o);
    }
    inline Weak_MMPtr<T> getWeakPtr() const {
      return Weak_MMPtr<T>( obj );
    }
};

template<class T>
class Weak_MMPtr {
  
  friend class MMPtr<T>;
  
protected:
  T* obj;
  
  Weak_MMPtr(T *target) { //Construction with a pointer
    obj = 0;
    *this = target;
  }
  
public:
  
  Weak_MMPtr() { //Empty Construction
    obj = 0;
  }
  
  Weak_MMPtr(const MMPtr<T> &target) { //Copy construction
    obj = 0;
    *this = target.getWeakPtr();
  }
  
  ~Weak_MMPtr() {
    
  }
  
  //inline to increase speed at the cost of program size
  inline void operator = (T * target) {
    obj = target;
  }
  
  inline void operator = (MMPtr<T> &target) {
    obj = 0;
    *this = target.getWeakPtr();
  }
  
  inline T* operator -> () const {
    assert(obj!= 0);
    return (obj);
  }
  
  inline T& operator *() const {
    assert(obj!= 0);
    return (*obj);
  }
  inline operator T*() const {
    return obj;
  }
  
  inline bool isValid() const {
    return (obj!=0);
  }
  inline bool operator !() {
    return !(obj);
  }
  inline bool operator ==(const MMPtr<T> &p) const {
    return (MMPtr<T>::operator==(p));
  }
  inline bool operator ==(const T* o) const {
    return (obj==o);
  }
};


#endif /* defined(____MMPtr__) */
