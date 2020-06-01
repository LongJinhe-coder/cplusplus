#pragma once
#include "observer.h"
#include "state.h"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
class observer;
using std::cout;
using std::string;
using std::vector;
class subject
{
public:
    virtual ~subject() {}
    virtual void attach(observer *o)
    {
        _observers.push_back(o);
    }
    virtual void detach(observer *o)
    {
        remove(_observers.begin(), _observers.end(), o);
    }
    virtual void notify()
    {
        cout << '\t' << _name << " is notifying each attached observers\n";
        for (int i = 0; i < _observers.size(); ++i)
            _observers[i]->update(this);
    }
    virtual state* getState() const = 0;
    virtual void setState(state *s) = 0;
protected:
    subject(const string &name) : _name(name) {}
protected:
    vector<observer *> _observers;
    state *_state;
    string _name;
};