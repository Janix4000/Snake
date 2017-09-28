#pragma once

#include "Border.h"
#include "Location.h" 
#include "Colors.h"
#include <random>

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& in_loc);
		void InitBody(std::mt19937& rng);
		void Follow(const Segment& next);
		void Draw(Board& brd)const;
		void MoveBy(const Location& delta_loc);
		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;
	};

public:
	Snake(const Location& loc, std::mt19937& in_rng);
	void MoveBy(const Location& delta_loc);
	void Grow();
	void Draw(Board& brd);
	Location GetNextHeadLocation( Location& delta_loc) const;
	bool IfIsInTile(const Location& target) const;
	bool IfIsInTileExceptLast(const Location& target)const;
	int GetLenght() const;

private:
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
	Location loc;
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	std::mt19937 rng;

};