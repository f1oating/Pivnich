#include "Sandbox2D.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_Camera((-(4 / 3)) * 10.0f, (4 / 3) * 10.0f, -10.0f, 10.0f)
{
}

void Sandbox2D::OnAttach()
{
	m_CheckerboardTexture = PV::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(PV::Timestep ts)
{
	PV::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	PV::RenderCommand::Clear();

	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		PV::Renderer2D::BeginScene(m_Camera);
		PV::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
		PV::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		PV::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
		PV::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture);
		PV::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_CheckerboardTexture);
		PV::Renderer2D::EndScene();

		PV::Renderer2D::BeginScene(m_Camera);
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
				PV::Renderer2D::DrawQuad({ x, y }, { 0.45f, 0.45f }, color);
			}
		}
		PV::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnEvent(PV::Event& e)
{
	
}