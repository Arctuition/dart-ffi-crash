#include <memory>
class Scene {
public:
    static std::shared_ptr<Scene> GetScene() {
        static auto scene = std::make_shared<Scene>();
        return scene;
    }

    void TriggerCrash(int crashType);
};



