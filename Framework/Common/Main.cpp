#include <stdio.h>
#include "IApplication.hpp"

using namespace My;

namespace My {
    extern IApplication* g_pApp;
}

int main(int argc, char** argv) {
    int ret;

    if ((ret = g_pApp->initialize()) != 0) {
        printf("App initialization failed, exit now...");
        return ret;
    }

    while (!g_pApp->isQuit()) {
        g_pApp->tick();
    }

    g_pApp->finalize();

    return 0;
}