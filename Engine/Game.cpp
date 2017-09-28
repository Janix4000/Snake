/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include "Graphics.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	brd ( gfx ),
	rng(std::random_device()()),
	snake( {2,2} , rng),
	fruit( rng, brd, snake)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (!gameIsOver)
	{
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			
			delta_loc = { 0,-1 };
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			delta_loc = { 0,1 };
		}
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			delta_loc = { -1,0 };
		}
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			delta_loc = { 1,0 };
		}

		if (accCounter++ == accTime)
		{
			if (snakeMovePeriod > 4)
			{
				snakeMovePeriod--;
			}
			accCounter = 0;
			accTime += 75;
			obstacles.AddNewStone(brd, rng, snake, fruit);
		}

		if (++snakeMoveCounter >= snakeMovePeriod)
		{
			snakeMoveCounter = 0;
			Location next = snake.GetNextHeadLocation(delta_loc);
			if (!brd.IsInBoard(next) ||
				snake.IfIsInTileExceptLast(next) ||
				obstacles.IsSnakeColliding(next))
			{
				gameIsOver = true;
			}
			else
			{
				const bool eaten = next == fruit.GetLocation();
				if (eaten)
				{
					snake.Grow();
				}
				snake.MoveBy(delta_loc);
				if (eaten)
				{
					fruit.Respawn(rng, brd, snake);
				}
			}
		
		}
	}
}

void Game::ComposeFrame()
{
	brd.DrawFrame();
	snake.Draw(brd);
	obstacles.DrawStones(brd);
	fruit.Draw(brd);
	
}

