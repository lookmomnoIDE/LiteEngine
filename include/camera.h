#ifndef CAMERA_H
#define CAMERA_H


enum Camera_Movement {FORWARD, BACKWARD, LEFT, RIGHT, UP, DOWN};

const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSE = 0.1f;
const float ZOOM = 45.0f;

class Camera
{
public:
	glm::vec3 Position;
	glm::vec3 Front;
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp;

	float Yaw;
	float Pitch;
	float MovementSpeed;
	float MouseSense;
	float Zoom;


}