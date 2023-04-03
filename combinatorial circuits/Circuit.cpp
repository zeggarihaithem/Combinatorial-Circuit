#include "Circuit.hpp"
ostream& operator<< (ostream& out, const Circuit * c) {
    c->displayInConsole(out);
    return out;
}