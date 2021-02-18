#include "rog.h"

class MainScene : public Scene {
	using Scene::Scene;
	public:
		void initScene() override;
		void onMoved(PaintObject* p);
		void onMovedObj(PaintObject *p) override;
		void onClickedLObj(PaintObject *p) override;
	private:
		RogButton *but;
		void paint();
		void update();
		coord circ;
		
};
