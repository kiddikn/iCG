//
// scatteredCircleBrush.cpp
//
// The implementation of Point Brush. It is a kind of ImpBrush. All your brush implementations
// will look like the file with the different GL primitive calls.
//

#include "impressionistDoc.h"
#include "impressionistUI.h"
#include "scatteredCircleBrush.h"
#include "math.h"
#define PI 3.1415

extern float frand();

ScatteredCircleBrush::ScatteredCircleBrush( ImpressionistDoc* pDoc, char* name ) :
	ImpBrush(pDoc,name)
{
}

void ScatteredCircleBrush::BrushBegin( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;

	int size = pDoc->getSize();
	

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPointSize( (float)size );

	BrushMove( source, target );
}

void ScatteredCircleBrush::BrushMove( const Point source, const Point target )
{
	ImpressionistDoc* pDoc = GetDocument();
	ImpressionistUI* dlg=pDoc->m_pUI;
	if ( pDoc == NULL ) {
		printf( "ScatteredCircleBrush::BrushMove  document is NULL\n" );
		return;
	}

	//scatteredCircleBrush
	int alpha = pDoc->getAlpha();
	SetColorAlpha( source, alpha );
	int size=pDoc->getSize();
	int div = 12;
	float radius = size/10;
	float Ax,Ay;
	float center_x,center_y;

	for(int i=0;i<10;i++){
		center_x=target.x-size/2+rand()%size;
		center_y=target.y-size/2+rand()%size;
		glBegin( GL_POLYGON );
		for(int j=0;j<div;j++){
			Ax=center_x+radius*cos(2*PI*j/div);
			Ay=center_y+radius*sin(2*PI*j/div);
			glVertex2f(Ax,Ay);	 //floatŒ^‚Åˆø”Žw’è
		}
		glEnd();
	}
}

void ScatteredCircleBrush::BrushEnd( const Point source, const Point target )
{
	// do nothing so far
	glDisable(GL_BLEND);

}

