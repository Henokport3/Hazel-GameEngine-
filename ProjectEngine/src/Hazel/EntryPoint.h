#pragma once

// Macros for running an entry point

// If running on Windows...
#ifdef HZ_PLATFORM_WINDOWS

	// Define an extern class that creates an application.
	extern Hazel::Application* Hazel::CreateApplication();	// EXTERN: Tells the compiler that the variable is defined somewhere else, so it doesn't complain about it being undefined (or multiply defined).

	// Entry Point
	int main(int argc, char** argv)
	{
		Hazel::Log::Init();					// Call initializer from log
		HZ_CORE_WARN("Initialized log!");	// Log from core as a warning
		HZ_INFO("Welcome!");				// Log from client as a message

		printf("Hazel Game Engine\n");
		auto app = Hazel::CreateApplication();
		app->Run();
		delete app;
	}

// If NOT running on Windows...
#else
	// ERROR!
	#error The engine only supports Windows!

#endif // HZ_PLATFORM_WINDOWS