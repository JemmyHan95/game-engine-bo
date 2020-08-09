#pragma once

#include "Interface.hpp"

namespace My {
    Interface IRuntimeModule {
    public:
        virtual ~IRuntimeModule() {};
        virtual int initialize() = 0;
        virtual void finalize() = 0;
        virtual void tick() = 0;
    };
}