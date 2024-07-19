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
		player_state = PlayerState::DEAD;
		player_position = initial_player_position;
		player_score = 0;
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
}