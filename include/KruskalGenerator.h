#ifndef KRUSKALGENERATOR_H
#define KRUSKALGENERATOR_H

#include "IGeneratorStrategy.h"

class KruskalGenerator : public IGeneratorStrategy {
public:
	void generate(Maze& maze) override;
};

#endif