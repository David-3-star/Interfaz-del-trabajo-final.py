#ifndef OBJETO_COMPARTIDO_H
#define OBJETO_COMPARTIDO_H

#include "Particula.h"
#include "Esfera.h"
#include <variant>
#include <vector>

using Objeto = std::variant<Particula, Esfera>;

extern std::vector<Objeto> objetos;

#endif
