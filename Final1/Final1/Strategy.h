#pragma once
#ifndef STRATEGY_H
#define STRATEGY_H
#include "plotImp.h"
#include "plotTen.h"
#include "plotTwenty.h"
// design pattern strategy
class Strategy
{
public:
	Strategy() { implement = new PlotTen; };
	void showTen() { delete implement; implement = new PlotTen; }
	void showTwenty() { delete implement; implement = new PlotTwenty; }
	void show() {
		implement->plot();
	}

private:
	PlotImpl* implement;
};
#endif // !STRATEGY_H

