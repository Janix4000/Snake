# include "Snake.h"
# include <assert.h>
# include "math.h"

Snake::Snake(const Location & loc, std::mt19937& in_rng)
{
	segments[0].InitHead(loc);
	rng = in_rng;
}

void Snake::MoveBy(const Location & delta_loc)
{
	for (int i = nSegments - 1; i > 0; i--)
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax)
	{
		segments[nSegments].InitBody(rng);
		nSegments++;
	}
}

void Snake::Draw(Board & brd)
{
	for (int i = 0; i < nSegments; i++)
	{
		segments[i].Draw(brd);
	}
}

Location Snake::GetNextHeadLocation(Location& delta_loc) const
{
	Location l = segments[0].GetLocation();
	l.Add(delta_loc);
	return l;
}

bool Snake::IfIsInTile(const Location & target) const
{
	for (int i = 0; i < nSegments; i++)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

bool Snake::IfIsInTileExceptLast(const Location & target) const
{
	for (int i = 0; i < nSegments-1; i++)
	{
		if (segments[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

int Snake::GetLenght() const
{
	return nSegments;
}

void Snake::Segment::InitHead(const Location & in_loc)
{
	c = Snake::headColor;
	loc = in_loc;
}

void Snake::Segment::InitBody(std::mt19937& rng)
{
	std::uniform_int_distribution<int> g (170, 255);
	
	c = { 0, unsigned char (g(rng)), 0 };
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

void Snake::Segment::MoveBy(const Location & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
