/******************************************************************************
 * $Id: ocpndebuggergui_impl.cpp,v 1.0 2011/02/26 01:54:37 nohal Exp $
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

#include "ocpndebuggergui_impl.h"

OpenCPNDebuggerDlgImpl::OpenCPNDebuggerDlgImpl( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : OpenCPNDebuggerDlg( parent, id, title, pos, size, style )
{
}

void OpenCPNDebuggerDlgImpl::SetGPSMessage(wxString &msg)
{
      if (!m_tbGPSPause->GetValue())
            m_tcGPS->AppendText(msg);
}

void OpenCPNDebuggerDlgImpl::SetAISMessage(wxString &msg)
{
      if (!m_tbAISPause->GetValue())
            m_tcAIS->AppendText(msg);
}

void OpenCPNDebuggerDlgImpl::SetPluginMessage(wxString &id, wxString &msg)
{
      if (!m_tbMessagesPause->GetValue())
      {
            m_tcMessages->AppendText(wxString::Format(_T("%s : "), id.c_str()));
            m_tcMessages->AppendText(msg);
      }
}

void OpenCPNDebuggerDlgImpl::SetNMEAEvent(wxString &msg)
{
      if (!m_tbNMEAEvtsPause->GetValue())
            m_tcEvents->AppendText(msg);
}