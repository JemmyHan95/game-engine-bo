#pragma once

#include "Interface.hpp"
#include "IRuntimeModule.hpp"

namespace My {
    Interface IApplication : implements IRuntimeModule {
    public:
        virtual int initialize() = 0;
        virtual void finalize() = 0;
        virtual void tick() = 0;
        virtual bool isQuit() = 0;
    };
}