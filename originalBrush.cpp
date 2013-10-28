//
// originalBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "originalBrush.h"
#include "math.h"
#define PI 3.1415

extern float frand();

OriginalBrush::OriginalBrush( ImpressionistDoc* pDoc, char* name ) :
	ImpBrush(pDoc,name)
{
}

void OriginalBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	int size = pDoc->getSize();
	

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPointSize( (float)size );

	BrushMove( source, target );
}

void OriginalBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	//スライダーつけたあと

	if ( pDoc == NULL ) {
		printf( "OriginalBrush::BrushMove  document is NULL\n" );
		return;
	}
	/*
	//SetColorAlpha( source, alpha );
	SetColor( source );
	glBegin( GL_POLYGON );
	glVertex2i( target.x         , target.y+0.5*size );
	glVertex2i( target.x+0.5*size, target.y-0.5*size );
	glVertex2i( target.x-0.5*size, target.y-0.5*size );
	glEnd();
	*/

	//originalBrush
	int alpha = pDoc->getAlpha();
	SetColorAlpha( source, alpha );
	int size=pDoc->getSize();
	float center_x,center_y;

	for(int i=0;i<10;i++){
		center_x=target.x-size/2+rand()%size;
		center_y=target.y-size/2+rand()%size;
		glBegin( GL_POLYGON );
			glVertex2i( center_x         , center_y+0.2*size );
			glVertex2i( center_x+0.2*size, center_y-0.2*size );
			glVertex2i( center_x-0.2*size, center_y-0.2*size );
		glEnd();

		
	}
}

void OriginalBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
	glDisable(GL_BLEND);

}

