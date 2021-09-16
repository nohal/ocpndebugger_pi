///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 10 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "ocpndebuggergui.h"

///////////////////////////////////////////////////////////////////////////


OpenCPNDebuggerDlg::OpenCPNDebuggerDlg(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos,
                                       const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style) {
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer* bSizer1;
    bSizer1 = new wxBoxSizer(wxVERTICAL);

    m_notebook1 = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);
    m_panelGPS = new wxPanel(m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    wxBoxSizer* bSizer3;
    bSizer3 = new wxBoxSizer(wxVERTICAL);

    m_tcGPS = new wxTextCtrl(m_panelGPS, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);
    bSizer3->Add(m_tcGPS, 1, wxALL | wxEXPAND, 5);

    m_tbGPSPause = new wxToggleButton(m_panelGPS, wxID_ANY, _("Pause"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer3->Add(m_tbGPSPause, 0, wxALL, 5);

    m_panelGPS->SetSizer(bSizer3);
    m_panelGPS->Layout();
    bSizer3->Fit(m_panelGPS);
    m_notebook1->AddPage(m_panelGPS, _("NMEA"), false);
    m_panelAIS = new wxPanel(m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    wxBoxSizer* bSizer4;
    bSizer4 = new wxBoxSizer(wxVERTICAL);

    m_tcAIS = new wxTextCtrl(m_panelAIS, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);
    bSizer4->Add(m_tcAIS, 1, wxALL | wxEXPAND, 5);

    m_tbAISPause = new wxToggleButton(m_panelAIS, wxID_ANY, _("Pause"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer4->Add(m_tbAISPause, 0, wxALL, 5);

    m_panelAIS->SetSizer(bSizer4);
    m_panelAIS->Layout();
    bSizer4->Fit(m_panelAIS);
    m_notebook1->AddPage(m_panelAIS, _("AIS"), false);
    m_panelEvents = new wxPanel(m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    wxBoxSizer* bSizer5;
    bSizer5 = new wxBoxSizer(wxVERTICAL);

    m_tcEvents =
        new wxTextCtrl(m_panelEvents, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);
    bSizer5->Add(m_tcEvents, 1, wxALL | wxEXPAND, 5);

    m_tbNMEAEvtsPause = new wxToggleButton(m_panelEvents, wxID_ANY, _("Pause"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer5->Add(m_tbNMEAEvtsPause, 0, wxALL, 5);

    m_panelEvents->SetSizer(bSizer5);
    m_panelEvents->Layout();
    bSizer5->Fit(m_panelEvents);
    m_notebook1->AddPage(m_panelEvents, _("NMEA Events"), true);
    m_panelMessages = new wxPanel(m_notebook1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
    wxBoxSizer* bSizer6;
    bSizer6 = new wxBoxSizer(wxVERTICAL);

    m_tcMessages =
        new wxTextCtrl(m_panelMessages, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);
    bSizer6->Add(m_tcMessages, 1, wxALL | wxEXPAND, 5);

    m_tbMessagesPause = new wxToggleButton(m_panelMessages, wxID_ANY, _("Pause"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer6->Add(m_tbMessagesPause, 0, wxALL, 5);

    m_panelMessages->SetSizer(bSizer6);
    m_panelMessages->Layout();
    bSizer6->Fit(m_panelMessages);
    m_notebook1->AddPage(m_panelMessages, _("Messages"), false);

    bSizer1->Add(m_notebook1, 1, wxEXPAND | wxALL, 5);

    m_sdbSizer1 = new wxStdDialogButtonSizer();
    m_sdbSizer1OK = new wxButton(this, wxID_OK);
    m_sdbSizer1->AddButton(m_sdbSizer1OK);
    m_sdbSizer1->Realize();

    bSizer1->Add(m_sdbSizer1, 0, wxALL | wxEXPAND, 5);

    this->SetSizer(bSizer1);
    this->Layout();

    this->Centre(wxBOTH);
}

OpenCPNDebuggerDlg::~OpenCPNDebuggerDlg() {}
