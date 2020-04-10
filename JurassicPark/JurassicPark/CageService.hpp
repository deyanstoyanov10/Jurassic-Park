#pragma once

#include<time.h>
#include "Cage.hpp"

class CageService
{
public:
	static Cage createNewCage(Climate climate, Period period);
	static Climate getClimateByKind(Kind kind);
private:
	static int randomNumber(int maxNumber);
};