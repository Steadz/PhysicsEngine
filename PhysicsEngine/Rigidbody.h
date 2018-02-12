#pragma once
#include "PhysicsObject.h"
#include <glm/glm.hpp>

class Rigidbody : public PhysicsObject
{
public:
	Rigidbody();
	Rigidbody(ShapeType shapeID, glm::vec2 position,
		glm::vec2 velocity, float rotation, float mass);
	~Rigidbody();

	virtual void fixedUpdate(glm::vec2 gravity, float timeStep);
	virtual void debug();
	void applyForce(glm::vec2 force);
	void applyForceToActor(Rigidbody* actor2, glm::vec2 force);

	glm::vec2 getPosition() { return m_position; }
	float getRotation() { return m_rotation; }
	glm::vec2 getVelocity() { return m_velocity; }
	void setVelocity(glm::vec2 a_vel);
	float getMass() { return m_mass; }

protected:
	glm::vec2 m_position;
	glm::vec2 m_velocity;
	glm::vec2 m_acceleration;
	float m_mass;
	float m_rotation; //2D so we only need a single float to represent our rotation

};

