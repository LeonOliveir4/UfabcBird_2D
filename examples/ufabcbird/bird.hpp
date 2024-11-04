#ifndef BIRD_HPP_
#define BIRD_HPP_

#include "abcgOpenGL.hpp"
#include "gamedata.hpp"

class Bird {
public:
    void create(GLuint program, GameData const &gamedata);
    void paint();
    void destroy();
    void update(GameData const &gamedata, float deltaTime);
    glm::vec2 normalizeCoord(glm::vec2 coord, GameData const &gamedata);
    void flap(float deltaTime);

    bool m_flapWing{false};
    bool  m_isFlapping{false};
    float m_flapDuration{0.f};
    float m_flapTimeA{0.0036};
    float m_flapTimeB{0.500};
    glm::vec2 m_flapPower{0.0f,11.0f};


    double m_total_time{0.0};
    float m_rotation{};
    float m_scale{0.125f};
    glm::vec2 m_velocity{};
    glm::vec2 m_realPosition{}; // Posicao no mundo real

    glm::vec2 m_translation{};
    glm::vec2 m_sustein{glm::vec2(0.0f,9.8f)}; //propriedade de planar;

private:
    GLuint m_program{};
    GLuint m_translationLoc{};
    GLuint m_flapLoc{};
    GLuint m_scaleLoc{};
    
    GLuint m_VAO{};
    GLuint m_VBO{};
    GLuint m_CBO{};
    GLuint m_EBO{};
};
#endif