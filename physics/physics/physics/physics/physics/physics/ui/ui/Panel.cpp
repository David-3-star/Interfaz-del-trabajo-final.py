#include "Panel.h"
#include <imgui.h>
#include <iostream>

void Panel::render() {
    mostrarPanelPrincipal();
    mostrarListaObjetos();
    mostrarInspector();
}

void Panel::mostrarPanelPrincipal() {
    ImGui::Begin("Panel de Control");

    ImGui::Text("Simulador de Campo Eléctrico");
    ImGui::Separator();

    // === CREAR PARTÍCULA ===
    ImGui::Text("Crear Partícula");
    ImGui::SliderFloat("Carga (C)", &nuevaCarga, -10.0f, 10.0f);
    ImGui::SliderFloat("Posición X", &nuevaPosX, -10.0f, 10.0f);
    ImGui::SliderFloat("Posición Y", &nuevaPosY, -10.0f, 10.0f);
    ImGui::SliderFloat("Posición Z", &nuevaPosZ, -10.0f, 10.0f);

    if (ImGui::Button("Crear Partícula")) {
        objetos.emplace_back(Particula(nuevaCarga, glm::vec3(nuevaPosX, nuevaPosY, nuevaPosZ)));
        std::cout << "Partícula creada en (" << nuevaPosX << ", " << nuevaPosY << ", " << nuevaPosZ << ")" << std::endl;
    }

    ImGui::Separator();

    // === CREAR ESFERA ===
    ImGui::Text("Crear Esfera");
    ImGui::SliderFloat("Radio", &nuevoRadio, 0.1f, 5.0f);

    if (ImGui::Button("Crear Esfera")) {
        objetos.emplace_back(Esfera(nuevaCarga, glm::vec3(nuevaPosX, nuevaPosY, nuevaPosZ), nuevoRadio));
        std::cout << "Esfera creada en (" << nuevaPosX << ", " << nuevaPosY << ", " << nuevaPosZ << ") con radio " << nuevoRadio << std::endl;
    }

    ImGui::Separator();

    // === CONTROLES DE SIMULACIÓN ===
    if (ImGui::Button("Iniciar")) {
        std::cout << "Simulación iniciada" << std::endl;
    }
    ImGui::SameLine();
    if (ImGui::Button("Pausar")) {
        std::cout << "Simulación pausada" << std::endl;
    }
    ImGui::SameLine();
    if (ImGui::Button("Reiniciar")) {
        objetos.clear();
        std::cout << "Simulación reiniciada" << std::endl;
    }

    ImGui::End();
}

void Panel::mostrarListaObjetos() {
    ImGui::Begin("Lista de Objetos");
    ImGui::Text("Objetos en la escena:");

    for (size_t i = 0; i < objetos.size(); ++i) {
        std::string label;
        if (std::holds_alternative<Particula>(objetos[i])) {
            label = "Partícula " + std::to_string(i);
        } else if (std::holds_alternative<Esfera>(objetos[i])) {
            label = "Esfera " + std::to_string(i);
        }

        if (ImGui::Selectable(label.c_str(), objetoSeleccionado == (int)i)) {
            objetoSeleccionado = (int)i;
        }
    }

    if (ImGui::Button("Eliminar seleccionado") && objetoSeleccionado >= 0 && objetoSeleccionado < (int)objetos.size()) {
        objetos.erase(objetos.begin() + objetoSeleccionado);
        objetoSeleccionado = -1;
    }

    ImGui::End();
}

void Panel::mostrarInspector() {
    if (objetoSeleccionado < 0 || objetoSeleccionado >= (int)objetos.size()) {
        return;
    }

    ImGui::Begin("Inspector");
    ImGui::Text("Propiedades del objeto seleccionado");

    auto& obj = objetos[objetoSeleccionado];

    if (std::holds_alternative<Particula>(obj)) {
        auto& p = std::get<Particula>(obj);
        ImGui::Text("Tipo: Partícula");
        ImGui::SliderFloat("Carga", &p.carga, -10.0f, 10.0f);
        ImGui::SliderFloat("Pos X", &p.posicion.x, -10.0f, 10.0f);
        ImGui::SliderFloat("Pos Y", &p.posicion.y, -10.0f, 10.0f);
        ImGui::SliderFloat("Pos Z", &p.posicion.z, -10.0f, 10.0f);
    } else if (std::holds_alternative<Esfera>(obj)) {
        auto& e = std::get<Esfera>(obj);
        ImGui::Text("Tipo: Esfera");
        ImGui::SliderFloat("Carga", &e.carga, -10.0f, 10.0f);
        ImGui::SliderFloat("Pos X", &e.posicion.x, -10.0f, 10.0f);
        ImGui::SliderFloat("Pos Y", &e.posicion.y, -10.0f, 10.0f);
        ImGui::SliderFloat("Pos Z", &e.posicion.z, -10.0f, 10.0f);
        ImGui::SliderFloat("Radio", &e.radio, 0.1f, 5.0f);
    }

    ImGui::End();
}
