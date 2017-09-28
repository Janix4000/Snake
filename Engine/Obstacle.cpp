# include "Obstacle.h"

void Obstacles::AddNewStone(Board & brd, std::mt19937 & rng, const Snake & snk, const Goal & frt)
{
	if (nStones < nStonesMax)
	{
		stones[nStones].InitStone(brd, rng, snk, frt);
		nStones++;
	}
}

void Obstacles::DrawStones(Board & brd) const
{
	for (int i = 0; i < nStonesMax; i++)
	{
		stones[i].Draw(brd);
	}
}

bool Obstacles::IsSnakeColliding(const Location & loc) const
{
	bool col = false;
	for (int i = 0; i < nStonesMax; i++)
	{
		col = col || stones[i].getLocation() == loc;
	}
	return col;
}

void Obstacles::Stone::InitStone(Board & brd, std::mt19937 & rng, const Snake & snk, const Goal & frt)
{
	std::uniform_int_distribution<int> rgb(80, 100);
	c = { unsigned char(rgb(rng)), unsigned char(rgb(rng)), unsigned char(rgb(rng)) };
	std::uniform_int_distribution<int> xDist(0, brd.getWidth()-1);
	std::uniform_int_distribution<int> yDist(0, brd.getHeight()-1);
	do
	{
		loc = { xDist(rng), yDist(rng) };
	} while (IsCollidingSnake(snk) || IsCollidingGoal(frt));
}

bool Obstacles::Stone::IsCollidingSnake(const Snake & snk) const
{
	return snk.IfIsInTile(loc);
}

bool Obstacles::Stone::IsCollidingStone(const Stone & stn) const
{
	return loc == stn.loc;
}

bool Obstacles::Stone::IsCollidingGoal(const Goal & frt) const
{
	return loc == frt.GetLocation();
}

void Obstacles::Stone::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

const Location Obstacles::Stone::getLocation() const
{
	return loc;
}
