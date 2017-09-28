#pragma once

#include "Snake.h"
#include "Border.h"
#include <random>

class Goal
{
public:
	Goal( std::mt19937& rng, const Board& brd, Snake& snk);
	void Respawn( std::mt19937& rng, const Board& brd, Snake& snk);
	const Location& GetLocation() const;
	void Draw(Board & brd) const;
private:
	Location loc;
	Color c = Colors::Red;
};