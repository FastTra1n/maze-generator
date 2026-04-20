#ifndef IGENERATORSTRATEGY_H
#define IGENERATORSTRATEGY_H

class Maze;

class IGeneratorStrategy {
public:
	virtual ~IGeneratorStrategy() = default;

	virtual void generate(Maze& maze) = 0;
protected:
	IGeneratorStrategy() = default;
};

#endif