///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jul 15 2016)
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
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/stattext.h>
#include <wx/scrolwin.h>
#include <wx/listctrl.h>
#include <wx/splitter.h>
#include <wx/notebook.h>
#include <wx/tglbtn.h>
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
		wxPanel* m_panelAIS;
		wxTextCtrl* m_tcAIS;
		wxPanel* m_panelEvents;
		wxTextCtrl* m_tcEvents;
		wxPanel* m_panelMessages;
		wxSplitterWindow* m_splitter1;
		wxPanel* m_panel1;
		wxScrolledWindow* m_scrolledWindow1;
		wxStaticText* m_stMessage;
		wxPanel* m_panel2;
		wxListCtrl* m_lMessages;
		wxToggleButton* m_tbPause;
		wxButton* m_bClear;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnMessageSelected( wxListEvent& event ) { event.Skip(); }
		virtual void OnClear( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		OpenCPNDebuggerDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("OPENCPN Debugger"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 701,370 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER ); 
		~OpenCPNDebuggerDlg();
		
		void m_splitter1OnIdle( wxIdleEvent& )
		{
			m_splitter1->SetSashPosition( 100 );
			m_splitter1->Disconnect( wxEVT_IDLE, wxIdleEventHandler( OpenCPNDebuggerDlg::m_splitter1OnIdle ), NULL, this );
		}
	
};

#endif //__OCPNDEBUGGERGUI_H__
