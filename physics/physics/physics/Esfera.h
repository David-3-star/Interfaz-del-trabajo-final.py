#ifndef ESFERA_H
#define ESFERA_H

#include <glm/glm.hpp>

class Esfera {
public:
    float carga;
    glm::vec3 posicion;
    float radio;

    Esfera(float carga = 1.0f, glm::vec3 posicion = glm::vec3(0.0f), float radio = 1.0f);
};

#endif
