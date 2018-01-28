#pragma once
#ifndef PLOTIMPL_H
#define PLOTIMPL_H
#include <fstream>
#include <string>
#include <engine.h>
#include <yvals.h>
#if (_MSC_VER >= 1600)
#define __STDC_UTF_16__
#endif
#include "mex.h"
class PlotImpl
{
public:
	virtual void plot() = 0;
private:

};
#endif // !PLOTIMPL_H

