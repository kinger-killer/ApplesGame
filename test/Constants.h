#pragma once
#include "string"
namespace AppleGame
{
   //Technical part
	//Screen settings
	const int ScreenWidth = 800;
	const int ScreenHeight = 600;
	//recurces Path
	const std::string RecurcesPath = "Recources/";
   //Game balance part
	//player settings
	const float InitialSpeed = 100.f; // pixels per second 
	const float PlayerSize = 20.f;
	const float AccelerationByTime = 10.f;
	const float AcceleretionByEatenApples = 40.f;
	//apples settings
	const int MinimumAppleNum = 15;
	const int MaximumAppleNum = 40;
	const int AppleSize = 10;
	//lemonz settings
	const int LemonSize = 20;
	const int MinimumLemonzNum = 0;
	const int MaximumLemonzNum = 10;
}