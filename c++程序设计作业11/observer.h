#pragma once
#include "subject.h"
class subject;
class observer {
public:
virtual ~observer() {}
virtual void update(subject * changedSubject) = 0;
protected:
observer(subject * s) :_subject(s) { 
// _subject->attach(this);
};
subject * _subject;
};