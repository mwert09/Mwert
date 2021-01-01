#include "mwpch.h"
#include "WindowsWindow.h"

namespace Mwert
{
	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_WindowData.Title = props.Title;
		m_WindowData.Width = props.Width;
		m_WindowData.Height = props.Height;

		MW_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if(!s_GLFWInitialized)
		{
			//TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			MW_CORE_ASSERT(success, "Could not initialize GLFW!");
			
			s_GLFWInitialized = true;
		}
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, &m_WindowData);
		SetVSync(true);
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}
	
	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_WindowData.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_WindowData.VSync;
	}

}