#pragma once

namespace Bullet
{
	class BulletService
	{
	private:
		void initialize();
		void update();
		void render();
	public:
		BulletService();
		~BulletService();
	};
}
