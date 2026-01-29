#pragma once

#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>

class Cosmos {
public:
    Cosmos();
    ~Cosmos() = default;

    // cambia el estado del universo
    void update(double dt);

    // Consultas
    glm::vec3 position() const;
    glm::quat orientation() const;

private:
    glm::vec3 m_position;
    glm::quat m_orientation;

    glm::vec3 m_angular_velocity; // eje * magnitud (rad/s)
};
