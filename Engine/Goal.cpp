#include "Goal.h"

Goal::Goal( std::mt19937 & rng, const Board & brd, Snake & snk)
{
	Respawn(rng, brd, snk);
}

void Goal::Respawn( std::mt19937 & rng, const Board & brd, Snake & snk)
{
	std::uniform_int_distribution<int> xDist(0, brd.getWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.getHeight() - 1);
	do
	{
		loc.x = xDist(rng);
		loc.y = yDist(rng);
	} while (snk.IfIsInTile(loc));
}

const Location& Goal::GetLocation() const
{
	return loc;
}

void Goal::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}
