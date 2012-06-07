///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 10 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __OCPNDEBUGGERGUI_H__
#define __OCPNDEBUGGERGUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/textctrl.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/tglbtn.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class OpenCPNDebuggerDlg
///////////////////////////////////////////////////////////////////////////////
class OpenCPNDebuggerDlg : public wxDialog 
{
	private:
	
	protected:
		wxNotebook* m_notebook1;
		wxPanel* m_panelGPS;
		wxTextCtrl* m_tcGPS;
		wxToggleButton* m_tbGPSPause;
		wxPanel* m_panelAIS;
		wxTextCtrl* m_tcAIS;
		wxToggleButton* m_tbAISPause;
		wxPanel* m_panelEvents;
		wxTextCtrl* m_tcEvents;
		wxToggleButton* m_tbNMEAEvtsPause;
		wxPanel* m_panelMessages;
		wxTextCtrl* m_tcMessages;
		wxToggleButton* m_tbMessagesPause;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
	
	public:
		
		OpenCPNDebuggerDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("OPENCPN Debugger"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 701,370 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER ); 
		~OpenCPNDebuggerDlg();
	
};

#endif //__OCPNDEBUGGERGUI_H__
