/******************************************************************************
 * $Id: ocpndebugger_pi.h,v 1.0 2011/02/26 01:54:37 nohal Exp $
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

#ifndef _OpenCPNDEBUGGERPI_H_
#define _OpenCPNDEBUGGERPI_H_

#include "wx/wxprec.h"

#ifndef WX_PRECOMP
#include <wx/glcanvas.h>
#include "wx/wx.h"
#endif  // precompiled headers

#include "version.h"

#define MY_API_VERSION_MAJOR 1
#define MY_API_VERSION_MINOR 14

#include "ocpn_plugin.h"

#include "ocpndebuggergui_impl.h"

class OpenCPNDebuggerDlgImpl;

//----------------------------------------------------------------------------------------------------------
//    The PlugIn Class Definition
//----------------------------------------------------------------------------------------------------------

#define OpenCPNDEBUGGER_TOOL_POSITION -1  // Request default positioning of toolbar tool

class ocpndebugger_pi : public opencpn_plugin_114 {
   public:
    ocpndebugger_pi(void *ppimgr);

    //    The required PlugIn Methods
    int Init(void);
    bool DeInit(void);

    int GetAPIVersionMajor();
    int GetAPIVersionMinor();
    int GetPlugInVersionMajor();
    int GetPlugInVersionMinor();
    wxBitmap *GetPlugInBitmap();
    wxString GetCommonName();
    wxString GetShortDescription();
    wxString GetLongDescription();

    //    The required override PlugIn Methods
    int GetToolbarToolCount(void);

    void OnToolbarToolCallback(int id);

    //    Optional plugin overrides
    void SetColorScheme(PI_ColorScheme cs);
    void SetNMEASentence(wxString &sentence);
    void SetAISSentence(wxString &sentence);
    void SetPluginMessage(wxString &message_id, wxString &message_body);
    void SetPositionFixEx(PlugIn_Position_Fix_Ex &pfix);

    //    Other public methods
    void SetOpenCPNDebuggerDialogX(int x) { m_ocpndebugger_dialog_x = x; };
    void SetOpenCPNDebuggerDialogY(int x) { m_ocpndebugger_dialog_y = x; }

    void OnOpenCPNDebuggerDialogClose();

   private:
    wxWindow *m_parent_window;

    OpenCPNDebuggerDlgImpl *m_pOpenCPNDebuggerDialog;

    int m_ocpndebugger_dialog_x, m_ocpndebugger_dialog_y;
    int m_display_width, m_display_height;

    int m_leftclick_tool_id;
};

#endif
