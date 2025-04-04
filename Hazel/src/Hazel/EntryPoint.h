#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	Hazel::Log::Init();
	HZ_CORE_WARN("Initialized Log!");
	int a = 5;
	HZ_INFO("Hello! Test={0}", a);

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif // HZ_PLATFORM_WINDOWS
