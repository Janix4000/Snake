#pragma once

struct Location
{
	void Add(const Location& val)
	{
		x += val.x;
		y += val.y;
	}
	bool operator==(const Location& rloc) const
	{
		return rloc.x == x && rloc.y == y;
	}
	int x;
	int y;
};