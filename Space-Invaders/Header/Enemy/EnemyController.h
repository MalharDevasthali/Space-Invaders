#pragma once
namespace Enemy
{
	class EnemyController
	{
	public:
		EnemyController();
		~EnemyController();

		void initialize();
		void update();
		void render();
	};
}
