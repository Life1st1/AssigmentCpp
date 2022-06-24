#ifndef __ASS12_H__
#define __ASS12_H__

#define NO_ERR 1
#define ERR 0

template <class T>

class CStacks{
    public:
       int Top = -1;
       T stack_element[10];

       int pop(T*);
	   void push(T);
};

#endif //__ASS12_H__