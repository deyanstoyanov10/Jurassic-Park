#include "Dinosaur.hpp"

Dinosaur::Dinosaur() {}

Dinosaur::Dinosaur(String _name, Gender _gender, Period _period, Kind _kind, Type _type, Food _food)
	:name(_name), gender(_gender), period(_period), kind(_kind), type(_type), food(_food) {}