#ifndef ICONS_H
#define ICONS_H 1

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#	include <wx/wx.h>
#endif

extern void initialize_images(void);

extern wxBitmap *_img_ocpndebugger;
extern wxBitmap *_img_ocpndebugger_pi;

#ifdef OCPNDEBUGGER_USE_SVG
extern wxString _svg_ocpndebugger;
extern wxString _svg_ocpndebugger_rollover;
extern wxString _svg_ocpndebugger_toggled;
#endif

#endif /* ICONS_H */
