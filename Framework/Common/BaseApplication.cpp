#include "BaseApplication.hpp"

int My::BaseApplication::initialize() {
    m_bQuit = false;

    return 0;
}

void My::BaseApplication::finalize() {}

void My::BaseApplication::tick() {}

bool My::BaseApplication::isQuit() {
    return m_bQuit;
}