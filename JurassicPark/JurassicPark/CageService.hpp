#ifndef __CAGESERVICE_HPP
#define __CAGESERVICE_HPP

#include<iostream>
#include<ctime>
#include "Climate.hpp"
#include "Kind.hpp"
#include "Period.hpp"

class CageService
{
public:
	static Climate getClimateByKind(Kind kind);
	static int randomNumber(int maxNumber);
};

#endif