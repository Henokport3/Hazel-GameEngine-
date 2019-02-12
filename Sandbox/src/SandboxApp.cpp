#include <Hazel.h>

// Create a class that initializes the game engine application on Sandbox.
class Sandbox : public Hazel::Application
{
public:
	Sandbox() {};
	~Sandbox() {};
};

// Starts application
Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}