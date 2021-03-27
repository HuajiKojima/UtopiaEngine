#include <UtopiaEngine.h>
#include <windows.h>

class SandboxApplication : public Utopia::Application
{
public:
	SandboxApplication() 
	{
		Utopia::ConsolePrint("SandboxApplication structor\n");
		Utopia::ConsoleLog::GetClientLogger()->info("SandboxApplication structor");
		Utopia::ConsoleLog::GetClientLogger()->warn("SandboxApplication structor");
		Utopia::ConsoleLog::GetClientLogger()->error("SandboxApplication structor");

	}
	~SandboxApplication()
	{

	}

private:

};

Utopia::Application* Utopia::CreateApplication() 
{
	return new SandboxApplication();
}
