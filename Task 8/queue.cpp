#include "queue.h"

Iterator * Queue::createIter(){
    return new Iterator(this);
}
Iterator * Iterator::first(){
    return queue.
}