#pragma once

#ifdef UTOPIA_PLATFORM_WINDOWS

extern Utopia::Application* Utopia::CreateApplication();

int main(int argc, char** argv)
{
	Utopia::ConsoleLog::LogInit();
	
	Utopia::ConsoleLog::GetCoreLogger()->flush();

	Utopia::ConsolePrint("Welcome!\n");
	
	auto app = Utopia::CreateApplication();
	app->run();
	delete app;
	return 0;
}

#endif // UTOPIA_PLATFORM_WINDOWS
