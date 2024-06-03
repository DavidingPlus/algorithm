#ifndef _STDTHREAD_H_
#define _STDTHREAD_H_
struct StdThread;
typedef struct StdThread thread;

thread* InitThread(void* (*func)(void*),void*arg);
unsigned long int GetThreadId(thread* t);
void ClodeThread(thread* t);
void* JoinThread(thread *t);
void DetachThread(thread *t);

#endif