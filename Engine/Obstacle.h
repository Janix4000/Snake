#pragma once

# include "Border.h"
# include "Snake.h"
# include "Goal.h"
#include <random>

class Obstacles
{
private:
	class Stone
	{
	public:
		void InitStone(Board& brd, std::mt19937& rng, const Snake& snk, const Goal& frt);
		bool IsCollidingSnake(const Snake& snk) const;
		bool IsCollidingStone(const Stone& stn) const;
		bool IsCollidingGoal(const Goal& frt) const;
		void Draw(Board& brd)const;
		const Location getLocation() const;

	private:
		Location loc;
		Color c;
	};
public:
	void AddNewStone(Board& brd, std::mt19937& rng, const Snake& snk, const Goal& frt);
	void DrawStones(Board& brd) const;
	bool IsSnakeColliding(const Location& loc) const;
private:
	static constexpr int nStonesMax = 10;
	int nStones = 0;
	Stone stones[nStonesMax];
};