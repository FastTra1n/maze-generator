#ifndef DFSGENERATOR_H
#define DFSGENERATOR_H

#include "IGeneratorStrategy.h"

class DFSGenerator : public IGeneratorStrategy {
public:
	void generate(Maze& maze) override;
};

#endif