#pragma once

#include "Hazel/Renderer/Buffer.h"

namespace Hazel
{
    // ------------------------------------------------------------------------
    // |                         OpenGLVertexBuffer                           |
    // ------------------------------------------------------------------------
    class OpenGLVertexBuffer : public VertexBuffer
    {
    public:
        OpenGLVertexBuffer(float* vertices, uint32_t size);
        virtual ~OpenGLVertexBuffer() override;

        virtual void Bind() const override;
        virtual void Unbind() const override;

        virtual const BufferLayout& GetLayout() const override { return m_Layout; }
        virtual void SetLayout(const BufferLayout& layout) override { m_Layout = layout; }
    private:
        uint32_t m_RendererID;
        BufferLayout m_Layout;
    };

    // ------------------------------------------------------------------------
    // |                          OpenGLIndexBuffer                           |
    // ------------------------------------------------------------------------
    class OpenGLIndexBuffer : public IndexBuffer
    {
    public:
        OpenGLIndexBuffer(uint32_t* indices, uint32_t size);
        virtual ~OpenGLIndexBuffer() override;

        virtual void Bind() const override;
        virtual void Unbind() const override;

        virtual inline uint32_t GetCount() const override { return m_Count; };
    private:
        uint32_t m_RendererID;
        uint32_t m_Count;
    };
}