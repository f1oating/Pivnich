#pragma once

#include "Pivnich/Core/GraphicsContext.h"

struct GLFWwindow;

namespace PV {

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};

}