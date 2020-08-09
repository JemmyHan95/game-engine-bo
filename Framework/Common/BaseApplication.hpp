#pragma once

#include "IApplication.hpp"

namespace My {
    class BaseApplication : implements IApplication {
    public:
        virtual int initialize();
        virtual void finalize();
        virtual void tick();
        virtual bool isQuit();
    protected:
        bool m_bQuit;
    };
}