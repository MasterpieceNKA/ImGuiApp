#ifndef __IMGUI_APP_LAYER__
#define __IMGUI_APP_LAYER__

namespace imguiapp {
    class Layer
    {
    public:
        virtual ~Layer() = default;

        virtual void OnAttach() {}
        virtual void OnDetach() {}

        virtual void OnUpdate(float ts) {}
        virtual void OnUIRender() {}
    };

}

#endif // __IMGUI_APP_LAYER__