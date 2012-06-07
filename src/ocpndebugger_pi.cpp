/******************************************************************************
 * $Id: ocpndebugger_pi.cpp,v 1.0 2011/02/26 01:54:37 nohal Exp $
 *
 * Project:  OpenCPN
 * Purpose:  OpenCPNDebugger Plugin
 * Author:   Pavel Kalian
 *
 ***************************************************************************
 *   Copyright (C) 2012 by Pavel Kalian   *
 *   $EMAIL$   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.             *
 ***************************************************************************
 */
#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

#include "ocpndebugger_pi.h"

// the class factories, used to create and destroy instances of the PlugIn

extern "C" DECL_EXP opencpn_plugin* create_pi(void *ppimgr)
{
    return new ocpndebugger_pi(ppimgr);
}

extern "C" DECL_EXP void destroy_pi(opencpn_plugin* p)
{
    delete p;
}

//---------------------------------------------------------------------------------------------------------
//
//    OpenCPNDebugger PlugIn Implementation
//
//---------------------------------------------------------------------------------------------------------

#include "icons.h"

//---------------------------------------------------------------------------------------------------------
//
//          PlugIn initialization and de-init
//
//---------------------------------------------------------------------------------------------------------

ocpndebugger_pi::ocpndebugger_pi(void *ppimgr)
      :opencpn_plugin_18(ppimgr)
{
      // Create the PlugIn icons
      initialize_images();
}

int ocpndebugger_pi::Init(void)
{
      AddLocaleCatalog( _T("opencpn-ocpndebugger_pi") );

      // Set some default private member parameters
      m_ocpndebugger_dialog_x = 0;
      m_ocpndebugger_dialog_y = 0;

      ::wxDisplaySize(&m_display_width, &m_display_height);

      //    Get a pointer to the opencpn display canvas, to use as a parent for the POI Manager dialog
      m_parent_window = GetOCPNCanvasWindow();

      //    This PlugIn needs a toolbar icon, so request its insertion
      m_leftclick_tool_id  = InsertPlugInTool(_T(""), _img_ocpndebugger, _img_ocpndebugger, wxITEM_NORMAL,
            _("OpenCPNDebugger"), _T(""), NULL,
             OpenCPNDEBUGGER_TOOL_POSITION, 0, this);

      m_pOpenCPNDebuggerDialog = NULL;

      return (WANTS_TOOLBAR_CALLBACK    |
              INSTALLS_TOOLBAR_TOOL     |
              WANTS_NMEA_SENTENCES      |
              WANTS_NMEA_EVENTS         |
              WANTS_AIS_SENTENCES       |
              WANTS_PLUGIN_MESSAGING
           );
}

bool ocpndebugger_pi::DeInit(void)
{
      //    Record the dialog position
      if (NULL != m_pOpenCPNDebuggerDialog)
      {
            wxPoint p = m_pOpenCPNDebuggerDialog->GetPosition();
            SetOpenCPNDebuggerDialogX(p.x);
            SetOpenCPNDebuggerDialogY(p.y);

            m_pOpenCPNDebuggerDialog->Close();
            delete m_pOpenCPNDebuggerDialog;
            m_pOpenCPNDebuggerDialog = NULL;
      }
      return true;
}

int ocpndebugger_pi::GetAPIVersionMajor()
{
      return MY_API_VERSION_MAJOR;
}

int ocpndebugger_pi::GetAPIVersionMinor()
{
      return MY_API_VERSION_MINOR;
}

int ocpndebugger_pi::GetPlugInVersionMajor()
{
      return PLUGIN_VERSION_MAJOR;
}

int ocpndebugger_pi::GetPlugInVersionMinor()
{
      return PLUGIN_VERSION_MINOR;
}

wxBitmap *ocpndebugger_pi::GetPlugInBitmap()
{
      return _img_ocpndebugger_pi;
}

wxString ocpndebugger_pi::GetCommonName()
{
      return _("OpenCPNDebugger");
}


wxString ocpndebugger_pi::GetShortDescription()
{
      return _("OpenCPNDebugger PlugIn for OpenCPN");
}

wxString ocpndebugger_pi::GetLongDescription()
{
      return _("Shows the OpenCPN streams from GPS and AIS ports that propagate through the plugin interface, NMEA Events and messages flowing through the polugin API");
}


int ocpndebugger_pi::GetToolbarToolCount(void)
{
      return 1;
}

void ocpndebugger_pi::SetColorScheme(PI_ColorScheme cs)
{
      if (NULL == m_pOpenCPNDebuggerDialog)
            return;

      DimeWindow(m_pOpenCPNDebuggerDialog);
}


void ocpndebugger_pi::OnToolbarToolCallback(int id)
{
      if(NULL == m_pOpenCPNDebuggerDialog)
      {
            m_pOpenCPNDebuggerDialog = new OpenCPNDebuggerDlgImpl(m_parent_window);
            m_pOpenCPNDebuggerDialog->Move(wxPoint(m_ocpndebugger_dialog_x, m_ocpndebugger_dialog_y));
      }

      m_pOpenCPNDebuggerDialog->Show(!m_pOpenCPNDebuggerDialog->IsShown());
}


void ocpndebugger_pi::SetNMEASentence(wxString &sentence)
{
      if(NULL != m_pOpenCPNDebuggerDialog)
            m_pOpenCPNDebuggerDialog->SetGPSMessage(sentence);
}

void ocpndebugger_pi::SetAISSentence(wxString &sentence)
{
      if(NULL != m_pOpenCPNDebuggerDialog)
            m_pOpenCPNDebuggerDialog->SetAISMessage(sentence);
}

void ocpndebugger_pi::SetPluginMessage(wxString &message_id, wxString &message_body)
{
      if(NULL != m_pOpenCPNDebuggerDialog)
            m_pOpenCPNDebuggerDialog->SetPluginMessage(message_id, message_body);
}

void ocpndebugger_pi::SetPositionFixEx(PlugIn_Position_Fix_Ex &pfix)
{
      if(NULL != m_pOpenCPNDebuggerDialog)
      {
            m_pOpenCPNDebuggerDialog->SetNMEAEvent(wxString::Format(_T("Cog: %f, Hdm: %f, Hdt: %f, Lat: %f, Lon: %f, Sog: %f, Var: %f, nSats: %d, Fixtime: %d\n"), 
                  pfix.Cog, pfix.Hdm, pfix.Hdt, pfix.Lat, pfix.Lon, pfix.Sog, pfix.Var, pfix.nSats, pfix.FixTime));
      }
}