#pragma once

#include "Mwert/Window.h"

#include <GLFW/glfw3.h>

namespace Mwert
{
	class WindowsWindow : public Mwert::Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_WindowData.Width; }
		inline unsigned int GetHeight() const override { return m_WindowData.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_WindowData.EventCallback = callback; }

		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;
		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_WindowData;
	};
}


