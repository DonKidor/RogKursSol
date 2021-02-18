#include "rog.h"

class SmileScene : public Scene {
	using Scene::Scene;
	public:
		void initScene() override;
	private:
		void paint();
		void update();
};
