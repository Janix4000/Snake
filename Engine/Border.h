#pragma once

#include "Graphics.h"
#include "Location.h"
#include "Colors.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	int getHeight() const;
	int getWidth() const;
	bool IsInBoard(Location& loc) const;
	void DrawFrame();
private:
	static constexpr Location lCor = { 50, 40 };
	static constexpr int dimension = 20;
	static constexpr int width = 25;
	static constexpr int height = 25;
	int frameWidth = 5;
	static constexpr Color c = Colors::Magenta;
	int pad = 3;
	Graphics& gfx;
};