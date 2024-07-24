#include "../../Header/Player/PlayerModel.h"
namespace Player
{
	PlayerModel::PlayerModel(Entity::EntityType owner_type)
	{
		this->owner_type = owner_type;
	}

	PlayerModel::~PlayerModel()
	{
	}

	void PlayerModel::initialize() { reset(); }

	void PlayerModel::reset()
	{
		player_state = PlayerState::ALIVE;
		player_position = initial_player_position;
		player_score = 0;

		b_shield = false;
		b_rapid_fire = false;
		b_tripple_laser = false;
	}

	sf::Vector2f PlayerModel::getPlayerPosition()
	{
		return player_position;
	}

	void PlayerModel::setPlayerPosition(sf::Vector2f position)
	{
		player_position = position;
	}

	PlayerState PlayerModel::getPlayerState()
	{
		return player_state;
	}

	void PlayerModel::setPlayerState(PlayerState state)
	{
		player_state = state;
	}
	Entity::EntityType PlayerModel::getOwnerEntityType()
	{
		return owner_type;
	}
	int PlayerModel::getPlayerScore()
	{
		return 0;
	}
	void PlayerModel::setPlayerScore(int score)
	{
		player_score = score;
	}

	bool PlayerModel::isShieldEnabled()
	{
		return b_shield;
	}

	bool PlayerModel::isRapidFireEnabled()
	{
		return b_rapid_fire;
	}

	bool PlayerModel::isTrippleLaserEnabled()
	{
		return b_tripple_laser;
	}

	void PlayerModel::setShieldState(bool value)
	{
		b_shield = value;
	}

	void PlayerModel::setRapidFireState(bool value)
	{
		b_rapid_fire = value;
	}

	void PlayerModel::setTrippleFireState(bool value)
	{
		b_tripple_laser = value;
	}
}