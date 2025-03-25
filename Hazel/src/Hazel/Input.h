#pragma once

#include "Hazel/Core.h"

namespace Hazel
{
	class HAZEL_API Input
	{
	public:
		static bool IsKeyPressed(int keycode) { return s_instance->IsKeyPressedImpl(keycode); }

		static bool IsMouseButtonPressed(int button) { return s_instance->IsMouseButtonPressedImpl(button); }
		static std::pair<float, float> GetMousePos() { return s_instance->GetMousePosImpl(); }
		static float GetMouseX() { return s_instance->GetMouseXImpl(); }
		static float GetMouseY() { return s_instance->GetMouseYImpl(); }
	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;

		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual std::pair<float, float> GetMousePosImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
	private:
		static Input* s_instance;
	};
}