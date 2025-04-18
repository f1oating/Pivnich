#include "pvpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace PV {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}