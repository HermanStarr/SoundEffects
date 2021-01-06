#pragma once
#include "../Headers.h"


class HolderConstructionException :
   virtual public std::exception
{
    std::string message;
public:
    
    explicit HolderConstructionException(const std::string& message) :
        message(message)
    {}

    virtual ~HolderConstructionException() throw() {}

    virtual const char* what() const throw() { return message.c_str(); }
};

