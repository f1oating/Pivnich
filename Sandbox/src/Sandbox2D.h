#pragma once

#include "Pivnich.h"

class Sandbox2D : public PV::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(PV::Timestep ts) override;
	void OnEvent(PV::Event& e) override;
private:
	PV::OrthographicCamera m_Camera;

	PV::Ref<PV::VertexArray> m_SquareVA;
	PV::Ref<PV::Shader> m_FlatColorShader;

	PV::Ref<PV::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};