//
// originalBrush.h
//
// The header file for Point Brush. 
//

#ifndef ORIGINALBRUSH_H
#define ORIGINALBRUSH_H

#include "impBrush.h"

class OriginalBrush : public ImpBrush
{
public:
	OriginalBrush( ImpressionistDoc* pDoc = NULL, char* name = NULL );

	void BrushBegin( const Point source, const Point target );
	void BrushMove( const Point source, const Point target );
	void BrushEnd( const Point source, const Point target );
	char* BrushName( void );
};

#endif
