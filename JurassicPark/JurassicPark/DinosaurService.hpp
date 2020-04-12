#pragma once

#include <iostream>
#include "String.hpp"
#include "Gender.hpp"
#include "Climate.hpp"
#include "Period.hpp"
#include "Kind.hpp"
#include "Type.hpp"
#include "Food.hpp"

class DinosaurService
{
public:
	static void ClimateInfo();
	static void FoodInfo();
	static void GenderInfo();
	static void KindInfo();
	static void PeriodInfo();
	static void TypeInfo();

	static Climate getClimateByIndex(int index);
	static Food getFoodByIndex(int index);
	static Gender getGenderByIndex(int index);
	static Kind getKindByIndex(int index);
	static Period getPeriodByIndex(int index);
	static Type getTypeByIndex(int index);

	static String printClimate(Climate climate);
	static String printFood(Food food);
	static String printGender(Gender gender);
	static String printKind(Kind kind);
	static String printPeriod(Period period);
	static String printType(Type type);
};