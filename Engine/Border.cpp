#include "Border.h"
#include <assert.h>

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{}

void Board::DrawCell(const Location & loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width );
	assert(loc.y >= 0);
	assert(loc.y < height );
	gfx.DrawRectDim(loc.x*dimension + lCor.x + pad, loc.y*dimension + lCor.y + pad, dimension - 2 * pad, dimension - 2 * pad, c);
}



int Board::getHeight() const
{
	return height;
}

int Board::getWidth() const
{
	return width;
}

bool Board::IsInBoard(Location & loc) const
{
	return loc.x >= 0 && loc.x < width &&
		loc.y >= 0 && loc.y< height;
}

void Board::DrawFrame()
{
	gfx.DrawRectDim(lCor.x - frameWidth, lCor.y - frameWidth, frameWidth, dimension * height + frameWidth, c);
	gfx.DrawRectDim(lCor.x + dimension * width, lCor.y - frameWidth, frameWidth, dimension * height + 2 * frameWidth, c);

	gfx.DrawRectDim(lCor.x - frameWidth, lCor.y + dimension * height, dimension * width + frameWidth, frameWidth, c);
	gfx.DrawRectDim(lCor.x - frameWidth, lCor.y - frameWidth, dimension * width + frameWidth, frameWidth, c);
}
