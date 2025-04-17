#include "pvpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace PV {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		PV_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		PV_CORE_ASSERT(status, "Failed to initialize Glad!");

		PV_LOG_CORE_INFO("OpenGL Info:");
		PV_LOG_CORE_INFO("  Vendor: {0}", (char*)glGetString(GL_VENDOR));
		PV_LOG_CORE_INFO("  Renderer: {0}", (char*)glGetString(GL_RENDERER));
		PV_LOG_CORE_INFO("  Version: {0}", (char*)glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}