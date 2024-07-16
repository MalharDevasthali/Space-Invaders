#pragma once
namespace Enemy
{
	class EnemyView;
	class EnemyController
	{
	private:
		EnemyView* enemy_view;
	public:
		EnemyController();
		~EnemyController();

		void initialize();
		void update();
		void render();
	};
}
