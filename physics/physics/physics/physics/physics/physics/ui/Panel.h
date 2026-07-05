#ifndef PANEL_H
#define PANEL_H

#include "../physics/ObjetoCompartido.h"

class Panel {
public:
    void render();

private:
    int objetoSeleccionado = -1;

    void mostrarPanelPrincipal();
    void mostrarListaObjetos();
    void mostrarInspector();

    // Variables para crear nuevos objetos
    float nuevaCarga = 1.0f;
    float nuevaPosX = 0.0f;
    float nuevaPosY = 0.0f;
    float nuevaPosZ = 0.0f;
    float nuevoRadio = 1.0f;
};

#endif
