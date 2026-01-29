#pragma once

#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>
#include <chrono>

using sclock = std::chrono::steady_clock;

struct Cosmos {
    Cosmos();
    ~Cosmos() = default;
// ==================   ==================   ==================
    sclock::time_point time0;
    sclock::time_point last_time;
// ==================   ==================   ==================
    bool cosmosStart();
    bool cosmosUpd();
    
    
    // Consultas


    glm::vec3 position() const;
    glm::quat orientation() const;

    glm::vec3 m_position;
    glm::quat m_orientation;
    glm::vec3 m_angular_velocity; // eje * magnitud (rad/s)
};
