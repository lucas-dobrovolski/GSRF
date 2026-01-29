#include "cosmos.hpp"

Cosmos::Cosmos()
{
    time0 = sclock::now();
    last_time = time0;

    m_position = glm::vec3(0.0f);
    m_orientation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
    m_angular_velocity = glm::vec3(0.0f);
}

bool Cosmos::cosmosStart()
{
    time0 = last_time = sclock::now();
    return true;
}
bool Cosmos::cosmosUpd()
{
    auto now = sclock::now();
    std::chrono::duration<double> delta = now - last_time;
    last_time = now;

    const double dt = delta.count();
    if (dt <= 0.0)
        return true;

    // --- Integración angular simple ---
    const float angle = static_cast<float>(glm::length(m_angular_velocity) * dt);

    if (angle > 0.0f)
    {
        const glm::vec3 axis = glm::normalize(m_angular_velocity);
        const glm::quat dq = glm::angleAxis(angle, axis);
        m_orientation = glm::normalize(dq * m_orientation);
    }

    return true;
}
