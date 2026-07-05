#ifndef PARTICULA_H
#define PARTICULA_H

#include <glm/glm.hpp>

class Particula {
public:
    float carga;
    glm::vec3 posicion;

    Particula(float carga = 1.0f, glm::vec3 posicion = glm::vec3(0.0f));
};

#endif
