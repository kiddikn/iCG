//
// impressionistUI.h
//
// The header file for the UI part
//

#ifndef ImpressionistUI_h
#define ImpressionistUI_h

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_File_Chooser.H>		// FLTK file chooser
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Color_Chooser.H>

#include "impressionist.h"
#include "originalView.h"
#include "paintView.h"
#include "FltDesignUI.h"
#include "impBrush.h"

const int FLT_WIDTH = 5;
const int FLT_HEIGHT = 5;

class ImpressionistUI {
public:
	ImpressionistUI();
	~ImpressionistUI();

	// The FLTK widgets
	Fl_Window*			m_mainWindow;
	Fl_Menu_Bar*		m_menubar;
								
	PaintView*			m_paintView;
	OriginalView*		m_origView;

	FltDesignUI*		fltDesignUI;

// for brush dialog
	Fl_Window*			m_brushDialog;
	Fl_Choice*			m_BrushTypeChoice;

	Fl_Slider*			m_BrushSizeSlider;
	//ÀK
	//px
	Fl_Slider*			m_BrushAngleSlider;
	//width
	Fl_Slider*			m_BrushWidthSlider;
	//¿lÌXC_[
	Fl_Slider*			m_BrushAlphaSlider;

	Fl_Button*          m_ClearCanvasButton;

	// Member functions
	void				setDocument(ImpressionistDoc* doc);
	ImpressionistDoc*	getDocument();

	void				show();
	void				resize_windows(int w, int h);

	// Interface to get attribute

	int					getSize();
	//ÀK
	//px
	int					getAngle();
	//width 
	int					getWidth();
	//alpha
	int					getAlpha();

	void				setSize(int size);
	//ÀK
	//px
	void				setAngle(int angle);
	//width
	void				setWidth(int width);
	//alpha
	void				setAlpha(int alpha);

	// Callbacks for the image filter dialogue (different from
	// the other callbacks because they aren't static)
	void				initFltDesignUI(void);
	void				updateFilter(void);

	void				cancelFilter(void);
	void				applyFilter(void);
	void				previewFilter(void);


private:
	ImpressionistDoc*	m_pDoc;		// pointer to document to communicate with the document

	// All attributes here
	int		m_nSize;
	//ÀK
	//px
	int		m_nAngle;
	//width
	int		m_nWidth;
	//alpha
	int		m_nAlpha;

	// These attributes are set by the filter kernel UI
	double fltKernel[FLT_WIDTH*FLT_HEIGHT];		//the kernel of the image filter
	double scale,offset;						//the divisor and offset parameter, 
												//applied after convolving to transform 
												//the filtered image into the range [0,255]


	// Static class members
	static Fl_Menu_Item		menuitems[];
	static Fl_Menu_Item		brushTypeMenu[NUM_BRUSH_TYPE+1];

	static ImpressionistUI*	whoami(Fl_Menu_* o);

	// All callbacks here.  Callbacks are declared 
	// static
	static void	cb_load_image(Fl_Menu_* o, void* v);
	static void	cb_save_image(Fl_Menu_* o, void* v);
	static void	cb_brushes(Fl_Menu_* o, void* v);
	static void cb_filter_kernel(Fl_Menu_* o, void* v);
	static void	cb_clear_canvas(Fl_Menu_* o, void* v);
	static void	cb_exit(Fl_Menu_* o, void* v);
	static void	cb_about(Fl_Menu_* o, void* v);
	static void	cb_brushChoice(Fl_Widget* o, void* v);
	static void	cb_clear_canvas_button(Fl_Widget* o, void* v);
	static void cb_copy_image_to_canvas(Fl_Menu_* o, void* v);  //RñÚÀK@FilterKernel
	static void	cb_sizeSlides(Fl_Widget* o, void* v);

	//ÀK
	//px
	static void cb_angleSlides(Fl_Widget* o,void* v);//Line BrushÌÇÁ(2)ÜÅâÁ½10/9
	//width
	static void cb_widthSlides(Fl_Widget* o,void* v);
	//¿lR[obN
	static void cb_alphaSlides(Fl_Widget* o,void* v);
};

#endif

